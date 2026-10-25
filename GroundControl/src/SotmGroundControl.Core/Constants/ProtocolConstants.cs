using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SotmGroundControl.Core.Constants
{
    public static class ProtocolConstants
    {
        public const byte StartByte = 0xAA;
        public const byte StopByte = 0x55;
        public const int MaxPayloadSize = 32;
    }
}
