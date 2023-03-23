/* 
  userInteract.h
  Header file by Isiah Torres
  Contains functions that prompt user interaction and stores/returns values.
                                                                            */
//==============================================================
// Include guard
#ifndef __USERINTERACT_H_INCLUDED__     // if userinteract.h hasnt been included yet...
#define __USERINTERACT_H_INCLUDED__     // #define this file so the compiler knows its included

//==============================================================
// Preprocessor directives
#include "weapons.h"
using namespace std; // to use string

//==============================================================
// Global Variables
static string user; // global variable, needs to be static to be seen in all files.

//==============================================================
//Function prototypes
// This function returns a string type value, requires a string to be passed as a parameter.  
string welcomeUser(const string title); // Parameter is a constant. The value cannot be changed.

// This function is a string type and requires a string parameter.
string askText(const string prompt); // Parameter is a constant.

// Function returns an integer type and requires a string to be passed as a parameter.
int askNum(const string prompt); // constant parameter

// Function returns a character type value and requires two string paramaters and one optional.
// if not paramater is passed for 'prompt', the default value will equal "Please choose."
// These parameters are constants.
char choice(const string choice1, const string choice2, const string prompt = "Please choose.");

// provides user with menu of actions
void menu();

// This function is a void type as well. 
void story();

// This function returns a float type value and requires a float as a parameter. 
float dropHealth(float* const health); // takes a pointer as an arguement
//==========================================================
//inline function definition
// create a pause that requires the user input to continue.
// void, no value is returned. Universal, not just a WindowsOS system pause.
inline void promptNext() // inline to ask compiler for optimization
{
    cout << "\nPress ENTER to continue...";
    cin.ignore();  /* Will empty the buffer,
				    used if user input is requested prior to use of cin.get(). */
    cin.get(); // Waits for user input in order for the program to move forward.
    // user has to press enter twice until user input is requested before this function.
    //TODO: Does not completely work as intended
}

#endif // __USERINTERACT_H_INCLUDED__  end of if statement, will skip over file if already included.