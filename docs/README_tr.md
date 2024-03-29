# Deneyap Toprak Nemi Ölçer TL555Q Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap Toprak Nemi Ölçer TL555Q için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M38**, **mpv1.0**
- `MCU` TL555Q, STM8S003F3
- `Ağırlık`
- `Modul Boyutları`
- `I2C Adres` 0x0F, 0x4D, 0x67, 0x69

| Adres |  | 
| :---  | :---     |
| 0x0F | varsayılan adres |
| 0x4D | ADR1 kısa devre yapıldığındaki adres |
| 0x67 | ADR2 kısa devre yapıldığındaki adres |
| 0x69 | ADR1 ve ADR2 kısa devre yapıldıklarındaki adres |

## :closed_book:Dokümanlar
Deneyap Toprak Nemi Ölçer TL555Q

[TL555Q-datasheet](https://www.ti.com/lit/ds/symlink/tlc555.pdf?ts=1660038235186)

[Arduino IDE'de Kütüphane Nasıl İndirilir](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Toprak Nemi Ölçer TL555Q
Bu Arduino kütüphanesi Deneyap Toprak Nemi Ölçer algılayıcısının I2C çevre birimi ile kullanılmasını sağlar. Arduino ile uyumlu, I2C çevre birimine sahip herhangi bir geliştirme kartı ile bu kütüphaneyi projelerinizde kullanabilirsiniz.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.0.0 - ilk sürüm

1.0.1 - library.properties dosyasının güncellenmesi

1.0.2 - ürün bilgi yazılarının güncellenmesi

## :rocket:Donanım Bağlantıları
- Deneyap Toprak Nemi Ölçer ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir.

| Toprak Nemi Ölçer | Fonksiyon | Kart pinleri |
| :---      |   :---    | :---      |
| 3.3V      | Güç       | 3.3V      |
| GND       | Toprak    | GND       |
| SDA       | I2C Data  | SDA pini |
| SCL       | I2C Clock | SCL pini |
| SWIM      | Debug     | bağlantı yok |
| RES       | Debug     | bağlantı yok |
| AO        | Output    |herhangi Analog pini|
| SIG       | Signal    | |

## :bookmark_tabs:Lisans Bilgisi
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-toprak-nemi-olcer-arduino-library/blob/master/LICENSE) dosyasını inceleyin.