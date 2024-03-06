#pragma once


#include <iostream>
#include <string>

class Book {
private:

	std::string autor, tytul;
	std::string* spis;
	std::size_t Ssize;

public:

	//konstruktor bezparametrowy
	Book();

	//konstruktor, kt�ry przyjmuje autora i tytu� jako sta�e l-referencje
	Book(const std::string& autor, const std::string& tytul);

	//konstruktor, kt�ry przyjmuje autora i tytu� jako sta�e r-referencje
	Book(std::string&& autor, std::string&& tytul);

	//konstruktor kopiuj�cy
	Book(const Book& book);

	//konstruktor przenosz�cy
	Book(Book&& book);

	//getery
	std::string GetAutor();
	std::string GetTytul();

	//setery l-referencyjne
	void SetAutor(const std::string& autor);
	void SetTytul(const std::string& tytul);
	void EditRozdzial(const std::string& tytul, const std::string& index);

	//setery r-referencyjne
	void SetAutor(std::string&& autor);
	void SetTytul(std::string&& tytul);

	//operator <<
	friend std::ostream& operator<<(std::ostream& out, const Book& book);
	//kopiuj�cy operator przypisania
	Book& operator=(const Book& book);
	//przenosz�cy operator przypisania
	Book& operator=(Book&& book);

	void SetRozdzial(const std::string& str);
};