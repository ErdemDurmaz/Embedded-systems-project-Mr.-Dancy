#include <Servo.h>
#include <Oscillator.h>
#include <US.h>
#include <Otto.h>
#include <EEPROM.h>
Otto Otto;
#define N_SERVOS 4
#define EEPROM_TRIM true  //Activate for calibration

#define TRIM_RR 0
#define TRIM_RL 40
#define TRIM_YR 4
#define TRIM_YL -7

#define PIN_RR 2
#define PIN_RL 3
#define PIN_YR 4
#define PIN_YL 5


 

int distance = 0;

#define INTERVALTIME 10.0

Oscillator servo[N_SERVOS];

void drunk (int tempo);
void kickLeft(int tempo);
void kickRight(int tempo);
void pasitos(int steps, int tempo);
void run(int steps, int T = 500);
void walk(int steps, int T = 1000);
void backyard(int steps, int T = 3000);
void moonWalkLeft(int steps, int T = 1000);
void moonWalkRight(int steps, int T = 1000);
void crusaito(int steps, int T = 1000);
void swing(int steps, int T = 1000);
void upDown(int steps, int tempo);
void flapping(int steps, int T = 1000);
void noGravity(int tempo);
void goingUp(int tempo);
void segunda_parte();
// TEMPO: 97 BPM
int t = 620;
double pause = 0;

void setup()
{
  Otto.init(PIN_YL, PIN_YR, PIN_RL, PIN_RR, true);

  servo[0].attach(PIN_RR);
  servo[1].attach(PIN_RL);
  servo[2].attach(PIN_YR);
  servo[3].attach(PIN_YL);

  servo[0].SetTrim(TRIM_RR);
  servo[1].SetTrim(TRIM_RL);
  servo[2].SetTrim(TRIM_YR);
  servo[3].SetTrim(TRIM_YL);


  for (int i = 0; i < 4; i++) servo[i].SetPosition(90);

  Serial.begin(9600);
  Otto.home();

}
String input;
void loop() {
  Otto.home();
  if (Serial.available()) {
    input = Serial.readString();
    Serial.println(input);
  }

  if (input == "1") {
    Otto.home();
    singleLadies();
  } else if (input == "2") {
    Otto.home();
    smooth();
  } else if (input == "3") {
    Otto.home();
    surprise();
  }

  input = "";
}

int oldPosition[] = {90, 90, 90, 90};

void primera_parte() {

  int move1[4] = {60, 120, 90, 90};
  int move2[4] = {90, 90, 90, 90};
  int move3[4] = {40, 140, 90, 90};

  for (int x = 0; x < 3; x++) {
    for (int i = 0; i < 3; i++) {
      lateral_fuerte(1, t / 2);
      lateral_fuerte(0, t / 4);
      lateral_fuerte(1, t / 4);
      delay(t);
    }

    pause = millis();
    for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
    moveNServos(t * 0.4, move1);
    moveNServos(t * 0.4, move2);
    while (millis() < (pause + t * 2));
  }

  for (int i = 0; i < 2; i++) {
    lateral_fuerte(1, t / 2);
    lateral_fuerte(0, t / 4);
    lateral_fuerte(1, t / 4);
    delay(t);
  }

  pause = millis();
  for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
  crusaito(1, t * 1.4);
  moveNServos(t * 1, move3);
  for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
  while (millis() < (pause + t * 4));
}

void goingUp(int tempo) {

  pause = millis();
  for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
  delay(tempo);
  servo[0].SetPosition(80);
  servo[1].SetPosition(100);
  delay(tempo);
  servo[0].SetPosition(70);
  servo[1].SetPosition(110);
  delay(tempo);
  servo[0].SetPosition(60);
  servo[1].SetPosition(120);
  delay(tempo);
  servo[0].SetPosition(50);
  servo[1].SetPosition(130);
  delay(tempo);
  servo[0].SetPosition(40);
  servo[1].SetPosition(140);
  delay(tempo);
  servo[0].SetPosition(30);
  servo[1].SetPosition(150);
  delay(tempo);
  servo[0].SetPosition(20);
  servo[1].SetPosition(160);
  delay(tempo);

  while (millis() < pause + 8 * t);

}

