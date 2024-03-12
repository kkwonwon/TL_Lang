#include <string>
#include "Kind.h"
using namespace std;

struct Token {
    Kind kind = Kind::Unknown;
    wstring str;
};