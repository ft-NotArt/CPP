#include "Harl.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage : ./harlFilter <\"DEBUG\"/\"INFO\"/\"WARNING\"/\"ERROR\">" << std::endl ;
		return 1 ;
	}

	std::string argv1(argv[1]) ;
	if (argv1 != "DEBUG" && argv1 != "INFO" && argv1 != "WARNING" && argv1 != "ERROR")
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl ;
		return 0 ;
	}


	Harl programer ;

	switch (argv[1][0]) {
	case 'D':
		std::cout << "[ DEBUG ]" << std::endl ;
		programer.complain("DEBUG") ;
		std::cout << std::endl ; //fallthrough
	case 'I':
		std::cout << "[ INFO ]" << std::endl ;
		programer.complain("INFO") ;
		std::cout << std::endl ; //fallthrough
	case 'W':
		std::cout << "[ WARNING ]" << std::endl ;
		programer.complain("WARNING") ;
		std::cout << std::endl ; //fallthrough
	case 'E':
		std::cout << "[ ERROR ]" << std::endl ;
		programer.complain("ERROR") ;
		std::cout << std::endl ;
		break ;
	default: break;
	}
}