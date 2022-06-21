/*
 *   Deneyap Toprak Nemi Ölçer sensöründen Toprak Nemi Okuma No I2C örneği,
 *   
 *   Sensörden gelen toprak nemi değerleri seri monitöre yazdırılmaktadır.
 *   
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır. 
 *   Bu örnek I2C haberleşme protokolü kullanılmadan yazılmıştır.
 *   
 *   Bu örnek Deneyap Toprak Nemi Ölçer için oluşturulmuştur
 *      ------>  www.....com <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-toprak-nemi-olcer-arduino-library  <------ 
 *     
*/
#define AOUTPIN A0                            // Toprak Nemi kartındaki AO pininin A0 pinine baglanmalıdır

void setup() {
    Serial.begin(115200);                     // Seri monitör başlatılması
}

void loop() {
    uint16_t nemDeger = analogRead(AOUTPIN);  // Nem değeri okunması
    Serial.println(nemDeger);                 // Nem değeri seri monitöre yazılması
}
