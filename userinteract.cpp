/* userInteract.cpp source code file by Isiah Torres
* Contain function definitions that prompt user interaction and stores/returns values.*/
//============================================================
// Included Dependencies
// Use #include to attach header files, the <iostream> file controls input and output.
#include <iostream>
// the <string> file has elements that deals with string types.
#include <string>
// we need to include our custom header files which contains function prototypes and classes.
#include "userinteract.h" // these are files that are created ourselves so it is in "" with the .h extension.

#include "weapons.h" 

#include "guns.h"

// Gets our elements from the standard library without having to type 'std::<element>'
using namespace std;
//=============================================================
// Variables 
float health = 100.0; // created a float variable
float* const pHealth = &health; // creates a constant pointer for health 
    
const string& rUser = user; // constant reference for user

//=============================================================
// Function definitions
// Asks user a question then returns the answer as a string type.
// prompt is the name of the parameter. 
string askText(const string prompt)
{
	//creates a string type variable named 'text'
	string text;
	while (text == "")
    	{
        	// sends string parameter that was passed to the output (or screen).
        	cout << prompt;
        	// getline() extracts characters from a source and then stores them into a string value.
        	// the first parameter 'cin' is the source, and 'text' was where the value was stored. 
        	// This allows white space to be captured from user input.
        	getline(cin, text);
            //return the string value of 'text' 
        }
	return text;
}

// Asks a question then returns the answer back as a integer type.
int askNum(const string prompt)
{
	// creates a integer variable
	int num; 
    {
    	// displays value of prompt to user
    	cout << prompt;
    	// user input is stored as 'num'
    	cin >> num;
    	// return integer value.
    }
    return num;
}

// Present a user with two choices, an optional question, and return the decision as a char value.
char choice(const string option1, const string option2, const string prompt)
{
	// create a char value type variable
	char answer;
	// use do loop to ensure the user only chooses a or b.
	do
	{
		// \n is special character for "new line" and \t is for "tab"
		// displays options to user.
		cout << "\n\ta. " << option1 << endl;
		cout << "\tb. " << option2 << endl;
		// Displays custom or default message to user.
		cout << prompt << " (a or b): ";
		// user makes decision with input
		cin >> answer;

		// Will continue unitl user selects 'a' or 'b'.
		// != is not equal to, && is the AND operator meaning run loop while not equal to a AND b. 
	} while (answer != 'a' && answer != 'b');
	
	// return which decision was made. if answer = 'a' then option1 was chose, not then option2 was chosen.
	return answer;
}

// Inflict damage or reduce total health.
// float types deal with fractional number or decimals. 
float dropHealth(float* const health) // takes a pointer as a parameter
{
	// create a float variable and assign it to the answer of this math problem.
	// access the value of the parameter 'health' to perform math.
	// math in the () is done first, then / division, then - subtraction.
	float newHealth = *health - (100.0 / 3.1);
	// return the float value
	return newHealth;
}

// Present title of program and ask for username.
// returns name as a string.
string welcomeUser(const string title)
{
	// Display title first
	cout << "\n\n### " << title << " ###\n\n";
	// prompt user
	cout << "Enter your name: ";
	// use getline() to allow user to name themselves anything.
	getline(cin, user);
	// return string value
	return user;
}

// Pops up a menu for the user 
void menu()
{	
    int choice; // user's decision
    bool success = false; 
	do // Loops until user chooses continue or quit
	{
	cout << "\n1. Check Health" << "\t2. Continue";
	cout << "\n3. Quit";
	cin >> choice;
	switch(choice) // used switch for decisions (much cleaner than if statements) 
        {
            case 1: cout << "\n" << rUser << ": " << *pHealth; // prints username along with current health
            break;

            case 2 : ;
            success = true; // exits loop and continues with program
            break;

            case 3 : exit(0); // exit() is used to end the program entirely.
            break;
        }
    } while (!success); // !success is true, when !success is false, loop ends
}

