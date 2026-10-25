using SotmGroundControl.Application.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;
using SotmGroundControl.Protocol.Codec;
using SotmGroundControl.Protocol.Framing;
using SotmGroundControl.Protocol.Messages;

namespace SotmGroundControl.Infrastructure.Communication.Transports
{
    public class SerialPortManager : ISerialCommunicationService, IDisposable
    {
        private readonly SerialPort _serialPort;
        private readonly FrameParser _frameParser;

        public event Action<UartFrame>? OnFrameReceived;

        public bool IsOpen => _serialPort.IsOpen;

        public SerialPortManager()
        {
            _serialPort = new SerialPort();
            _frameParser = new FrameParser();

            // Seri porttan veri geldiğinde otomatik tetiklenecek metodu bağlıyoruz
            _serialPort.DataReceived += SerialPort_DataReceived;
        }

        public void Connect(string portName, int baudRate)
        {
            if (_serialPort.IsOpen) return;

            _serialPort.PortName = portName;
            _serialPort.BaudRate = baudRate;
            _serialPort.Parity = Parity.None;
            _serialPort.DataBits = 8;
            _serialPort.StopBits = StopBits.One;

            _serialPort.Open();
        }

        public void Disconnect()
        {
            if (_serialPort.IsOpen)
            {
                _serialPort.Close();
            }
        }

        // Arayüzden (Web) gelen nesneyi byte dizisine çevirip STM32'ye gönderir
        public void SendCommand<T>(byte commandId, T payload) where T : struct
        {
            if (!_serialPort.IsOpen)
                throw new InvalidOperationException("Seri port kapalı, komut gönderilemez.");

            byte[] packet = MessageEncoder.Encode(commandId, payload);
            _serialPort.Write(packet, 0, packet.Length);
        }

        // STM32'den UART üzerinden byte geldiğinde çalışan donanım kesmesi (Interrupt)
        private void SerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            int bytesToRead = _serialPort.BytesToRead;
            byte[] buffer = new byte[bytesToRead];
            _serialPort.Read(buffer, 0, bytesToRead);

            // Gelen ham byte'ları havuzumuza atıyoruz
            _frameParser.AddBytes(buffer);

            // Havuzda tam bir paket oluşmuşsa çıkarıp işliyoruz. 
            // Aynı anda birden fazla paket geldiyse while döngüsü hepsini sırayla çözer.
            UartFrame? frame;
            while ((frame = _frameParser.TryParseFrame()) != null)
            {
                // Yakalanan hatasız paketi Web katmanındaki servislere fırlatıyoruz
                OnFrameReceived?.Invoke(frame);
            }
        }

        public void Dispose()
        {
            Disconnect();
            _serialPort.Dispose();
        }
    }
}
