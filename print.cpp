#include "fun.h"

void spausdinimas(Studentas& temp) {
	cout << setw(15) << temp.vardas << setw(20) << temp.pavarde << setw(25) << fixed << setprecision(2) << temp.galutinis << endl;
}

void header_print() {
	cout << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(25) << "Galutinis ivertinimas" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
}

void double_header_print() {
	cout << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(25) << "Vid." << setw(30) << "Med." << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
}
