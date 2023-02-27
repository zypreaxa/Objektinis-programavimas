#include "personal_lib.h"

struct Studentas {
	string vardas, pavarde;
	vector<int> paz; //naudojamas vietoje masyvo rodykles
	int egz;
	float galutinis; //apskaičiuojamas pagal pasirinkimą(vidurkį arba medianą).
};

Studentas temp;
vector<Studentas> sarasas;

int masyv = 1; //struktūrų masyvų skaičius.

void skaiciavimas(Studentas& temp) {
	char inp;
	cout << "Norint gauti rezultata skaiciuota su mediana, spauskite m.\nNorint gauti rezultata skaiciuota su vidurkiu, spauskite v." << endl; cin >> inp;
	while (inp != 'v' && inp != 'm') {
		cout << "Dar karta iveskite savo pasirinkima" << endl; cin >> inp;
	};

	if (inp == 'v') { //jei įvedama 'v', skaičiuojamas galutinis balas naudojant vidurkį.
		float vidurkis;
		if (temp.paz.size() != 0) {
			int suma = 0;
			for (int i = 0; i < temp.paz.size(); i++) {
				suma = suma + temp.paz[i];
			}
			vidurkis = (float)suma / temp.paz.size();
		}
		else {
			vidurkis = 0;
		}

		temp.galutinis = (float)(0.4 * vidurkis) + (0.6 * temp.egz);
	}
	else { //jei įvedama 'm', skaičiuojamas galutinis balas naudojant medianą.
		float mediana = 0;
		if (temp.paz.size() != 0) {
			sort(temp.paz.begin(), temp.paz.end());
			if (temp.paz.size() % 2 == 0) {
				mediana = (float)(temp.paz[temp.paz.size() / 2] + temp.paz[temp.paz.size() / 2 - 1]) / 2.0;
			}
			else {
				mediana = temp.paz[temp.paz.size() / 2];
			};
		}
		else mediana = 0;

		temp.galutinis = (0.4 * mediana) + (0.6 * temp.egz);
	}
}

