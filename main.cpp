#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"word.h"
bool isnew(std::string word, std::vector <Word> v);
void getfilename(std::string &name);
int main()
{
	bool value;
	Word* ptr = NULL;
	Word n;
	std::string filename;
	getfilename(filename); 
	char ch;
	int line = 1;
	std::string word;
	std::vector <Word> concordence;
	std::ifstream doc;
	doc.open(filename.c_str());
	while(doc.get(ch))
	{
		ch = tolower(ch);
		if ( isalpha(ch))
		{
			word = word + ch; 
		}
		if ( !isalpha(ch) )
		{
			if ( isnew(word, concordence))
			{
				n.setword(word);
				n.addloc(line);
				concordence.push_back(n);
				n.resetloc();
			}
			if(!isnew(word, concordence))
			{
				for(int i; i < concordence.size(); i++)
				{
					concordence[i].print();
					if(concordence[i].rword() == word)
					{
						concordence[i].addloc(line);
					}
				
				}
			}
			word = "";
		}
		if ( ch == '\n')
		{
			line ++;
		}
	}
	for ( int a; a < concordence.size(); a++)
	{
		concordence[a].print();
	}

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
/*
bool isnew(std::string word ,std::vector <Word> &v, int l)
{
	bool value; 
	value = true;
	std::vector<int> list;
	for(int i; i < v.size(); i++)
	{
		if (v[i].rword() == word)
		{
			value =false;
			v[i].addcount();
			list = v[i].rloc();
			if( list[list.size() - 1] != l)
			{
			 v[i].addloc(l);
			}
			break;
		}
	}
		return value;
}*/

void getfilename(std::string &name)
{
	std::string file;
	std::cout <<"Please enter the file name: ";
	std::cin >> file;
	name = file;
}
