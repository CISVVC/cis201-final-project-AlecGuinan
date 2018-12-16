/* 
Author: Alec Guinan
File: word.h
Purpose: this creates a class called Word
Email; Guinana@student.vvc.edu
*/
#ifndef WORD_H
#define WORD_H
#include<string>
#include<vector>
class Word
{
	private: 
	
	std::string m_name; // hold the name of the word
	
	int m_counter; // counts the number of times the word appears

	std::vector < int> m_location; // tracks where the word appeared
	
	public: 
	
	Word();// default constructor
	
	int prevloc();// gives me the previous line number

	void addcount();// adds one to the current count
	
	void resetcount();// resets the count of the word to zero

	void addloc(int l);// adds a new line number

	void resetloc();// clears the line numbers

	void setword(std::string n);// this sets the name of the word

	int rcount();// this returns the current count

	std::vector <int> rloc();// this returns the locations the word occured as a vector

	std::string rword();// this returns the name of the word

	void print();// this prints Word
};
#endif
