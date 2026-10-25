using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.Generic;
using SotmGroundControl.Core.Constants;
using SotmGroundControl.Protocol.Messages;

namespace SotmGroundControl.Protocol.Framing
{
    public class FrameParser
    {
        // Gelen byte'ları biriktirdiğimiz geçici havuz
        private readonly List<byte> _buffer = new List<byte>();

        // Seri porttan yeni veri geldikçe bu havuza ekliyoruz
        public void AddBytes(byte[] data)
        {
            _buffer.AddRange(data);
        }

        // Havuzda tam ve hatasız bir paket olup olmadığını kontrol eden fonksiyon
        public UartFrame? TryParseFrame()
        {
            while (_buffer.Count > 0)
            {
                int startIndex = _buffer.IndexOf(ProtocolConstants.StartByte);

                if (startIndex == -1)
                {
                   // Console.WriteLine("[PARSER] Start byte (0xAA) yok, buffer temizlendi.");
                    _buffer.Clear();
                    return null;
                }

                if (startIndex > 0)
                {
                   // Console.WriteLine($"[PARSER] {startIndex} byte çöp atıldı.");
                    _buffer.RemoveRange(0, startIndex);
                }

                if (_buffer.Count < 6)
                    return null;

                byte commandId = _buffer[1];
                byte payloadLength = _buffer[2];

                if (payloadLength > ProtocolConstants.MaxPayloadSize)
                {
                  //  Console.WriteLine($"[PARSER] RED: payloadLength={payloadLength} > Max={ProtocolConstants.MaxPayloadSize}");
                    _buffer.RemoveAt(0);
                    continue;
                }

                int expectedFrameLength = 1 + 1 + 1 + payloadLength + 2 + 1;

                if (_buffer.Count < expectedFrameLength)
                    return null;

                if (_buffer[expectedFrameLength - 1] != ProtocolConstants.StopByte)
                {
                  //  Console.WriteLine($"[PARSER] RED: Stop byte yanlış. Beklenen 0x55, gelen 0x{_buffer[expectedFrameLength - 1]:X2}, len={payloadLength}");
                    _buffer.RemoveAt(0);
                    continue;
                }

                ushort receivedCrc = (ushort)(_buffer[3 + payloadLength] | (_buffer[4 + payloadLength] << 8));
                byte[] snapshot = _buffer.ToArray();

                ushort calculatedCrc = Crc16Calculator.ComputeChecksum(snapshot, 1, 2 + payloadLength);

                if (receivedCrc != calculatedCrc)
                {
                    // Arkadaşın start byte'ı da CRC'ye katmış olabilir, onu da dene
                    ushort altCrc = Crc16Calculator.ComputeChecksum(snapshot, 0, 3 + payloadLength);
                 //   Console.WriteLine($"[PARSER] RED: CRC uyuşmuyor. Gelen=0x{receivedCrc:X4}, Hesaplanan=0x{calculatedCrc:X4}, StartByte'lı hesap=0x{altCrc:X4}");
                    _buffer.RemoveAt(0);
                    continue;
                }

                var frame = new UartFrame
                {
                    StartByte = _buffer[0],
                    CommandId = commandId,
                    PayloadLength = payloadLength,
                    Payload = new byte[payloadLength],
                    Crc16 = receivedCrc,
                    StopByte = _buffer[expectedFrameLength - 1]
                };

                _buffer.CopyTo(3, frame.Payload, 0, payloadLength);
                _buffer.RemoveRange(0, expectedFrameLength);

              //  Console.WriteLine($"[PARSER] OK: cmd=0x{commandId:X2}, len={payloadLength}");
                return frame;
            }

            return null;
        }
    }
}
