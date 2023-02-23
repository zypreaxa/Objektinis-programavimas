#include "Header.h"

struct Studentas {
	string vardas, pavarde;
	vector<int> paz; //naudojamas vietoje masyvo rodykles
	int egz;
	float galutinis; //apskaičiuojamas pagal pasirinkimą(vidurkį arba medianą).
};

int masyv = 1; //struktūrų masyvų skaičius.

void skaiciavimas(Studentas& temp) {
	char inp;
	cout << "Norint gauti rezultata skaiciuota su mediana, spauskite m.\nNorint gauti rezultata skaiciuota su vidurkiu, spauskite v."; cin >> inp;
	while (inp != 'v' && inp != 'm') {
		cout << "Dar karta iveskite savo pasirinkima" << endl; cin >> inp;
	};

	if(inp == 'v') { //jei įvedama 'v', skaičiuojamas galutinis balas naudojant vidurkį.
		float vidurkis;
		if(temp.paz.size() != 0) {
			int suma = 0;
			for(int i = 0; i < temp.paz.size(); i++) {
				suma = suma + temp.paz[i];
			}
			vidurkis = (float)suma / temp.paz.size();
		}
		else{
			vidurkis = 0;
		}

		temp.galutinis = (float)(0.4 * vidurkis) + (0.6 * temp.egz);
	}
	else{ //jei įvedama 'm', skaičiuojamas galutinis balas naudojant medianą.
		float mediana = 0;
		if(temp.paz.size() != 0) {
			sort(temp.paz.begin(), temp.paz.end());
			if(temp.paz.size() % 2 == 0) {
				mediana = (float)(temp.paz[temp.paz.size() / 2] + temp.paz[temp.paz.size() / 2 - 1]) / 2.0;
			}
			else{
				mediana = temp.paz[temp.paz.size() / 2];
			};
		}
		else mediana = 0;

		temp.galutinis = (0.4 * mediana) + (0.6 * temp.egz);
	}
}


// void mediana(Studentas &temp) {
//     double median = 0;
//     if(temp.paz_mas_dydis%2 != 0) {
//         median = temp.paz[temp.paz_mas_dydis/2];
//     }
//     else median = (temp.paz[temp.paz_mas_dydis/2] + temp.paz[(temp.paz_mas_dydis/2)-1]) / 2;
//     temp.med_gal=0.4*median+0.6*temp.egz;
// }

// void vidurkis(Studentas &temp) {
//     double vidurk;
//     for(int i=0; i<temp.paz_mas_dydis; i++) {
//         vidurk = vidurk + temp.paz[i];
//     }
//     vidurk = vidurk/temp.paz_mas_dydis;
//     temp.vid_gal=0.4*vidurk+0.6*temp.egz;
// }

void ivedimas(Studentas& temp) {
	cout << "Iveskite varda ir pavarde: "; cin >> temp.vardas >> temp.pavarde;

	char ivestis;
	cout << "Rankine ivestis - 'r'.\nAutomatinis pazymiu generavimas - 'a'." << endl;
	cin >> ivestis;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	while(true) {
		if(ivestis == 'r') {
			cout << "Iveskite pazymius: " << endl;

			int pazymys;
			int dydis = 1, index = 0; //dydis - masyvo dydis. index - pozicija masyve.
			int* a = new int[dydis];

			while(cin >> pazymys) {
				if(dydis == 1) {
					while(true) {
						if(pazymys >= 0 && pazymys <= 10) {
							a[index] = pazymys;
							dydis++;
							int* b = new int[dydis];	  //sukuriamas didesnis masyvas
							copy_n(a, 1, b);		  //a -> b
							delete[]a;				  //a -/- 
							a = b;					  //rodyklė rodo į b
							b = NULL;					  //b rodo į null
							break;
						}
						else{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Pazymiai gali buti tik [0; 10]." << endl; cin >> pazymys;
						}
					}
				}
				else{
					while(true) {					//viskas vykdoma kol programa užbaigiama
						if(pazymys >= 0 && pazymys <= 10) { //[0;10]
							dydis++;
							index++;
							a[index] = pazymys;
							int* b = new int[dydis];
							copy(a, a + (dydis - 1), b);
							delete[]a;
							a = b;
							b = NULL;
							break;
						}
						else{ //įvestis nepriklauso [0;10]
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Pazymiai gali buti tik [0; 10]." << endl; cin >> pazymys;
						}
						temp.paz.push_back(pazymys);
					}
				}
			}

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			int egzamino_balas = 0;
			cout << "Iveskite egzamino bala: " << endl; cin >> egzamino_balas;
			while(egzamino_balas < 0 || egzamino_balas>10) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Pazymiai gali buti tik [0; 10]." << endl; cin >> egzamino_balas;
			}
			temp.egz = egzamino_balas;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		else if(ivestis == 'a') {
			srand(time(NULL));

			cout << "Kiek pazymiu norite sugeneruoti?" << endl; int pazymiu_skaicius; cin >> pazymiu_skaicius;
			for(int i = 0; i < pazymiu_skaicius; i++) {
				temp.paz.push_back((rand() % 10) + 1);
			}

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			char ivestis;
			cout << "Jei norite ivesti egzamino rezultata, spauskite i.\nJei norite sugeneruoti egzamino rezultata, spauskite s." << endl; cin >> ivestis;
			if((ivestis != 'i') && (ivestis != 's')) {
				cout << "Dar karta iveskite savo pasirinkima." << endl; cin >> ivestis;
			}
			else if(ivestis == 's') {
				temp.egz = (rand() % 10) + 1;
			}

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		else{
			cout << "Dar karta iveskite savo pasirinkima." << endl; cin >> ivestis;
		}
	}
	skaiciavimas(temp);
}

void spausdinimas(Studentas& temp) {
	cout << setw(15) << temp.vardas << setw(20) << temp.pavarde << setw(25) << fixed << setprecision(2) << temp.galutinis << endl;
}


int main()
{
	vector<Studentas> sarasas;
	Studentas temp;
	char ivestis;
	do{
		ivedimas(temp);
		sarasas.push_back(temp);
		temp.paz.clear();
		cout << "Ar norite pildyti studentu sarasa?\nTaip - 't'.\nRodyti rezultatus - 'q'." << endl; cin >> ivestis;
		while((ivestis != 't') && (ivestis != 'q')) {
			cout << "Dar karta iveskite savo pasirinkima." << endl; cin >> ivestis;
		};
	} while(ivestis == 't');
	masyv - 1;
	cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(25) << "Galutinis ivertinimas" << endl;
	cout << "------------------------------------------------------------" << endl;
	for(int i = 0; i < sarasas.size(); i++) spausdinimas(sarasas[i]);
	sarasas.clear();
}
