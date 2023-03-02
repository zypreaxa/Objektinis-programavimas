
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