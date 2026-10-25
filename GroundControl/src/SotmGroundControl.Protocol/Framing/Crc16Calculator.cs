using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SotmGroundControl.Protocol.Framing
{
    /*Gömülü sistemlerde verinin yolda bozulup bozulmadığını kontrol etmek şarttır.
     Arkadaşına CRC standardını sormanı önermiştim; şimdilik endüstride (ve STM32 projelerinde) 
    en yaygın kullanılan CRC-16 Modbus algoritmasını buraya ekliyoruz. Eğer arkadaşın farklı bir 
    polinom kullanıyorsa buradaki 0xA001 sabitini değiştirmemiz yeterli olacaktır.*/
    public static class Crc16Calculator
    {
        public static ushort ComputeChecksum(byte[] bytes, int start, int length)
        {
            ushort crc = 0xFFFF;
            for (int pos = start; pos < start + length; pos++)
            {
                crc ^= bytes[pos];
                for (int i = 8; i != 0; i--)
                {
                    if ((crc & 0x0001) != 0)
                    {
                        crc >>= 1;
                        crc ^= 0xA001;
                    }
                    else
                    {
                        crc >>= 1;
                    }
                }
            }
            return crc;
        }
    }
}
