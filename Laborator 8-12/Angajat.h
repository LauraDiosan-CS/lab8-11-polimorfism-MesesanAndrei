#pragma once
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Angajat {
private:
	int id;
	string nume;
	string email;
	int gradAcces;
public:
	Angajat() = default;
	Angajat(int id, const string& nume, const string& email, int gradAcces) : id{ id }, nume{ nume }, email{ email }, gradAcces{ gradAcces }{};
	Angajat(const Angajat& other) : id{ other.id }, nume{ other.nume }, email{ other.email }, gradAcces{ other.gradAcces }{};
	Angajat(int id) : id{ id }, nume{ "" }, email{ "" }, gradAcces{ 0 }{};
	~Angajat() {};

	const int getId() const noexcept {
		//Returneaza id-ul.
		return id;
	}

	const string getNume() const noexcept {
		//Returneaza numele.
		return nume;
	}

	const string getEmail() const noexcept {
		//Retuneaza email-ul.
		return email;
	}

	const int getGradAcces() const noexcept {
		//Retuneaza gradul de acces.
		return gradAcces;
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

	void setEmail(const string& value) {
		/*
			Seteaza o noua valoare pentru email.
			in: value - string
		*/
		this->email = value;
	}

	void setGradAcces(int value) {
		/*
			Seteaza o noua valoare pentru gradul de acces.
			in: value - int
		*/
		this->gradAcces = value;
	}

	bool operator==(const Angajat& angajat) const noexcept {
		/*
			Operatorul de egalitate.
			in: angajat - Angajat
			out: true daca este adevarat, false daca nu
		*/
		return this->getId() == angajat.getId() && this->getNume() == angajat.getNume() && this->getEmail() == angajat.getEmail() && this->getGradAcces() == angajat.getGradAcces();
	}

	bool operator!=(const Angajat& angajat) const noexcept {
		/*
			Operatorul de inegalitate.
			in: angajat - Angajat
			out: true daca este adevarat, false daca nu
		*/
		return !(*this == angajat);
	}

	Angajat& operator=(const Angajat& other) {
		/*
			Operator de atribuire.
			in: other - Angajat
			out: continutul indicat de this
		*/
		setId(other.getId());
		setNume(other.getNume());
		setEmail(other.getEmail());
		setGradAcces(other.getGradAcces());
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Angajat& angajat) {
		out << angajat.getId() << " " << angajat.getNume() << " " << angajat.getEmail() << " " << angajat.getGradAcces() << " ";
		return out;
	}

};