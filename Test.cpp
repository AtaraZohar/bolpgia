/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
	  ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"},c5848{"5848"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"}, g58{"58"},g584844{"584844"},g58484{"58484"},g5848{"5848"};
		RandomChooser rchooser;
	  SmartGuesser schooser;

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		//my tests
		testcase.setname("Calculate bull and pgia with no errors")
		.CHECK_OUTPUT(calculateBullAndPgia("1111","1111"), "4,0")      
		.CHECK_OUTPUT(calculateBullAndPgia("2222","2222"), "0,4")     
		.CHECK_OUTPUT(calculateBullAndPgia("1223","4225"), "2,4")     
		.CHECK_OUTPUT(calculateBullAndPgia("1","1"), "1,0")     
		.CHECK_OUTPUT(calculateBullAndPgia("5567","7569"), "2,0")     
		.CHECK_OUTPUT(calculateBullAndPgia("5663","6583"), "0,2")  
		.CHECK_OUTPUT(calculateBullAndPgia("3698","8963"), "0,4")  
		.CHECK_OUTPUT(calculateBullAndPgia("5201","4321"), "0,2")  
		.CHECK_OUTPUT(calculateBullAndPgia("6543","1258"), "0,1")  
		.CHECK_OUTPUT(calculateBullAndPgia("9546","4321"), "0,0")  
		.CHECK_OUTPUT(calculateBullAndPgia("56","65"), "0,2")    
		.CHECK_OUTPUT(calculateBullAndPgia("25894","28795"), "1,4")   
		.CHECK_OUTPUT(calculateBullAndPgia("98","12"), "0,0")    
		.CHECK_OUTPUT(calculateBullAndPgia("000555","888999"), "0,0")        
		;

		 testcase.setname("Calculate bull and pgia with wrong length")
		.CHECK_OUTPUT(calculateBullAndPgia("1111","11"), "2,0")      
		.CHECK_OUTPUT(calculateBullAndPgia("159","1596"), "3,0")     
		.CHECK_OUTPUT(calculateBullAndPgia("6589","1568458"), "0,3")     
		.CHECK_OUTPUT(calculateBullAndPgia("1","11111"), "1,0")     
		.CHECK_OUTPUT(calculateBullAndPgia("369","7410"), "0,0")     
		.CHECK_OUTPUT(calculateBullAndPgia("7965","014758"), "0,1")       
		;

		testcase.setname("worng guesser length")
		.CHECK_EQUAL(play(c5848, g58, 4, 100), 0)
		.CHECK_EQUAL(play(c5848, g584844, 4, 100), 0) 
		.CHECK_EQUAL(play(c5848, g58484, 4, 100), 0)  
		.CHECK_EQUAL(play(c5848, g12345, 4, 100), 0)
		;

		testcase.setname("worng chooser length") 
		.CHECK_EQUAL(play(c5848, g58, 2, 100), 0)
		.CHECK_EQUAL(play(c5848, g584844, 6, 100), 0) 
		.CHECK_EQUAL(play(c5848, g58484, 5, 100), 0)  
		.CHECK_EQUAL(play(c5848, g12345, 5, 100), 0) 
		;

			testcase.setname("correct guessers")
		.CHECK_EQUAL(play(c12345, g12345, 4, 100), 1)
		.CHECK_EQUAL(play(c9999, g9999, 4, 100), 1)
		.CHECK_EQUAL(play(c5848, g5848, 4, 100), 1)
		;

		 testcase.setname("Test Play With Random ")
	   .CHECK_EQUAL(play(rchooser, schooser, 5, 100)<=6, true)  
	   .CHECK_EQUAL(play(rchooser, schooser, 5, 100)<=100, true)   		  		 
     .CHECK_EQUAL(play(rchooser, schooser, 3, 100)<=1, false)
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}

				SmartGuesser gg;
		gg.learn("4,5");
		cout<<endl;
		cout<<"oeriyfeldgc"<<gg.numOfPgia<<endl;

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}