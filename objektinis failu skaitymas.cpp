#include "headers/personal_lib.h"
#include "headers/functions.h"
#include "headers/studentas.h"

bool compare_by_name(const Studentas& s1, const Studentas& s2);
int counter(string filename);
void double_header_print();
int element_count(string filename);
void header_print();
void ivedimas(Studentas& temp);
int read_file();
void read_file_datacalc(int count);
void skaiciavimas(Studentas& temp);
void sort_names();
void spausdinimas(Studentas& temp);


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
