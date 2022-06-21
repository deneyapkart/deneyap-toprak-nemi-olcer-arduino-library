/*
 *   Deneyap Toprak Nemi Ölçer sensöründen Toprak Nemi Okuma örneği,
 *   
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır. 
 *   Sensörden gelen toprak nemi değerleri seri monitöre yazdırılmaktadır.
 *   
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *   
 *   Bu örnek Deneyap Toprak Nemi Ölçer için oluşturulmuştur
 *      ------>  www.....com <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-5x7-led-matris-arduino-library  <------ 
 *     
*/
#include <Deneyap_ToprakNemiOlcer.h>                   // Deneyap_ToprakNemiOlcer.h kütüphanesi eklenmesi

SoilMoisture ToprakNemi;                               // SoilMoisture için class tanımlaması

void setup() {
    Serial.begin(115200);                              // Seri monitör başlatılması
    if (!ToprakNemi.begin(0x0F)) {                     // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");   // I2C bağlantısı başarısız olursa seri monitore yazdırılması
        while (1);
    }
}

void loop() {
    uint16_t nemDeger = ToprakNemi.ReadSoilMoisture(); // Nem değeri okunması
    Serial.print("Toprak Nemi Degeri: ");
    Serial.println(nemDeger);                          // Nem değeri seri monitöre yazılması
    delay(100);
}
