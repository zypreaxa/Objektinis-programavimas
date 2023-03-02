int counter(string filename) {
	ifstream file(filename);
	int count = 0;
	string line;

	while (getline(file, line)) {
		count++;
	}
	file.close();
	return count - 1;
}