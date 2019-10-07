char dato;
String readString;

void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void leer_Dato(){
  while(Serial.available()){
    delay(10);
    if (Serial.available() >0){
      dato=Serial.read();
      readString += dato;
    }
  }
}

void loop() {
  leer_Dato();
  
  if(readString.length() >0) {
    if(readString == "A") {
      Serial.println("APAGAR");
      digitalWrite(13, LOW);
    }
    else if (readString == "B"){
      Serial.println("ENCENDER");
      digitalWrite(13, HIGH);
    }
         readString = "";
  }
}



