
// #include "Guesser.hpp"
// #include <iostream>
// #include <stdlib.h>
// using namespace std;
//#pragma once
#include <iostream> 
#include "SmartGuesser.hpp"
#include "calculate.hpp"
#include <list> 
#include <iterator> 
using namespace std; 


 bullpgia::SmartGuesser::SmartGuesser(){
            this->myTry = "0000";
            this->numOfBull = 0;
            this->numOfPgia = 0;
     }

    string  bullpgia::SmartGuesser::guess() {
             this->myTry= this->allOptions.front();
         return this->myTry;
    }



  void bullpgia::SmartGuesser::learn(string firstTry){

      for (auto itr = allOptions.begin(); itr != allOptions.end(); itr++)
    {
        if (firstTry != calculateBullAndPgia(myTry, *itr))
        {
            itr = allOptions.erase(itr);
        }
    }

}

void bullpgia::SmartGuesser::startNewGame(uint length){
    SmartGuesser();
    if (!allOptions.empty())
    {
        allOptions.clear();
    }

    if (length==4){
    for(int i=0 ;i<=9; i++){ 
			for(int k=0 ;k<=9; k++){
				for(int w=0 ;w<=9; w++){
					for(int j=0 ;j<=9; j++){
						string ans= to_string(i) + to_string(k) + to_string(w)+ to_string(j) ; 
						this->allOptions.push_back(ans);
					}
				}
			}
        }
    }
    if (length==3){
			for(int k=0 ;k<=9; k++){
				for(int w=0 ;w<=9; w++){
					for(int j=0 ;j<=9; j++){
						string ans=to_string(k) + to_string(w)+ to_string(j) ; 
						this->allOptions.push_back(ans);
					}
				}
			}
    }
    if (length==2){
				for(int w=0 ;w<=9; w++){
					for(int j=0 ;j<=9; j++){
						string ans=to_string(w)+ to_string(j) ; 
						this->allOptions.push_back(ans);
					}
				}
			}
    if (length==1){
			for(int j=0 ;j<=9; j++){
				string ans=to_string(j) ; 
				this->allOptions.push_back(ans);
			}
		}		
};