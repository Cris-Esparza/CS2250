#include <iostream>
#include <string>
#include <vector>
#include "Trophy.h"
using namespace std;

// Reusable strings
const string PROMPT_FOR_NAME = "Please enter the name of the Trophy";
const string PROMPT_FOR_LEVEL = "Please enter the level of your Trophy (between 1 and 10)";
const string PROMPT_FOR_COLOR = "Please enter the color of your Trophy (GOLD, SILVER, or BRONZE)";

// Menu choice handlers
void addTrophy(/* TODO: vector of trophies */vector<Trophy> trophies);
void copyTrophy(/* TODO: vector of trophies */vector<Trophy> trophies);
void deleteTrophy(/* TODO: vector of trophies */vector<Trophy> trophies);
void renameTrophy(/* TODO: vector of trophies */vector<Trophy> trophies);
void relevelTrophy(/* TODO: vector of trophies */vector<Trophy> trophies);
void recolorTrophy(/* TODO: vector of trophies */vector<Trophy> trophies);
void printTrophies(/* TODO: vector of trophies */vector<Trophy> trophies);

// Input handlers
int printMenu();
/* TODO: Return a Trophy instead of void */
Trophy promptForTrophy();
string promptForString(const string& message);
int promptForInt(const string& message, int minimum, int maximum);
/* TODO: Return a color instead of void */
Color promptForColor(const string& message);

// Useful helper methods
string stringToUpper(string value);
int searchForTrophy(/* TODO: vector of trophies, name of a trophy  */);

// This application allows for the management of a trophy collection
int main()
{
	cout << "***********************************************" << endl
		<< "Welcome to the Trophy editor!" << endl
		<< "With this application, you can manage your trophy" << endl
		<< "collection - add, modify, or remove trophies by" << endl
		<< "using this simple menu!" << endl
		<< "***********************************************" << endl;

	// TODO: Create a vector of Trophy objects
	vector<Trophy> trophies;
	
	// Loop the menu, allowing the user to select an action each time
	int input;
	do
	{
		input = printMenu();
		switch (input)
		{
		case 1:		// Add a new Trophy
			addTrophy(/* collection of trophies  */trophies);
			break;
		case 2:		// Copy an existing Trophy
			copyTrophy(/* collection of trophies  */trophies);
			break;
		case 3:		// Delete an existing Trophy
			deleteTrophy(/* collection of trophies  */trophies);
			break;
		case 4:		// Rename a Trophy
			renameTrophy(/* collection of trophies  */trophies);
			break;
		case 5:		// Change the level of a Trophy
			relevelTrophy(/* collection of trophies  */trophies);
			break;
		case 6:		// Change the color of a Trophy
			recolorTrophy(/* collection of trophies  */trophies);
			break;
		case 7:		// Print all Trophies
			printTrophies(/* collection of trophies  */trophies);
			break;
		case 8:		// Exit
			cout << "You have chosen to exit the application, good-bye!" << endl;
			break;
		default:
			cout << "That is not a recognized menu selection, choose again." << endl;
			break;
		}

	} while (input != 8);

	return 0;
}

// Print the menu to the user and accept their menu choice
int printMenu()
{
	int input;
	cout << "-----------------------------------------" << endl
		<< "Please select an option :" << endl
		<< "1 - Add a new Trophy" << endl
		<< "2 - Copy a Trophy" << endl
		<< "3 - Delete a Trophy" << endl
		<< "4 - Rename a Trophy" << endl
		<< "5 - Change the level of a Trophy" << endl
		<< "6 - Change the color of a Trophy" << endl
		<< "7 - Print All the Trophies" << endl
		<< "8 - Exit the program" << endl
		<< "-----------------------------------------" << endl;
	cin >> input;
	cin.ignore();
	return input;
}

// Add a new Trophy to the collection
void addTrophy(/* TODO: vector of trophies */vector<Trophy> trophies)
{
	cout << "You have chosen to add a trophy." << endl;
	// TODO: Ask the user for the Trophy info (hint: there's a function for this...) and add it to the vector
	Trophy trophy = promptForTrophy();
	trophies.push_back(trophy);
}

// Delete an existing Trophy from the collection
void deleteTrophy(/* TODO: vector of trophies */vector<Trophy> trophies)
{
	cout << "You have chosen to delete an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	// TODO: Find the trophy and if it exists, erase it to the vector
}

