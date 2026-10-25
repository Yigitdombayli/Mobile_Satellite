

using Microsoft.AspNetCore.SignalR;

namespace SotmGroundControl.Web.Hubs
{
    public class TelemetryHub : Hub
    {
        // İstemciden sunucuya doğrudan bir SignalR tetiklemesi gerekirse buraya metod eklenebilir.
        // Şimdilik sadece arka plandan veri fırlatacağımız için gövde boş kalabilir.
    }
}