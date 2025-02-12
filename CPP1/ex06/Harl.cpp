#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "printf(\"ici\\n\") ;" << std::endl ;
}

void Harl::info() {
	std::cout << "printf(\"i:%d\\n\", i) ;" << std::endl ;
}

void Harl::warning() {
	std::cout << "int i ;\nprintf(\"i:%d\\n\", i) ;" << std::endl ;
}

void Harl::error() {
	std::cout << "NULL[42] ;" << std::endl ;
}


void Harl::complain(std::string level) {
	static void (Harl::* levels[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error } ;

	static int translateTable[256] ;
	static bool initialized = false ;
	if (!initialized) {  
		std::memset(translateTable, -1, sizeof(translateTable));
		translateTable['D'] = 0;
		translateTable['I'] = 1;
		translateTable['W'] = 2;
		translateTable['E'] = 3;
		initialized = true;  
	}
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
		std::cout << "Compiled perfectly !" << std::endl ;
	else
		(this->*levels[translateTable[static_cast<unsigned char> (level[0])]])() ;
}