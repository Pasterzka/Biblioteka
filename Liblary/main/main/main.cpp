#include "Liblary.h"

int main()
{
	Liblary e;
	std::cout << "e: " << e << std::endl;
	//3-5 książek 
	Liblary l1 = { {"autor1", "tytul1"},
	{"autor2", "tytul2"},
	{"autor3", "tytul3"},
	{"autor4", "tytul4"},
	{"autor5", "tytul5"} };
	std::cout << "l1: " << l1 << std::endl;
	Liblary l2(2);
	std::cout << "l2: " << l2 << std::endl;
	l2[0] = { "autor6", "tytul6" };
	l2[1] = { "autor7", "tytul7" };
	std::cout << "l2: " << l2 << std::endl;
	e = std::move(l2);
	std::cout << "e: " << e << " l2: " << l2 << std::endl;
	l1[0] = std::move(e[1]);
	std::cout << "l1: " << l1 << " e: " << e << std::endl;
	return 0;
}
