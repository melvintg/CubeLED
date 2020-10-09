
#define layerOne 2
#define layerTwo 3
#define layerThree 4

#define pin11 5
#define pin12 6
#define pin13 7
#define pin21 8
#define pin22 9
#define pin23 10
#define pin31 11
#define pin32 12
#define pin33 13

// layerOne   -> 0 - 8
// layerTwo   -> 9 - 17
// layerThree -> 18 - 26
const byte lenLEDs = 27;
byte LEDs[lenLEDs];

int LayerDuration = 3000;
unsigned long oldMicros = 0;
int stretch = 40;
int layer = 0;
int count = 0;

int i = 0;

int q = 0;
int nWall = 0;

void setup() {
  pinMode(layerOne, OUTPUT);
  pinMode(layerTwo, OUTPUT);
  pinMode(layerThree, OUTPUT);

  pinMode(pin11, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, OUTPUT);
  pinMode(pin21, OUTPUT);
  pinMode(pin22, OUTPUT);
  pinMode(pin23, OUTPUT);
  pinMode(pin31, OUTPUT);
  pinMode(pin32, OUTPUT);
  pinMode(pin33, OUTPUT);

  digitalWrite(layerOne, LOW);
  digitalWrite(layerTwo, LOW);
  digitalWrite(layerThree, LOW);

  digitalWrite(pin11, LOW);
  digitalWrite(pin12, LOW);
  digitalWrite(pin13, LOW);
  digitalWrite(pin21, LOW);
  digitalWrite(pin22, LOW);
  digitalWrite(pin23, LOW);
  digitalWrite(pin31, LOW);
  digitalWrite(pin32, LOW);
  digitalWrite(pin33, LOW);


}

void loop() {

  // waits until LayerDuration is reached and than goes through cycle
  if(micros()>= oldMicros){
    // updates oldMicros value by adding the micros() with LayerDuration
    oldMicros = micros() + LayerDuration;

    if (count % stretch == 0) {
      
      if (count < 10*stretch) {
        reset();
        allLayer(0);
      }

      if(count >= 10*stretch && count < 20*stretch) {
        reset();
        allLayer(1);
      }

      if(count >= 20*stretch && count < 30*stretch) {
        reset();
        allLayer(2);
      }

      if(count >= 30*stretch && count < 50*stretch) {
        reset();
        wallLED();
      }
      
      if(count >= 50*stretch && count < 70*stretch) {
        reset();
        randomLED();
      }

      if(count >= 70*stretch && count < (70+lenLEDs)*stretch) {
        reset();
        test();
      }

      if(count >= (70+lenLEDs)*stretch) {
        reset();
        allLEDs();
      }
      

    }

    cubeUpdate(layer);
    layer++;
    count++;

    if(layer > 2) {
      layer = 0;
    }

    if (count == 120*stretch) {
      count = 0;
      q = 0;
      nWall = 0;
    }
  }
}


void cubeUpdate(int nLayer) {

  if (nLayer == 0) {
    digitalWrite(layerOne, LOW);
    digitalWrite(layerTwo, LOW);
    digitalWrite(layerThree, LOW);
    delay(0.2);

    digitalWrite(pin11, LEDs[0]);
    digitalWrite(pin12, LEDs[1]);
    digitalWrite(pin13, LEDs[2]);
    digitalWrite(pin21, LEDs[3]);
    digitalWrite(pin22, LEDs[4]);
    digitalWrite(pin23, LEDs[5]);
    digitalWrite(pin31, LEDs[6]);
    digitalWrite(pin32, LEDs[7]);
    digitalWrite(pin33, LEDs[8]);

    digitalWrite(layerOne, HIGH);
  }

  if (nLayer == 1) {
    digitalWrite(layerOne, LOW);
    digitalWrite(layerTwo, LOW);
    digitalWrite(layerThree, LOW);
    delay(0.2);

    digitalWrite(pin11, LEDs[9]);
    digitalWrite(pin12, LEDs[10]);
    digitalWrite(pin13, LEDs[11]);
    digitalWrite(pin21, LEDs[12]);
    digitalWrite(pin22, LEDs[13]);
    digitalWrite(pin23, LEDs[14]);
    digitalWrite(pin31, LEDs[15]);
    digitalWrite(pin32, LEDs[16]);
    digitalWrite(pin33, LEDs[17]);

    digitalWrite(layerTwo, HIGH);
  }

  if (nLayer == 2) {
    digitalWrite(layerOne, LOW);
    digitalWrite(layerTwo, LOW);
    digitalWrite(layerThree, LOW);
    delay(0.2);

    digitalWrite(pin11, LEDs[18]);
    digitalWrite(pin12, LEDs[19]);
    digitalWrite(pin13, LEDs[20]);
    digitalWrite(pin21, LEDs[21]);
    digitalWrite(pin22, LEDs[22]);
    digitalWrite(pin23, LEDs[23]);
    digitalWrite(pin31, LEDs[24]);
    digitalWrite(pin32, LEDs[25]);
    digitalWrite(pin33, LEDs[26]);

    digitalWrite(layerThree, HIGH);
  }
}


