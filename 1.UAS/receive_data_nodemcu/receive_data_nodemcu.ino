void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
void loop() {
  String data = "";

  while(Serial.available()>0)
  {
   data += char(Serial.read()); 
  }
  
  Serial.println(data);
  delay(800);
} 
