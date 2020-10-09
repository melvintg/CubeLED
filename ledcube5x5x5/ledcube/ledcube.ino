
#include "Tlc5940.h"  //don't forget to download the Tlc5940 lib from arduino playground ( http://tlc5940arduino.googlecode.com/files/Tlc5940_r014_2.zip )
#define LayerOne 4      //Gate of 1.MOSFET which connects to Layer "a" (anodes of all Strings in Layer "a")
#define LayerTwo 5      //Gate of 2.MOSFET which connects to Layer "b" (anodes of all StringS in Layer "b")
#define LayerThree 6    //Gate of 3.MOSFET which connects to Layer "c" (anodes of all Strings in Layer "c")
#define LayerFour 7     //Gate of 4.MOSFET which connects to Layer "d" (anodes of all Strings in Layer "d")
#define LayerFive 8     //Gate of 5.MOSFET which connects to Layer "e" (anodes of all Strings in Layer "e")


#define Ach 0  //defines the "A"  for the tlc5940 -->OUTPUT 0 first TLC5940
#define Bch 1  //defines the "B"  for the tlc5940 -->OUTPUT 1
#define Cch 2  //defines the "C"  for the tlc5940 -->OUTPUT 2
#define Dch 3  //defines the "D"  for the tlc5940 -->OUTPUT 3
#define Ech 4  //defines the "E"  for the tlc5940 -->OUTPUT 4
#define Fch 5  //defines the "F"  for the tlc5940 -->OUTPUT 5
#define Gch 6  //defines the "G"  for the tlc5940 -->OUTPUT 6
#define Hch 7  //defines the "H"  for the tlc5940 -->OUTPUT 7
#define Ich 8  //defines the "I"  for the tlc5940 -->OUTPUT 8
#define Jch 9  //defines the "J"  for the tlc5940 -->OUTPUT 9
#define Kch 10 //defines the "K"  for the tlc5940 -->OUTPUT 10
#define Lch 11 //defines the "L"  for the tlc5940 -->OUTPUT 11
#define Mch 12 //defines the "M"  for the tlc5940 -->OUTPUT 12
#define Nch 13 //defines the "N"  for the tlc5940 -->OUTPUT 13
#define Och 14 //defines the "O"  for the tlc5940 -->OUTPUT 14
#define Pch 15 //defines the "P"  for the tlc5940 -->OUTPUT 15
#define Qch 16 //defines the "Q"  for the tlc5940 -->OUTPUT 16 second TLC5940
#define Rch 17 //defines the "R"  for the tlc5940 -->OUTPUT 17
#define Sch 18 //defines the "S"  for the tlc5940 -->OUTPUT 18
#define Tch 19 //defines the "T"  for the tlc5940 -->OUTPUT 19
#define Uch 20 //defines the "U"  for the tlc5940 -->OUTPUT 20
#define Vch 21 //defines the "V"  for the tlc5940 -->OUTPUT 21
#define Wch 22 //defines the "W"  for the tlc5940 -->OUTPUT 22
#define Xch 23 //defines the "X"  for the tlc5940 -->OUTPUT 23
#define Ych 24 //defines the "Y"  for the tlc5940 -->OUTPUT 24


int Aa = 0;   // set a variable for all LEDs and set the value to 0 for the beginning
int Ba = 0;
int Ca = 0;
int Da = 0;
int Ea = 0;
int Fa = 0;
int Ga = 0;
int Ha = 0;
int Ia = 0;
int Ja = 0;
int Ka = 0;
int La = 0;
int Ma = 0;
int Na = 0;
int Oa = 0;
int Pa = 0;
int Qa = 0;
int Ra = 0;
int Sa = 0;
int Ta = 0;
int Ua = 0;
int Va = 0;
int Wa = 0;
int Xa = 0;
int Ya = 0;


