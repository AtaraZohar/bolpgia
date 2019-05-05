#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
using std::string;

 namespace bullpgia {
class SmartGuesser: public bullpgia::Guesser{
    public:
    int numOfPgia;
    int numOfBull;
    
    SmartGuesser();
    string guess() override{
        return " ";
    };
     void learn(string firstTry) override;
};
}