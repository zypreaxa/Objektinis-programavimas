#include "fun.h"

Studentas temp;				   //abu reikia deklaruoti bent vieną kartą, o *.h faile jie turi būti deklaruoti kaip extern.
vector<Studentas> sarasas;     //abu reikia deklaruoti bent vieną kartą, o *.h faile jie turi būti deklaruoti kaip extern.

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

void ivedimas(Studentas& temp) {
	cout << "Iveskite varda ir pavarde: "; cin >> temp.vardas >> temp.pavarde;

	char ivestis;
	cout << "Rankine ivestis - 'r'.\nAutomatinis pazymiu generavimas - 'a'." << endl; cin >> ivestis;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	while (true) {
		if ((ivestis == 'r') || (ivestis == 'R')) {
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
		else if ((ivestis == 'a') || (ivestis == 'A')) {
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


