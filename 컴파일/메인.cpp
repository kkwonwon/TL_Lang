#include <iostream>
#include <fstream>
#include <string>
#include "파일.cpp"
#include "빌드.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    string **file = file_scan(argc, argv);
    int *lineCounts = line_count(argc, argv);

    if (scan_error(file, lineCounts, argc)) return 1;

    print_file(file, lineCounts, argc);

    build(file, lineCounts, argc);

    for (int i = 0; i < argc - 1; i++)
        delete[] file[i];
    delete[] file;
    delete[] lineCounts;

    return 0;
}
