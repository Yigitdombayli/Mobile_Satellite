using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using SotmGroundControl.Core.Constants;
using SotmGroundControl.Protocol.Framing;

/*Bu sınıf, arayüzden "Manuel Moda Geç" veya "Azimuth'u 45 yap" dediğinde devreye girecek. 
 C# nesneni bellekteki ham byte'lara (Marshal) dönüştürüp aralarına 
 0xAA ve 0x55 ekleyerek gönderime hazır hale getirir.*/

namespace SotmGroundControl.Protocol.Codec
{

    public static class MessageEncoder
    {
        public static byte[] Encode<T>(byte commandId, T payloadData) where T : struct
        {
            int payloadLength = Marshal.SizeOf(typeof(T));

            if (payloadLength > ProtocolConstants.MaxPayloadSize)
                throw new ArgumentException("Payload boyutu maksimum sınırı aşıyor.");

            int frameLength = 1 + 1 + 1 + payloadLength + 2 + 1; // Start + Cmd + Len + Payload + Crc + Stop
            byte[] frame = new byte[frameLength];

            frame[0] = ProtocolConstants.StartByte;
            frame[1] = commandId;
            frame[2] = (byte)payloadLength;

            // Struct yapısını pointer üzerinden byte dizisine kopyala (Marshaling)
            IntPtr ptr = Marshal.AllocHGlobal(payloadLength);
            Marshal.StructureToPtr(payloadData, ptr, true);
            Marshal.Copy(ptr, frame, 3, payloadLength);
            Marshal.FreeHGlobal(ptr);

            // CRC Hesaplama (Genellikle CommandId ve Payload verisi dahil edilerek hesaplanır)
            ushort crc = Crc16Calculator.ComputeChecksum(frame, 1, 2 + payloadLength);

            // Little-Endian formatında CRC byte'larını yerleştir
            frame[3 + payloadLength] = (byte)(crc & 0xFF);
            frame[4 + payloadLength] = (byte)((crc >> 8) & 0xFF);

            frame[5 + payloadLength] = ProtocolConstants.StopByte;

            return frame;
        }
    }
}
