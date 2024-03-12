#include <iostream>
#include <fstream>
#include <string>
#include "./Analysis/Scan.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    vector<Token> tokenList = scan_token(argc, argv);

    return 0;
}