void ivedimas(Studentas& temp) {
	cout << "Iveskite varda ir pavarde: "; cin >> temp.vardas >> temp.pavarde;

	char ivestis;
	cout << "Rankine ivestis - 'r'.\nAutomatinis pazymiu generavimas - 'a'." << endl; cin >> ivestis;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	while (true) {
		if (ivestis == 'r') {
			cout << "Iveskite pazymius: " << endl;

			int pazymys;

			while (cin >> pazymys) {
				if ((pazymys >= 0) && (pazymys <= 10)) { temp.paz.push_back(pazymys); }
				else {
					while ((pazymys < 0) || pazymys > 10) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Pazymiai gali buti tik [0;10]." << endl; cin >> pazymys;
					}
					temp.paz.push_back(pazymys);
				}
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			int egzamino_balas = 0;
			cout << "Iveskite egzamino bala: " << endl; cin >> egzamino_balas;
			while (egzamino_balas < 0 || egzamino_balas>10) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Pazymiai gali buti tik [0; 10]." << endl; cin >> egzamino_balas;
			}
			temp.egz = egzamino_balas;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		else if (ivestis == 'a') {
			srand(time(NULL));

			cout << "Kiek pazymiu norite sugeneruoti?" << endl; int pazymiu_skaicius; cin >> pazymiu_skaicius;
			for (int i = 0; i < pazymiu_skaicius; i++) {
				temp.paz.push_back((rand() % 10) + 1);
			}

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			char ivestis;
			cout << "Jei norite ivesti egzamino rezultata, spauskite i.\nJei norite sugeneruoti egzamino rezultata, spauskite s." << endl; cin >> ivestis;
			if ((ivestis != 'i') && (ivestis != 's')) {
				cout << "Dar karta iveskite savo pasirinkima." << endl; cin >> ivestis;
			}
			else if (ivestis == 's') {
				temp.egz = (rand() % 10) + 1;
			}

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		else {
			cout << "Dar karta iveskite savo pasirinkima." << endl; cin >> ivestis;
		}
	}
	skaiciavimas(temp);
}

void spausdinimas(Studentas& temp) {
	cout << setw(15) << temp.vardas << setw(20) << temp.pavarde << setw(25) << fixed << setprecision(2) << temp.galutinis << endl;
}

int counter(string filename) {
	ifstream file(filename);
	int count = 0;
	string line;

	while (getline(file, line)) {
		count++;
	}
	file.close();
	return count-1;
}

bool compare_by_name(const Studentas & s1, const Studentas & s2) {
		return s1.vardas < s2.vardas;
	}

void sort_names() {
	sort(sarasas.begin(), sarasas.end(), compare_by_name);
}


void header_print() {
	cout << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(25) << "Galutinis ivertinimas" << endl;
	cout << "------------------------------------------------------------" << endl;
}

void double_header_print() {
	cout << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(25) << "Vid." << setw(30) << "Med." << endl;
	cout << "---------------------------------------------------------------------" << endl;
}

int read_file() {
	string filename; //failo, kuris yra nuskaitomas, pavadinimas (su .txt!).
	cout << "Iveskite norimo nuskaityti failo pavadinima: " << endl; cin >> filename;
	int element_count;
	cout << "Kelis namu darbu irasus siame faile turi kiekvienas mokinys?" << endl; cin >> element_count;

	ifstream file(filename);
	string c, line;
	int p;
	int count = counter(filename);

	getline(file, line); //praleidžiama pirmoji nenaudojama eilutė.

	for (int i = 0; i < count; i++) {
		file >> c;
		temp.vardas = c;
		file >> c;
		temp.pavarde = c;
		for (int i = 0; i < element_count; i++) {
			file >> p;
			temp.paz.push_back(p);
		}
		file >> p;
		temp.egz = p;
		sarasas.push_back(temp);
		temp.paz.clear();
	}
	file.close();
	return count;
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


int main()
{
	char ivestis;
	cout << "Ar norite, kad butu:\n n - Nuskaitomas pasirinktas failas?\n i - Naudojami ranka ivesti duomenys?" << endl; cin >> ivestis;
	while (((ivestis != 'n') && (ivestis != 'N')) && ((ivestis != 'i') && (ivestis != 'I'))) { cout << "Dar karta iveskite savo pasirinkima." << endl; cin >> ivestis; };
	if (ivestis == 'n' || ivestis == 'N') {
		read_file_datacalc(read_file());

		cout << "Ar norite:\nn- Toliau vesti duomenis?\nq - Baigti programos veikla?" << endl; cin >> ivestis;
		while (((ivestis != 'n') && (ivestis != 'N')) && ((ivestis != 'q') && (ivestis != 'Q'))) { cout << "Dar karta iveskite savo pasirinkima." << endl; cin >> ivestis; }
		if ((ivestis == 'n') || (ivestis == 'N')) { main(); }
		else return 0;
	}



	while(ivestis=='i' || ivestis=='I'){  //ivestis rankiniu būdu/atsitiktinis generavimas.
		do{
			ivedimas(temp);
			sarasas.push_back(temp);
			temp.paz.clear();
			cout << "Ar norite pildyti studentu sarasa?\nTaip - 't'.\nRodyti rezultatus - 'q'." << endl; cin >> ivestis;
			while((ivestis != 't') && (ivestis != 'q')) {
				cout << "Dar karta iveskite savo pasirinkima." << endl; cin >> ivestis;
			};
		} 
		while(ivestis == 't');
		masyv - 1;
		header_print();
		for(int i = 0; i < sarasas.size(); i++) spausdinimas(sarasas[i]);
		sarasas.clear();

		cout << "Ar norite:\nn- Toliau vesti duomenis?\nq - Baigti programos veikla?" << endl; cin >> ivestis;
		while (((ivestis != 'n') && (ivestis != 'N')) && ((ivestis != 'q') && (ivestis != 'Q'))) { cout << "Dar karta iveskite savo pasirinkima." << endl; cin >> ivestis; }
		if ((ivestis == 'n') || (ivestis == 'N')) { main(); }
		else return 0;
	}
	return 0;
}
