#pragma once

#include <stdint.h>

typedef struct Data
{
	int feur0 ;
	int feur1 ;
	int feur2 ;
	int feur3 ;
	int feur4 ;
	int feur5 ;
	int feur6 ;
	int feur7 ;
} data ;


class Serializer
{
private:
	Serializer() ;
	Serializer(const Serializer &copy) ;
	Serializer &operator=(const Serializer &copy) ;
public:
	~Serializer() ;
	static uintptr_t serialize(Data* ptr) ;
	static Data* deserialize(uintptr_t raw) ;
};
