#include "Zombie.hpp"

#define ZOMBIE_NB 5

int main()
{
	Zombie *horde = zombieHorde(ZOMBIE_NB, "carl") ;

	for (size_t i = 0; i < ZOMBIE_NB; i++)
		horde[i].announce() ;

	/* equivalent to C free, try to remove to check difference during correction */
	delete[] horde ;
}