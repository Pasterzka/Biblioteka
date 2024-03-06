#include "Book.h"

Book::Book() :
	Ssize(0)
{
	//std::cout << "Konstruktor bezparametrowy" << std::endl;
}

Book::Book(const std::string& autor, const std::string& tytul) :
	autor(autor), tytul(tytul), Ssize(0) {
	//std::cout << "konstruktor, który przyjmuje autora i tytu³ jako sta³e l-referencje" << std::endl;;
}

Book::Book(std::string&& autor, std::string&& tytul) :
	autor(autor), tytul(tytul), Ssize(0) {
	//std::cout << "konstruktor, który przyjmuje autora i tytu³ jako sta³e r-referencje" << std::endl;;
}

Book::Book(const Book& book) :
	autor(book.autor), tytul(book.tytul), Ssize(0) {
	//std::cout << "Konstruktor kopiujacy" << std::endl;
}

Book::Book(Book&& book) :
	autor(std::move(book.autor)), tytul(std::move(book.tytul)), Ssize(0) {
	//std::cout << "Konstruktor przenoszacy" << std::endl;
}


std::string Book::GetAutor() {
	return this->autor;
}

std::string Book::GetTytul() {
	return this->tytul;
}

void Book::EditRozdzial(const std::string& nazwa, const std::string& nn) {
	for (size_t i = 0; i < Ssize; i++)
	{
		if (spis[i]==nazwa)
		{
			spis[i] = nn;
		}
	}
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
	if (book.Ssize>0)
	{
		std::cout << ", Spis:";
		for (size_t i = 0; i < book.Ssize; i++)
		{
			std::cout << book.spis[i] << " ";
		}
	}
	
	
	std::cout << "; ";
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

void Book::SetRozdzial(const std::string& str) {
	std::string* NowySpis = new std::string[Ssize + 1];
	for (size_t i = 0; i < Ssize; i++)
	{
		NowySpis[i] = std::move(spis[i]);
	}
	if (Ssize>0)
	{
		NowySpis[Ssize++] = str;
		delete[] spis;
		spis = NowySpis;
	}
	else {

		NowySpis[Ssize++] = str;
		spis = NowySpis;
	}
}