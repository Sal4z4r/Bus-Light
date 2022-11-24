#define BUZZER 13

const int Trigger = 6;   
const int Echo = 5;  
const int ledRojo = 8;
const int ledAmarillo = 10;
const int ledVerde = 12;
const float sonido = 34300.0; // Velocidad del sonido en cm/s
const float umbral1 = 30.0;
const float umbral2 = 20.0;
const float umbral3 = 10.0;


void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT); 
  pinMode(ledRojo, OUTPUT); 
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(Echo, INPUT);  
  pinMode(BUZZER, OUTPUT);
  digitalWrite(Trigger, LOW);
  digitalWrite(ledRojo , LOW);   
  digitalWrite(ledAmarillo , LOW); 
  digitalWrite(ledVerde , LOW); 

}

void loop()
{

  long tiempo; 
  long distancia; 

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          
  digitalWrite(Trigger, LOW);     
  
  tiempo = pulseIn(Echo, HIGH); 
  distancia = tiempo / 59;             
  
  Serial.print("Distancia: ");
  Serial.print(distancia);      
  Serial.print("cm");
  distancia = tiempo * 0.000001 * sonido / 2.0;
  Serial.println();
  if (distancia >= 30) 
  {
   digitalWrite(ledRojo, HIGH); 
   digitalWrite(ledAmarillo, LOW);   
   digitalWrite(ledVerde, LOW);  
   tone(BUZZER, 3000, 100);   
  }
  if (distancia >= 11 && distancia <= 29) 
  {
   digitalWrite(ledRojo, LOW);   
   digitalWrite(ledAmarillo, HIGH);   
   digitalWrite(ledVerde, LOW);   
   tone(BUZZER, 2500, 200);
  }
  if (distancia <= 10)
  {
   digitalWrite(ledRojo, LOW);   
   digitalWrite(ledAmarillo, LOW);   
   digitalWrite(ledVerde, HIGH);   
   tone(BUZZER, 6000, 600);
  }         
  delay(500);
}