int Ab = 0;
int Bb = 0;
int Cb = 0;
int Db = 0;
int Eb = 0;
int Fb = 0;
int Gb = 0;
int Hb = 0;
int Ib = 0;
int Jb = 0;
int Kb = 0;
int Lb = 0;
int Mb = 0;
int Nb = 0;
int Ob = 0;
int Pb = 0;
int Qb = 0;
int Rb = 0;
int Sb = 0;
int Tb = 0;
int Ub = 0;
int Vb = 0;
int Wb = 0;
int Xb = 0;
int Yb = 0;


int Ac = 0;
int Bc = 0;
int Cc = 0;
int Dc = 0;
int Ec = 0;
int Fc = 0;
int Gc = 0;
int Hc = 0;
int Ic = 0;
int Jc = 0;
int Kc = 0;
int Lc = 0;
int Mc = 0;
int Nc = 0;
int Oc = 0;
int Pc = 0;
int Qc = 0;
int Rc = 0;
int Sc = 0;
int Tc = 0;
int Uc = 0;
int Vc = 0;
int Wc = 0;
int Xc = 0;
int Yc = 0;


int Ad = 0;
int Bd = 0;
int Cd = 0;
int Dd = 0;
int Ed = 0;
int Fd = 0;
int Gd = 0;
int Hd = 0;
int Id = 0;
int Jd = 0;
int Kd = 0;
int Ld = 0;
int Md = 0;
int Nd = 0;
int Od = 0;
int Pd = 0;
int Qd = 0;
int Rd = 0;
int Sd = 0;
int Td = 0;
int Ud = 0;
int Vd = 0;
int Wd = 0;
int Xd = 0;
int Yd = 0;

int Ae = 0;
int Be = 0;
int Ce = 0;
int De = 0;
int Ee = 0;
int Fe = 0;
int Ge = 0;
int He = 0;
int Ie = 0;
int Je = 0;
int Ke = 0;
int Le = 0;
int Me = 0;
int Ne = 0;
int Oe = 0;
int Pe = 0;
int Qe = 0;
int Re = 0;
int Se = 0;
int Te = 0;
int Ue = 0;
int Ve = 0;
int We = 0;
int Xe = 0;
int Ye = 0;


int LEDs[]={Aa,Ba,Ca,Da,Ea,Fa,Ga,Ha,Ia,Ja,Ka,La,Ma,Na,Oa,Pa,Qa,Ra,Sa,Ta,Ua,Va,Wa,Xa,Ya,
            Ab,Bb,Cb,Db,Eb,Fb,Gb,Hb,Ib,Jb,Kb,Lb,Mb,Nb,Ob,Pb,Qb,Rb,Sb,Tb,Ub,Vb,Wb,Xb,Yb,
            Ac,Bc,Cc,Dc,Ec,Fc,Gc,Hc,Ic,Jc,Kc,Lc,Mc,Nc,Oc,Pc,Qc,Rc,Sc,Tc,Uc,Vc,Wc,Xc,Yc,
            Ad,Bd,Cd,Dd,Ed,Fd,Gd,Hd,Id,Jd,Kd,Ld,Md,Nd,Od,Pd,Qd,Rd,Sd,Td,Ud,Vd,Wd,Xd,Yd,
            Ae,Be,Ce,De,Ee,Fe,Ge,He,Ie,Je,Ke,Le,Me,Ne,Oe,Pe,Qe,Re,Se,Te,Ue,Ve,We,Xe,Ye};


int LayerDuration = 4000;     // ON time of each Layer in microseconds
int layer = 0;                // starting with Layer 0 (Layer "a")
unsigned long oldMicros = 0;  // starting counter to decide when if(micros()>=oldMicros)is true to change active layer, count++1, MatrixUpdate(); don't know what micros() is? Look here: http://arduino.cc/de/Reference/Micros#.UygzAIWmWd4
int count=0;                // starting counter which is included in if() statement to change the shown picture, not necessary when using a static picture
int stretch=50;             // set timer for the change of the shown picture, if animation should move really fast then low stretch value, if animation should move really slow than big stretch value
int bright=4095;            // set brightness for all Strings(4095=20mA, 0=0ma, 1000=4.88mA,....). If you want individually brightness for a String you have to change the value in tab "function"
int p;                      // used in functions for-loop
int q;                      // used in functions for-loop

