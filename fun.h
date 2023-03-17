#pragma once

#include "personal_lib.h"

struct Studentas {
	string vardas, pavarde;
	vector<int> paz; //naudojamas vietoje masyvo rodykles
	int egz;
	float galutinis; //apskaičiuojamas pagal pasirinkimą(vidurkį arba medianą).
	bool status;
};

extern Studentas temp;
extern vector<Studentas> sarasas;

extern vector<string> names;
extern vector<string> surnames;
extern vector<Studentas> kvaileliai;
extern vector<Studentas> protingi;

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
void name_vectors();
void file_generate(int size, string filename, int hw_count);
void requirement_generate();
void gen_file_datacalc(int count, char input);
void sort_status();
void user_comm();
void custom_file();
void show_loading_indicator(std::atomic_bool& loading);
void data_sep();
void line_calc(std::istringstream &line);
void calculate(Studentas& temp);
void sort_stud(Studentas& temp, ofstream& protingi, ofstream& kvaili, std::istringstream& line);

void template_gen_read();
vector<Studentas>* gen(int size, int index);
void split(vector<Studentas>* list);

