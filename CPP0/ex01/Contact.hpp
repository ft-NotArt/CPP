#pragma once

#include <string>

bool isValidPhoneNumber(std::string) ;

class Contact
{
private:
	std::string _firstName ;
	std::string _lastName ;
	std::string _nickName ;
	std::string _phoneNumber ;
	std::string _darkestSecret ;
public:
	Contact() ;
	Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret) ;
	~Contact() ;
	void setFirstName(std::string firstName) ;
	void setLastName(std::string lastName) ;
	void setNickName(std::string nickName) ;
	void setPhoneNumber(std::string phoneNumber) ;
	void setDarkestSecret(std::string darkestSecret) ;
	std::string getFirstName() ;
	std::string getLastName() ;
	std::string getNickName() ;
	std::string getPhoneNumber() ;
	std::string getDarkestSecret() ;
};
