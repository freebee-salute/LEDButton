const int buttonPin = D1;    // Button - auf D1, 3v auf S
const int redPin = D2;       // LED - auf GND, LED G auf D2
const int bluePin = D3;     // LED B auf D3
const int greenPin = D4;   // LED R auf D4 , beschriftung auf LED scheint falsch zu sein...
const int touchSensor = D5; // Touch Sensor
   
        
int zaehler = 0;            // Zähler initialisieren
int buttonStatus = 0;        // Status des Buttons initialisieren
int letzterButtonStatus = 0;    // Status des Buttons auf 0 setzen
int touchStatus = 0;
int letzterTouchStatus = 0;

void setup() {
  pinMode(buttonPin, INPUT);    // Button auf Input setzen
  pinMode(redPin, OUTPUT);      // Pins der LED auf Output setzen
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(115200);         // Geschwindigkeit festlegen, optional, notwendig um Serial.print auszulesen
  pinMode(touchSensor, INPUT);
}
void loop() {
 
  touchStatus = digitalRead(touchSensor); // Status des Touchsensors wird ausgelesen

 if (touchStatus != letzterTouchStatus) {  // wenn der Status des Sensors nicht mit dem gespeicherten Wert
    if (touchStatus == HIGH) {          // übereinstimmt, wird 1 hochgezählt
      zaehler++;
      Serial.println(zaehler);
    } else if (zaehler >= 4){           // wenn der Zähler bei 4 steht, wird er auf 0 zurückgesetzt
      zaehler = 0;
      } else {
    }
    delay(100);                          // kurze Pause, um falsches Auslesen zu vermeiden
 }
   letzterTouchStatus = touchStatus;       // neuen Touch Status speichern

  if (zaehler == 1) {                   // Begin der Schleife, wenn Zähler = 1 -> LED ist Rot
    digitalWrite(redPin, HIGH);         
    digitalWrite(bluePin, LOW);
    digitalWrite(greenPin, LOW);
  } else if (zaehler == 2) {            // Wenn Zähler = 2 -> LED ist Blau
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, HIGH);
    digitalWrite(greenPin, LOW);
  } else if (zaehler == 3){             // Wenn Zähler = 3 -> LED ist Grün
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(greenPin, HIGH);
    } else if (zaehler == 4) {          // Wenn Zähler = 4 -> LED ist aus
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(greenPin, LOW);  
      }

      buttonStatus = digitalRead(buttonPin);
      if (buttonStatus != letzterButtonStatus) {
        if (buttonStatus == HIGH) {
            Serial.println("Neue Nachricht: ");
            Serial.println(zaehler);
            }
        delay(50);
        }
  letzterButtonStatus = buttonStatus;
}