// puts the story together and prints it.
void story()
{
	// displays text to the user
	cout << "\n\nYEAR 3051";
    promptNext(); // create a pause with promptNext()

	cout << "\n\n** You slowly start waking up.**\n";
	promptNext(); 
		
	cout << "** You hear alarms, explosions, and gunfire.**\n";
	cout << "** Your head hurts and you don't remember anything.**\n";
	cout << "** Suddenly someone with a familiar voice yanks you to your feet.**\n";
	cout << "** You're alert and now face to face with a woman in a black uniform**\n\n";
	promptNext();

	// take the value of user from welcomeUser() and plug it in throughout the story.
	cout << "UNKNOWN: Commander " << rUser << ", WE HAVE TO GO! NOW\n\n"; // use reference to display user's value
	cout << "\tHealth: %" << *pHealth; // Display the current value of the float 'health' with a dereference pointer

	// Plug in names to simulate dialogue
	cout << "\n\n" << rUser << ": Who are you? What's going on?!";
	promptNext(); 

	cout << "\nUNKNOWN: You really don't remember who I am?";
	cout << "\nUNKNOWN: Look, right now we don't have time for this. This ship is gonna blow.";
	cout << "\nUNKNOWN: We have to head to the dock, take a patrol ship, and get the hell out.";
	cout << "\nUNKNOWN: Ill explain everything in a sec. MEN LETS MOVE!";
	
	Weapons Pipe("Steel Pipe", "Melee", "Common", ""); // created a Weapon called Pipe and assigned values with its constructor.
	promptNext();
	cout << "You pick up a" << Pipe.GetWpnName() << ".\n"; // I use Pipe.GetWpnName() to use class method to display/access private data members

	cout << "\n**You turn around and see a platoon of troops running up to you and the woman.**";
	cout << "\n**The troops are dressed in black armor and helmets, all holding energy weapons.**";
	cout << "\n**They run past you both and continue down the sleek metallic hall.**";
	cout << "\n**The woman follows them and so do you.**";
	cout << "\n**As you're running, you look over and notice the woman's gun on her hip**.";
	cout << "\n**You look down at yourself and you have nothing...**";
	cout << "\n**but you notice that you're in a gray jumpsuit with a number on your sleeve.**";
	cout << "\n\n"; // create some space with \n newline character

	// create int variable
	int userNum;
	// use a do loop to keep the user stuck here until a valid answer is given.
	do
	{
		// use askNum to ask user for input then assign it as a variable.
		userNum = askNum("Pick any number equal to or less than 999. ");

		// keeps looping until the number is equal to or less than 999.
	} while (userNum > 999);

	// plug in the number passed from the user. 
	cout << "\n**The number " << userNum << " is there, under it is the name " << rUser << ".**";
	cout << "\n**There is a patch on the other sleeve that reads, 'HIGHEST COMMAND'--**";

	menu(); // pop up menu to show menu functionality
	

	cout << "\n\n**While you were looking at yourself, an explosion occurs in the hallway.**";
	cout << "\n**The ship is shaking, some of the roof collapsed, and now theres small fires.**";
	cout << "\n**The explosion knocks you and the woman down to the ground.**";
	cout << "\n**You start to get up when you see you've landed between two soldiers bodies.**";
	cout << "\n**You look up and the entire platoon of soldiers that were in front are dead.**";
	

	cout << "\n\n**You are unharmed**.";
	promptNext();

	cout << "\n\n**To your right, you see two guns on the floor, an energy pistol and rifle.**\n";
	// present user with a decision to make, the choice is saved in the character type variable.
	// a custom message is specified as the third parameter.
	// create two new objects belonging to the Guns class, child class of Weapons.
	// used Guns constructor (Guns()) to assign values to objects
	Guns EnergyPistol("Energy Pistol", "Energy Firearm", "Rare", "After Burn", "Pew Pew Pew", 40, 100, 100);
	Guns EnergyRifle("Energy Rifle", "Energy Firearm", "Rare", "Melt Shot", "BRRRRDD, DOO DOO DOO", 50, 100, 40);
	char decision1 = choice("Energy Pistol", "Energy Rifle", "Which weapon do you grab?");
	Guns weapon; // We decide what weapon the user will use based on that character
	if (decision1 == 'a')
	{
	    weapon = EnergyPistol; // if decision is 'a', then user chose option1.
	    // weapon gets assigned an object
	}
	else 
	{
	    weapon = EnergyRifle; // if 'b', the user chose option2.
	}
	// plug in the value we got from the decision made by the user.
	// since m_WpnName is a private data member of the class, we access the value with a get method
	// can plug in the dot operator after the variable we create to simulate the object calling the method.
	cout << "\n**You picked up the " << weapon.GetWpnName() << ". It feels good in your hands.**";
	
	weapon.Display(); // use display method to show user the object and its properties.
	
	cout << "\n\n**Two guards approach from behind, shooting.**";
	// another decision is presented to the user, this time using the default value for parameter 3.
	char decision2 = choice("left", "right");
	// creates a variable for both answers
	string direction1;
	string direction2;
	// if user picks option 1, assign the option as direction1 and the other as direction2.
	if (decision2 == 'a')
	{
		direction1 = "left";
		direction2 = "right";
	}
	// Otherwise, assign option2 as direction1 and option1 as direction2.
	else
	{
		direction1 = "right";
		direction2 = "left";
	}
	// plug in the options into the story. 
	// variables we captured from the user are plugged into the output.
	cout << "\n\n**You raise your " << weapon.GetWpnName() << " and shoot the one on the " << direction1 << ".**";
	cout << "\n\n**Immediately after, a blast comes from behind you...**";
	cout << "\n\n**It flies past you and hits the guard on the " << direction2 << ".**";
	cout << "\n**The shot was fired by the woman.**";
	promptNext();
	

	// sets up for a question.
	cout << "\n" << rUser << ": Thanks... why don't I know your name?"; // rUser is a constant reference, not a copy.
	// asks user to input a string value with a question.
	// this allows the user to name their companion themselves and plugs the value into the story.
	string ally = askText("\nEnter a name for your ally. "); // user inputs their own value for ally
	const string& rAlly = ally; // constant reference for ally for efficiency. // create a constant reference for this characters name
	// Now dialogue looks like the character is going by the name given.
	cout << "\n" << rAlly << ": How do you not remember me?\n"; // plug in the characters name through constant reference
	cout << "\n" << rAlly << ": Its me, " << rAlly << ", your childhood friend and right hand Commander.";
	cout << "\n" << rAlly << ": Come one lets go theres not much time!";

	cout << "\n**You and " << rAlly << " run past the bodies and debris down the hall.**";
	cout << "\n**You see the doors to the dock in sight.**";
	cout << "\n**As you're running down the hall, you start having various flashbacks.**";
	cout << "\n**Your remember " << rAlly << " saving you before, in fact you've saved each other.**";
	cout << "\n**As you both are moving toward the dock doors, a guard stepped through.**";


	cout << "\n**The guard starts shooting their energy rifle at " << rAlly << ".**";
	// presents the user with another decision.
	// the first parameter includes the value of another string by using the append operator +.
	char decision3 = choice("Save " + rAlly, "Shoot back", "What do you do?");
	if (decision3 == 'a')
	{
		// If option1 was chosen, print this event happening in the story.
		cout << "\n\n**You dive and grab " << rAlly << " out of the way.**";
		cout << "\n**However, a blast hit your leg on the way down.**";
		// call dropHealth() to reduce the value of 'health' and simulate taking damage.
		*pHealth = dropHealth(pHealth); // passed a pointer as a parameter
		// print the new value of health to the screen.
		cout << "\nHealth: " << *pHealth; // display dereferenced pointer
		cout << "\n**You and " << rAlly << " pop up shooting from behind cover and finished off the guard**";
	}
	else
	{
		// otherwise print this story if option2 was chosen.
		cout << "\n\n**You draw your weapon with fire in your eyes and shoot back at the guard.**";
		cout << "\n**The guard was dropped swiftly. Thankfully, " << rAlly << " took cover.**";
	}


	cout << "\n**You and " << rAlly << " walk through the dock doors and look at each other.**";
	cout << "\n" << rUser << ": So, what happens next?";

	promptNext(); 
	
	cout << "\n\n### End of Act I ###";

}