
int read_file() {
	string filename; //failo, kuris yra nuskaitomas, pavadinimas (su .txt!).
	cout << "Iveskite norimo nuskaityti failo pavadinima: " << endl; cin >> filename;

	ifstream file(filename);
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
