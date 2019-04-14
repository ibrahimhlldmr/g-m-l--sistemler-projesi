#include <LiquidCrystal.h> //LCD kütüphanesini kodumuza dahil ediyoruz

#define s0 8 //Bağladığımız pinlere göre tanımlamalarımızı yapıyoruz
#define s1 9
#define s2 10
#define s3 11
#define sensorOut 12

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);//LCD pinlerini tanımlıyoruz
int K, Y, M = 0; //3 ana renk için değişken tanımlıyoruz

void setup() {

  lcd.begin(16,2);
  pinMode(s0, OUTPUT);//S0, S1, S2 ve S3 pinlerini OUTPUT olarak tanımlıyoruz
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(sensorOut, INPUT);//OUT pinini INPUT olarak tanımlıyoruz

  digitalWrite(s1,LOW);  //Frekans ölçeğimizi %20 olarak tanımlıyoruz
  digitalWrite(s0,HIGH);  
  Serial.begin(9600);

}

void loop() {
  
  lcd.print("K=");
  digitalWrite(s2, LOW); //Kırmızıyı filtrele
  digitalWrite(s3, LOW);
  K = pulseIn(sensorOut, LOW); //OUT pini üzerindeki LOW süresini okur
  //K=map(K,33,270,0,255); 
  Serial.print("Kırmızı= ");
  Serial.print(K); //Kırmızı için aldığımız değeri serial monitöre yazdır
  Serial.print("  ");
  lcd.print(K); //Kırmızı için aldığımız değeri LCD ekrana yazdır
  lcd.print("  ");
  lcd.setCursor(7, 0); //İmleci 7. sütuna al
  delay(50); //50 milisaniye bekle
 
  lcd.print("Y=");
  digitalWrite(s2, HIGH); //Yeşili filtrele
  digitalWrite(s3, HIGH);
  Y = pulseIn(sensorOut, LOW); //OUT pini üzerindeki LOW süresini okur
   //Y=map(Y,46,374,0,255);
  Serial.print("Yeşil= ");
  Serial.print(Y); //Yeşil için aldığımız değeri serial monitöre yazdır
  Serial.print("   ");
  lcd.print(Y); //Yeşil için aldığımız değeri LCD ekrana yazdır
  delay(50);

  lcd.setCursor(4, 1); //İmleci 2. satır 4. sütuna taşı
  lcd.print("M=");
  digitalWrite(s2, LOW); //Maviyi filtrele
  digitalWrite(s3, HIGH);
  M = pulseIn(sensorOut, LOW); //OUT pini üzerindeki LOW süresini okur
   //M=map(M,55,435,0,255);
  Serial.print("Mavi= "); 
  Serial.print(M); //Mavi için aldığımız değeri serial monitöre yazdır
  Serial.println();
  lcd.print(M); //Mavi için aldığımız değeri LCD ekrana yazdır
  lcd.setCursor(0, 0);
  delay(1000); //1000 milisaniye bekle
  //Renk değerlerini 1 saniye boyunca ekranda göreceğiz
  
  lcd.clear(); //Ekranı temizle
  delay(150); //150 milisaniye bekle


  lcd.setCursor(1,0); //İmleci 1. sütuna al
  lcd.print("Algilanan Renk");
  lcd.setCursor(2,1); //İmleci 2. satır 2. sütuna al
  //Kalibrasyon bölümünde elde ettiğimiz değerleri bu kısımda kullanacağız
  
  if(K<70 && M<70 && Y<70) //Eğer tüm renklerin yoğunluğu yüksekse: Beyaz
  {
  Serial.print("Renk = Beyaz   ");
  lcd.print("Beyaz");  
  }
  else if(K<100 && M>K && Y<M && abs(K-Y)<50)
  //Kırmızı yoğunluğu yüksek ve yeşille arasındaki değer 20'den azsa: Sarı
  {
  Serial.print("Renk = Sarı   ");
  lcd.print("Sari");
  }
  else if(K<100 && M<Y && abs(M-K)<40)
  //Kırmızı yoğunluğu yüksek ve mavi ile arasındaki değer 20'den azsa: Magenta
  {
  Serial.print("Renk = Magenta   ");
  lcd.print("Magenta");
  }
  else if(Y<130 && Y<M && Y<K)
  //Yeşil yoğunluğu belli bir seviyenin üstünde ve kırmızı-maviden daha yoğunsa: Yeşil
  {
  Serial.print("Renk = Yeşil   ");
  lcd.print("Yesil");
  }
  else if(M<100 && M<Y && M<K) //Mavi yoğunluğu belli bir seviyenin üstünde ve yeşil-kırmızıdan daha yoğunsa: Mavi
  {
  Serial.print("Renk = Mavi   ");
  lcd.print("Mavi");
  }
  else if(K<100 && K<Y && K<M)
  //Kırmızı yoğunluğu belli bir seviyenin üstünde ve yeşil-maviden daha yoğunsa: Kırmızı
  {
  Serial.print("Renk = Kırmızı   ");
  lcd.print("Kirmizi");
  }
  
  
  else if(K<30 && K<Y && K<M)
  {
  Serial.print("Renk = Mavi   ");
  lcd.print("Mavi");
  }
  
  else
  {
  Serial.print("Renk algılanamadı   ");//Belirlediğimiz kıstaslara uymayan diğer renkler
  lcd.print("---");
  }
  
  Serial.println(); //Serial monitörde bir satır aşağı geç
  delay(1000);//1000 milisaniye bekle
  lcd.clear();//LCD ekranı temizle
  delay(150);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
}
