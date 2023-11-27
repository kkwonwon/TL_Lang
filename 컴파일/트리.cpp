#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TreeNode
{
public:
    string data;
    vector<TreeNode> *child;

    TreeNode(string value) : data(value), child(nullptr) {}
};

class AST {

};
