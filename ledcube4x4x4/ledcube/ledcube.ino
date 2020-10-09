
#include "Tlc5940.h"  //don't forget to download the Tlc5940 lib from arduino playground ( http://tlc5940arduino.googlecode.com/files/Tlc5940_r014_2.zip )
#define LayerOne 4      //Gate of 1.MOSFET which connects to Layer "a" (anodes of all Strings in Layer "a")
#define LayerTwo 5      //Gate of 2.MOSFET which connects to Layer "b" (anodes of all StringS in Layer "b")
#define LayerThree 6    //Gate of 3.MOSFET which connects to Layer "c" (anodes of all Strings in Layer "c")
#define LayerFour 7     //Gate of 4.MOSFET which connects to Layer "d" (anodes of all Strings in Layer "d")


#define Ach 0 //defines the "A" (RED)string for the tlc5940 -->OUTPUT 0 first TLC5940
#define Bch 1 //defines the "B" (RED)string for the tlc5940 -->OUTPUT 1
#define Cch 2 //defines the "C" (RED)string for the tlc5940 -->OUTPUT 2
#define Dch 3 //defines the "D" (RED)string for the tlc5940 -->OUTPUT 3
#define Ech 4 //defines the "E" (RED)string for the tlc5940 -->OUTPUT 4
#define Fch 5 //defines the "F" (RED)string for the tlc5940 -->OUTPUT 5
#define Gch 6 //defines the "G" (RED)string for the tlc5940 -->OUTPUT 6
#define Hch 7 //defines the "H" (RED)string for the tlc5940 -->OUTPUT 7
#define Ich 8 //defines the "I" (RED)string for the tlc5940 -->OUTPUT 8
#define Jch 9 //defines the "J" (RED)string for the tlc5940 -->OUTPUT 9
#define Kch 10//defines the "K" (RED)string for the tlc5940 -->OUTPUT 10
#define Lch 11//defines the "L" (RED)string for the tlc5940 -->OUTPUT 11
#define Mch 12//defines the "M" (RED)string for the tlc5940 -->OUTPUT 12
#define Nch 13//defines the "N" (RED)string for the tlc5940 -->OUTPUT 13
#define Och 14//defines the "O" (RED)string for the tlc5940 -->OUTPUT 14
#define Pch 15//defines the "P" (RED)string for the tlc5940 -->OUTPUT 15


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

int LEDs[]={Aa,Ba,Ca,Da,Ea,Fa,Ga,Ha,Ia,Ja,Ka,La,Ma,Na,Oa,Pa,
               Ab,Bb,Cb,Db,Eb,Fb,Gb,Hb,Ib,Jb,Kb,Lb,Mb,Nb,Ob,Pb,
               Ac,Bc,Cc,Dc,Ec,Fc,Gc,Hc,Ic,Jc,Kc,Lc,Mc,Nc,Oc,Pc,
               Ad,Bd,Cd,Dd,Ed,Fd,Gd,Hd,Id,Jd,Kd,Ld,Md,Nd,Od,Pd};
                   
int LayerDuration = 5000;     // ON time of each Layer in microseconds  
int layer = 0;                // starting with Layer 0 (Layer "a")
unsigned long oldMicros = 0;  // starting counter to decide when if(micros()>=oldMicros)is true to change active layer, count++1, MatrixUpdate(); don't know what micros() is? Look here: http://arduino.cc/de/Reference/Micros#.UygzAIWmWd4
int count=0;                // starting counter which is included in if() statement to change the shown picture, not necessary when using a static picture
int stretch=20;             // set timer for the change of the shown picture, if animation should move really fast then low stretch value, if animation should move really slow than big stretch value
int bright=4000;            // set brightness for all Strings(4095=20mA, 0=0ma, 1000=4.88mA,....). If you want individually brightness for a String you have to change the value in tab "function"
int p;                      // used in functions for-loop
int q;                      // used in functions for-loop

