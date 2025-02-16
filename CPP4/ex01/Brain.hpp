#pragma once

#include <string>
#include <iostream>

#define BRAIN_CAPACITY 100

class Brain
{
private:
	std::string ideas[BRAIN_CAPACITY] ;
public:
	Brain() ;
	Brain(const Brain &brain) ;
	~Brain() ;
	Brain &operator=(const Brain &brain) ;
	std::string getIdea(int index) const ;
	void setIdea(std::string idea, int index) ;
};
