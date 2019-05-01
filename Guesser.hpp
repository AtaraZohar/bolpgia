#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
using std::string;

namespace bullpgia {
class Guesser{

    public:
    unsigned int length;
    string  myTry;
   

        virtual string guess()=0;
        virtual void learn(string myTry2){
            this->myTry=myTry2;

        }
        virtual void startNewGame(uint length){
            this->length=length;
        }
    };
}