#pragma once

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

#define NB_MAX_CONTACT 8

class PhoneBook
{
private:
	Contact _contacts[NB_MAX_CONTACT] ;
	int _contactIndex ;
	void IncrementContactIndex() ;
	std::string FormatName(std::string name) ;
public:
	PhoneBook() ;
	~PhoneBook() ;
	void Add() ;
	void Search() ;
};