// Copy an existing Trophy in the collection
void copyTrophy(/* TODO: vector of trophies */vector<Trophy> trophies)
{
	cout << "You have chosen to copy an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	// TODO: Find the trophy and if it exists, copy it and add the copy to the vector
}

// Rename an existing Trophy (change the name)
void renameTrophy(/* TODO: vector of trophies */vector<Trophy> trophies)
{
	cout << "You have chosen to rename an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	// TODO: Find the trophy and if it exists, change its name
}

// Relevel an existing Trophy (change the level)
void relevelTrophy(/* TODO: vector of trophies */vector<Trophy> trophies)
{
	cout << "You have chosen to change the level of an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	// TODO: Find the trophy and if it exists, change its level
}

// Recolor an existing Trophy (change the color)
void recolorTrophy(/* TODO: vector of trophies */vector<Trophy> trophies)
{
	cout << "You have chosen to change the color of an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	// TODO: Find the trophy and if it exists, change its color
}

// Print all of the Trophies in the collection
void printTrophies(/* TODO: vector of trophies */vector<Trophy> trophies)
{
	cout << "You have chosen to print all of the trophies." << endl;
	// TODO: Print all the trophies in the order they are stored in the vector
}

// Ask the user for a Trophy, validate their responses
// Return the Trophy
Trophy /* TODO: Return a Trophy instead of void */ promptForTrophy()
{
	string name = promptForString(PROMPT_FOR_NAME);
	int level = promptForInt(PROMPT_FOR_LEVEL, 1, 10);
	/* TODO: Store the color the user selected  */
	Color trophyColor = promptForColor(PROMPT_FOR_COLOR);

	// TODO: Create a new trophy with the above info
	Trophy trophy(name, level, trophyColor);
	// TODO: Return a Trophy
	return trophy;
}

// Ask the user for a string, validate their response
// Return the string
string promptForString(const string& message)
{
	string value;
	cout << message << endl;
	// TODO: read in the trophy name
	// TODO: while the user has not entered any characters
	if (getline(cin, value))
	{
		if (value.empty())
		{
			cout << "That is not a valid name.  Try again.";
		}
	}
	// TODO: read in the trophy name
	return value;
}

// Ask the user for an int, validate their response by
// checking that it is between minimum and maximum values
// Return the int
int promptForInt(const string& message, int minimum, int maximum)
{
	int value;
	cout << message << endl;
	// TODO: read in a level number
	// TODO: while the level number is not between the minimum and maximum (inclusive)
	do
	{
		cin >> value;
		if (value < minimum || value > maximum)
		{
			cout << "That value is outside the acceptable range.  Try again." << endl;
		}
	} while (value < minimum || value > maximum);
	// TODO: read in a level number
	return value;
}

// Convert a string to all uppercase (so that we can compare the
// user's entered color to the official color)
string stringToUpper(string value)
{
	// TODO: Convert the string parameter into all uppercase
	int i = 0;
	char c;
	while (value[i]) {
		c = value[i];
		putchar(toupper(c));
		i++;
	}
	return value;
}

// Ask the user for a color, validate the response
// Return the color
Color /* TODO: Return a color instead of void */ promptForColor(const string& message)
{
	/* TODO: Create a Color variable */
	string value;
	Color trophyColor = Color :: COPPER;
	cout << message << endl;
	
	// TODO: while the color is not acceptable
	do
	{
		// TODO: read in the color
		cin >> value;
		stringToUpper(value);
		// TODO: If the color is  GOLD, SILVER, or BRONZE (hint: case insensitive!)
		// TODO:    convert the string color into the enumerated type Color
		if (value.compare("GOLD"))
		{
			trophyColor = Color :: GOLD;
		}
		else if (value.compare("SILVER"))
		{
			trophyColor = Color :: SILVER;
		}
		else if (value.compare("BRONZE"))
		{
			trophyColor = Color :: BRONZE;
		}
		else
		// TODO: otherwise, print an error
		{
			cout << "That is not an acceptable color.  Try again." << endl;
		}
	} while (trophyColor == Color :: BRONZE || trophyColor == Color :: SILVER || trophyColor == Color :: GOLD);
	cin.ignore();
	/* TODO: Return the Color that the user selected */
	return trophyColor;
}

// Search for a trophy in the collection by name
int searchForTrophy(/* TODO: vector of trophies, name of a trophy  */)
{
	// TODO: Find the trophy in the collection by its name
	// TODO: If you find the trophy, return its position in the collection
	// TODO: if the trophy was not found, print this error, return -1
	cout << "ERROR: The Trophy was not found" << endl;
	return -1;
}