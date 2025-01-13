#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook phoneBook ;

	while (true)
	{
		std::cout << "<| MAXI PHONEBOOK PRO+ 2000 |> " ;
		std::string action ;
		if (!std::getline(std::cin, action))
		{
			std::cout << std::endl ;
			return 1 ;
		}
		if (action == "ADD")
			phoneBook.Add() ;
		else if (action == "SEARCH")
			phoneBook.Search() ;
		else if (action == "EXIT")
			break ;
	}
	return 0 ;
}