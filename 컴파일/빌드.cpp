#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string varType[] = {"정수형인", "실수형인", "문자형인", "논리형인"};

string funcType[] = {"반환하지않는", "정수형을반환하는", "실수형을반환하는",
                     "문자형을반환하는", "논리형을반환하는"};

void build(string **file, int *lineCounts, int fileCount) {
    ofstream cfile("krl.c");
    
    find_main(file, lineCounts, fileCount);
    // cfile.write("#include <stdio.h>", 18);
    
    cfile.close();
}

void find_main(string **file, int *lineCounts, int fileCount) {
    for (int i = 0; i < fileCount - 1; i++)
    {
        for (int j = 0; j < lineCounts[i]; j++)
        {
            vector<string> line = split(file[i][j], ' ');
        }
    }
}

vector<string> split(string s, char key) {
    vector<string> re;
    stringstream ss(s);
    string temp;
 
    while (getline(ss, temp, key)) {
        re.push_back(temp);
    }
 
    return re;
}