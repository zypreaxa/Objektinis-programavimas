#include "fun.h"
vector<Studentas> protingi;
vector<Studentas> kvaileliai;

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
	string filename;
	ofstream protingi("protingi.txt");
	ofstream kvaili("kvaili.txt");
	cout << "What is the name of the file you want to read from?" << endl; cin >> filename;
	try {
		auto start = std::chrono::high_resolution_clock::now();
		ifstream file(filename);
		if (!file) {
			throw runtime_error("Failas nerastas!");
		}
		string line;

		cout << "Reseving space for student list...";
		cout << "\r" << "                                               ";
		getline(file, line); //praleidžiama pirmoji nenaudojama eilutė.

		std::atomic_bool loading = { true };
		std::thread l_thread(show_loading_indicator, std::ref(loading));
		while (getline(file, line)) {
			std::istringstream iss(line);
			line_calc(iss);
			sort_stud(temp, protingi, kvaili, iss);
		}

		file.close();
		protingi.close();
		kvaili.close();
		loading = false;
		l_thread.join();
		cout << "\r";
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		double seconds = duration.count() / 1000000.0;
		cout << "File reading took " << fixed << setprecision(2) << seconds << " seconds." << endl;
		int count = counter(filename);
		return count;
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
		int main();
	}
}

void line_calc(std::istringstream &line) {
	line >> temp.vardas >> temp.pavarde;
	int p;
	while (line >> p) {
		temp.paz.push_back(p);
	}
	temp.egz = temp.paz.back();
	calculate(temp);
	temp.paz.clear();
	temp.egz = 0;
}

void sort_stud(Studentas& temp, ofstream &protingi, ofstream &kvaili, std::istringstream &line) {
	string line_str = line.str(); //istringstreamas pakeiciamas i paprasta stringa.
	if (temp.galutinis > 5) {
		protingi << line_str << '\n';
	}
	else if (temp.galutinis <= 5 && temp.galutinis > 0) {
		kvaili << line_str << '\n';
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

void sort_status() { //patikrina kiekvieną sąraše esantį studentą ir pagal jo statusą prirašo jį į priklausomą failą.
	auto start = std::chrono::high_resolution_clock::now();


	for (int i = 0; i < sarasas.size(); i++) {
		if (sarasas[i].status == 1) {
			protingi.push_back(sarasas[i]);
		}
		else if (sarasas[i].status == 0) {
			kvaileliai.push_back(sarasas[i]);
		}
	}
	sarasas.clear();

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	cout << "Student sorting took " << duration.count() / 1000000.0 << " seconds." << endl;
	cout << "Student list has been split successfully." << endl;
	data_sep();
}

void data_sep() {

	auto start = std::chrono::high_resolution_clock::now();
	
	ofstream file_pr("protingi.txt");
	for (int i = 0; i < protingi.size(); i++) {
		file_pr << left << setw(15) << protingi[i].vardas << left << setw(15) << protingi[i].pavarde << left << setw(20) << fixed << setprecision(2) << protingi[i].galutinis << '\n';
	}
	file_pr.close();
	protingi.clear();

	ofstream file_kv("kvaileliai.txt");
	for (int i = 0; i < kvaileliai.size(); i++) {
		file_kv << left << setw(15) << kvaileliai[i].vardas << left << setw(15) << kvaileliai[i].pavarde << left << setw(20) << fixed << setprecision(2) << kvaileliai[i].galutinis << '\n';
	}
	file_kv.close();
	kvaileliai.clear();
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	cout << "File sorting took " << duration.count() / 1000000.0 << " seconds.\nAll done!\nPress any key to go back to the main screen.\n";

}

void gen_file_datacalc(int count, char input) { // nuskaito failo duomenis, juos sudeda į struktūras, apskaičiuoja studento statusą pagal galutinį balą.
	auto start = std::chrono::high_resolution_clock::now();
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
		else vidurkis = 0;
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
		if (input == 'A'|| input == 'a') {
			sarasas[i].galutinis = vidurkinis;
		}
		else if (input == 'M'|| input == 'm') {
			sarasas[i].galutinis = medianinis;
		}

		if (sarasas[i].galutinis < 5.0) { //priskiria mokiniui statusą (jei geras gauna 1, jei ne - 0).
			sarasas[i].status = 0;
		}
		else {
			sarasas[i].status = 1;
		}
	}
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	double seconds = duration.count() / 1000000.0;
	cout << "Student data calculation and tagging took " << seconds << " seconds." << endl;
	sort_status();
}