void setup()
{
  pinMode(LayerOne, OUTPUT);
  pinMode(LayerTwo, OUTPUT);
  pinMode(LayerThree, OUTPUT);
  pinMode(LayerFour, OUTPUT);
  pinMode(LayerFive, OUTPUT);

  // configures the arduino to use the tlc5940,
  // be sure to connect the arduino correctly to the tlc
  Tlc.init();

 /*          ARDUINO                                         TLC5940
              13|-> SCLK (pin 25)           OUT1 String "B" |1     28| OUT0 String "A"
              12|                           OUT2 String "C" |2     27|-> GND (VPRG)
              11|-> SIN (pin 26)            OUT3 String "D" |3     26|-> SIN (pin 11)
              10|-> BLANK (pin 23)          OUT4 String "E" |4     25|-> SCLK (pin 13)
               9|-> XLAT (pin 24)           OUT5 String "F" |5     24|-> XLAT (pin 9)
               8|                           OUT6 String "G" |6     23|-> BLANK (pin 10)
               7|                           OUT7 String "H" |7     22|-> GND
               6|                           OUT8 String "I" |8     21|-> VCC (+5V)
               5|                           OUT9 String "J" |9     20|-> 2K Resistor -> GND
               4|                          OUT10 String "K" |10    19|-> +5V (DCPRG)
               3|-> GSCLK (pin 18)         OUT11 String "L" |11    18|-> GSCLK (pin 3)
               2|                          OUT12 String "M" |12    17|-> SOUT (only used when you want to use more than one tlc5940)
               1|                          OUT13 String "N" |13    16|-> XERR (can be used as error report, but not necessary)
               0|                          OUT14 String "O" |14    15| OUT15 String "P"       */
  }

void loop(){

  // waits until LayerDuration is reached and than goes through cycle
  if(micros()>= oldMicros){
    // updates oldMicros value by adding the micros() with LayerDuration
    oldMicros = micros() + LayerDuration;



     if(count % stretch == 0 && count < 125*stretch){
       reset();
       test(bright);
     }
     

     if(count % stretch == 0 && count >= 125*stretch && count < 175*stretch){
       reset();
       randomLED(bright);
     }   
     
  
     if(count % stretch == 0 && count >= 175*stretch) {
       //reset();
       allLEDs(bright);
     }


     CubeUpdate(layer);                                                  // sets the values for the tlc5940 Outputs and puts all MOSFET Gates HIGH (not active) except for one MOSFET Low (active) -->this layer is ON, also look under tab "function"  
     layer++;                                                           // layer counter +1, so MatrixUpdate(layer) will affect the next layer during the next if() cycle 
     count++;                                                           // count counter +1, to change the picture in next if() cycle
     if(layer==6) {
       layer = 1;
     }                                           // we only have 5 layers, so we start with layer 1 again if layer counter goes to 6
     if (count==250*stretch) {
       count=0;
     }                                    // we have 8 static picture for the moving sine wave, so if count counter would hit the 9.(not existing) pic, it goes back to count=0
  }
}

void reset(){                 // we set all LEDs to 0 brightness
  for (p=0;p<125;p++){
    LEDs[p]=0;}
}

void allLEDs(int bright){
  for (int p=0;p<125;p++) {
    LEDs[p] = bright;
  }
}

void allLayers(int layer, int bright){
  if (layer == 1) {
    for (int p=0;p<25;p++) {
      LEDs[p] = bright;
    }
  }
}

void randomLED(int bright){
  for (p=0;p<50;p++){
    LEDs[random(125)] = random(500, bright);
  }
}

void test(int bright){
  LEDs[q]=bright;
  q=q+1;
  if (q==125){
    q=0;
  }
}

