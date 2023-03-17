#include "fun.h"

void custom_file() {
	cout << "To proceed, fill in the information about the contents of this file:" << endl
		<< "How many students do you want the file to contain?" << " "; 
	int student_count; cin >> student_count;
	cout << endl << "What is the name of the file? (Please do include the .txt file extension.)" << " ";
	string filename; cin >> filename;
	cout << endl << "How many homework grades will each student have?" << " ";
	int hw_count; cin >> hw_count;
	cout << endl;

	name_vectors();
	file_generate(student_count, filename, hw_count);
}

void user_comm() {
	auto start = std::chrono::high_resolution_clock::now();
	char input;
	cout << "What would you like to do?" << endl << "----------------------------------------------------------------------" << endl
		<< "G(1) - generate a randomized student list file." << endl << "R(2) - input student data by hand." << endl
		<< "F(3) - read from a student file." << endl << "Q(4) - exit the program." << endl;

	try {
		cin >> input;

		if ((input != 'G') && (input != 'g') && (input != '1') && (input != 'R') && (input != 'r') && (input != '2') && (input != 'F') && (input != 'f') && (input != '3') && (input != 'Q') && (input != 'q') && (input != '4')) {
			throw runtime_error("Input could not be recognized. Please try again.");
		}

		while (input == 'G' || input == 'g' || input == '1') { //pasirinktas failų generavimas
			cout << "How would you like your files to be generated?" << endl << "R(1) - create a customised student list file." << endl << "T(2) - create student list files based on a template." << endl; cin >> input;
				if (input != 'R' && input != 'r' && input != '1' && input!='T' && input !='t' && input !='2') { throw runtime_error("Input could not be recognized. Please try again."); }
				if (input == 'R' || input == 'r' || input == '1') { //failas kuriamas pagal parinktis
					custom_file();
					if (cin >> input)
					system("cls");
					user_comm();
				}
				else if (input == 'T' || input == 't' || input == '2') { //generavimas pagal užduotį
					requirement_generate();
					if (cin >> input)
				    system("cls");
					user_comm();
				}
		}

		while (input == 'R' || input == 'r' || input == '2') {  //ivestis rankiniu būdu.
			do {
				ivedimas(temp);
				sarasas.push_back(temp);
				temp.paz.clear();
				cout << "Would you like to continue adding to the list?\nT - yes.\nQ - show results.\n"; cin >> input;
				while ((input != 't') && (input != 'q')) {
					cout << "Input could not be recognized.\n"; cin >> input;
				};
			} while (input == 't');
			header_print();
			for (int i = 0; i < sarasas.size(); i++) spausdinimas(sarasas[i]);
			sarasas.clear();
		}

		while (input == 'F' || input == 'f' || input == '3') { //skaitymas iš failo
			cout << "How would you like the file to be used?" << endl << "D(1) - displayed in the console." << endl << "F(2) - processed and split into two different files based on their final grade." << endl;
			cin >> input;
			if (input != 'D' && input != 'd' && input != '1' && input !='F' && input!='f' && input !='2') {
				throw runtime_error("Input could not be recognized. Please try again.");
			}
			if (input == 'D' || input == 'd' || input == '1') {
				read_file_datacalc(read_file());
				if (cin >> input)
				system("cls");
				user_comm();
			}
			else if (input == 'F' || input == 'f' || input == '2') {
				char grade_type;
				cout << "Would you like the students to be sorted by their average or median final grade?" << endl << "A - average." << endl << "M - median." << endl; cin >> grade_type;
				while (grade_type != 'A' && grade_type != 'a' && grade_type != 'M' && grade_type != 'm') {
					cout << "Input could not be recognized. Please try again." << endl; cin >> grade_type;
				}
				gen_file_datacalc(read_file(), grade_type);
				if (cin >> input)
				system("cls");
				user_comm();
			}
		}

		while (input == 'Q' || input == 'q' || input == '4') { //programos užbaigimas
			system("cls");
			cout << "Closing the program..." << endl;
			exit(1);
		}
	}

	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		system("cls");
		user_comm();
	}
	system("cls");
	user_comm();
}