
#include "calculate.hpp"
#include <string>
#include <iostream>
using std::string;

string bullpgia::calculateBullAndPgia(string choose, string gusses){
    int pgia=0;
    int bull=0;
    int stringLength=choose.size();
    int arr[10]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0; i<stringLength;i++){
        arr[choose.at(i)-48]++;
    }
    for(int i=0; i<choose.length(); i++){
          if(choose.at(i)==gusses.at(i)){
             bull++;
             arr[choose.at(i)-48]--;
          }
    }
    for(int i=0; i<gusses.length(); i++){
         if(arr[gusses.at(i)-48]>0&&(gusses.at(i)-48)!=(choose.at(i)-48)){
             pgia++;
             arr[gusses.at(i)-48]--;
         }
    }
    string ans=std::to_string(bull)+","+std::to_string(pgia);
    return ans;
}
