#include <iostream>
#include <string>
using namespace std;

class TreeNode {
public:
    string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string value) : data(value), left(nullptr), right(nullptr) {}
};