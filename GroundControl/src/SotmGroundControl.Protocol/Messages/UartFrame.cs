using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SotmGroundControl.Protocol.Messages
{
    /*STM32'nin gönderdiği #pragma pack yapısındaki iletişim paketinin
    C# tarafındaki karşılığı budur. Gelen paketi doğrulamak için ara
    bellekte bu sınıfı kullanacağız. */
    public class UartFrame
    {
        public byte StartByte { get; set; }
        public byte CommandId { get; set; }
        public byte PayloadLength { get; set; }
        public byte[] Payload { get; set; } = Array.Empty<byte>();
        public ushort Crc16 { get; set; }
        public byte StopByte { get; set; }
    }
}
