// Lembrando, na imagem desse projeto o sensor de umidade da terra foi substituido por um potênciometro.

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int umidade;

void setup()
{
  lcd.init();
  lcd.begin(16, 2);
  pinMode(13, OUTPUT);
}

void loop()
{
  lcd.setBacklight(HIGH);
  digitalWrite(13, LOW);
  lcd.setCursor(0, 0);
  umidade = analogRead(A0);
  umidade = map(umidade, 1023, 0, 0, 200);
  lcd.print("Umidade em:");
  lcd.print(umidade);
  lcd.print(" %");
  if(umidade < 20)
  {
       digitalWrite(13, HIGH);
  }
  delay(500);
  lcd.clear();
}
