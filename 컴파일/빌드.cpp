#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

class Build
{
private:
    stack<string> stack;
public:
    Build(string** file);
    ~Build();
};

Build::Build(string** file)
{
}

Build::~Build()
{
}
