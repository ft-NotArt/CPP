#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
public:
	virtual ~Base() ;
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate() ;
void identify(Base *ptr) ;
void identify(Base &ref) ;
