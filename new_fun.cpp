#include "fun.h"

void template_gen_read() {
	int size = 1000;
	for (int i = 0; i < 5; i++) {
		split(gen(size, i));
		size = size * 10;
	}
}

vector<Studentas>* gen(int size, int index) {
	auto start = std::chrono::high_resolution_clock::now();
	vector<Studentas>* list = new vector<Studentas>();
	int gen_grade;
	string name, surname;
	ofstream file(std::to_string(index+1) + ".txt");
	if (!file) {
		cout << "error creating the file.\n";
	}
		cout << "yea";
		file << left << setw(15) << "Name" << left << setw(15) << "Surname";
		for (int i = 0; i < 15; i++) {
			file << left << setw(7) << i + 1;
		}
		file << setw(8) << "Ex." << "\n";

		const int buffer_size = 1000;
		char buffer[buffer_size];

		for (int i = 0; i < size; i++) {
			int name_index = rand() % names.size();
			int surname_index = rand() % surnames.size();
			name = names[name_index]; surname = surnames[surname_index];
			temp.vardas = name; temp.pavarde = surname;
			int grades[16];
			for (int i = 0; i < 15 + 1; i++) {
				gen_grade = rand() % 11;
				grades[i] = gen_grade;
				temp.paz.push_back(grades[i]);
			}
			temp.egz = temp.paz.back();
			calculate(temp);
			list->push_back(temp);
			temp.paz.clear();
			snprintf(buffer, buffer_size, "%-15s%-15s%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%\n", name.c_str(), surname.c_str(), grades[0], grades[1], grades[2], grades[3], grades[4], grades[5], grades[6], grades[7], grades[8], grades[9], grades[10], grades[11], grades[12], grades[13], grades[14], gen_grade);
			file << buffer;
		}
		file.close();
	

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	cout << "File reading took " << duration.count() / 1000000.0 << " seconds.\n";
	return list;
}

void split(vector<Studentas>* list) {
	auto start = std::chrono::high_resolution_clock::now();
	string line;
	ofstream protingi("protingi.txt");
	ofstream kvaili("kvaili.txt");

	const int buffer_size = 1000;
	char buffer[buffer_size];

	for (int i = 0; i < list->size(); i++) {
		snprintf(buffer, buffer_size, "%-15s%-15s%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%\n", list->at(i).vardas.c_str(), list->at(i).pavarde.c_str(), list->at(i).paz[0], list->at(i).paz[1], list->at(i).paz[2], list->at(i).paz[3], list->at(i).paz[4], list->at(i).paz[5], list->at(i).paz[6], list->at(i).paz[7], list->at(i).paz[8], list->at(i).paz[9], list->at(i).paz[10], list->at(i).paz[11], list->at(i).paz[12], list->at(i).paz[13], list->at(i).paz[14], list->at(i).egz);
		if (list->at(i).galutinis > 5) {
			protingi << buffer;
		}
		else kvaili << buffer;
	}
	protingi.close();
	kvaili.close();
	list->clear();
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	cout << "Student sorting took "<< duration.count() / 1000000.0 << " seconds.\n";
	delete list;
}