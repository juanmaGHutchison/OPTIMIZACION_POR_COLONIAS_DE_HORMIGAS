#ifndef TEST_HORMIGAS_INO_
#define TEST_HORMIGAS_INO_
#include "PINS.hpp"
#include "MOTOR.hpp"
#include "2xCNY.hpp"
#include "CNY.hpp"
#include <SoftwareSerial.h>
/**ONLY FOR DEBUG**/
//#define SERIAL_BLUETOOTH_ONLY_ 
//uncomment this line if you are using bluetooth to comunicate the ant with the PC
#define SERIAL_WIRED_ONLY_       
//uncomment this line if you are using wired connection between arduino and the PC
//#define STRAIGHT_FOWARD_          
//uncomment this line if you want the robot to go straight and foward
//#define RUN_ROBOT_               
//uncomment if you want the robot to run
//#define RUN_WHITE_PATH_ROBOT_     
//uncomment if you want the robot to run through a white path
//#define PRINT_CNY_READ_          
//uncomment if you want to display the cny analog read
//#define PROBAR_COLORES_        
//uncomment if you want to activate and display wich colour is the sensor colour reading
//#define NODE_OPERATIONS_       
//uncomment to enable actions to do when the robot finds a node
//#define NEIGHBORS_              
//uncomment this line to search for the neighbors and continue
//#define TURN_AROUND_              
//uncomment this line to calibrate the robots turnning around
//#define FOLLOW_BLACK_LINES_       
//uncomment this line to follow black lines
#define GRADES_                     
//uncomment this line to calibrate de grades of the robot
//SOME INIZIALITATIONS
#ifdef SERIAL_BLUETOOTH_ONLY_
SoftwareSerial bluetoothSerial(BLUETOOTH_RECEIVE, BLUETOOTH_TRANSMIT);
#endif
String cadena_iteracion;
MOTOR motor;
CNY cny_left(CNY_LEFT, 800), cny_right(CNY_RIGHT, 800);
x2CNY cnys(cny_left, cny_right);
byte countRed = 0;
byte countGreen = 0;
byte countBlue = 0;
void setup() {
  // put your setup code here, to run once: 
  #ifdef SERIAL_BLUETOOTH_ONLY_
  #ifndef SERIAL_WIRED_ONLY_
    bluetoothSerial.begin(9600);
  #endif
  #endif
  #ifdef SERIAL_WIRED_ONLY_
  #ifndef SERIAL_BLUETOOTH_ONLY_
    Serial.begin(9600);
  #endif
  #endif
  pinMode(A1, INPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
}
//PROBAR CROSS RIGHT AND LEFT
void loop() {
  #ifdef STRAIGHT_FOWARD_
    motor.straight();
    delay(1000);
    motor.back();
    delay(1000);
  #endif
  #ifdef PROBAR_COLORES_
  Serial.println("prueba colores");
  for(int i = 0; i < 50; ++i){
          digitalWrite(S2, LOW);
          digitalWrite(S3, LOW);
          countRed = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
          digitalWrite(S3, HIGH);
          countBlue = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
          digitalWrite(S2, HIGH);
          countGreen = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);       
          cadena_iteracion = "Contadores\n";
          cadena_iteracion += "Rojo: ";
          cadena_iteracion += String(countRed);
          cadena_iteracion += "\nAzul: ";
          cadena_iteracion += String(countBlue);
          cadena_iteracion += "\nVerde: ";
          cadena_iteracion += String(countGreen);
          cadena_iteracion += "\n";       
          cadena_iteracion += "Color: ";
          if (countRed < countBlue && countRed < countGreen && countRed < 80) 
            cadena_iteracion += "ROJO\n";
          else if (countGreen < countRed && (countGreen - countBlue) < 4) 
            cadena_iteracion += "VERDE\n";
          else if (countBlue < countRed && countBlue < countGreen) 
            cadena_iteracion += "AZUL\n";
          else cadena_iteracion += "-\n";      
      }
      Serial.println(cadena_iteracion);
      delay(1000);
      #endif
#ifdef RUN_ROBOT_  
    /*while(cnys.bothBlack())
      motor.straight();
    if(cnys.rightWhite())
      while(cnys.rightWhite() && !cnys.bothWhite())
        motor.left();
    if(cnys.leftWhite())
      while(cnys.leftWhite() && !cnys.bothWhite())
        motor.right();*/
    if(cnys.leftWhite())
      while(!cnys.bothBlack() && !cnys.bothWhite())
        motor.right();
  if(cnys.rightWhite())
    while(!cnys.bothBlack() && !cnys.bothWhite())
      motor.left();  
   while(cnys.bothBlack()) {
      motor.straight();
      #ifdef PRINT_CNY_READ_
      cadena_iteracion = "CNY IZQDA.: ";
      cadena_iteracion += analogRead(CNY_LEFT);
      cadena_iteracion += ((cny_left.isWhite() == true) ? " White" : " Black");
      cadena_iteracion += "\nCNY DRCHA.: ";
      cadena_iteracion += analogRead(CNY_RIGHT);
      cadena_iteracion += ((cny_right.isWhite()) ? " White" : " Black");
      cadena_iteracion += "\n";
      Serial.println(cadena_iteracion);
      //delay(2000);
      #endif
   }
   while(cnys.bothWhite()){
    motor.botStop();
    #ifdef PRINT_CNY_READ_
    cadena_iteracion = "CNY IZQDA.: ";
    cadena_iteracion += analogRead(CNY_LEFT);
    cadena_iteracion += ((cny_left.isWhite() == true) ? " White" : " Black");
    cadena_iteracion += "\nCNY DRCHA.: ";
    cadena_iteracion += analogRead(CNY_RIGHT);
    cadena_iteracion += ((cny_right.isWhite()) ? " White" : " Black");
    cadena_iteracion += "\n";
    Serial.println(cadena_iteracion);
    //delay(2000);
    #endif
   } 
#endif
#ifdef RUN_WHITE_PATH_ROBOT_
  if(cnys.leftBlack())
    while(!cnys.bothBlack() && !cnys.bothWhite())
      motor.right(); 
  if(cnys.rightBlack())
    while(!cnys.bothBlack() && !cnys.bothWhite())
      motor.left();    
   while(cnys.bothWhite()) 
      motor.straight();
   while(cnys.bothBlack())
    motor.botStop();
#endif
  #ifdef PRINT_CNY_READ_
  cadena_iteracion = "CNY IZQDA.: ";
  cadena_iteracion += analogRead(CNY_LEFT);
  cadena_iteracion += ((cny_left.isWhite() == true) ? " White" : " Black");
  cadena_iteracion += "\nCNY DRCHA.: ";
  cadena_iteracion += analogRead(CNY_RIGHT);
  cadena_iteracion += ((cny_right.isWhite()) ? " White" : " Black");
  cadena_iteracion += "\n";
  Serial.println(cadena_iteracion);
  delay(100);
  /*Serial.print(analogRead(CNY_LEFT));
  Serial.print(" - ");
  Serial.println(analogRead(CNY_RIGHT));*/
  #endif
  //GET COLOUR
  /*#ifdef PROBAR_COLORES_
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  countRed = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
  digitalWrite(S3, HIGH);
  countBlue = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
  digitalWrite(S2, HIGH);
  countGreen = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
  cadena_iteracion = "Contadores\n";
  cadena_iteracion += "Rojo: ";
  cadena_iteracion += String(countRed);
  cadena_iteracion += "\nAzul: ";
  cadena_iteracion += String(countBlue);
  cadena_iteracion += "\nVerde: ";
  cadena_iteracion += String(countGreen);
  cadena_iteracion += "\n";
  cadena_iteracion += "Color: ";
  if (countRed < countBlue && countRed < countGreen && countRed < 80)  
    cadena_iteracion += "ROJO\n";
  else if (countBlue < countRed && countBlue < countGreen) 
    cadena_iteracion += "AZUL\n";
  else if (countGreen < countRed && countGreen < countBlue) 
    cadena_iteracion += "VERDE\n";
  else cadena_iteracion += "-\n";
  delay(3000);
  #endif*/
  #ifdef SERIAL_BLUETOOTH_ONLY_
  bluetoothSerial.write(cadena_iteracion.c_str());
  #endif
  #ifdef SERIAL_WIRED_ONLY_
  //Serial.println(cadena_iteracion.c_str());
  #endif
  ////////////////////////////////////////////////////////////
  ///////////        NODE    OPERATIONS     //////////////////
  ////////////////////////////////////////////////////////////
  /********************PSEUDOCODE*****************************
   * 1. ANT-ROBOTS CNY DETECTS WHITE IN BOTH CNYs
   * 2. MOVES STRAIGHT UNTIL BOTH CNYs DETECT BLACK
   * 3. DELAY 2 SECONDS
   * 4. READS COLOUR
   * 5. ANT-ROBOT CONTINUES FOLLOWING LINES
   */
   #ifdef NODE_OPERATIONS_
    if(cnys.bothWhite()){
      //Serial.println("both white");
      while(!cnys.bothBlack()){
          if(cnys.leftBlack())
            while(!cnys.bothBlack() && !cnys.bothWhite())
              motor.left(); 
          if(cnys.rightBlack())
            while(!cnys.bothBlack() && !cnys.bothWhite())
              motor.right();  
          while(cnys.bothWhite()) 
            motor.straight();
      }
      //Serial.println("1. ANT-ROBOTS CNY DETECTS WHITE IN BOTH CNYs");
      motor.botStop();      
    }
    //Serial.println("both black");
    if(cnys.leftWhite())
      if(cnys.leftWhite())
      while(!cnys.bothBlack() && !cnys.bothWhite())
        motor.right();
    if(cnys.rightWhite())
      while(!cnys.bothBlack() && !cnys.bothWhite())
        motor.left();   
     while(cnys.bothBlack()) 
        motor.straight();
     for(int i = 0; i < 50; ++i){
          #ifdef PROBAR_COLORES_
          digitalWrite(S2, LOW);
          digitalWrite(S3, LOW);
          countRed = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
          digitalWrite(S3, HIGH);
          countBlue = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
          digitalWrite(S2, HIGH);
          countGreen = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);         
          cadena_iteracion = "Contadores\n";
          cadena_iteracion += "Rojo: ";
          cadena_iteracion += String(countRed);
          cadena_iteracion += "\nAzul: ";
          cadena_iteracion += String(countBlue);
          cadena_iteracion += "\nVerde: ";
          cadena_iteracion += String(countGreen);
          cadena_iteracion += "\n"; 
          cadena_iteracion += "Color: ";
          if (countRed < countBlue && countRed < countGreen && countRed < 80) 
            cadena_iteracion += "ROJO\n";
          else if (countBlue < countRed && countBlue < countGreen) 
            cadena_iteracion += "AZUL\n";
          else if (countGreen < countRed && countGreen < countBlue) 
            cadena_iteracion += "VERDE\n";
          else cadena_iteracion += "-\n";
          #endif    
      }
      Serial.println(cadena_iteracion); 
   #endif
   #ifdef NEIGHBORS_
    /*********************************************************
     *        SEARCH FOR THE NEIGBORS                        *
     *********************************************************
     * 1. STOPS AND READS THE COLOUR
     * 2. THE ROBOT MAKES A SWEEP SEARCHING FOR ITS NEIGBORS
     * 3. CONTINUES THROUGH THE APPROPIATE PATH
     *********************************************************/
      bool continueFollowing = false;  
      while(!cnys.bothWhite()){
          if(cnys.leftWhite())
            while(!cnys.bothBlack() && !cnys.bothWhite())
              motor.right();   
          if(cnys.rightWhite())
            while(!cnys.bothBlack() && !cnys.bothWhite())
              motor.left();         
           while(cnys.bothBlack()) 
              motor.straight();
           continueFollowing = true;
      }  
      //Serial.println("both white");
      if(continueFollowing){
            continueFollowing = false;
            while(!cnys.bothBlack()) {
            if(cnys.leftBlack())
              while(!cnys.bothBlack() && !cnys.bothWhite())
                motor.right(); 
            if(cnys.rightBlack())
              while(!cnys.bothBlack() && !cnys.bothWhite())
                motor.left();
            while(cnys.bothWhite()) 
              motor.straight();
          }
          motor.botStop();
          for(int i = 0; i < 1000; ++i){
              digitalWrite(S2, LOW);
              digitalWrite(S3, LOW);
              countRed = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
              digitalWrite(S3, HIGH);
              countBlue = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
              digitalWrite(S2, HIGH);
              countGreen = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);     
              /*cadena_iteracion = "Contadores\n";
              cadena_iteracion += "Rojo: ";
              cadena_iteracion += String(countRed);
              cadena_iteracion += "\nAzul: ";
              cadena_iteracion += String(countBlue);
              cadena_iteracion += "\nVerde: ";
              cadena_iteracion += String(countGreen);
              cadena_iteracion += "\n";*/
          /*do
            motor.straight();
          while(!cnys.bothBlack());*/
        }
        cadena_iteracion += "Color: ";
        if (countRed < countBlue && countRed < countGreen && countRed < 80) 
          cadena_iteracion += "ROJO\n";
        else if (countBlue < countRed && countBlue < countGreen) 
          cadena_iteracion += "AZUL\n";
        else if (countGreen < countRed && countGreen < countBlue) 
          cadena_iteracion += "VERDE\n";
        else cadena_iteracion += "-\n";  
        Serial.println(cadena_iteracion);
        continueFollowing = true;
      }
      //Serial.println("1. ANT-ROBOTS CNY DETECTS WHITE IN BOTH CNYs");
      delay(5000);
      if(cnys.bothBlack() && continueFollowing){
        continueFollowing = false;
        motor.right();
        delay(2000);
        motor.straight();
        delay(1000);
        /*while(!cnys.bothBlack()){
          motor.straight();
        }
        motor.botStop();*/
      }
      //NEW aqui se decide si izquierda o dcha
      /*do
        motor.crossLeft();
      while(!cnys.bothWhite());
      delay(1000);
      do
        motor.straight();
      while(!cnys.bothBlack());
      delay(1000);*/
   #endif
   #ifdef TURN_AROUND_
    bool continueFollowing = true;
    if(continueFollowing){
          Serial.println("1 - Avanzo hasta encontrar negro, PRELECTURA");
            continueFollowing = false;
            while(!cnys.bothBlack()) {
            if(cnys.leftBlack())
              while(!cnys.bothBlack() && !cnys.bothWhite())
                motor.right(); 
            if(cnys.rightBlack())
              while(!cnys.bothBlack() && !cnys.bothWhite())
                motor.left();
            while(cnys.bothWhite()) 
              motor.straight();
          }
          motor.botStop();
          for(int i = 0; i < 1000; ++i){
              digitalWrite(S2, LOW);
              digitalWrite(S3, LOW);
              countRed = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
              digitalWrite(S3, HIGH);
              countBlue = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
              digitalWrite(S2, HIGH);
              countGreen = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
        }
        cadena_iteracion += "Color: ";
        if (countRed < countBlue && countRed < countGreen && countRed < 80) 
          cadena_iteracion += "ROJO\n";
        else if (countBlue < countRed && countBlue < countGreen) 
          cadena_iteracion += "AZUL\n";
        else if (countGreen < countRed && countGreen < countBlue) 
          cadena_iteracion += "VERDE\n";
        else cadena_iteracion += "-\n";
        Serial.println("2 - Lectura de color");
        Serial.println(cadena_iteracion);
        continueFollowing = true;
      }
      motor.right();
      motor.backRight();
      delay(3650);
      motor.botStop();
      if(continueFollowing){
          Serial.println("3 - Avanzo hasta encontrar negro, POSTLECTURA");
            continueFollowing = false;
            while(!cnys.bothBlack()) {
            if(cnys.leftBlack())
              while(!cnys.bothBlack() && !cnys.bothWhite())
                motor.right(); 
            if(cnys.rightBlack())
              while(!cnys.bothBlack() && !cnys.bothWhite())
                motor.left();
            while(cnys.bothWhite()) 
              motor.straight();
          }
          motor.botStop();
      }
      while(!cnys.bothWhite()){
          Serial.println("4 - Siguelinea");
          if(cnys.leftWhite())
            while(!cnys.bothBlack() && !cnys.bothWhite())
              motor.right();
          if(cnys.rightWhite())
            while(!cnys.bothBlack() && !cnys.bothWhite())
              motor.left();
           while(cnys.bothBlack()) 
              motor.straight();
           continueFollowing = true;
      }     
   #endif
   #ifdef FOLLOW_BLACK_LINES_
    while(!cnys.bothWhite()){
          Serial.println("4 - Siguelinea");
          if(cnys.leftWhite())
            while(!cnys.bothBlack() && !cnys.bothWhite())
              motor.right();
          if(cnys.rightWhite())
            while(!cnys.bothBlack() && !cnys.bothWhite())
              motor.left();       
           while(cnys.bothBlack()) 
              motor.straight();
           Serial.print("RIGHT: ");
           Serial.println(analogRead(CNY_RIGHT));
           Serial.print("LEFT: ");
           Serial.println(analogRead(CNY_LEFT));
      }
    #endif
    #ifdef GRADES_
      //90º RIGHT
      motor.right();
      motor.backRight();
      delay(1150);
      motor.botStop();
      delay(5000);
      //90º LEFT
      motor.left();
      motor.backLeft();
      delay(1200);
      motor.botStop();
      delay(5000);
      //180º
      motor.right();
      motor.backRight();
      delay(2300);
      motor.botStop();
      delay(5000);
    #endif
}
#endif
