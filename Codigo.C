const int pinoSensor = A0;
const int pinoMotor = 2;     
const int pinoLED = 4;       
const int pinoBuzzer = 7;   

void setup() {
  pinMode(pinoMotor, OUTPUT);
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int leituraBruta = analogRead(pinoSensor);
  float voltagem = leituraBruta * (5.0 / 1023.0);
  float temperaturaC = (voltagem - 0.5) * 100.0;
  Serial.print("Temperatura: ");
  Serial.print(temperaturaC);
  Serial.println(" C");


  if (temperaturaC > 50.0) {
    digitalWrite(pinoMotor, HIGH);   
    digitalWrite(pinoLED, HIGH);
    tone(pinoBuzzer, 1000); 
  }  
  else if (temperaturaC >= 30.0) {
    digitalWrite(pinoMotor, HIGH);
    digitalWrite(pinoLED, LOW); 
    noTone(pinoBuzzer);
  }
  else {
    digitalWrite(pinoMotor, LOW);
    digitalWrite(pinoLED, LOW);  
    noTone(pinoBuzzer);  
  }

  delay(1000);
}
