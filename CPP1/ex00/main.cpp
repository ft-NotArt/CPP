#include "Zombie.hpp"

int main()
{
	Zombie *carl = newZombie("carl") ;

	randomChump("noublard") ;

	carl->announce() ;
	std::cout << carl->getName() << " is walking toward you !" << std::endl ;

	randomChump("G_arRet_uN_1_bUs_Avc_ma_teTe") ;

	/* equivalent to C free, try to remove to check difference during correction */
	delete carl ;
}