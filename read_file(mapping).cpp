#include "fun.h"
#include "windows.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <memory>
#include <thread>
#include <utility>

void read_file_map(const std::string& filename, char input) {
    HANDLE hFile = CreateFileA(filename.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Failed to open file " << filename << std::endl;
        return;
    }

    // Get the size of the file
    LARGE_INTEGER file_size;
    GetFileSizeEx(hFile, &file_size);

    // Map the file into memory
    HANDLE hMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, file_size.HighPart, file_size.LowPart, NULL);
    if (hMapping == NULL) {
        CloseHandle(hFile);
        std::cerr << "Error: Failed to create file mapping" << std::endl;
        return;
    }

    char* file_data = static_cast<char*>(
        MapViewOfFile(hMapping, FILE_MAP_READ, 0, 0, file_size.QuadPart)
        );

    // Close the file mapping handle and file handle since we don't need them anymore
    CloseHandle(hMapping);
    CloseHandle(hFile);

    // Iterate over the file data and extract the specific member you need
    char* ptr = file_data;
    string name, surname;
    int p;
    int hw_count = element_count(filename) - 3;
    int count = 0;
    string remainder;

    auto start = std::chrono::high_resolution_clock::now();
    std::atomic<bool> loading(true);
    std::thread l_thread(show_loading_indicator, std::ref(loading));

    while (ptr < file_data + file_size.QuadPart) {
        // Find the end of the current line
        char* end = strchr(ptr, '\n');
        if (end == NULL) {
            end = file_data + file_size.QuadPart;
        }

        // Extract the current line
        size_t len = end - ptr;
        std::string line(ptr, len);

        // Process the line
        std::istringstream iss(line);
        iss >> name >> surname;
        temp.vardas = name; temp.pavarde = surname;
        for (int i = 0; i < hw_count; i++) {
            iss >> p; temp.paz.push_back(p);
        }
        iss >> p; temp.egz = p;

            float vidurkis;
            if (temp.paz.size() != 0) {
                int suma = 0;
                for (int k = 0; k < temp.paz.size(); k++) {
                    suma = suma + temp.paz[k];
                }
                vidurkis = (float)suma / temp.paz.size();
            }
            else vidurkis = 0;
            float vidurkinis = (float)(0.4 * vidurkis) + (0.6 * temp.egz);

            float mediana = 0; //vidurkinio galutinio balo skaičiavimas.
            if (temp.paz.size() != 0) {
                sort(temp.paz.begin(), temp.paz.end());
                if (temp.paz.size() % 2 == 0) {
                    mediana = (float)(temp.paz[temp.paz.size() / 2] + temp.paz[temp.paz.size() / 2 - 1]) / 2.0;
                }
                else {
                    mediana = temp.paz[temp.paz.size() / 2];
                };
            }
            else mediana = 0;
            float medianinis = (0.4 * mediana) + (0.6 * temp.egz);
            if (input == 'v') {
                temp.galutinis = vidurkinis;
            }
            else if (input == 'm') {
                temp.galutinis = medianinis;
            }

            if (temp.galutinis < 5.0) { //priskiria mokiniui statusą (jei geras gauna 1, jei ne - 0).
                temp.status = 0;
            }
            else {
                temp.status = 1;
            }  
            sarasas.push_back(temp);
            temp.paz.clear();

        // Move the pointer to the beginning of the next line
        ptr = end + 1;
    }
    // Unmap the file from memory
    UnmapViewOfFile(file_data);
    loading = false;
    l_thread.join();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    cout << "Done! The process took " << duration.count() << " seconds." << endl;
    sort_status();
}




