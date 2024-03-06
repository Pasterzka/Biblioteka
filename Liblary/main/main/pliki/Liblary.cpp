#include "Liblary.h"

Liblary::Liblary() :
	books(nullptr), size(0) {
	//std::cout << "konstruktor bezparametrowy" << std::endl;
}

Liblary::Liblary(const std::initializer_list<Book> bookis) :
	books(new Book[bookis.size()]), size(bookis.size()) {
	//std::cout << "Konstrukto ze wczytania" << std::endl;
	std::size_t i = 0;
	for (Book book : bookis) {
		books[i++] = book;
	}
}

Liblary::Liblary(const Liblary& lib) :
	books(new Book[lib.size]), size(lib.size) {
	//std::cout << "Konstruktor kopiuj¹cy" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		books[i] = lib.books[i];
	}
}

Liblary::Liblary(Liblary&& lib) :
	books(new Book[lib.size]), size(lib.size) {
	lib.books = nullptr;
	lib.size = 0;
}

Liblary::Liblary(std::size_t i) :
	books(new Book[i]), size(i) {

}

std::size_t Liblary::GetSize() {
	return this->size;
}

Liblary::~Liblary() {
	delete[] books;
}

Liblary& Liblary::operator=(const Liblary&lib){
	Liblary tmp(lib);
	std::swap(books, tmp.books);
	std::swap(size, tmp.size);
	return *this;
}

Liblary& Liblary::operator=(Liblary&& lib) {
	std::swap(books, lib.books);
	std::swap(size, lib.size);
	return *this;
}

Book& Liblary::operator[](std::size_t i) {
	return books[i];
}

const Book& Liblary::operator[](std::size_t i) const {
	return books[i];
}

std::ostream& operator<<(std::ostream& out, const Liblary& lib) {
	out << "Ksizaki w Bibliotece: ";
	for (size_t i = 0; i < lib.size; i++)
	{
		if (i < 0) {
			out << ", ";
		}
		out << "Index " << i << " " << lib.books[i] << " ;";
	}
	out << ".";
	return out;
}

void Liblary::DodajKsiazke(const Book& book) {
	Book* NoweKsiazki = new Book[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		NoweKsiazki[i] = std::move(books[i]);
	}
	NoweKsiazki[size++] = book;
	delete[] books;
	books = NoweKsiazki;
}

void Liblary::UsunKsiazke(std::size_t index) {
	for (std::size_t i = index; i < size - 1; ++i) {
		books[i] = std::move(books[i + 1]);
	}
	--size;
}

void Liblary::DodajRozdzial(std::size_t x,const std::string& str) {
	books[x].SetRozdzial(str);
}

void Liblary::Edytuj(std::size_t index) {
	int wyb = 0;
	bool wyj = true;
	std::string text="x", nazwa = "x", nn ="x";
	while (wyj)
	{
		std::cout << "1-Autor, 2-tytul, 3-wyjscie, 4-rozdzial: ";
		std::cin >> wyb;
		switch (wyb)
		{
		case 1:
			std::cout << "Wczytaj autora: ";
			std::cin >> text;
			books[index].SetAutor(text);
			break;
		case 2:
			std::cout << "Wczytaj tytul: ";
			std::cin >> text;
			books[index].SetTytul(text);
			break;
		case 3:
			wyj = false;
			break;
		case 4:
			std::cout << "wczytaj nazwe rozdzialu: ";
			std::cin >> nazwa;
			std::cout << "wczytaj nowa nazwe: ";
			std::cin >> nn;
			books[index].EditRozdzial(nazwa, nn);
			break;
		default:
			break;
		}
	}
}