void segunda_parte() {

  int move1[4] = {90, 90, 80, 100};
  int move2[4] = {90, 90, 100, 80};
  int move3[4] = {90, 90, 80, 100};
  int move4[4] = {90, 90, 100, 80};

  int move5[4] = {40, 140, 80, 100};
  int move6[4] = {40, 140, 100, 80};
  int move7[4] = {90, 90, 80, 100};
  int move8[4] = {90, 90, 100, 80};

  int move9[4] = {40, 140, 80, 100};
  int move10[4] = {40, 140, 100, 80};
  int move11[4] = {90, 90, 80, 100};
  int move12[4] = {90, 90, 100, 80};

  for (int x = 0; x < 7; x++) {
    for (int i = 0; i < 3; i++) {
      pause = millis();
      moveNServos(t * 0.15, move1);
      moveNServos(t * 0.15, move2);
      moveNServos(t * 0.15, move3);
      moveNServos(t * 0.15, move4);
      while (millis() < (pause + t));
    }
    pause = millis();
    moveNServos(t * 0.15, move5);
    moveNServos(t * 0.15, move6);
    moveNServos(t * 0.15, move7);
    moveNServos(t * 0.15, move8);
    while (millis() < (pause + t));
  }

  for (int i = 0; i < 3; i++) {
    pause = millis();
    moveNServos(t * 0.15, move9);
    moveNServos(t * 0.15, move10);
    moveNServos(t * 0.15, move11);
    moveNServos(t * 0.15, move12);
    while (millis() < (pause + t));
  }
}

void smooth() {
  primera_parte();
  segunda_parte();
  moonWalkLeft(4, t * 2);
  moonWalkRight(4, t * 2);
  moonWalkLeft(4, t * 2);
  moonWalkRight(4, t * 2);
  primera_parte();
  crusaito(1, t * 8);
  crusaito(1, t * 7);

  for (int i = 0; i < 16; i++) {
    flapping(1, t / 4);
    delay(3 * t / 4);
  }

  moonWalkRight(4, t * 2);
  moonWalkLeft(4, t * 2);
  moonWalkRight(4, t * 2);
  moonWalkLeft(4, t * 2);

  drunk(t * 4);
  drunk(t * 4);
  drunk(t * 4);
  drunk(t * 4);
  kickLeft(t);
  kickRight(t);
  drunk(t * 8);
  drunk(t * 4);
  drunk(t / 2);
  delay(t * 4);

  drunk(t / 2);

  delay(t * 4);
  walk(2, t * 2);
  backyard(2, t * 2);
  goingUp(t * 2);
  goingUp(t * 1);
  noGravity(t * 2);
  crusaito(1, t * 2);
  crusaito(1, t * 8);
  crusaito(1, t * 2);
  crusaito(1, t * 8);
  crusaito(1, t * 2);
  crusaito(1, t * 3);

  delay(t);
  primera_parte();
  for (int i = 0; i < 32; i++) {
    flapping(1, t / 2);
    delay(t / 2);
  }

  for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
}

void noGravity(int tempo) {

  int move1[4] = {120, 140, 90, 90};
  int move2[4] = {140, 140, 90, 90};
  int move3[4] = {120, 140, 90, 90};
  int move4[4] = {90, 90, 90, 90};


  for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
  for (int i = 0; i < N_SERVOS; i++) oldPosition[i] = 90;
  moveNServos(tempo * 2, move1);
  moveNServos(tempo * 2, move2);
  delay(tempo * 2);
  moveNServos(tempo * 2, move3);
  moveNServos(tempo * 2, move4);



}

