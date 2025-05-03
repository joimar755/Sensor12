#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

// LCD I2C
LiquidCrystal_PCF8574 lcd(0x3F);  // Cambia a 0x27 si tu pantalla lo necesita

// Botón
const int BTN1 = 18;

void setup() {
  Serial.begin(9600);

  // Inicializa LCD y botón
  Wire.begin(21, 22);  // SDA = 21, SCL = 22
  lcd.begin(16, 2);
  lcd.setBacklight(255);

  pinMode(BTN1, INPUT_PULLUP);

  // Mensaje inicial
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Presiona boton 1");
}

void loop() {
  if (digitalRead(BTN1) == LOW) {
    delay(50);
    if (digitalRead(BTN1) == LOW) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("inicio de seccion");
      lcd.setCursor(5, 1);
      lcd.print("Jesus");

      Serial.println("inicio de seccion Jesus");

      // Esperar que se suelte el botón
      while (digitalRead(BTN1) == LOW);
      delay(50);

      // Opcional: volver a mensaje inicial
      delay(2000); // espera 2 segundos antes de limpiar
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Presiona boton 1");
    }
  }
}
