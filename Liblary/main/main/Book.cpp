#include "Book.h"

Book::Book() {
	//std::cout << "Konstruktor bezparametrowy" << std::endl;
}

Book::Book(const std::string& autor, const std::string& tytul) :
	autor(autor), tytul(tytul) {
	//std::cout << "konstruktor, który przyjmuje autora i tytu³ jako sta³e l-referencje" << std::endl;;
}

Book::Book(std::string&& autor, std::string&& tytul) :
	autor(autor), tytul(tytul) {
	//std::cout << "konstruktor, który przyjmuje autora i tytu³ jako sta³e r-referencje" << std::endl;;
}

Book::Book(const Book& book) :
	autor(book.autor), tytul(book.tytul) {
	//std::cout << "Konstruktor kopiujacy" << std::endl;
}

Book::Book(Book&& book) :
	autor(std::move(book.autor)), tytul(std::move(book.tytul)) {
	//std::cout << "Konstruktor przenoszacy" << std::endl;
}


std::string Book::GetAutor() {
	return this->autor;
}

std::string Book::GetTytul() {
	return this->tytul;
}

void Book::SetAutor(const std::string& autor) {
	this->autor = autor;
}

void Book::SetTytul(const std::string& tytul) {
	this->tytul = tytul;
}

void Book::SetAutor(std::string&& autor) {
	this->autor = std::move(autor);
}

void Book::SetTytul(std::string&& tytul) {
	this->tytul = std::move(tytul);
}

std::ostream& operator<<(std::ostream& out, const Book& book) {
	out << "Autor: " << book.autor << ", Tytul: " << book.tytul;
	return out;
}

Book& Book::operator=(const Book& book) {
	Book tmp = book;
	std::swap(autor, tmp.autor);
	std::swap(tytul, tmp.tytul);
	return *this;
}

Book& Book::operator=(Book&& book) {
	std::swap(autor, book.autor);
	std::swap(tytul, book.tytul);
	return *this;
}