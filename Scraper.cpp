/*
 *	Created by AJ Taft
 *	Created on 11-1-16
 *	Version 0.1
 *	Last Edited: 11-16-15
 */

#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

string trim(string &s);

int main()
{
	//Variables
	/*
	 * String to hold the current line
	 * char array to hold the file name
	 * fstream to input and output data
	 */
	string currentLine;
	char* fileName;
	fstream inout;

	//Prompt the user for a file path to scrape
	cout << "Please enter the file you want to scrape" << endl;
	cin >> fileName;
	inout.open(fileName, ios::in);

	//Error Checking
	/*
	 * Try to open the file
	 * if it fails tell the user it did not open and exit the program
	 */
	if (inout.fail())
	{
		cout << fileName << "Failed to open OR Does not exist";
		exit(1);
	}

	//Getting the currentLine
	/*
	 * While the file has more lines get the current line
	 * send the line to trim and get rid of any whitespace in front
	 * Check if the line starts with a comment character
	 * if so add the line to an output string
	 */
	string output;
	while( !(inout.eof()) )
	{
		getline(inout, currentLine);

		currentLine = trim(currentLine);
		cout << currentLine << endl;

		if(currentLine.substr(0,1) == "*")
		{
			output += currentLine + "\n";
		} else if(currentLine.substr(0,2) == "//") {
			output += currentLine + "\n";
		} else if(currentLine.substr(0,2) == "/*") {
			output += currentLine + "\n";
		}
	}
	inout.close();

	//Writing the product
	/*
	 * Place the output string into the following .txt file for reading
	 */
	inout.open("comments.txt", ios::out);
	inout << output;
	inout.close();

	return 0;
}

//String trim function
string trim(string &s)
{
	//Variables
	/*
	 * Have a string to return
	 * have an index for sunstrings starting at 0
	 * store the length of the line
	 * create a boolean to see if the line had started yet
	 */
	string line;
	int index = 0;
	int length = s.length();
	bool notBegOfLine = true;

	/*
	 * While it is not the beginning of the line and not over the length-1
	 * Check if it is a space
	 * if it is a character change the boolean to false and break from the loop
	 * incriment index +1 every loop
	 */
	while(notBegOfLine && index < length-1)
	{
		if( !isspace(s.at(index)) )
		{
			notBegOfLine = false;
			break;
		}

		index++;
	}
	//Return the line starting at the first character
	line = s.substr(index);
	return line;
}
