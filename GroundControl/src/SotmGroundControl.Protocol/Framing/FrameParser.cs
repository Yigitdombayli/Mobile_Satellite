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
                // 1. Start Byte (0xAA) ara
                int startIndex = _buffer.IndexOf(ProtocolConstants.StartByte);

                if (startIndex == -1)
                {
                    _buffer.Clear(); // Başlangıç byte'ı yoksa hepsi çöptür, havuzu temizle
                    return null;
                }

                // Eğer Start Byte'tan önce çöp veriler (noise) varsa, onları silip Start Byte'ı başa al
                if (startIndex > 0)
                {
                    _buffer.RemoveRange(0, startIndex);
                }

                // Minimum paket boyutu: Start(1) + Cmd(1) + Len(1) + Payload(0) + CRC(2) + Stop(1) = 6 byte
                if (_buffer.Count < 6)
                    return null; // Paket henüz tamamlanmadı, yeni verilerin gelmesini bekle

                byte commandId = _buffer[1];
                byte payloadLength = _buffer[2];

                // Güvenlik: Şartnamedeki maksimum limiti aşıyorsa hatalı veridir
                if (payloadLength > ProtocolConstants.MaxPayloadSize)
                {
                    _buffer.RemoveAt(0); // Baştaki hatalı Start Byte'ı atıp bir sonraki 0xAA'yı ara
                    continue;
                }

                int expectedFrameLength = 1 + 1 + 1 + payloadLength + 2 + 1;

                if (_buffer.Count < expectedFrameLength)
                    return null; // Paket boyutu belli oldu ama henüz tüm byte'lar ulaşmadı, bekle

                // 2. Stop Byte (0x55) Kontrolü
                if (_buffer[expectedFrameLength - 1] != ProtocolConstants.StopByte)
                {
                    _buffer.RemoveAt(0); // Stop byte yanlış, demek ki yolda kayma oldu
                    continue;
                }

                // 3. CRC Kontrolü
                // STM32 tarafı Little-Endian çalışır, CRC'nin önce düşük, sonra yüksek byte'ı gelir
                ushort receivedCrc = (ushort)(_buffer[3 + payloadLength] | (_buffer[4 + payloadLength] << 8));

                // Kendi CRC'mizi hesaplıyoruz (Sadece Cmd, Len ve Payload kısımları hesaplamaya girer)
                ushort calculatedCrc = Crc16Calculator.ComputeChecksum(_buffer.ToArray(), 1, 2 + payloadLength);

                if (receivedCrc != calculatedCrc)
                {
                    _buffer.RemoveAt(0); // Veri yolda elektriksel gürültüden bozulmuş, çöpe at
                    continue;
                }

                // 4. Bütün testleri geçtiyse paketi oluştur!
                var frame = new UartFrame
                {
                    StartByte = _buffer[0],
                    CommandId = commandId,
                    PayloadLength = payloadLength,
                    Payload = new byte[payloadLength],
                    Crc16 = receivedCrc,
                    StopByte = _buffer[expectedFrameLength - 1]
                };

                // Havuzdaki asıl veriyi paketin Payload kısmına kopyala
                _buffer.CopyTo(3, frame.Payload, 0, payloadLength);

                // İşlenen paketi havuzdan sil ki bir sonraki pakete geçebilelim
                _buffer.RemoveRange(0, expectedFrameLength);

                return frame;
            }

            return null; // İşlenecek tam paket yok
        }
    }
}
