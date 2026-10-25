using SotmGroundControl.Application.Interfaces;
using SotmGroundControl.Infrastructure.Communication.Transports;
using SotmGroundControl.Web.BackgroundServices;
using SotmGroundControl.Web.Hubs;



var builder = WebApplication.CreateBuilder(args);

// 1. MVC (Arayüz) ve SignalR (Canlý Veri) servislerini ekliyoruz
builder.Services.AddControllersWithViews();
builder.Services.AddSignalR();

// 2. DONANIM VE ARKA PLAN SERVÝS KAYITLARI
// Seri portu uygulamada tek bir nesne olarak (Singleton) ayaða kaldýrýyoruz.
builder.Services.AddSingleton<ISerialCommunicationService, SerialPortManager>();

// Arka planda 7/24 çalýþacak olan dinleme servisini kaydediyoruz.
builder.Services.AddHostedService<TelemetryBackgroundService>();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}

app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();
app.UseAuthorization();

// 3. Ýletiþim Uç Noktalarýný (Endpoints) Belirliyoruz
app.MapHub<TelemetryHub>("/telemetryHub"); // SignalR baðlantý köprüsü
app.MapStaticAssets();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}")
    .WithStaticAssets();


app.Run();