void singleLadies() {
  pasitos(8, t * 2);
  crusaito(1, t);
  patada(t);
  delay(t);
  twist(2, t);
  twist(3, t / 2);
  upDown(1, t * 2);
  patada(t * 2);
  drunk(t * 2);
  flapping(1, t * 2);
  walk(2, t);
  walk(1, t * 2);
  backyard(2, t);
  patada(t * 2);
  flapping(1, t * 2);
  patada(t * 2);
  twist(8, t / 2);
  moonWalkLeft(2, t);
  crusaito(1, t * 2);

  for (int i = 0; i < 2 ; i++) {
    lateral_fuerte(0, t);
    lateral_fuerte(1, t);
    upDown(1, t * 2);
  }

  saludo(1, t * 2);
  saludo(1, t);
  delay(t);
  swing(3, t);
  for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
  delay(t);

  lateral_fuerte(0, t);
  lateral_fuerte(1, t);
  lateral_fuerte(0, t / 2);
  lateral_fuerte(1, t / 2);
  lateral_fuerte(0, t / 2);
  delay(t / 2);
  lateral_fuerte(0, t);
  lateral_fuerte(1, t);
  lateral_fuerte(0, t / 2);
  lateral_fuerte(1, t / 2);
  delay(t);

  pasitos(1, t * 2);
  pasitos(1, t);
  delay(t / 2);
  pasitos(1, t * 2);
  pasitos(1, t);
  delay(t / 2);

  crusaito(2, t);
  crusaito(1, t * 2);
  crusaito(2, t);
  crusaito(1, t * 2);
  crusaito(2, t);
  crusaito(1, t * 2);

  upDown(2, t);
  crusaito(1, t * 2);
  for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
  delay(t / 2);
  pasitos(2, t * 2);
  pasitos(2, t);
  flapping(1, t * 2);
  upDown(2, t);
  upDown(1, t * 2);

  for (int i = 0; i < 4; i++) {
    pasitos(1, t);
    delay(t);
  }
  reverencia1(1, t * 4);
  reverencia2(1, t * 4);
  upDown(1, t);
  run(2, t / 2);
  patada(t * 2);

  lateral_fuerte(0, t);
  lateral_fuerte(1, t);
  upDown(2, t);
  lateral_fuerte(0, t);
  lateral_fuerte(1, t);
  upDown(2, t);
  pasitos(4, t);
  lateral_fuerte(0, t);
  lateral_fuerte(1, t);
  upDown(2, t);

  patada(t * 2);
  pasitos(2, t);
  patada(t * 2);
  pasitos(2, t);
  swing(2, t * 2);
  pasitos(4, t);

  for (int i = 0; i < 4; i++) {
    lateral_fuerte(0, t);
    lateral_fuerte(1, t);
    lateral_fuerte(0, t / 2);
    lateral_fuerte(1, t / 2);
    lateral_fuerte(0, t / 2);
    delay(t / 2);
  }

  pasitos(6, t);
  delay(t);
  pasitos(1, t);
  delay(t / 2);
  pasitos(3, t);
  delay(t / 2);
  swing(4, t);

  twist(2, t / 2);
  delay(t / 2);
  twist(2, t / 2);
  delay(t / 2);

  drunk(t * 2);
  drunk(t / 2);
  drunk(t * 2);
  delay(t / 2);
  walk(1, t);
  backyard(1, t);

  servo[0].SetPosition(110);
  servo[1].SetPosition(130);
  delay(t);

  crusaito(3, t);
  crusaito(1, 2 * t);
  upDown(1, t * 2);
  upDown(2, t / 2);

  kickLeft(t / 2);
  kickRight(t / 2);
  moonWalkLeft(1, t * 2);
  moonWalkLeft(2, t);
  moonWalkRight(1, t * 2);
  moonWalkRight(2, t);

  walk(4, t);
  backyard(4, t);

  lateral_fuerte(0, t);
  lateral_fuerte(0, t);
  lateral_fuerte(1, t);
  lateral_fuerte(1, t);
  walk(2, t);
  backyard(2, t);

  pasitos(6, t * 2);
  swing(1, t);
  upDown(1, t);
  delay(t);
  upDown(6, t);
  delay(t);

  for (int i = 0; i < 4; i++) {
    lateral_fuerte(0, t);
    lateral_fuerte(1, t);
  }

  delay(t);
  for (int i = 0; i < 7; i++) {
    pasitos(2, t);
    swing(2, t);
  }

  pasitos(1, t);
  crusaito(1, t * 2);
  upDown(1, t);

  delay(2000);
}

void oscillate(int A[N_SERVOS], int O[N_SERVOS], int T, double phase_diff[N_SERVOS]) {
  for (int i = 0; i < 4; i++) {
    servo[i].SetO(O[i]);
    servo[i].SetA(A[i]);
    servo[i].SetT(T);
    servo[i].SetPh(phase_diff[i]);
  }
  double ref = millis();
  for (double x = ref; x < T + ref; x = millis()) {
    for (int i = 0; i < 4; i++) {
      servo[i].refresh();
    }
  }
}

unsigned long final_time;
unsigned long interval_time;
int oneTime;
int iteration;
float increment[N_SERVOS];

void moveNServos(int time, int  newPosition[]) {
  for (int i = 0; i < N_SERVOS; i++)  increment[i] = ((newPosition[i]) - oldPosition[i]) / (time / INTERVALTIME);

  final_time =  millis() + time;

  iteration = 1;
  while (millis() < final_time) { //Javi del futuro cambia esto
    interval_time = millis() + INTERVALTIME;

    oneTime = 0;
    while (millis() < interval_time) {
      if (oneTime < 1) {
        for (int i = 0; i < N_SERVOS; i++) {
          servo[i].SetPosition(oldPosition[i] + (iteration * increment[i]));
        }
        iteration++;
        oneTime++;
      }
    }
  }

  for (int i = 0; i < N_SERVOS; i++) {
    oldPosition[i] = newPosition[i];
  }
}




