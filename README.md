# CSE102 - C Programming Homeworks

Bu repository, CSE102 C Programlama dersi ödevlerini içermektedir.

# CSE102 - C Programming Homeworks

Bu repository, CSE102 C Programlama dersi ödevlerini içermektedir.

## Ödevler

### **PA1**: Sınıflandırma Algoritması (Classification Algorithm)
İki sınıfın ortalama noktalarını hesaplayarak, yeni gelen noktaları bu sınıflara ayıran makine öğrenmesi algoritması.
- **Özellikler**:
  - 2D düzlemde iki sınıf için 10'ar nokta alır
  - Sınıfların ortalama noktalarını hesaplar
  - Ayırıcı doğru oluşturur
  - Yeni noktaları sınıflandırır ve mesafe hesaplar
- **Kullanılan Kavramlar**: Matematik fonksiyonları, ortalama hesabı, eğim hesabı, mesafe formülü

### **PA2**: N-gram Analizi (2-gram Counter)
Metin dosyasındaki 2-gram'ları (ardışık iki sayı) sayar ve frekanslarını hesaplar.
- **Özellikler**:
  - Dosyadan sayı çiftleri okur
  - Tekrarlayan 2-gram'ları tespit eder
  - Frekans sayımı yapar
  - Sonuçları dosyaya yazar
- **Kullanılan Kavramlar**: Dosya işlemleri, dizi manipülasyonu, fseek kullanımı

### **PA3**: Polinom Değerlendirici (Polynomial Evaluator)
Polinom ifadelerini okuyarak belirli değerler için hesaplar.
- **Özellikler**:
  - Polinom dosyasından ifadeleri okur
  - Değişken değerlerini dosyadan alır
  - ax^b formatındaki terimleri parse eder
  - String manipülasyonu ile polinom çözümü
- **Kullanılan Kavramlar**: String işleme, strtok, sscanf, math.h, dosya işlemleri

### **PA4**: Kelime Arama Oyunu (Word Search Puzzle)
2D karakter matrisinde kelimeleri yatay, dikey ve çapraz yönlerde arar.
- **Özellikler**:
  - Karakter matrisini dosyadan okur
  - Kelime listesini işler
  - Üç yönde (horizontal, vertical, diagonal) arama yapar
  - Bulunan kelimelerin pozisyonlarını rapor eder
- **Kullanılan Kavramlar**: 2D diziler, string karşılaştırma, fonksiyon tasarımı

### **PA5**: Beslenme Analizi (Nutrition Calculator)
Yemek tariflerini analiz ederek toplam kalori ve makro besin değerlerini hesaplar.
- **Özellikler**:
  - Recursive function kullanımı
  - Struct veri yapısı ile besin bilgileri
  - Kalori hesaplaması (karbonhidrat: 4kcal/g, protein: 4kcal/g, yağ: 9kcal/g)
  - Yüzdelik oranlar hesabı
- **Kullanılan Kavramlar**: Struct, recursive functions, string parsing, matematik işlemleri

### **PA6**: Dil Tanıma (Language Recognition)
Bi-gram frekans analizi ile metinlerin hangi dile ait olduğunu tahmin eder.
- **Özellikler**:
  - Bi-gram (iki karakter) frekans analizi
  - 5 farklı dil ile karşılaştırma
  - Benzerlik ölçümü (dissimilarity calculation)
  - İstatistiksel dil tanıma algoritması
- **Kullanılan Kavramlar**: 2D diziler, istatistik, dosya işlemleri, fabs() fonksiyonu

### **PA7**: Dijital Devre Simülatörü (Digital Circuit Simulator)
Mantık kapılarından oluşan dijital devreleri simüle eder.
- **Özellikler**:
  - Dinamik bellek yönetimi (malloc/free)
  - Linked data structures
  - AND, OR, NOT, FLIPFLOP kapıları
  - Recursive evaluation
  - Devre dosyası ve input dosyası işleme
- **Kullanılan Kavramlar**: Struct, pointer, malloc/free, recursive evaluation, switch-case

## Derleme

Her bir C dosyasını derlemek için:

```bash
gcc -o PA1 hasan_can_istekli_PA1.c -lm
gcc -o PA2 hasan_can_istekli_PA2.c -lm
gcc -o PA3 hasan_can_istekli_PA3.c -lm
gcc -o PA4 hasan_can_istekli_PA4.c -lm
gcc -o PA5 hasan_can_istekli_PA5.c -lm
gcc -o PA6 hasan_can_istekli_PA6.c -lm
gcc -o PA7 hasan_can_istekli_PA7.c -lm
```

## Dosya Yapısı

- **Kaynak Kodlar**:
  - `hasan_can_istekli_PA*.c` - C kaynak kod dosyaları
- **Dokümantasyon**:
  - `PA*.pdf` - Ödev talimatları ve açıklamaları
  - `README.md` - Bu dokümantasyon dosyası
- **Derlenmiş Dosyalar** (gitignore'da):
  - `PA*` - Derlenmiş çalıştırılabilir dosyalar

## Kullanılan C Programlama Konuları

### Temel Kavramlar
- **Değişkenler ve Veri Tipleri**: int, float, double, char
- **Diziler**: 1D ve 2D diziler, string manipülasyonu
- **Döngüler**: for, while, do-while
- **Koşullu İfadeler**: if-else, switch-case
- **Fonksiyonlar**: Parametre geçirme, return değerleri

### İleri Seviye Konular
- **Struct Yapıları**: Veri organizasyonu ve manipulation
- **Pointer Kullanımı**: Bellek adresleme ve referans geçirme
- **Dinamik Bellek Yönetimi**: malloc, free
- **Recursive Functions**: Kendini çağıran fonksiyonlar
- **Dosya İşlemleri**: fopen, fclose, fscanf, fprintf, fgets, fseek

### Kullanılan Kütüphaneler
- **stdio.h**: Standart input/output işlemleri
- **string.h**: String manipülasyon fonksiyonları
- **math.h**: Matematik fonksiyonları (pow, sqrt, fabs)
- **stdlib.h**: Dinamik bellek yönetimi ve utility fonksiyonları

## Notlar

- Tüm programlar matematik kütüphanesi (`-lm` flag) kullanmaktadır
- Dosyalar GCC derleyicisi ile test edilmiştir
- Programlar Linux/Unix sistemlerinde çalışacak şekilde tasarlanmıştır
- Her ödev farklı programlama kavramlarını ve problem çözme tekniklerini göstermektedir