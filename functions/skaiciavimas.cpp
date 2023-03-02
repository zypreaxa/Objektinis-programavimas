
void skaiciavimas(Studentas& temp) {
	char inp;
	cout << "Norint gauti rezultata skaiciuota su mediana, spauskite m.\nNorint gauti rezultata skaiciuota su vidurkiu, spauskite v." << endl; cin >> inp;
	while ((inp != 'v') && (inp != 'V') && (inp != 'm') && (inp != 'M')) {
		cout << "Dar karta iveskite savo pasirinkima" << endl; cin >> inp;
	};

	if ((inp == 'v') || (inp == 'V')) { //jei įvedama 'v', skaičiuojamas galutinis balas naudojant vidurkį.
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