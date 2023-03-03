#include "fun.h"

int main() {
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



		while (ivestis == 'i' || ivestis == 'I') {  //ivestis rankiniu būdu/atsitiktinis generavimas.
			do {
				ivedimas(temp);
				sarasas.push_back(temp);
				temp.paz.clear();
				cout << "Ar norite pildyti studentu sarasa?\nTaip - 't'.\nRodyti rezultatus - 'q'." << endl; cin >> ivestis;
				while ((ivestis != 't') && (ivestis != 'q')) {
					cout << "Dar karta iveskite savo pasirinkima." << endl; cin >> ivestis;
				};
			} while (ivestis == 't');
			header_print();
			for (int i = 0; i < sarasas.size(); i++) spausdinimas(sarasas[i]);
			sarasas.clear();

			cout << "Ar norite:\nn- Toliau vesti duomenis?\nq - Baigti programos veikla?" << endl; cin >> ivestis;
			while (((ivestis != 'n') && (ivestis != 'N')) && ((ivestis != 'q') && (ivestis != 'Q'))) { cout << "Dar karta iveskite savo pasirinkima." << endl; cin >> ivestis; }
			if ((ivestis == 'n') || (ivestis == 'N')) { main(); }
			else return 0;
}
	return 0;
}