void turnon(int liste[], int anzahl, int bright2){
  for (int i = 0; i < anzahl; i++) {
      LEDs[liste[i]]=bright2;
  }
}

void wall(int bright){
  if(q==0){reset();
           int turnonlist[] = {0,1,2,3,4,  25,26,27,28,29,    50,51,52,53,54, 75,76,77,78,79, 100,101,102,103,104};
           turnon(turnonlist, 16, bright);}
  if(q==1){reset();
           int turnonlist[] = {1,2,3,7,   17,18,19,23,   33,34,35,39,   49,50,51,55};
           turnon(turnonlist, 16, bright);}
  if(q==2){reset();
           int turnonlist[] = {2,3,7,11,   18,19,23,27,   34,35,39,43,   50,51,55,59};
           turnon(turnonlist, 16, bright);}
  if(q==3){reset();
           int turnonlist[] = {3,7,11,15,   19,23,27,31,   35,39,43,47,   51,55,59,63};
           turnon(turnonlist, 16, bright);}
  if(q==4){reset();
           int turnonlist[] = {7,11,15,14,   23,27,31,30,   39,43,47,46,   55,59,63,62};
           turnon(turnonlist,16, bright);}
  if(q==5){reset();
           int turnonlist[] = {11,15,14,13,   27,31,30,29,   43,47,46,45,   59,63,62,61};
           turnon(turnonlist, 16, bright);}
  if(q==6){reset();
           int turnonlist[] = {15,14,13,12,   31,30,29,28,   47,46,45,44,   63,62,61,60};
           turnon(turnonlist, 16, bright);}
  if(q==7){reset();
           int turnonlist[] = {14,13,12,8,   30,29,28,24,   46,45,44,40,   62,61,60,56};
           turnon(turnonlist, 16, bright);}
  if(q==8){reset();
           int turnonlist[] = {13,12,8,4,   29,28,24,20,   45,44,40,36,   61,60,56,52};
           turnon(turnonlist, 16, bright);}
  if(q==9){reset();
           int turnonlist[] = {12,8,4,0,   28,24,20,16,   44,40,36,32,   60,56,52,48};
           turnon(turnonlist, 16, bright);}
  if(q==10){reset();
            int turnonlist[] = {8,4,0,1,   24,20,16,17,   40,36,32,33,   56,52,48,49};
            turnon(turnonlist, 16, bright);}
  if(q==11){reset();
            int turnonlist[] = {4,0,1,2,   20,16,17,18,   36,32,33,34,   52,48,49,50};
            turnon(turnonlist, 16, bright);}
  q=q+1;
  if(q==12){
    q=0;
  }
}






