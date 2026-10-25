using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace SotmGroundControl.Protocol.Codec
{
    public static class MessageDecoder
    {
        public static T DecodePayload<T>(byte[] payload) where T : struct
        {
            int size = Marshal.SizeOf(typeof(T));

            if (payload.Length != size)
                throw new ArgumentException($"Payload boyutu ({payload.Length}) ile nesne boyutu ({size}) uyuşmuyor.");

            IntPtr ptr = Marshal.AllocHGlobal(size);
            Marshal.Copy(payload, 0, ptr, size);

            T result = (T)Marshal.PtrToStructure(ptr, typeof(T))!;
            Marshal.FreeHGlobal(ptr);

            return result;
        }
    }
}
