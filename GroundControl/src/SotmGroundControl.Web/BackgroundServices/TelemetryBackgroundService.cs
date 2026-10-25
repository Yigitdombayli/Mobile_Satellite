using Microsoft.AspNetCore.SignalR;
using Microsoft.Extensions.Hosting;
using SotmGroundControl.Application.Interfaces;
using SotmGroundControl.Core.Enums;
using SotmGroundControl.Core.Models;
using SotmGroundControl.Protocol.Codec;
using SotmGroundControl.Protocol.Messages;
using SotmGroundControl.Web.Hubs;
using System;
using System.ComponentModel.Design;
using System.Threading;
using System.Threading.Tasks;





namespace SotmGroundControl.Web.BackgroundServices
{
    public class TelemetryBackgroundService : BackgroundService
    {
        private readonly ISerialCommunicationService _serialService;
        private readonly IHubContext<TelemetryHub> _hubContext;

        // Dependency Injection ile gerekli servisleri alıyoruz
        public TelemetryBackgroundService(
            ISerialCommunicationService serialService,
            IHubContext<TelemetryHub> hubContext)
        {
            _serialService = serialService;
            _hubContext = hubContext;
        }

        protected override async Task ExecuteAsync(CancellationToken stoppingToken)
        {
            // 1. Uygulama başlarken seri portu açıyoruz. (COM port adını kendi cihazına göre değiştir)
            try
            {
                _serialService.OnFrameReceived += async (frame) =>
                {
                    await ProcessReceivedFrameAsync(frame);
                };
                _serialService.Connect("COM4", 9600);
                Console.WriteLine("Seri port başarıyla açıldı ve dinleniyor...");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Seri port açılamadı: {ex.Message}");
            }

            // 2. Hatasız bir paket yakalandığında tetiklenen olayı (Event) dinliyoruz
          /*  _serialService.OnFrameReceived += async (frame) =>
            {
                await ProcessReceivedFrameAsync(frame);
            };
          */
            // 3. Servis kapanana kadar arka planda açık tutuyoruz
            while (!stoppingToken.IsCancellationRequested)
            {
                await Task.Delay(1000, stoppingToken);
            }

            // 4. Uygulama kapatıldığında portu güvenli bir şekilde serbest bırakıyoruz
            _serialService.Disconnect();
        }

        private async Task ProcessReceivedFrameAsync(UartFrame frame)
        {
            try
            {
                if (frame.CommandId == (byte)CommandId.ResTelemetry)
                {
                    var telemetryData = MessageDecoder.DecodePayload<TelemetryData>(frame.Payload);
                    Console.WriteLine($"[TELEMETRI] Roll={telemetryData.CurrentRoll:F2} Pitch={telemetryData.CurrentPitch:F2}");
                    await _hubContext.Clients.All.SendAsync("ReceiveTelemetry", telemetryData);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"[HATA] Frame işlenemedi: {ex.Message}");
            }
        }

    }
}
