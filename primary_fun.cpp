#include "fun.h"

Studentas temp;				   //abu reikia deklaruoti bent vieną kartą, o *.h faile jie turi būti deklaruoti kaip extern.
vector<Studentas> sarasas;     //abu reikia deklaruoti bent vieną kartą, o *.h faile jie turi būti deklaruoti kaip extern.

void skaiciavimas(Studentas& temp) {
	char inp;
	cout << "Would you like the final grade to be calculated by:\nA(1) - average grade.\nM(2) - median of grades.\n" << endl; cin >> inp;
	while ((inp != 'A') && (inp != 'a') && (inp != '1') && (inp != 'M') && (inp != 'm') && (inp != '2')) {
		cout << "Input could not be recognized\n"; cin >> inp;
	}

	if ((inp == 'A') || (inp == 'a') || (inp == '1')){ //jei įvedama 'v', skaičiuojamas galutinis balas naudojant vidurkį.
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
	cout << "Provide the name and surname of the student.\n"; cin >> temp.vardas >> temp.pavarde;

	char ivestis;
	cout << "R(1) - custom grades.\nA(2) - automated grades.\n"; cin >> ivestis;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	while (ivestis != 'R' && ivestis != 'r' && ivestis!= '1' && ivestis != 'A' && ivestis != 'a' && ivestis !='2') { cout << "Input could not be recognized." << endl; cin >> ivestis; }

		if ((ivestis == 'r') || (ivestis == 'R')) {
			cout << "Type in the grades of the student.\n" << endl;

			int pazymys;

			while (cin >> pazymys) {
				if ((pazymys >= 0) && (pazymys <= 10)) { temp.paz.push_back(pazymys); }
				else {
					while ((pazymys < 0) || pazymys > 10) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Student grades can only be [0;10].\n"; cin >> pazymys;
					}
					temp.paz.push_back(pazymys);
				}
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			int egzamino_balas = 0;
			cout << "What is the student's exam grade?\n " << endl; cin >> egzamino_balas;
			while (egzamino_balas < 0 || egzamino_balas>10) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Student exam grade can only be [0; 10]." << endl; cin >> egzamino_balas;
			}
			temp.egz = egzamino_balas;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if ((ivestis == 'a') || (ivestis == 'A')) {
			srand(time(NULL));

			cout << "How many grades do you wish to generate?\n" << endl; int pazymiu_skaicius; cin >> pazymiu_skaicius;

			for (int i = 0; i < pazymiu_skaicius; i++) {
				temp.paz.push_back((rand() % 10) + 1);
			}
			temp.egz = (rand() % 10) + 1;
		}
		else {
			cout << "Input could not be recognized.\n" << endl; cin >> ivestis;
		}
		cin.clear();
		skaiciavimas(temp);	
}



void calculate(Studentas& temp) {
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