void setup()
{
  pinMode(LayerOne, OUTPUT);  // declare arduino nano pin A0(LayerOne) as OUTPUT
  pinMode(LayerTwo, OUTPUT);  // declare arduino nano pin A1(LayerTwo) as OUTPUT
  pinMode(LayerThree, OUTPUT);// declare arduino nano pin A2(LayerThree) as OUTPUT
  pinMode(LayerFour, OUTPUT); // declare arduino nano pin A3(LayerFour) as OUTPUT
  Tlc.init();               // configures the arduino to use the tlc5940, be sure to connect the arduino correctly to the tlc 
 
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


     
     if(count % stretch == 0 && count < 64*stretch){
       reset();
       test(bright);
     }
     

     
     if(count >= 64*stretch && count < 100*stretch && count%stretch == 0) {
       reset();
       wall(bright);
     }

     if(count >= 100*stretch && count < 120*stretch){
       reset();
       randomLED(bright);
     }   
  
     if(count >= 120*stretch) {
       reset();
       allLEDs(bright);
     }


     CubeUpdate(layer);                                                 // sets the values for the tlc5940 Outputs and puts all MOSFET Gates HIGH (not active) except for one MOSFET Low (active) -->this layer is ON, also look under tab "function"  
     layer++;                                                           // layer counter +1, so MatrixUpdate(layer) will affect the next layer during the next if() cycle 
     count++;                                                           // count counter +1, to change the picture in next if() cycle
     if(layer==5) {
       layer = 1;
     }                                           // we only have 5 layers, so we start with layer 1 again if layer counter goes to 6
     if (count==150*stretch) {
       count=0;
     }                                    // we have 8 static picture for the moving sine wave, so if count counter would hit the 9.(not existing) pic, it goes back to count=0
  }
}


