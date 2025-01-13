#include "Contact.hpp"

bool isValidPhoneNumber(std::string phoneNumber) {
	if (phoneNumber.length() > 10)
		return false ;
	for (size_t i = 0; phoneNumber[i]; i++)
	{
		if (!isdigit(phoneNumber[i]))
			return false ;
	}
	return true ;
}

Contact::Contact() {}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret) {
	this->_firstName = firstName ;
	this->_lastName = lastName ;
	this->_nickName = nickName ;
	this->_phoneNumber = phoneNumber ;
	this->_darkestSecret = darkestSecret ;
}

Contact::~Contact() {}

void Contact::setFirstName(std::string firstName) { this->_firstName = firstName ;}

void Contact::setLastName(std::string lastName) { this->_lastName = lastName ;}

void Contact::setNickName(std::string nickName) { this->_nickName = nickName ;}

void Contact::setPhoneNumber(std::string phoneNumber) { this->_phoneNumber = phoneNumber ;}

void Contact::setDarkestSecret(std::string darkestSecret) { this->_darkestSecret = darkestSecret ;}

std::string Contact::getFirstName() { return this->_firstName ;}

std::string Contact::getLastName() { return this->_lastName ;}

std::string Contact::getNickName() { return this->_nickName ;}

std::string Contact::getPhoneNumber() { return this->_phoneNumber ;}

std::string Contact::getDarkestSecret() { return this->_darkestSecret ;}
