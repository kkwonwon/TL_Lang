#include <string>
#include <map>
#include "Kind.h"
using namespace std;

static map<wstring, Kind> stringToKind = {
    {L"#unknown",       Kind::Unknown},
    {L"#EndOfCode",     Kind::EndOfCode},

    {L"참",             Kind::TrueLiteral},
    {L"거짓",           Kind::FalseLiteral},
    {L"#Number",        Kind::NumberLiteral},
    {L"#String",        Kind::StringLiteral},
    {L"#identifier",    Kind::Identifier},

    {L"함수",           Kind::Function},
    {L"반환한다",       Kind::Return},
    {L"만약",           Kind::If},
    {L"아니면",         Kind::Else}
};