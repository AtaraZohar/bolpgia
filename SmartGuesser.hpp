#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
using std::string;

 namespace bullpgia {
class SmartGuesser: public bullpgia::Guesser{
    string guess() override;
};
 }