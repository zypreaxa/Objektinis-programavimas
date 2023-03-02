
int element_count(string filename) { //skaičiuojama kiek elementų yra vienoje eilutėje. Vėliau naudojama pažymių sukėlimui į vektorių (elemetų skaičius - 3 = ND pažymių skaičius).

	ifstream file(filename);

	string line;
	getline(file, line);
	stringstream s(line);

	string element;
	int count = 0;

	while (s >> element) { count++; }
	file.close();
	return count;
}