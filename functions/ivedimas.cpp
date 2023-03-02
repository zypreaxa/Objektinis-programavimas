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