void pasitos(int steps, int tempo) {
  int move1[4] = {90, 120, 60, 60};
  int move2[4] = {90, 90, 90, 90};
  int move3[4] = {60, 90, 120, 120};
  int move4[4] = {90, 90, 90, 90};

  for (int i = 0; i < steps; i++) {
    pause = millis();
    moveNServos(tempo * 0.25, move1);
    moveNServos(tempo * 0.25, move2);
    moveNServos(tempo * 0.25, move3);
    moveNServos(tempo * 0.25, move4);
    while (millis() < (pause + t));
  }
}

void patada (int tempo) {
  for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
  servo[0].SetPosition(115);
  servo[1].SetPosition(120);
  delay(tempo / 4);
  servo[0].SetPosition(115);
  servo[1].SetPosition(70);
  delay(tempo / 4);
  servo[0].SetPosition(100);
  servo[1].SetPosition(80);
  delay(tempo / 4);
  servo[0].SetPosition(90);
  servo[1].SetPosition(90);
  delay(tempo / 4);
}

void twist(int steps, int tempo) {
  int move1[4] = {90, 90, 50, 130};
  int move2[4] = {90, 90, 90, 90};


  for (int x = 0; x < steps; x++) {
    pause = millis();
    moveNServos(tempo * 0.1, move1);
    moveNServos(tempo * 0.1, move2);
    while (millis() < (pause + tempo));
  }
}

void reverencia1 (int steps, int tempo) {
  int move1[4] = {130, 50, 90, 90};
  int move2[4] = {90, 90, 90, 90};

  for (int x = 0; x < steps; x++) {
    pause = millis();
    for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
    moveNServos(tempo * 0.3, move1);
    delay(tempo * 0.2);
    moveNServos(tempo * 0.3, move2);
    while (millis() < (pause + tempo));
  }
}

void reverencia2 (int steps, int tempo) {
  int move1[4] = {130, 50, 90, 90};
  int move2[4] = {130, 50, 60, 120};
  int move3[4] = {90, 90, 90, 90};


  for (int x = 0; x < steps; x++) {
    pause = millis();
    for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
    delay(tempo * 0.2);
    moveNServos(tempo * 0.05, move1);
    moveNServos(tempo * 0.05, move2);
    moveNServos(tempo * 0.05, move1);
    moveNServos(tempo * 0.05, move2);
    delay(tempo * 0.2);
    moveNServos(tempo * 0.1, move3);
    while (millis() < (pause + tempo));
  }
}

void saludo(int steps, int tempo) {
  int move1[4] = {60, 60, 90, 90};
  int move2[4] = {120, 60, 90, 90};

  for (int x = 0; x < steps; x++) {
    pause = millis();
    for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
    moveNServos(tempo * 0.25, move1);
    moveNServos(tempo * 0.25, move2);
    moveNServos(tempo * 0.25, move1);
    moveNServos(tempo * 0.25, move2);
    while (millis() < (pause + tempo));
  }
}

void upDown(int steps, int tempo) {
  int move1[4] = {50, 130, 90, 90};
  int move2[4] = {90, 90, 90, 90};

  for (int x = 0; x < steps; x++) {
    pause = millis();
    moveNServos(tempo * 0.2, move1);
    delay(tempo * 0.4);
    moveNServos(tempo * 0.2, move2);
    while (millis() < (pause + tempo));
  }
}

void lateral_fuerte(boolean side, int tempo) {

  for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
  if (side) servo[0].SetPosition(40);
  else servo[1].SetPosition(140);
  delay(tempo / 2);
  servo[0].SetPosition(90);
  servo[1].SetPosition(90);
  delay(tempo / 2);

}

void run(int steps, int T) {
  int A[4] = {10, 10, 10, 10};
  int O[4] = {0, 0, 0, 0};
  double phase_diff[4] = {DEG2RAD(0), DEG2RAD(0), DEG2RAD(90), DEG2RAD(90)};

  for (int i = 0; i < steps; i++)oscillate(A, O, T, phase_diff);
}

void drunk (int tempo) {

  pause = millis();

  int move1[] = {60, 70, 90, 90};
  int move2[] = {110, 120, 90, 90};
  int move3[] = {60, 70, 90, 90};
  int move4[] = {110, 120, 90, 90};
  int move5[] = {90, 90, 90, 90};

  moveNServos(tempo * 0.235, move1);
  moveNServos(tempo * 0.235, move2);
  moveNServos(tempo * 0.235, move3);
  moveNServos(tempo * 0.235, move4);
  moveNServos(tempo * 0.06, move5);
  while (millis() < (pause + tempo));

}

