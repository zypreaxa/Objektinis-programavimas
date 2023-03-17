#include "fun.h"

vector<string> names;
vector<string> surnames;

void name_vectors() {
	srand(time(0));

	string name;
	ifstream namefile("first_names.txt");

	int name_count = counter("first_names.txt");
	for (int i = 0; i < name_count; i++) {
		getline(namefile, name);
		names.push_back(name);
	}
	namefile.close();

	string surname;
	ifstream surnamefile("surnames.txt");

	int surname_count = counter("surnames.txt");
	for (int i = 0; i < surname_count; i++) {
		getline(surnamefile, surname);
		surnames.push_back(surname);
	}
	surnamefile.close();
}



void file_generate(int size, string filename, int hw_count) {
	srand(time(0));
	std::atomic_bool loading{ true };
	std::thread loading_thread(show_loading_indicator, std::ref(loading));
	auto start = std::chrono::high_resolution_clock::now();
	int gen_grade;
	string name, surname;
	ofstream file(filename);

	if (file.is_open()) {
		file << left << setw(15) << "Name" << left << setw(15) << "Surname";
		for (int i = 0; i < hw_count; i++) {
			file << left << setw(7) << i + 1;
		}
		file << setw(8) << "Ex." << "\n";

		const int buffer_size = 1000;
		char buffer[buffer_size];
			
		for (int i = 0; i < size; i++) {
			int name_index = rand() % names.size();
			int surname_index = rand() % surnames.size();
			name = names[name_index]; surname = surnames[surname_index];
			int grades[15];
			for (int i = 0; i < hw_count + 1; i++) {
				gen_grade = rand() % 11;
				grades[i] = gen_grade;
			}
			snprintf(buffer, buffer_size, "%-15s%-15s%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%\n", name.c_str(), surname.c_str(), grades[0], grades[1], grades[2], grades[3], grades[4], grades[5], grades[6], grades[7], grades[8], grades[9], grades[10], grades[11], grades[12], grades[13], grades[14], gen_grade);
			file << buffer;
		}


		file.close();
		loading = false;
		loading_thread.join();
		cout << "\r";

		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		double seconds = duration.count() / 1000000.0;
		double minutes = seconds / 60.0;
		if (seconds < 60) { cout << "File '" << filename << "' has been created successfuly. Process took " << fixed << setprecision(2) << seconds << " seconds. " << endl; }
		else if (seconds >= 60) { cout << "File '" << filename << "' has been created successfuly. Process took " << fixed << setprecision(2) << minutes << " minutes. " << endl; }
		
	}
	else { cout << "File could not be created." << endl; }
}



void requirement_generate() {
	
	auto start = std::chrono::high_resolution_clock::now();
	name_vectors();
	file_generate(1000, "pirmas.txt", 15);
	file_generate(10000, "antras.txt", 15);
	file_generate(100000, "trecias.txt", 15);
	file_generate(1000000, "ketvirtas.txt", 15);
	file_generate(10000000, "penktas.txt", 15);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	cout << "File bundle took " << fixed << setprecision(2) << duration.count() / 1000000.0 << " seconds to generate.\n";
	cout << "All files have been generated successfully." << endl;
}

