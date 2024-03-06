#include "Liblary.h"

int main()
{
	Liblary e;
	Book b;
	bool out = true;
	std::string autor= "x", tytul ="x", rozdzial = "x";
	int zmienna = 0, index = 0;
	
	while (out)
	{
		std::cout << "Wtbierz co chcesz robic 1-dodac, 2-wyjsc, 3-usun, 4-wysiwetl, 5-dodajrozdzial, 6-Edytuj: ";
		std::cin >> zmienna;
		std::cout << std::endl;
		switch (zmienna)
		{
		case 1:
			std::cout << "Wczytaj Autor: ";
			std::cin >> autor;

			std::cout << "Wczytaj Tytul: ";
			std::cin >> tytul;

			b.SetAutor(autor);
			b.SetTytul(tytul);

			e.DodajKsiazke(b);
			break;
		case 2:
			out = false;
			break;
		case 3:
			std::cout << "Wybierz indeks do usuniecia." << std::endl;
			std::cout << e << std::endl;
			std::cin >> index;
			e.UsunKsiazke(index);
			break;
		case 4:
			std::cout << e << std::endl;
			break;
		case 5:
			std::cout << e << std::endl;
			std::cout << "Wybierz Indeks ksiazki, do ktorej chcesz dodac rodzial: ";
			std::cin >> index;
			std::cout << "Wczytaj nazwe: ";
			std::cin >> rozdzial;
			e.DodajRozdzial(index, rozdzial);
			break;
		case 6:
			std::cout << "Wybierz indeks do edytowania." << std::endl;
			std::cout << e << std::endl;
			std::cin >> index;
			e.Edytuj(index);
			break;
		default:
			break;
		}

	}

	return 0;
}
