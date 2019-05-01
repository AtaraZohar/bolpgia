
// #include "Guesser.hpp"
// #include <iostream>
// #include <stdlib.h>
// using namespace std;
//#pragma once
#include "SmartGuesser.hpp"
 #include <iostream>


 bullpgia::SmartGuesser::SmartGuesser(){
            this->myTry = "0000";
            this->numOfBull = 0;
            this->numOfPgia = 0;

        }

  void bullpgia::SmartGuesser::learn(string firstTry){


      string sbull= firstTry.substr(0,firstTry.find(","));
      int ibull= stoi(sbull);

      string spgia= firstTry.substr(firstTry.find(",")+1,firstTry.length());
      int ipgia= stoi(spgia); 

      this->numOfBull=ibull;
      this->numOfPgia=ipgia;

}