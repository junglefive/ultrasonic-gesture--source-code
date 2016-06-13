const int TrigPin1 = 2;//SR04-1信号发射
const int EchoPin1 = 3;//SR04-1信号接收
const int TrigPin2 = 4;//SR04-2信号发射
const int EchoPin2 = 5;//SR04-2信号接收
int distance1;       //SR04-1测得距离
int distance2;       //SR04-2测得距离
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);       //设置串口波特率
  pinMode(TrigPin1, OUTPUT); //关联引脚
  pinMode(EchoPin1, INPUT); 
  pinMode(TrigPin2, OUTPUT); 
  pinMode(EchoPin2, INPUT); 
}

void loop() {
// put your main code here, to run repeatedly:
distance1 = 0;
distance2 = 0;
 delay(20);
digitalWrite(TrigPin1, LOW); 
delayMicroseconds(2); 
digitalWrite(TrigPin1, HIGH); 
delayMicroseconds(12); 
digitalWrite(TrigPin1, LOW); 

distance1 = pulseIn(EchoPin1, HIGH) / 58.0; // cm

delay(20);  
digitalWrite(TrigPin2, LOW); 
delayMicroseconds(2); 
digitalWrite(TrigPin2, HIGH); 
delayMicroseconds(12); 
digitalWrite(TrigPin2, LOW);

distance2 = pulseIn(EchoPin2, HIGH)/ 58.0; //cm

//if(distance1>30){distance1=30;}
//if(distance2>30){distance2=30;}

if(1 < distance1 && 1<distance2 )
{
    Serial.println(10000+distance2); //----X1----left-----//
    Serial.println(20000+distance1); //----X2----right------//
}
else
{
//   Serial.println(10060);
  }
}

