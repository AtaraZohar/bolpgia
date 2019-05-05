
#include "calculate.hpp"
//#include <string>
//#include <iostream>
using std::string, std::to_string ,std::fill ;


string bullpgia::calculateBullAndPgia(string choose, string gusses){
    int stringLength=choose.size();
    int pgia=0;
    int bull=0;
    int arr[10];
    for(int i=0;i<stringLength;i++){
        arr[choose.at(i)-48]++;
    }
    for(int i=0;i<choose.length(); i++){
          if(choose.at(i)==gusses.at(i))
          {
             bull++;
             arr[choose.at(i)-48]--;
          }
    }
    for(int i=0;i<gusses.length(); i++){
        if(arr[choose.at(i)-48]>0){
            pgia++;
            arr[choose.at(i)-48]--;
        }

    }
    string ans= to_string(bull) + "," + to_string(pgia); 
    return ans;
}

