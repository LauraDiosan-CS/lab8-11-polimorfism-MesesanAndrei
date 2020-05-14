#pragma once
#include <assert.h>
#include "Repository.h"
#include "Medicament.h"
#include "Angajat.h"
#include "ServiceMedicament.h"

void testDomainMedicament() {
	Medicament m1{ 1, "nume 1", true, 10, "producator 1" };
	Medicament m2{ 2, "nume 2", false, 20, "producator 2" };
	Medicament m3{ 3, "nume 3", true, 30, "producator 3" };
	Medicament m4{ 4 };
	Medicament m5{ m1 };
	assert(m1 == m5);
	assert(m1 != m2);
	m2 = m1;
	assert(m2 == m1);

	assert(m3.getId() == 3);
	assert(m3.getNume() == "nume 3");
	assert(m3.getNecesitaReteta() == true);
	assert(m3.getNumarStoc() == 30);
	assert(m3.getProducator() == "producator 3");

	m3.setId(2);
	m3.setNume("a");
	m3.setNecesitaReteta(false);
	m3.setNumarStoc(3);
	m3.setProducator("aa");
	assert(m3.getId() == 2);
	assert(m3.getNume() == "a");
	assert(m3.getNecesitaReteta() == false);
	assert(m3.getNumarStoc() == 3);
	assert(m3.getProducator() == "aa");

	stringstream ss;
	ss << m3;
	string s = ss.str();
	//cout << s;
	assert(s == "2 a 0 3 aa ");
}

void testDomainAngajat() {
	Angajat a1{ 1, "nume 1", "email 1", 2};
	Angajat a2{ 2, "nume 2", "email 2", 4};
	Angajat a3{ 3, "nume 3", "email 3", 2};
	Angajat a4{ 4 };
	Angajat a5{ a1 };
	assert(a1 == a5);
	assert(a1 != a2);
	a2 = a1;
	assert(a2 == a1);

	assert(a3.getId() == 3);
	assert(a3.getNume() == "nume 3");
	assert(a3.getEmail() == "email 3");
	assert(a3.getGradAcces() == 2);

	a3.setId(2);
	a3.setNume("a");
	a3.setEmail("a");
	a3.setGradAcces(3);
	assert(a3.getId() == 2);
	assert(a3.getNume() == "a");
	assert(a3.getEmail() == "a");
	assert(a3.getGradAcces() == 3);

	stringstream ss;
	ss << a3;
	string s = ss.str();
	//cout << s;
	assert(s == "2 a a 3 ");
}

void myTestRepositoryFileTXT() {
	RepositoryFileTXT<Medicament> repo("repotest.txt");

	Medicament m1{ 1, "nume 1", true, 10, "producator 1" };
	Medicament m2{ 2, "nume 2", false, 20, "producator 2" };
	Medicament m3{ 3, "nume 3", true, 30, "producator 3" };
	Medicament m4{ 4, "nume 4", true, 40, "producator 4" };
	Medicament m5{ 5, "nume 5", false, 50, "producator 5" };

	// adaug m1
	try {
		repo.add(m1);
		assert(true);
	}
	catch (const RepositoryException& exception) {
		assert(false);
	}

	// arunca exc pt ca m1 exista deja
	try {
		repo.add(m1);
		assert(false);
	}
	catch (const RepositoryException& exception) {
		assert(true);
	}

	// adaug m2
	try {
		repo.add(m2);
		assert(true);
	}
	catch (const RepositoryException& exception) {
		assert(false);
	}

	assert(repo.getAll().size() == 2);


	// incerc sa sterg m5, care nu exista -> exceptie
	try {
		repo.remove(m5.getId());
		assert(false);
	}
	catch (const RepositoryException& exception) {
		assert(true);
	}
	try {
		repo.remove(m1.getId());
		assert(true);
	}
	catch (const RepositoryException& exception) {
		assert(false);
	}

	assert(repo.getAll().size() == 1);
	Medicament m2_nou{ 2, "nume_nou", true, 20, "producator 2" };
	try {
		repo.update(m2, m2_nou);
		assert(true);
	}
	catch (const RepositoryException& exception) {
		assert(false);
	}
	try {
		repo.update(m5, m2_nou);
		assert(false);
	}
	catch (const RepositoryException& exception) {
		assert(true);
	}
	repo.remove(m2.getId());
}

void testRepositoryFileTXT() {
	Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
	Medicament m1 = new Medicament(100, "parasinus", false, 10, "p1");
	Medicament m2 = new Medicament(200, "ketonal", false, 90, "p2");
	Medicament m3 = new Medicament(300, "antibiotic", true, 70, "p3");

	repo->add(m1);
	repo->add(m2);
	assert(repo->getAll().size() == 2);
	assert(repo->getAll()[0] == m1);
	assert(repo->getAll()[1] == m2);
	repo->add(m3);
	assert(repo->getAll()[2] == m3);

	Medicament m1_new(100, "paracetamol", false, 50, "p1");
	repo->update(m1, m1_new);
	assert(repo->getAll()[0] != m1);
	assert(repo->getAll()[0] == m1_new);

	repo->remove(200);
	assert(repo->getAll().size() == 2);
}

void myTestServiceMedicament() {
	Repository<Medicament> repo{};

	MedicineService service{ repo };
	Medicament m1{ 1, "nume 1", true, 10, "producator 1" };
	Medicament m2{ 2, "nume 2", false, 20, "producator 2" };
	Medicament m3{ 3, "nume 3", true, 30, "producator 3" };
	Medicament m4{ 4, "nume 4", true, 40, "producator 4" };
	Medicament m5{ 5, "nume 5", false, 50, "producator 5" };

	assert(service.getAll().size() == repo.getAll().size());

	try {
		service.add(m1);
		assert(true);
	}
	catch (RepositoryException& e) {
		assert(false);
	}
	try {
		service.add(m1);
		assert(false);
	}
	catch (RepositoryException& e) {
		assert(true);
	}

	try {
		Medicament m1_nou{ 1, "nume nou", false, 20, "producator 1" };
		service.update(m1, m1_nou);
		Medicament m = service.findMedicament(m1.getId());
		assert(m.getNume().compare(m1_nou.getNume()) == 0);
	}
	catch (RepositoryException& e) {
		assert(false);
	}

	try {
		service.remove(m1.getId());
		assert(true);
	}
	catch (RepositoryException& e) {
		assert(false);
	}
	try {
		service.remove(m1.getId());
		assert(false);
	}
	catch (RepositoryException& e) {
		assert(true);
	}
}

void testServiceMedicament() {
	Repository<Medicament> repository{};
	MedicineService * service = new MedicineService{ repository };
	Medicament m1 = new Medicament(100, "parasinus", false, 10, "p1");
	Medicament m2 = new Medicament(200, "ketonal", false, 90, "p2");
	Medicament m3 = new Medicament(300, "antibiotic", true, 70, "p3");

	service->add(m1);
	service->add(m2);
	assert(service->getAll().size() == 2);
	assert(service->getAll()[0] == m1);
	assert(service->getAll()[1] == m2);
	service->add(m3);
	assert(service->getAll()[2] == m3);

	//assert(service->search("ic").size() == 1);
	assert(service->search("a").size() == 3);

	Medicament m1_new(100, "altceva", false, 50, "p1");
	service->update(m1, &m1_new);
	assert(service->search("al").size() == 2);
	assert(service->search("al")[0] == m1_new);
	assert(service->search("al")[1] == m2);
	service->remove(200);
	assert(service->search("al").size() == 1);
	assert(service->search("al")[0] == m1_new);

}