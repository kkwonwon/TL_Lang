#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string varType[] = {"정수형인", "실수형인", "문자형인", "논리형인"};

string funcType[] = {"반환하지 않는", "정수형을 반환하는", "실수형을 반환하는",
                     "문자형을 반환하는", "논리형을 반환하는"};

void build() {
    ofstream cfile("krl.c");
    
    
    
    cfile.close();
}