#pragma once
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Medicament {
private:
	int id;
	string nume;
	bool necesitaReteta;
	int numarStoc;
	string producator;
public:
	Medicament() = default;
	Medicament(int id, const string& nume, const bool necesitaReteta, int numarStoc, const string& producator) : id{ id }, nume{ nume }, necesitaReteta{ necesitaReteta }, numarStoc{ numarStoc }, producator{ producator }{};
	Medicament(const Medicament& other) : id{ other.id }, nume{ other.nume }, necesitaReteta{ other.necesitaReteta }, numarStoc{ other.numarStoc }, producator{ other.producator }{};
	Medicament(const Medicament* other) : id{ other->id }, nume{ other->nume }, necesitaReteta{ other->necesitaReteta }, numarStoc{ other->numarStoc }, producator{ other->producator }{};
	Medicament(int id) : id{ id }, nume{ "" }, necesitaReteta{ "" }, numarStoc{ 0 }, producator{ "" }{};
	~Medicament() {};

	const int getId() const noexcept {
		//Returneaza id-ul.
		return id;
	}

	const string getNume() const noexcept {
		//Returneaza numele.
		return nume;
	}

	const bool getNecesitaReteta() const noexcept {
		//Retuneaza daca necesita reteta sau nu.
		return necesitaReteta;
	}

	int getNumarStoc() const noexcept {
		//Retuneaza numar pe stoc.
		return numarStoc;
	}

	const string getProducator() const noexcept {
		// Returneaza producatorul.
		return producator;
	}

	void setId(int newId) noexcept {
		/*
			Seteaza un nou id.
			in: newId - int
		*/
		this->id = newId;
	}

	void setNume(const string& value) {
		/*
			Seteaza un nume nou.
			in: value - string
		*/
		this->nume = value;
	}

	void setNecesitaReteta(const bool value) {
		/*
			Seteaza o noua valoare pentru necesitaReteta.
			in: value - bool
		*/
		this->necesitaReteta = value;
	}

	void setNumarStoc(int value) {
		/*
			Seteaza o noua valoare pentru numarStoc.
			in: value - int
		*/
		this->numarStoc = value;
	}

	void setProducator(const string& value) {
		/*
			Seteaza o noua valoare pentru producator.
			in: value - string
		*/
		this->producator = value;
	}

	bool operator==(const Medicament& medicament) const noexcept {
		/*
			Operatorul de egalitate.
			in: medicament - Medicament
			out: true daca este adevarat, false daca nu
		*/
		return this->getId() == medicament.getId() && this->getNume() == medicament.getNume() && this->getNecesitaReteta() == medicament.getNecesitaReteta() && this->getNumarStoc() == medicament.getNumarStoc() && this->getProducator() == medicament.getProducator();
	}

	bool operator!=(const Medicament& medicament) const noexcept {
		/*
			Operatorul de inegalitate.
			in: medicament - Medicament
			out: true daca este adevarat, false daca nu
		*/
		return !(*this == medicament);
	}

	Medicament& operator=(const Medicament& other) {
		/*
			Operator de atribuire.
			in: other - Medicament
			out: continutul indicat de this
		*/
		setId(other.getId());
		setNume(other.getNume());
		setNecesitaReteta(other.getNecesitaReteta());
		setNumarStoc(other.getNumarStoc());
		setProducator(other.getProducator());
		return *this;
	}

	const Medicament& operator*() {
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Medicament& medicament) {
		out << medicament.getId() << " " << medicament.getNume() << " " << medicament.getNecesitaReteta() << " " << medicament.getNumarStoc() << " " << medicament.getProducator() << " ";
		return out;
	}

	friend istream& operator>>(istream& in_stream, Medicament& rez) {
		int id;
		string nume;
		bool necesitaReteta;
		int numarStoc;
		string producator;
		if (in_stream.eof()) {
			return in_stream;
		}
		in_stream >> id;
		rez.setId(id);
		if (in_stream.eof()) {
			return in_stream;
		}
		in_stream >> nume;
		rez.setNume(nume);
		if (in_stream.eof()) {
			return in_stream;
		}
		in_stream >> necesitaReteta;
		rez.setNecesitaReteta(necesitaReteta);
		if (in_stream.eof()) {
			return in_stream;
		}
		in_stream >> numarStoc;
		rez.setNumarStoc(numarStoc);
		if (in_stream.eof()) {
			return in_stream;
		}
		in_stream >> producator;
		rez.setProducator(producator);
		if (in_stream.eof()) {
			return in_stream;
		}
		return in_stream;
	}
};