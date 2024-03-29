#pragma once

#include "Book.h"
#include <initializer_list> 

class Liblary {

	Book* books;
	std::size_t size;

public:
	
	//konstruktor bezparametrowy
	Liblary();

	//konstruktor initializer_list
	Liblary(const std::initializer_list<Book> books);

	//konstruktor kopiujący
	Liblary(const Liblary& lib);

	//konstruktor przenoszący
	Liblary(Liblary&& lib);

	Liblary(std::size_t);

	std::size_t GetSize();

	//destruktor
	~Liblary();

	//kopiujący operator przypisania
	Liblary& operator=(const Liblary& lib);

	//przenoszący operator przypisania
	Liblary& operator=(Liblary&& lib);

	//operator []
	Book& operator[](std::size_t i);

	//const operator []
	const Book& operator[](std::size_t i)const;

	friend std::ostream& operator<<(std::ostream& out, const Liblary& lib);

	void DodajKsiazke(const Book& book);
	void UsunKsiazke(std::size_t index);
	void DodajRozdzial(std::size_t x, const std::string& str);
	void Edytuj(std::size_t x);
};
