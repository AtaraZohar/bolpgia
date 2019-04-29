#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
using std::string;

namespace bullpgia {
class Guesser{

    public:
    unsigned int length;
    string firstTry;

        virtual string guess()=0;
        virtual void learn(string firstTry){}
        virtual void startNewGame(uint length){}
    };
}