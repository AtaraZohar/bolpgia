#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
using std::string;
#include <vector> 
using namespace std; 

 namespace bullpgia {
class SmartGuesser: public bullpgia::Guesser{
    public:
    int numOfPgia;
    int numOfBull;
    vector<string> allOptions;

    
    SmartGuesser();
    string guess() override;
     void learn(string firstTry) override;
};
}