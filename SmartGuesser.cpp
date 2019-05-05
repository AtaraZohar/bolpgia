
// #include "Guesser.hpp"
// #include <iostream>
// #include <stdlib.h>
// using namespace std;
//#pragma once
#include <iostream> 
#include "SmartGuesser.hpp"
#include "calculate.hpp"
#include <vector> 
using namespace std; 


 bullpgia::SmartGuesser::SmartGuesser(){
            this->myTry = "0000";
            this->numOfBull = 0;
            this->numOfPgia = 0;
     }

    string  bullpgia::SmartGuesser::guess() {
             this->myTry= this->allOptions.front();
             int i=0;
             for (std::vector<string>::iterator it = allOptions.begin() ; it != allOptions.end(); ++it){
                 i++;
                    string answer=calculateBullAndPgia(this->myTry,this->allOptions.at(i));
                   if((stoi(answer.substr(0,answer.find(",")))!= this->numOfBull )|| (stoi(answer.substr(answer.find(",")+1,answer.length()))!=this->numOfPgia)){
                       //0this->allOptions.remove(this->allOptions.at(i));
                       this->allOptions.erase(it);
                   }
               }
             
         return this->myTry;
    }



  void bullpgia::SmartGuesser::learn(string firstTry){

      string sbull= firstTry.substr(0,firstTry.find(","));
      int ibull= stoi(sbull);

      string spgia= firstTry.substr(firstTry.find(",")+1,firstTry.length());
      int ipgia= stoi(spgia); 

      this->numOfBull=ibull;
      this->numOfPgia=ipgia;

}
void bullpgia::SmartGuesser::startNewGame(uint length){
    SmartGuesser();
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
						string ans= to_string(i) + to_string(k) + to_string(w)+ to_string(j) ; 
						this->allOptions.push_back(ans);
					}
				}
			}
    }
    if (length==2){
				for(int w=0 ;w<=9; w++){
					for(int j=0 ;j<=9; j++){
						string ans= to_string(i) + to_string(k) + to_string(w)+ to_string(j) ; 
						this->allOptions.push_back(ans);
					}
				}
			}
    if (length==1){
			for(int j=0 ;j<=9; j++){
				string ans= to_string(i) + to_string(k) + to_string(w)+ to_string(j) ; 
				this->allOptions.push_back(ans);
			}
		}		
};