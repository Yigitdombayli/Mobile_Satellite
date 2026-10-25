using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace SotmGroundControl.Core.Models
{
    [StructLayout(LayoutKind.Sequential, Pack = 1)]
    public struct ManualCommandData
    {
        public float TargetAzimuth;
        public float TargetElevation;
    }
}
