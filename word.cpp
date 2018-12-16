#include<iostream>
#include"word.h"

Word::Word()
{
	std::vector<int> m_location;

	m_counter = 1;
	
	m_name = "EMPTY";

}

void Word::addcount()
{
	m_counter ++;
}

void Word::resetcount()
{
	m_counter = 1;
}

void Word::addloc( int l)
{
	m_location.push_back(l);
}

void Word::resetloc()
{
	m_location.clear();
}

void Word::setword( std::string n)
{
	m_name = n;
}

int Word::rcount()
{
	return m_counter;
}

std::vector <int> Word::rloc()
{
	return m_location;
}

std::string Word::rword()
{
	std::string name;
	name = m_name;
	return name;
}

void Word::print()
{
	std::cout << m_name << " : " <<  m_counter << " : "; 
	for( int i = 0; i < m_location.size(); i++)
	{
		std::cout << m_location[i] << ", ";
	}
	std::cout << std::endl;
}

int Word::prevloc()
{
	return m_location[m_location.size() -1];
}
