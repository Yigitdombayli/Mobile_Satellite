using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SotmGroundControl.Core.Enums
{
    public enum  CommandId : byte
    {
        SetMode=0x10,
        ManualAngles = 0x11,
        SetSatelliteGps=0x12,
        ReqTelemetry = 0x20,
        ResTelemetry= 0x21
    }
}