void reset() {
  for (i = 0; i < lenLEDs; i++) {
    LEDs[i] = LOW;
  }
}

void allLEDs() {
  for (i = 0; i < lenLEDs; i++) {
    LEDs[i] = HIGH;
  }
}

void allLayer(int nLayer) {
  int aux = 0;
  if (nLayer == 0)
    aux = 0;
  if (nLayer == 1)
    aux = 9;
  if (nLayer == 2)
    aux = 18;

  for (i = 0; i < 9; i++) {
    LEDs[i+aux] = HIGH;
  }
}

void randomLED(){
  for (i = 0 ;i < 10; i++){
    LEDs[random(lenLEDs)] = HIGH;
  }
}
  
void test(){
  LEDs[q] = HIGH;
  q++;
  if (q == lenLEDs){
    q=0;
  }
}

void wallLED() {
  if(nWall == 0) {
    LEDs[0] = HIGH;
    LEDs[1] = HIGH;
    LEDs[2] = HIGH;
    LEDs[9] = HIGH;
    LEDs[10] = HIGH;
    LEDs[11] = HIGH;
    LEDs[18] = HIGH;
    LEDs[19] = HIGH;
    LEDs[20] = HIGH;
  }

  if(nWall == 1) {
    LEDs[1] = HIGH;
    LEDs[2] = HIGH;
    LEDs[5] = HIGH;
    LEDs[10] = HIGH;
    LEDs[11] = HIGH;
    LEDs[14] = HIGH;
    LEDs[19] = HIGH;
    LEDs[20] = HIGH;
    LEDs[23] = HIGH;
  }

  if(nWall == 2) {
    LEDs[2] = HIGH;
    LEDs[5] = HIGH;
    LEDs[8] = HIGH;
    LEDs[11] = HIGH;
    LEDs[14] = HIGH;
    LEDs[17] = HIGH;
    LEDs[20] = HIGH;
    LEDs[23] = HIGH;
    LEDs[26] = HIGH;
  }

  if(nWall == 3) {
    LEDs[5] = HIGH;
    LEDs[8] = HIGH;
    LEDs[7] = HIGH;
    LEDs[14] = HIGH;
    LEDs[17] = HIGH;
    LEDs[16] = HIGH;
    LEDs[23] = HIGH;
    LEDs[26] = HIGH;
    LEDs[25] = HIGH;
  }

  if(nWall == 4) {
    LEDs[8] = HIGH;
    LEDs[7] = HIGH;
    LEDs[6] = HIGH;
    LEDs[17] = HIGH;
    LEDs[16] = HIGH;
    LEDs[15] = HIGH;
    LEDs[26] = HIGH;
    LEDs[25] = HIGH;
    LEDs[24] = HIGH;
  }

  if(nWall == 5) {
    LEDs[7] = HIGH;
    LEDs[6] = HIGH;
    LEDs[3] = HIGH;
    LEDs[16] = HIGH;
    LEDs[15] = HIGH;
    LEDs[12] = HIGH;
    LEDs[25] = HIGH;
    LEDs[24] = HIGH;
    LEDs[21] = HIGH;
  }

  if(nWall == 6) {
    LEDs[6] = HIGH;
    LEDs[3] = HIGH;
    LEDs[0] = HIGH;
    LEDs[15] = HIGH;
    LEDs[12] = HIGH;
    LEDs[9] = HIGH;
    LEDs[24] = HIGH;
    LEDs[21] = HIGH;
    LEDs[18] = HIGH;
  }

  if(nWall == 6) {
    LEDs[3] = HIGH;
    LEDs[0] = HIGH;
    LEDs[1] = HIGH;
    LEDs[12] = HIGH;
    LEDs[9] = HIGH;
    LEDs[10] = HIGH;
    LEDs[21] = HIGH;
    LEDs[18] = HIGH;
    LEDs[19] = HIGH;
  }

  nWall++;
  if (nWall == 7)
    nWall = 0;

}