void CubeUpdate(int layerno){ 
  
  if(layerno == 1){                 
                                  // Tlc.set(OUTPUT, BRIGHTNESS VALUE (0-4095)), general use of Tlc.set      
    Tlc.set(Ach, LEDs[0]);             // set AaR brightness to AchR OUTPUT(OUTPUT 0); first TLC5940 
    Tlc.set(Bch, LEDs[1]);             // set BaR brightness to BchR OUTPUT(OUTPUT 1);
    Tlc.set(Cch, LEDs[2]);             // set CaR brightness to CchR OUTPUT(OUTPUT 2);
    Tlc.set(Dch, LEDs[3]);             // set DaR brightness to DchR OUTPUT(OUTPUT 3);
    Tlc.set(Ech, LEDs[4]);             // set EaR brightness to EchR OUTPUT(OUTPUT 4);
    Tlc.set(Fch, LEDs[5]);             // set FaR brightness to FchR OUTPUT(OUTPUT 5);
    Tlc.set(Gch, LEDs[6]);             // set GaR brightness to GchR OUTPUT(OUTPUT 6);
    Tlc.set(Hch, LEDs[7]);             // set HaR brightness to HchR OUTPUT(OUTPUT 7);
    Tlc.set(Ich, LEDs[8]);             // set IaR brightness to IchR OUTPUT(OUTPUT 8);
    Tlc.set(Jch, LEDs[9]);             // set JaR brightness to JchR OUTPUT(OUTPUT 9);
    Tlc.set(Kch, LEDs[10]);             // set KaR brightness to KchR OUTPUT(OUTPUT 10);
    Tlc.set(Lch, LEDs[11]);             // set LaR brightness to LchR OUTPUT(OUTPUT 11);
    Tlc.set(Mch, LEDs[12]);             // set MaR brightness to MchR OUTPUT(OUTPUT 12);
    Tlc.set(Nch, LEDs[13]);             // set NaR brightness to NchR OUTPUT(OUTPUT 13);
    Tlc.set(Och, LEDs[14]);             // set OaR brightness to OchR OUTPUT(OUTPUT 14);
    Tlc.set(Pch, LEDs[15]);             // set PaR brightness to PchR OUTPUT(OUTPUT 15);
    
    digitalWrite(LayerOne, HIGH);     // sets LayerOne (pin A0) High (not active)--> Layer one OFF
    digitalWrite(LayerTwo, HIGH);     // sets LayerTwo (pin A1) High (not active)--> Layer two OFF
    digitalWrite(LayerThree, HIGH);   // sets LayerThree (pin A2) High (not active)--> Layer three OFF
    digitalWrite(LayerFour, HIGH);    // sets LayerFour (pin A3) High (not active)--> Layer four OFF
    Tlc.update();                     // writes the values for the LEDs brightness to the tlc
    delay(1);                         // give the tlc some time to let the value settle
    digitalWrite(LayerOne, LOW);      // sets LayerOne (pin A0) Low (active)--> Layer one ON
  }
  
    if(layerno == 2){
  
    Tlc.set(Ach, LEDs[16]);             // same as if(layerno == 1) but we use different brightness, so we define LEDs in the second layer
    Tlc.set(Bch, LEDs[17]);
    Tlc.set(Cch, LEDs[18]);
    Tlc.set(Dch, LEDs[19]);    
    Tlc.set(Ech, LEDs[20]);
    Tlc.set(Fch, LEDs[21]);
    Tlc.set(Gch, LEDs[22]);
    Tlc.set(Hch, LEDs[23]);    
    Tlc.set(Ich, LEDs[24]);
    Tlc.set(Jch, LEDs[25]);
    Tlc.set(Kch, LEDs[26]);
    Tlc.set(Lch, LEDs[27]);
    Tlc.set(Mch, LEDs[28]);
    Tlc.set(Nch, LEDs[29]);
    Tlc.set(Och, LEDs[30]);
    Tlc.set(Pch, LEDs[31]);
    
    digitalWrite(LayerOne, HIGH);  // same as if(layerno==1)
    digitalWrite(LayerTwo, HIGH);
    digitalWrite(LayerThree, HIGH);
    digitalWrite(LayerFour, HIGH);
    Tlc.update();
    delay(1);
    digitalWrite(LayerTwo, LOW);  // sets LayerTwo (pin A1) Low (active)--> Layer two ON
  }
  
  
  if(layerno == 3){
    
    Tlc.set(Ach, LEDs[32]);             // same as if(layerno == 1) but we use different brightness, so we define LEDs in the third layer
    Tlc.set(Bch, LEDs[33]);
    Tlc.set(Cch, LEDs[34]);
    Tlc.set(Dch, LEDs[35]);    
    Tlc.set(Ech, LEDs[36]);
    Tlc.set(Fch, LEDs[37]);
    Tlc.set(Gch, LEDs[38]);
    Tlc.set(Hch, LEDs[39]);    
    Tlc.set(Ich, LEDs[40]);
    Tlc.set(Jch, LEDs[41]);
    Tlc.set(Kch, LEDs[42]);
    Tlc.set(Lch, LEDs[43]);
    Tlc.set(Mch, LEDs[44]);
    Tlc.set(Nch, LEDs[45]);
    Tlc.set(Och, LEDs[46]);
    Tlc.set(Pch, LEDs[47]);
    
    digitalWrite(LayerOne, HIGH);   // same as if(layerno==1)
    digitalWrite(LayerTwo, HIGH);
    digitalWrite(LayerThree, HIGH);
    digitalWrite(LayerFour, HIGH);
    Tlc.update();
    delay(1);
    digitalWrite(LayerThree, LOW);   // sets LayerThree (pin A2) Low (active)--> Layer three ON 
  }
  
  
  if(layerno == 4){
    
    Tlc.set(Ach, LEDs[48]);             // same as if(layerno == 1) but we use different brightness, so we define LEDs in the fourth layer
    Tlc.set(Bch, LEDs[49]);
    Tlc.set(Cch, LEDs[50]);
    Tlc.set(Dch, LEDs[51]);    
    Tlc.set(Ech, LEDs[52]);
    Tlc.set(Fch, LEDs[53]);
    Tlc.set(Gch, LEDs[54]);
    Tlc.set(Hch, LEDs[55]);    
    Tlc.set(Ich, LEDs[56]);
    Tlc.set(Jch, LEDs[57]);
    Tlc.set(Kch, LEDs[58]);
    Tlc.set(Lch, LEDs[59]);
    Tlc.set(Mch, LEDs[60]);
    Tlc.set(Nch, LEDs[61]);
    Tlc.set(Och, LEDs[62]);
    Tlc.set(Pch, LEDs[63]);
    
    digitalWrite(LayerOne, HIGH);  // same as if(layerno==1)
    digitalWrite(LayerTwo, HIGH);
    digitalWrite(LayerThree, HIGH);
    digitalWrite(LayerFour, HIGH);
    Tlc.update();
    delay(1);
    digitalWrite(LayerFour, LOW);  // sets LayerFour (pin A3) Low (active)--> Layer four ON
  }}
      
  void reset(){                 // we set all LEDs to 0 brightness
    for (p=0;p<64;p++){
      LEDs[p]=0;}
  }
  
  void allLEDs(int bright){
    for (int p=0;p<64;p++) {
      LEDs[p] = bright;
    }
  }

  void allLayers(int layer, int bright){
    if (layer == 1) {
      for (int p=0;p<16;p++) {
        LEDs[p] = bright;
      }
    }
    
  }

  void randomLED(int bright){
    for (p=0;p<10;p++){
      LEDs[random(64)] = random(500, bright);
    }
  }

  void test(int bright){
    LEDs[q]=bright;
    q=q+1;
    if (q==64){
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
             int turnonlist[] = {0,1,2,3,  16,17,18,19,    32,33,34,35,    48,49,50,51};
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
  
