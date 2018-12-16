#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"word.h"
void printvec(std::vector <Word> v);
bool isnew(std::string word, std::vector <Word> v);
void getfilename(std::string &name);
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
	doc.open(filename.c_str());
	while(doc.get(ch))
	{
		ch = tolower(ch);
		if( isalpha(ch))
		{
			word = word + ch;
		}
		if(ch == '\n')
		{
			line ++;
		}
		if (!isalpha(ch))
		{
			if(isnew(word, concordence))
			{
				n.setword(word);
				n.addloc(line);
				concordence.push_back(n);
				n.resetloc();
			}
			else if(!isnew(word, concordence))
			{
				while ( a < concordence.size()) 
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
