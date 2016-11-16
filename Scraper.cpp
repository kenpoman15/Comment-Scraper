/*
 *
 */

#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

string trim(string &s);

int main()
{
	//variables
	string currentLine;
	char* fileName;
	fstream inout;

	cout << "Please enter the file you want to scrape" << endl;
	cin >> fileName;
	inout.open(fileName, ios::in);

	//Error Checking
	if (inout.fail())
	{
		cout << fileName << "Failed to open OR Does not exist";
		exit(1);
	}

	//Getting the currentLine

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
	inout.open("comments.txt", ios::out);
	inout << output;
	inout.close();

	return 0;
}

string trim(string &s)
{
	string line;
	int index = 0;
	int length = s.length();
	bool notBegOfLine = true;

	while(notBegOfLine && index < length-1)
	{
		if( !isspace(s.at(index)) )
		{
			notBegOfLine = false;
			break;
		}

		index++;
	}

	line = s.substr(index);
	return line;
}
