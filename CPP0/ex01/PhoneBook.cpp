#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::IncrementContactIndex() { this->_contactIndex = (this->_contactIndex + 1) % NB_MAX_CONTACT ;}

void PhoneBook::Add() {
	std::string firstName ;
	do {
		std::cout << "Enter First Name\t: " ;
		if (!std::getline(std::cin, firstName))
			return ;
	} while (firstName.empty()) ;

	std::string lastName ;
	do {
		std::cout << "Enter Last Name\t\t: " ;
		if (!std::getline(std::cin, lastName))
			return ;
	} while (lastName.empty()) ;

	std::string nickName ;
	do {
		std::cout << "Enter Nick Name\t\t: " ;
		if (!std::getline(std::cin, nickName))
			return ;
	} while (nickName.empty()) ;

	std::string phoneNumber ;
	do {
		std::cout << "Enter Phone Number\t: " ;
		if (!std::getline(std::cin, phoneNumber))
			return ;
		while (phoneNumber.find(' ') != std::string::npos)
			phoneNumber.erase(phoneNumber.find(' '), 1) ;
	} while (phoneNumber.empty() || !isValidPhoneNumber(phoneNumber)) ;

	std::string darkestSecret ;
	do {
		std::cout << "Enter Darkest Secret\t: " ;
		if (!std::getline(std::cin, darkestSecret))
			return ;
	} while (darkestSecret.empty()) ;
	
	this->_contacts[this->_contactIndex].setFirstName(firstName) ;
	this->_contacts[this->_contactIndex].setLastName(lastName) ;
	this->_contacts[this->_contactIndex].setNickName(nickName) ;
	this->_contacts[this->_contactIndex].setPhoneNumber(phoneNumber) ;
	this->_contacts[this->_contactIndex].setDarkestSecret(darkestSecret) ;
	this->IncrementContactIndex() ;
}

std::string PhoneBook::FormatName(std::string name) {
	std::string res ;
	for (size_t i = 0; name.length() < 10 && i < 10 - name.length(); i++) {
		res.push_back(' ') ;
	}
	for (size_t i = 0; name[i] && i < 10; i++) {
		res.push_back(name[i]) ;
	}
	if (name.length() >= 10) {
		res[9] = '.' ;
	}
	return res ;
}

void PhoneBook::Search() {
	std::cout		<< "\t\t ___________________________________________ " << std::endl
					<< "\t\t|   index  |first name| last name| nickname |" << std::endl
					<< "\t\t|___________________________________________|" << std::endl ;
	int authorizedIndexes = -1 ;
	for (size_t i = 0; i < NB_MAX_CONTACT && !this->_contacts[i].getFirstName().empty() ; i++, authorizedIndexes++) {
		std::cout	<< "\t\t|         " << i << "|"
					<< FormatName(this->_contacts[i].getFirstName())<< "|"
					<< FormatName(this->_contacts[i].getLastName()) << "|"
					<< FormatName(this->_contacts[i].getNickName()) << "|" << std::endl
					<< "\t\t|___________________________________________|" << std::endl ;
	}


	if (authorizedIndexes == -1)
	{
		std::cout << "PHONEBOOK is EMPTY !!" << std::endl ;
		return ;
	}


	int wantedIndex ;
	std::string strWantedIndex ;
	do {
		std::cout << "Which index do you wish to display ? : " ;
		if (!std::getline(std::cin, strWantedIndex))
			return ;
		wantedIndex = atoi(strWantedIndex.c_str()) ;
	} while (strWantedIndex.empty() || wantedIndex < 0 || wantedIndex > authorizedIndexes) ;

	std::cout	<< std::endl << "\t\tContact :" << std::endl
				<< "\t\t\t First Name \t => " << this->_contacts[wantedIndex].getFirstName() << std::endl
				<< "\t\t\t Last Name \t => " << this->_contacts[wantedIndex].getLastName() << std::endl
				<< "\t\t\t Nick Name \t => " << this->_contacts[wantedIndex].getNickName() << std::endl
				<< "\t\t\t Phone Number \t => " << this->_contacts[wantedIndex].getPhoneNumber() << std::endl
				<< "\t\t\t Darkest Secret\t => " << this->_contacts[wantedIndex].getDarkestSecret() << std::endl << std::endl ;
}
