int Motor1 = 13;
int Motor2 = 12;
int rainsensor = 7;
int stop1 = 0;
int stop2 = 0;
int stop3 = 0;
int stop4 = 0;
void setup() {
  pinMode(Motor1,OUTPUT);
  pinMode(Motor2,OUTPUT);
  pinMode(rainsensor,INPUT);
  digitalWrite(Motor1,LOW);
  digitalWrite(Motor2,LOW);
  Serial.begin(9600);
}

void loop() {
  int rain = digitalRead(rainsensor);
  int LDRval = analogRead(A0);
  delay(500);
  if(LDRval > 100 || rain == 1){  /*Terang dan Hujan maka motor menutup atap*/
    if(stop1==0){
    digitalWrite(Motor1,HIGH);
    delay(1000);
    digitalWrite(Motor1,LOW);
    stop1 = 1;
    stop2 = 0;
    stop3 = 0;
    stop4 = 0;
    }
  }
  else if(LDRval < 100 || rain == 0){   /*Gelap dan Tidak hujan maka motor membuka atap*/
    if(stop2 ==0 ){
    digitalWrite(Motor2,HIGH);
    delay(1000);
    digitalWrite(Motor2,LOW);
    stop2 = 1;
    stop1 = 0;
    stop3 = 0;
    stop4 = 0;
    } 
  }
  else if (LDRval > 100 || rain == 0){   /* Terang dan Tidak hujan maka motor membuka atap*/
    if(stop3==0){
    digitalWrite(Motor2,HIGH);
    delay(1000);
    digitalWrite(Motor2,LOW);
    stop3 = 1;
    stop1 = 0;
    stop2 = 0;
    stop4 = 0;
    }
  }
  else if (LDRval < 100 || rain == 1){   /*Gelap dan Hujan maka motor menutup atap*/
    if(stop4==0){
    digitalWrite(Motor1,HIGH);
    delay(1000);
    digitalWrite(Motor1,LOW);
    stop4 = 1;
    stop1 = 0;
    stop2 = 0;
    stop3 = 0;
    }  
  }
}
