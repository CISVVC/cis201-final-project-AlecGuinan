/*
Author: Alec Guinan
Purpose: this program creates a concordence
File name: main.cpp
Email: Guinana@student.vvc.edu
*/
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"word.h"
void printvec(std::vector <Word> v);// this prints out the concordence
bool isnew(std::string word, std::vector <Word> v);// this checks if a word is already in the concordence
void getfilename(std::string &name);// this prompts the user for a file name
int main()
{
	Word b;
	int a = 0;
	int line = 1;
	Word n;
	std::vector< Word> concordence;
	std::string word;
	char ch;
	std::ifstream doc;
	std::string filename;
	
	getfilename(filename);
	doc.open(filename.c_str());// this opens the file
	while(doc.get(ch))// grabs one character at a time from the file
	{
		ch = tolower(ch);// makes every letter lowercase
		if( isalpha(ch))// checks if the character is a letter and if it is then it adds it to a string
		{
			word = word + ch;
		}
		if(ch == '\n')// if its a new line it adds one to the line count
		{
			line ++;
		}
		if (!isalpha(ch))// if it is anything but a charater then we assume the word is done
		{
			if(isnew(word, concordence))// if its a new word then we add the current line to it and push it back on the vector
			{
				n.setword(word);
				n.addloc(line);
				concordence.push_back(n);
				n.resetloc();
			}
			else if(!isnew(word, concordence))// if its not a new word then we find its location in the vector and add one to the count and add the location if its different from the one before it
			{
				while ( a < concordence.size()) // for some reason my for loop didnt run here so i made my own 
				{	
					if(concordence[a].rword() == word)
					{
						concordence[a].addcount();
						if(concordence[a].prevloc() != line)
						{
							concordence[a].addloc(line);
						}
					
					}
					a++;
				}
			}a =0;
			word = "";
		}
	}
	printvec(concordence);
	return 0;
}

bool isnew(std::string word, std::vector <Word> v)
{
	bool value;
	value = true;
	std::vector <int> list;
	for(int i; i< v.size(); i++)
	{
		if (v[i].rword() == word)
		{
			value = false;
		}
	}
	return value;
}

void getfilename(std::string &name)
{
	std::string file;
	std::cout <<"Please enter the file name: ";
	std::cin >> file;
	name = file;
}

void printvec(std::vector <Word> v)
{
	for (int i; i< v.size(); i++ )
	{
		v[i].print();
	}
}
