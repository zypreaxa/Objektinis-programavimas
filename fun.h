#pragma once

#include "personal_lib.h"

struct Studentas {
	string vardas, pavarde;
	vector<int> paz; //naudojamas vietoje masyvo rodykles
	int egz;
	float galutinis; //apskaičiuojamas pagal pasirinkimą(vidurkį arba medianą).
};

extern Studentas temp;
extern vector<Studentas> sarasas;

void skaiciavimas(Studentas& temp);
void ivedimas(Studentas& temp);
void spausdinimas(Studentas& temp);
int counter(string filename);
bool compare_by_name(const Studentas& s1, const Studentas& s2);
void sort_names();
void header_print();
void double_header_print();
int element_count(string filename);
extern int read_file();
void read_file_datacalc(int count);

