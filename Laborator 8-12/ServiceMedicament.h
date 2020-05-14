#pragma once
#include <string>
#include <vector>
#include "Medicament.h"
#include "Repository.h"

using namespace std;


class MedicineService
{
private:
	Repository<Medicament>& repository;

public:
	MedicineService() = delete;
	MedicineService(Repository<Medicament>& repository)noexcept : repository{ repository } {};
	~MedicineService() {};

	void add(const Medicament& medicament) {
		/*
			Adauga un medicament.
			in: medicament - Medicament
		*/
		repository.add(medicament);
	}

	void remove(int id) {
		/*
			Sterge un medicament dupa id.
			in: id - int
		*/
		Medicament oldMedicament{ id };
		repository.remove(oldMedicament.getId());
	}

	void update(const Medicament& medicament, const Medicament& medicament_nou) {
		/*
			Modifica un medicament.
			in: medicament - Medicament
				medicament_nou - Medicament
		*/
		repository.update(medicament, medicament_nou);
	}

	const Medicament& findMedicament(int id) const {
		/*
			Returneaza un medicament cu un id dat.
			in: id - int
			out: m - Medicament&
		*/
		const Medicament& m = repository.find(id);
		return m;
	}

	const vector<Medicament>& getAll() const noexcept {
		/*
			Returneaza toate medicamentele.
		*/
		return repository.getAll();
	}
	const vector<Medicament> search(const string& subsir) const noexcept {
		vector<Medicament> result{};
		for (auto med : getAll()) {
			if (med.getNume().find(subsir) != std::string::npos) {
				result.push_back(med);
			}
		}
		return result;
	}
};