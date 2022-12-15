//============================================================================
// Name        : compiler2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Tokenization Functions Prototypes
bool checkReserved(string s);
string opType="";
bool checkOperator(string s);
string bracketType="";
bool checkBrackets(string s);
bool checkComments(string s);
bool checkDataTypes(string s);
bool checkID(string s);
bool checkDigit(string s);

int main() {
	string input;
	while(cin>>input){

		//Create object of stringstream ss and initialize it with the input string
		stringstream ss(input);

		//Extract each words only..no spaces
		string word;
		while (getline(ss, word, ' ')) {

			// Turn string to lower case (Language is case-insensitive)
			transform(word.begin(), word.end(), word.begin(), ::tolower);

			// Tokenization Functions
			if (checkReserved(word)) cout<<word<<"\t\tReserved word\n";
			else if (checkOperator(word)) cout<<word<<"\t\t"<< opType <<"\n";
			else if (checkBrackets(word)) cout<<word<<"\t\t"<< bracketType <<"\n";
			else if (checkComments(word)) cout<<word<<"\t\tComment\n";
			else if (checkDataTypes(word)) cout<<word<<"\t\tData Type\n";
			else if (checkDigit(word)) cout<<word<<"\t\tDigit\n";
			else if (checkID(word)) cout<<word<<"\t\tIdentifier\n";
			else cout<<word<<"\t\n";

		}
	}

	return 0;
}


// Tokenization Functions Implementation

string reservedWords[]={"read", "write", "set",
		"if", "then", "else", "endif",
		"while", "do", "endwhile",
		"until", "enduntil", "call"};

bool checkReserved(string s){
	int arrSize= sizeof(reservedWords)/ sizeof(string);
	bool found=0;
	for (int i=0; i<arrSize;i++){
		if (s==reservedWords[i]){
			found=1;
			break;
		}
	}
	return found;
}


string arithmeticOperators[]={"+", "-", "/", "*"};
string relationalOperators[]={"=", "!", "<", ">"};

bool checkOperator(string s){
	bool found=0;

	//arithmeticOperators
	int arrSize= sizeof(arithmeticOperators)/ sizeof(string);
	if (!found){
		for (int i=0; i<arrSize;i++){
			if (s==arithmeticOperators[i]){
				found=1;
				opType="Arithmetic Operator";
				break;
			}
		}
	}

	//relationalOperators
	if (!found){
		arrSize= sizeof(relationalOperators)/ sizeof(string);
		for (int i=0; i<arrSize;i++){
			if (s==relationalOperators[i]){
				found=1;
				opType="Relational Operator";
				break;
			}
		}
	}

	//Others
	if (!found && s==","){
		found=1;
		opType="Comma";
	}

	if (!found && s==";"){
			found=1;
			opType="Semi-Colon";
		}

	return found;
}

string leftBrackets[]={"[", "("};
string RightBrackets[]={"]", ")"};

bool checkBrackets(string s){
	int arrSize= sizeof(leftBrackets)/ sizeof(string);
	bool found=0;

	for (int i=0; i<arrSize;i++){
		if (s==leftBrackets[i]){
			found=1;
			bracketType = "Left Bracket";
			break;
		}
	}

	if (!found){
		arrSize= sizeof(RightBrackets)/ sizeof(string);
		for (int i=0; i<arrSize;i++){
			if (s==RightBrackets[i]){
				found=1;
				bracketType = "Right Bracket";
				break;
			}
		}
	}
	return found;
}

bool checkComments(string s){
	int arrSize= sizeof(leftBrackets)/ sizeof(string);
	bool found=0;

	for (int i=0; i<arrSize;i++){
		if (s=="{" || s=="}"){
			found=1;
			break;
		}
	}
	return found;
}

string dataTypes[]={"integer", "double", "string", "char"};

bool checkDataTypes(string s){
	int arrSize= sizeof(dataTypes)/ sizeof(string);
	bool found=0;
	for (int i=0; i<arrSize;i++){
		if (s==dataTypes[i]){
			found=1;
			break;
		}
	}
	return found;
}

bool checkID(string s){
	bool isID=1;
	if (isalpha(s.at(0))){ //Must start with letter
		for (int i=0; i<s.length();i++){
			char currentChar = s.at(i);
			if (!isalpha(currentChar) && !isdigit(currentChar) && currentChar!='_' && currentChar!='$'){
				isID=0;
				break;
			}

		}
	}
	else isID=0;
	return isID;
}

bool checkDigit(string s){
	bool isDigit=1;
	for (int i=0; i<s.length();i++){
		char currentChar = s.at(i);
		if (!isdigit(currentChar) && currentChar !='.'){
			isDigit=0;
			break;
		}

	}

	return isDigit;
}





/*
 **** TEST (1) ****
WHILE x ! 0 DO
IF x < 0 THEN SET y = 10 - 4.5 * 5
ELSE SET y = 4.5 * x + 10
ENDIF ;
ENDWHILE ;

 *
 */


/*
 **** TEST (2) ****
Integer x ;
Set x = 1 ;

 *
 */
