#include "Serializer.hpp"
#include <iostream>

int main() {
	Data *ptr = new data ;

	ptr->feur0 = 0 ;
	ptr->feur1 = 1 ;
	ptr->feur2 = 2 ;
	ptr->feur3 = 3 ;
	ptr->feur4 = 4 ;
	ptr->feur5 = 5 ;
	ptr->feur6 = 6 ;
	ptr->feur7 = 7 ;

	std::cout << "-- BEFORE --" << std::endl ;
	std::cout << "ptr: " << ptr << std::endl ;
	std::cout << "ptr adr: " << &ptr << std::endl ;
	std::cout << ptr->feur0 << std::endl ;
	std::cout << ptr->feur1 << std::endl ;
	std::cout << ptr->feur2 << std::endl ;
	std::cout << ptr->feur3 << std::endl ;
	std::cout << ptr->feur4 << std::endl ;
	std::cout << ptr->feur5 << std::endl ;
	std::cout << ptr->feur6 << std::endl ;
	std::cout << ptr->feur7 << std::endl ;

	uintptr_t raw = Serializer::serialize(ptr) ;
	ptr = Serializer::deserialize(raw) ;
	std::cout << std::endl ;

	std::cout << "-- AFTER --" << std::endl ;
	std::cout << "ptr: " << ptr << std::endl ;
	std::cout << "ptr adr: " << &ptr << std::endl ;
	std::cout << ptr->feur0 << std::endl ;
	std::cout << ptr->feur1 << std::endl ;
	std::cout << ptr->feur2 << std::endl ;
	std::cout << ptr->feur3 << std::endl ;
	std::cout << ptr->feur4 << std::endl ;
	std::cout << ptr->feur5 << std::endl ;
	std::cout << ptr->feur6 << std::endl ;
	std::cout << ptr->feur7 << std::endl ;



	delete ptr ;
}