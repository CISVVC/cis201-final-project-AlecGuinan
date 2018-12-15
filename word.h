#ifndef WORD_H
#define WORD_H
#include<string>
#include<vector>
class Word
{
	private: 
	
	std::string m_name; 
	
	int m_counter; 

	std::vector < int> m_location; 
	
	public: 
	
	Word();

	void addcount();
	
	void resetcount();

	void addloc(int l);

	void resetloc();

	void setword(std::string n);

	int rcount();

	std::vector <int> rloc();

	std::string rword();

	void print();
};
#endif
