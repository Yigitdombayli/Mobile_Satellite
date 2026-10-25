using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SotmGroundControl.Protocol.Messages;


namespace SotmGroundControl.Application.Interfaces
{
    public interface ISerialCommunicationService
    {
        bool IsOpen { get; }
        void Connect(string portName, int baudRate);
        void Disconnect();
        void SendCommand<T>(byte commandId, T payload) where T : struct;

        // STM32'den hatasız tam bir paket geldiğinde bu event tetiklenecek
        event Action<UartFrame>? OnFrameReceived;
    }
}
