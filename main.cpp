#include <time.h>
#include "Game.hpp"

int main() {
	srand(time(NULL));
	std::cout << "*************************************************" << std::endl;
	std::cout << "*             ULTIMATE BANK HEIST GAME          *" << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::cout << "Your goal in this game is to steal as much money as possible from the bank";
	std::cout << " before the police arrive.  If you trigger the police you will have ten turns";
	std::cout << " to escape before you are arrested. Look around, find keys, steal money and";
	std::cout << " most importantly, find a way to escape!\n" << std::endl;

	std::cout << "Here is a map if you need it:" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "~ Bank Map:                                   ~" << std::endl;
	std::cout << "~*********************************************~" << std::endl;
	std::cout << "~|| - = Wall  || V = Vault  || M = Managers ||~" << std::endl;
	std::cout << "~|| 0 = Empty || W = Window || F = Front    ||~" << std::endl;
	std::cout << "~*********************************************~" << std::endl;
	std::cout << "~               - - - - - - - -               ~" << std::endl;
	std::cout << "~               - - 0 - W - - -               ~" << std::endl;
	std::cout << "~               F 0 0 0 0 0 0 -               ~" << std::endl;
	std::cout << "~               - - - M - - 0 -               ~" << std::endl;
	std::cout << "~               - - - - - - V -               ~" << std::endl;
	std::cout << "~               - - - - - - - -               ~" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;

	std::cout << "Hope this helps you out bud.\n" << std::endl;

	/*- = Wall
	V = Vault
	M = Managers Office
	0 = Empty Room
	W = Windowed room
	F = Front Door

	Game Map:
	- - - - - - - -
	- - 3 - W - - -
	F 1 2 4 5 6 7 -
	- - - M	- - 8 -
	- - - - - - V -
	- - - - - - - -

*/

	Game newGame;
	newGame.start();




	return 0;
}