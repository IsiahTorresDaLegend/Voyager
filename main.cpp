/*  Interactive Simulation using functions (refactored)
    Voyager by Isiah Torres
    Interactive Fiction game 
    
    ACT I:                                              */

// Use #include to attach header files, the <iostream> file controls input and output.
#include <iostream>
// the <string> file has elements that deals with string types.
#include <string>
// we need to include our custom header file which contains function prototypes.
#include "userinteract.h" // this is a header file that was created ourselves so it is in "" with the .h extension.

#include "weapons.h" // Include the header file I made

#include "guns.h"   // Include another header file I made "" are used for file names

// Gets our elements from the standard library without having to type 'std::<element>'
using namespace std;

// Main function is what makes the program work. This is what runs and controls the functions.
int main()
{
	// we assign a value to 'user' with the welcomeUser() function.
	// To obtain username from user's input.
	user = welcomeUser("VOYAGER"); // A string "VOYAGER" is passed. 
	
	// calls the story() function which will just print to the screen.
	story();

	// ends program.
	return 0;
}

