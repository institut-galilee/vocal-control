int ledVerte = 10;
int ledBleue = 9;
int ledRouge= 8;
int message = 0; 
 
void setup() {
     pinMode(ledVerte, OUTPUT);
     pinMode(ledBleue, OUTPUT);
     pinMode(ledRouge, OUTPUT);
     
     Serial.begin(9600); // Baud par défault pour le module bluetooth
 }
 
void loop() {

      //On lit le message reçu du module bluetooth
     if(Serial.available() > 0){
     message = Serial.read();
     }
    
     //On allume la led verte 
     if (message == '1') {
     digitalWrite(ledVerte, HIGH);
     }
    
     //On éteint la led verte
     else if (message == '2') {
     digitalWrite(ledVerte, LOW);
    }
    
    //On allume la led bleue
    else if (message == '3') {
     digitalWrite(ledBleue, HIGH);
    }
    
    //On éteint la led bleue
    else if (message == '4') {
     digitalWrite(ledBleue, LOW);
    }
    
    //On allume la led rouge
    else if (message == '5') {
     digitalWrite(ledRouge, HIGH);
    }
    
    //On éteint la led rouge
    else if (message == '6') {
     digitalWrite(ledRouge, LOW);
    }
    
    //On allume toutes les leds
    else if (message == '7') {
     digitalWrite(ledVerte, HIGH);
     digitalWrite(ledBleue, HIGH);
     digitalWrite(ledRouge, HIGH);
    }
    
    //On éteint toutes les leds
    else if (message == '8') {
     digitalWrite(ledVerte, LOW);
     digitalWrite(ledBleue, LOW);
     digitalWrite(ledRouge, LOW);
    }
    
    //On fait clignoter les led
    else if (message == '9') {
    
     //On éteint d'abord toutes les leds
     digitalWrite(ledVerte, LOW);
     digitalWrite(ledBleue, LOW);
     digitalWrite(ledRouge, LOW);
    
     delay(100);
    
      //On allume la led si elle est éteinte, et l'éteint si elle est allumée tout en bloquant le programme par intervalle
      digitalWrite(ledVerte, !digitalRead(ledVerte) ); 
      delay(200);
      digitalWrite(ledBleue, !digitalRead(ledBleue) );
      delay(200); 
      digitalWrite(ledRouge, !digitalRead(ledRouge) ); 
      delay(200);      
     
}
}

