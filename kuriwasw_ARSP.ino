#include <SoftwareSerial.h>
#include <Servo.h>
int rxPin = 10;//rxのピン番号
int txPin = 11;//txのピン番号
int ddPin = 5; //参考[1]のBRC
SoftwareSerial Roomba(rxPin, txPin);

int INPUT_passive = 4;  // タクトスイッチからの入力を4ピンに割り当て
int passive;
int INPUT_safe = 3;  // タクトスイッチからの入力を3ピンに割り当て
int safe;

const int pingPinA = 9;
const int pingPinB = 8;
const int pingPinC = 7;
const int pingPinD = 6;

unsigned long durationA;
int cm;
unsigned long durationB;
int cm1;
unsigned long durationC;
int cm2;
unsigned long durationD;
int cm3;

byte val=0;
//#define LED_PIN 13

const int DIN_PIN = 12;
const int LED_PIN = 13;

int value;

Servo servoa;
Servo servob;
Servo servoc;
Servo servod;

int magaru=0;

int modoru=0;

void wakeUp(void) {
  //起動
  digitalWrite(ddPin, HIGH);
  delay(100);
  digitalWrite(ddPin, LOW);

  delay(500);
  digitalWrite(ddPin, HIGH);
  delay(2000);
}

void startSafe() { //startmodeに移行
  Roomba.write(128); //start
  Roomba.write(131); //safe mode
  delay(100);//とりあえず入れる
  //Serial.begin(9600);
  Serial.println("startsafe");
}

void startPassive() { //passivemodeに移行
  Roomba.write(128); //start
  delay(100);
}

unsigned int hex_convert_to8_high(int a) {
  return (unsigned int)(a >> 8) & 0x00FF;
};

unsigned int hex_convert_to8_low(int a) {
  return a ^ (hex_convert_to8_high(a) << 8);
};

unsigned int hex_convert_to16(int a, int b) {
  return (unsigned int)(a << 8) | (int)(b);
};

void roomba_send_num(int num) { //numを二つの8bitに変換してルンバに送信
  Roomba.write(hex_convert_to8_high(num));
  Roomba.write(hex_convert_to8_low(num));

};

void roomba_drive(int right, int left) { //直進　左と右のタイヤの速度が引数
  Roomba.write(145);
  roomba_send_num(right); //Velocity right
  roomba_send_num(left); //Velocity left
  Serial.println("モーター動作中");
  delay(100);
  delay(10);
};

void roomba_drive_right(int right, int left) { //直進　左と右のタイヤの速度が引数
  Roomba.write(145);
  roomba_send_num(-right); //Velocity right
  roomba_send_num(left); //Velocity left
  Serial.println("モーター動作中");
  delay(100);
  delay(10);
};


void ultrasound1() {
  //pingPin
  //ピンをOUTPUTに設定（パルス送信のため）
  pinMode(pingPinA, OUTPUT);
  //LOWパルスを送信
  digitalWrite(pingPinA, LOW);
  delayMicroseconds(2);
  //HIGHパルスを送信
  digitalWrite(pingPinA, HIGH);
  //5uSパルスを送信してPingSensorを起動
  delayMicroseconds(5);
  digitalWrite(pingPinA, LOW);

  //入力パルスを読み取るためにデジタルピンをINPUTに変更（シグナルピンを入力に切り替え）
  pinMode(pingPinA, INPUT);

  //入力パルスの長さを測定
  durationA = pulseIn(pingPinA, HIGH);

  //パルスの長さを半分に分割
  durationA = durationA / 2;
  //cmに変換
  cm = int(durationA / 29);
  Serial.println("");
  Serial.println("前");
  Serial.print(cm);
  Serial.println("cm");
};

void ultrasound2() {
  //pingPin
  //ピンをOUTPUTに設定（パルス送信のため）
  pinMode(pingPinB, OUTPUT);
  //LOWパルスを送信
  digitalWrite(pingPinB, LOW);
  delayMicroseconds(2);
  //HIGHパルスを送信
  digitalWrite(pingPinB, HIGH);
  //5uSパルスを送信してPingSensorを起動
  delayMicroseconds(5);
  digitalWrite(pingPinB, LOW);

  //入力パルスを読み取るためにデジタルピンをINPUTに変更（シグナルピンを入力に切り替え）
  pinMode(pingPinB, INPUT);

  //入力パルスの長さを測定
  durationB = pulseIn(pingPinB, HIGH);

  //パルスの長さを半分に分割
  durationB = durationB / 2;
  //cmに変換
  cm1 = int(durationB / 29);
  Serial.println("");
  Serial.println("左");
  Serial.print(cm1);
  Serial.println("cm");
};

