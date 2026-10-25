using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using SotmGroundControl.Core.Enums;

namespace SotmGroundControl.Core.Models
{
    [StructLayout(LayoutKind.Sequential, Pack = 1)]  //STM32 tarafında #pragma pack(push,1) kuralı için Pack=1 niteliği eklendi - byte kaymaları olmaması adına 
    public struct TelemetryData
    {
        public SystemMode CurrentMode;
        public float CurrentAzimuth;
        public float CurrentElevation;
        public float CurrentRoll;
        public float CurrentPitch;
        public byte SystemStatus;
    }
}