void CubeUpdate(int layerno){
  if(layerno == 1){
    digitalWrite(LayerOne, HIGH);
    digitalWrite(LayerTwo, HIGH);
    digitalWrite(LayerThree, HIGH);
    digitalWrite(LayerFour, HIGH);
    digitalWrite(LayerFive, HIGH);
    
    // Tlc.set(OUTPUT, BRIGHTNESS VALUE (0-4095)), general use of Tlc.set
    Tlc.set(Ach, LEDs[0]);
    Tlc.set(Bch, LEDs[1]);
    Tlc.set(Cch, LEDs[2]);
    Tlc.set(Dch, LEDs[3]);
    Tlc.set(Ech, LEDs[4]);
    Tlc.set(Fch, LEDs[5]);
    Tlc.set(Gch, LEDs[6]);
    Tlc.set(Hch, LEDs[7]);
    Tlc.set(Ich, LEDs[8]);
    Tlc.set(Jch, LEDs[9]);
    Tlc.set(Kch, LEDs[10]);
    Tlc.set(Lch, LEDs[11]);
    Tlc.set(Mch, LEDs[12]);
    Tlc.set(Nch, LEDs[13]);
    Tlc.set(Och, LEDs[14]);
    Tlc.set(Pch, LEDs[15]);
    Tlc.set(Qch, LEDs[16]);
    Tlc.set(Rch, LEDs[17]);
    Tlc.set(Sch, LEDs[18]);
    Tlc.set(Tch, LEDs[19]);
    Tlc.set(Uch, LEDs[20]);
    Tlc.set(Vch, LEDs[21]);
    Tlc.set(Wch, LEDs[22]);
    Tlc.set(Xch, LEDs[23]);
    Tlc.set(Ych, LEDs[24]);

    Tlc.update();                     // writes the values for the LEDs brightness to the tlc
    delay(2);                         // give the tlc some time to let the value settle
    digitalWrite(LayerOne, LOW);
  }

  if(layerno == 2){
      digitalWrite(LayerOne, HIGH);
      digitalWrite(LayerTwo, HIGH);
      digitalWrite(LayerThree, HIGH);
      digitalWrite(LayerFour, HIGH);
      digitalWrite(LayerFive, HIGH);
      Tlc.set(Ach, LEDs[25]);
      Tlc.set(Bch, LEDs[26]);
      Tlc.set(Cch, LEDs[27]);
      Tlc.set(Dch, LEDs[28]);
      Tlc.set(Ech, LEDs[29]);
      Tlc.set(Fch, LEDs[30]);
      Tlc.set(Gch, LEDs[31]);
      Tlc.set(Hch, LEDs[32]);
      Tlc.set(Ich, LEDs[33]);
      Tlc.set(Jch, LEDs[34]);
      Tlc.set(Kch, LEDs[35]);
      Tlc.set(Lch, LEDs[36]);
      Tlc.set(Mch, LEDs[37]);
      Tlc.set(Nch, LEDs[38]);
      Tlc.set(Och, LEDs[39]);
      Tlc.set(Pch, LEDs[40]);
      Tlc.set(Qch, LEDs[41]);
      Tlc.set(Rch, LEDs[42]);
      Tlc.set(Sch, LEDs[43]);
      Tlc.set(Tch, LEDs[44]);
      Tlc.set(Uch, LEDs[45]);
      Tlc.set(Vch, LEDs[46]);
      Tlc.set(Wch, LEDs[47]);
      Tlc.set(Xch, LEDs[48]);
      Tlc.set(Ych, LEDs[49]);

      Tlc.update();                     // writes the values for the LEDs brightness to the tlc
      delay(2);                         // give the tlc some time to let the value settle
      digitalWrite(LayerTwo, LOW);
  }


  if(layerno == 3){
    digitalWrite(LayerOne, HIGH);
    digitalWrite(LayerTwo, HIGH);
    digitalWrite(LayerThree, HIGH);
    digitalWrite(LayerFour, HIGH);
    digitalWrite(LayerFive, HIGH);
    
    Tlc.set(Ach, LEDs[50]);
    Tlc.set(Bch, LEDs[51]);
    Tlc.set(Cch, LEDs[52]);
    Tlc.set(Dch, LEDs[53]);
    Tlc.set(Ech, LEDs[54]);
    Tlc.set(Fch, LEDs[55]);
    Tlc.set(Gch, LEDs[56]);
    Tlc.set(Hch, LEDs[57]);
    Tlc.set(Ich, LEDs[58]);
    Tlc.set(Jch, LEDs[59]);
    Tlc.set(Kch, LEDs[60]);
    Tlc.set(Lch, LEDs[61]);
    Tlc.set(Mch, LEDs[62]);
    Tlc.set(Nch, LEDs[63]);
    Tlc.set(Och, LEDs[64]);
    Tlc.set(Pch, LEDs[65]);
    Tlc.set(Qch, LEDs[66]);
    Tlc.set(Rch, LEDs[67]);
    Tlc.set(Sch, LEDs[68]);
    Tlc.set(Tch, LEDs[69]);
    Tlc.set(Uch, LEDs[70]);
    Tlc.set(Vch, LEDs[71]);
    Tlc.set(Wch, LEDs[72]);
    Tlc.set(Xch, LEDs[73]);
    Tlc.set(Ych, LEDs[74]);

    Tlc.update();                     // writes the values for the LEDs brightness to the tlc
    delay(2);                         // give the tlc some time to let the value settle
    digitalWrite(LayerThree, LOW);
  }


  if(layerno == 4){
    digitalWrite(LayerOne, HIGH);
    digitalWrite(LayerTwo, HIGH);
    digitalWrite(LayerThree, HIGH);
    digitalWrite(LayerFour, HIGH);
    digitalWrite(LayerFive, HIGH);
    
    Tlc.set(Ach, LEDs[75]);
    Tlc.set(Bch, LEDs[76]);
    Tlc.set(Cch, LEDs[77]);
    Tlc.set(Dch, LEDs[78]);
    Tlc.set(Ech, LEDs[79]);
    Tlc.set(Fch, LEDs[80]);
    Tlc.set(Gch, LEDs[81]);
    Tlc.set(Hch, LEDs[82]);
    Tlc.set(Ich, LEDs[83]);
    Tlc.set(Jch, LEDs[84]);
    Tlc.set(Kch, LEDs[85]);
    Tlc.set(Lch, LEDs[86]);
    Tlc.set(Mch, LEDs[87]);
    Tlc.set(Nch, LEDs[88]);
    Tlc.set(Och, LEDs[89]);
    Tlc.set(Pch, LEDs[90]);
    Tlc.set(Qch, LEDs[91]);
    Tlc.set(Rch, LEDs[92]);
    Tlc.set(Sch, LEDs[93]);
    Tlc.set(Tch, LEDs[94]);
    Tlc.set(Uch, LEDs[95]);
    Tlc.set(Vch, LEDs[96]);
    Tlc.set(Wch, LEDs[97]);
    Tlc.set(Xch, LEDs[98]);
    Tlc.set(Ych, LEDs[99]);

    Tlc.update();                     // writes the values for the LEDs brightness to the tlc
    delay(2);                         // give the tlc some time to let the value settle
    digitalWrite(LayerFour, LOW);
  }

  if(layerno == 5){

    digitalWrite(LayerOne, HIGH);
    digitalWrite(LayerTwo, HIGH);
    digitalWrite(LayerThree, HIGH);
    digitalWrite(LayerFour, HIGH);
    digitalWrite(LayerFive, HIGH);
    
    Tlc.set(Ach, LEDs[100]);
    Tlc.set(Bch, LEDs[101]);
    Tlc.set(Cch, LEDs[102]);
    Tlc.set(Dch, LEDs[103]);
    Tlc.set(Ech, LEDs[104]);
    Tlc.set(Fch, LEDs[105]);
    Tlc.set(Gch, LEDs[106]);
    Tlc.set(Hch, LEDs[107]);
    Tlc.set(Ich, LEDs[108]);
    Tlc.set(Jch, LEDs[109]);
    Tlc.set(Kch, LEDs[110]);
    Tlc.set(Lch, LEDs[111]);
    Tlc.set(Mch, LEDs[112]);
    Tlc.set(Nch, LEDs[113]);
    Tlc.set(Och, LEDs[114]);
    Tlc.set(Pch, LEDs[115]);
    Tlc.set(Qch, LEDs[116]);
    Tlc.set(Rch, LEDs[117]);
    Tlc.set(Sch, LEDs[118]);
    Tlc.set(Tch, LEDs[119]);
    Tlc.set(Uch, LEDs[120]);
    Tlc.set(Vch, LEDs[121]);
    Tlc.set(Wch, LEDs[122]);
    Tlc.set(Xch, LEDs[123]);
    Tlc.set(Ych, LEDs[124]);

    Tlc.update();                     // writes the values for the LEDs brightness to the tlc
    delay(2);                         // give the tlc some time to let the value settle
    digitalWrite(LayerFive, LOW);
  }
}
