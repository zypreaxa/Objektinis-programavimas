#include "fun.h"

bool compare_by_name(const Studentas& s1, const Studentas& s2) {
	return s1.vardas < s2.vardas;
}

void sort_names() {
	sort(sarasas.begin(), sarasas.end(), compare_by_name);
}

int element_count(string filename) { //skaičiuojama kiek elementų yra vienoje eilutėje. Vėliau naudojama pažymių sukėlimui į vektorių (elemetų skaičius - 3 = ND pažymių skaičius).

	ifstream file(filename);

	string line;
	getline(file, line);
	stringstream s(line);

	string element;
	int count = 0;

	while (s >> element) { count++; }
	file.close();
	return count;
}

int counter(string filename) {
	ifstream file(filename);
	int count = 0;
	string line;

	while (getline(file, line)) {
		count++;
	}
	file.close();
	return count - 1;
}

int read_file() {
	string filename; //failo, kuris yra nuskaitomas, pavadinimas (su .txt!).
	cout << "Iveskite norimo nuskaityti failo pavadinima: " << endl; cin >> filename;
	try {
		ifstream file(filename);
		if (!file) {
			throw runtime_error("Failas tokiu pavadinimu nerastas!");
		}
		string c, line;
		int p;
		int count = counter(filename);

		getline(file, line); //praleidžiama pirmoji nenaudojama eilutė.

		int hw_count = element_count(filename) - 3;

		for (int i = 0; i < count; i++) {
			file >> c;
			temp.vardas = c;
			file >> c;
			temp.pavarde = c;
			for (int i = 0; i < hw_count; i++) {
				file >> p;
				if ((p <= 10) && (p >= 0)) {
					temp.paz.push_back(p);
				}
				else throw "Pažymiai neatitinka deštimtbalės sistemos.";
			}
			file >> p;
			if ((p <= 10) && (p >= 0)) {
				temp.egz = p;
			}
			else throw "Egzamino pažymiai neatitinka dešimtbalės sistemos.";
			sarasas.push_back(temp);
			temp.paz.clear();
		}

		file.close();
		return count;
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
		read_file();
	}
}


void read_file_datacalc(int count) {
	char ivestis;
	cout << "Ar norite, kad isvestis butu surusiuota pagal vardo pirmaja raide?\nt - Taip.\nn - Ne." << endl; cin >> ivestis;
	while ((ivestis != 't') && (ivestis != 'T') && (ivestis != 'n') && (ivestis != 'N')) { cin.clear(); cout << "Dar karta iveskite savo pasirinkima." << endl; cin >> ivestis; }
	if ((ivestis == 't') || (ivestis == 'T')) { sort_names(); }
	double_header_print();
	for (int i = 0; i < count; i++) {
		//vidurkinio galutinio balo skaičiavimas.
		float vidurkis;
		if (sarasas[i].paz.size() != 0) {
			int suma = 0;
			for (int k = 0; k < sarasas[i].paz.size(); k++) {
				suma = suma + sarasas[i].paz[k];
			}
			vidurkis = (float)suma / sarasas[i].paz.size();
		}
		else {
			vidurkis = 0;
		}

		float vidurkinis = (float)(0.4 * vidurkis) + (0.6 * sarasas[i].egz);

		float mediana = 0; //vidurkinio galutinio balo skaičiavimas.
		if (sarasas[i].paz.size() != 0) {
			sort(sarasas[i].paz.begin(), sarasas[i].paz.end());
			if (sarasas[i].paz.size() % 2 == 0) {
				mediana = (float)(sarasas[i].paz[sarasas[i].paz.size() / 2] + sarasas[i].paz[sarasas[i].paz.size() / 2 - 1]) / 2.0;
			}
			else {
				mediana = sarasas[i].paz[sarasas[i].paz.size() / 2];
			};
		}
		else mediana = 0;

		float medianinis = (0.4 * mediana) + (0.6 * temp.egz);

		cout << setw(15) << sarasas[i].vardas << setw(20) << sarasas[i].pavarde << setw(25) << fixed << setprecision(2) << vidurkinis << setw(30) << fixed << setprecision(2) << medianinis << endl;
	}

	sarasas.clear();
}