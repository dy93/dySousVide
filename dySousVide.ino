class SevenSeg {
public:
  SevenSeg(int one, int two, int three, int four, int five, int six, int seven, int eight, int nine, int ten, int eleven) :
     _one(one), _two(two), _three(three), _four(four), _five(five), _six(six), _seven(seven), _eight(eight), _nine(nine), _ten(ten), _eleven(eleven) {
    
  }

  void display(float num) {    
    if (num >= 100) {
      clearAll();
      digitalWrite(_six, 1);
      writeNum((int)num / 100);

      clearAll();
      digitalWrite(_three, 1);
      writeNum(((int)num % 100) / 10);

      clearAll();
      digitalWrite(_two, 1);
      writeNum(((int)num) % 10);
    } else if (num < 0) {
      num = -num; 
      clearAll();
      digitalWrite(_six, 1);
      digitalWrite(_seven, 0);

      clearAll();
      digitalWrite(_three, 1);
      writeNum((int)num / 10);

      clearAll();
      digitalWrite(_two, 1);
      writeNum((int)num % 10);
    } else {
      clearAll();
      digitalWrite(_six, 1);
      int n = (int)num / 10;
      writeNum(n);
      
      clearAll();
      digitalWrite(_three, 1);
      writeNum((int)num % 10);
      digitalWrite(_nine, 0);
      
      clearAll();
      digitalWrite(_two, 1);
      writeNum(((int)(num * 10)) % 10);
    }
  }
private:
  void clearAll() {
    digitalWrite(_one, 1);
    digitalWrite(_two, 0);
    digitalWrite(_three, 0);
    digitalWrite(_four, 1);
    digitalWrite(_five, 1);
    digitalWrite(_six, 0);
    digitalWrite(_seven, 1);
    digitalWrite(_eight, 1);
    digitalWrite(_nine, 1);
    digitalWrite(_ten, 1);
    digitalWrite(_eleven, 1);
  }
  void writeNum(int num) {
    switch (num) {
      case 0:
        digitalWrite(_one, 0);
        digitalWrite(_four, 0);
        digitalWrite(_five, 0);
        digitalWrite(_eight, 0);
        digitalWrite(_ten, 0);
        digitalWrite(_eleven, 0);
        break;
      case 1:
        digitalWrite(_one, 0);
        digitalWrite(_eight, 0);
        break;
      case 2:
        digitalWrite(_one, 0);
        digitalWrite(_five, 0);
        digitalWrite(_seven, 0);
        digitalWrite(_ten, 0);
        digitalWrite(_eleven, 0);
        break;
      case 3:
        digitalWrite(_one, 0);
        digitalWrite(_five, 0);
        digitalWrite(_seven, 0);
        digitalWrite(_eight, 0);
        digitalWrite(_ten, 0);
        break;
      case 4:
        digitalWrite(_one, 0);
        digitalWrite(_four, 0);
        digitalWrite(_seven, 0);
        digitalWrite(_eight, 0);
        break;
      case 5:
        digitalWrite(_four, 0);
        digitalWrite(_five, 0);
        digitalWrite(_seven, 0);
        digitalWrite(_eight, 0);
        digitalWrite(_ten, 0);
        break;
     case 6:
        digitalWrite(_four, 0);
        digitalWrite(_five, 0);
        digitalWrite(_seven, 0);
        digitalWrite(_eight, 0);
        digitalWrite(_ten, 0);
        digitalWrite(_eleven, 0);
        break;
      case 7:
        digitalWrite(_one, 0);
        digitalWrite(_four, 0);
        digitalWrite(_five, 0);
        digitalWrite(_eight, 0);
        break;
      case 8:
        digitalWrite(_one, 0);
        digitalWrite(_four, 0);
        digitalWrite(_five, 0);
        digitalWrite(_seven, 0);
        digitalWrite(_eight, 0);
        digitalWrite(_ten, 0);
        digitalWrite(_eleven, 0);
        break;
      case 9:
        digitalWrite(_one, 0);
        digitalWrite(_four, 0);
        digitalWrite(_five, 0);
        digitalWrite(_seven, 0);
        digitalWrite(_eight, 0);
        break;
    }
  }
  
private:
  int _one;
  int _two;
  int _three;
  int _four;
  int _five;
  int _six;
  int _seven;
  int _eight;
  int _nine;
  int _ten;
  int _eleven;
};

SevenSeg sevenSeg(2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13);
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
//  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  sevenSeg.display(-12.5);
}