void ultrasound3() {
  //pingPin
  //ピンをOUTPUTに設定（パルス送信のため）
  pinMode(pingPinC, OUTPUT);
  //LOWパルスを送信
  digitalWrite(pingPinC, LOW);
  delayMicroseconds(2);
  //HIGHパルスを送信
  digitalWrite(pingPinC, HIGH);
  //5uSパルスを送信してPingSensorを起動
  delayMicroseconds(5);
  digitalWrite(pingPinC, LOW);

  //入力パルスを読み取るためにデジタルピンをINPUTに変更（シグナルピンを入力に切り替え）
  pinMode(pingPinC, INPUT);

  //入力パルスの長さを測定
  durationB = pulseIn(pingPinC, HIGH);

  //パルスの長さを半分に分割
  durationC = durationC / 2;
  //cmに変換
  cm2 = int(durationC / 29);
  Serial.println("");
  Serial.println("後");
  Serial.print(cm2);
  Serial.println("cm");
};

void ultrasound4() {
  //pingPin
  //ピンをOUTPUTに設定（パルス送信のため）
  pinMode(pingPinD, OUTPUT);
  //LOWパルスを送信
  digitalWrite(pingPinD, LOW);
  delayMicroseconds(2);
  //HIGHパルスを送信
  digitalWrite(pingPinD, HIGH);
  //5uSパルスを送信してPingSensorを起動
  delayMicroseconds(5);
  digitalWrite(pingPinD, LOW);

  //入力パルスを読み取るためにデジタルピンをINPUTに変更（シグナルピンを入力に切り替え）
  pinMode(pingPinD, INPUT);

  //入力パルスの長さを測定
  durationD = pulseIn(pingPinD, HIGH);

  //パルスの長さを半分に分割
  durationD = durationD / 2;
  //cmに変換
  cm3 = int(durationD / 29);
  Serial.println("");
  Serial.println("右");
  Serial.print(cm3);
  Serial.println("cm");
};




/*
void kaiten(){
  roomba_drive(100, -100); 
  delay(9000);
}
*/

void saabo_tukamu(){
  servoa.write(0);
  servob.write(90);
  servoc.write(0);
  servod.write(82);
  delay(500);
}

void saabo_hanasu(){
 servoa.write(180);
  servob.write(90);
  servoc.write(180);
  
  delay(500);
}


void genkan(){
  if(magaru==1){
    roomba_drive(0, 0);
    Serial.print('A');
    loop();
  }
  else{
    roomba_drive(100, 100);
    delay(4000);
    roomba_drive(-100, 100);
    delay(700);
    roomba_drive(205, 200);
    delay(20000);
    roomba_drive(100, -100);
    delay(2800);
    magaru=magaru+1;
  }
}

void modoritai(){
  if(modoru == 1){
    roomba_drive(0, 0);
  }
  else{
    roomba_drive(200, 210);
    delay(20000);
    roomba_drive(100, -100);
    delay(700);
    roomba_drive(100, 100);
    delay(1000);
    modoru = modoru + 1; 
  }
}

void setup() {
  pinMode(INPUT_passive, INPUT_PULLUP);  // タクトスイッチに繋いだピンを入力に設定
  pinMode(INPUT_safe, INPUT_PULLUP);  // タクトスイッチに繋いだピンを入力に設定
  Roomba.begin(115200);
  Roomba.write(5);//9600に変更
  Roomba.end();//一度きる
  Roomba.begin(9600);//19200でスタート
  Serial.println("roomba 9600 start");
  Serial.begin(19200);
  pinMode(LED_PIN, OUTPUT); 
  wakeUp(); //wake up Roomba
  startPassive();//start roomba in passive
  startSafe(); // start roomba in safe mode
  pinMode( DIN_PIN, INPUT_PULLUP );
  pinMode( LED_PIN, OUTPUT );
  servoa.attach(30);
  servob.attach(31);
  servoc.attach(32);
  servod.attach(33);
}



void loop() {
  value = digitalRead( DIN_PIN );

  //ultrasound1();
  //ultrasound2();
  //ultrasound3();
  //ultrasound4();

  if(Serial.available() > 0){ 
    val = Serial.read();
  }
  else if(val == 'a') {
    digitalWrite(LED_PIN, HIGH);
    genkan();
    //kaiten();
  }
  else if (val == 'b'){
    digitalWrite(LED_PIN, LOW);
    modoritai();
   
  }
  else if (val == 'c'){
    digitalWrite(LED_PIN, LOW);
  }
  else{
    roomba_drive(0, 0);
  }

}









