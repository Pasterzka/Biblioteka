#include "Liblary.h"

Liblary::Liblary() :
	books(nullptr), size(0) {
	//std::cout << "konstruktor bezparametrowy" << std::endl;
}

Liblary::Liblary(const std::initializer_list<Book> bookis) :
	books(new Book[bookis.size()]), size(bookis.size()) {
	//std::cout << "Konstrukto ze wczytania" << std::endl;
	std::size_t i = 0;
	for (const auto& book : bookis) {
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
		out << lib.books[i];
	}
	out << ".";
	return out;
}