void kickLeft(int tempo) {
  for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
  delay(tempo);
  servo[0].SetPosition(50); 
  servo[1].SetPosition(60); 
  delay(tempo);
  servo[0].SetPosition(80); 
  servo[1].SetPosition(60); 
  delay(tempo / 4);
  servo[0].SetPosition(40); 
  servo[1].SetPosition(60); 
  delay(tempo / 4);
  servo[0].SetPosition(80); 
  servo[1].SetPosition(60); 
  delay(tempo / 4);
  servo[0].SetPosition(40); 
  servo[1].SetPosition(60); 
  delay(tempo / 4);
  servo[0].SetPosition(80); 
  servo[1].SetPosition(60); 
  delay(tempo);
}

void kickRight(int tempo) {
  for (int i = 0; i < 4; i++) servo[i].SetPosition(90);
  delay(tempo);
  servo[0].SetPosition(120); //pie derecho
  servo[1].SetPosition(130); //pie izquiero
  delay(tempo);
  servo[0].SetPosition(120); //pie derecho
  servo[1].SetPosition(100); //pie izquiero
  delay(tempo / 4);
  servo[0].SetPosition(120); //pie derecho
  servo[1].SetPosition(140); //pie izquiero
  delay(tempo / 4);
  servo[0].SetPosition(120); //pie derecho
  servo[1].SetPosition(80); //pie izquiero
  delay(tempo / 4);
  servo[0].SetPosition(120); //pie derecho
  servo[1].SetPosition(140); //pie izquiero
  delay(tempo / 4);
  servo[0].SetPosition(120); //pie derecho
  servo[1].SetPosition(100); //pie izquiero
  delay(tempo);
}

void walk(int steps, int T) {
  int A[4] = {15, 15, 30, 30};
  int O[4] = {0, 0, 0, 0};
  double phase_diff[4] = {DEG2RAD(0), DEG2RAD(0), DEG2RAD(90), DEG2RAD(90)};

  for (int i = 0; i < steps; i++)oscillate(A, O, T, phase_diff);
}

void backyard(int steps, int T) {
  int A[4] = {15, 15, 30, 30};
  int O[4] = {0, 0, 0, 0};
  double phase_diff[4] = {DEG2RAD(0), DEG2RAD(0), DEG2RAD(-90), DEG2RAD(-90)};

  for (int i = 0; i < steps; i++)oscillate(A, O, T, phase_diff);
}

void moonWalkRight(int steps, int T) {
  int A[4] = {25, 25, 0, 0};
  int O[4] = { -15 , 15, 0, 0};
  double phase_diff[4] = {DEG2RAD(0), DEG2RAD(180 + 120), DEG2RAD(90), DEG2RAD(90)};

  for (int i = 0; i < steps; i++)oscillate(A, O, T, phase_diff);
}

void moonWalkLeft(int steps, int T) {
  int A[4] = {25, 25, 0, 0};
  int O[4] = { -15, 15, 0, 0};
  double phase_diff[4] = {DEG2RAD(0), DEG2RAD(180 - 120), DEG2RAD(90), DEG2RAD(90)};

  for (int i = 0; i < steps; i++)oscillate(A, O, T, phase_diff);
}

void crusaito(int steps, int T) {
  int A[4] = {25, 25, 30, 30};
  int O[4] = { - 15, 15, 0, 0};
  double phase_diff[4] = {DEG2RAD(0), DEG2RAD(180 + 120), DEG2RAD(90), DEG2RAD(90)};

  for (int i = 0; i < steps; i++)oscillate(A, O, T, phase_diff);
}

void swing(int steps, int T) {
  int A[4] = {25, 25, 0, 0};
  int O[4] = { -15, 15, 0, 0};
  double phase_diff[4] = {DEG2RAD(0), DEG2RAD(0), DEG2RAD(90), DEG2RAD(90)};

  for (int i = 0; i < steps; i++)oscillate(A, O, T, phase_diff);
}

void flapping(int steps, int T) {
  int A[4] = {15, 15, 8, 8};
  int O[4] = { -A[0], A[1], 0, 0};
  double phase_diff[4] = {DEG2RAD(0), DEG2RAD(180), DEG2RAD(90), DEG2RAD(-90)};

  for (int i = 0; i < steps; i++)oscillate(A, O, T, phase_diff);
}

void surprise() {
  
}
