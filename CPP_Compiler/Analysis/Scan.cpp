#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../Define/Token.h"
using namespace std;

static wstring::iterator current;

enum class CharType
{
    Unknown,
    WhiteSpace,
    NumberLiteral,
    StringLiteral,
    IdentifierAndKeyword,
    OperatorAndPunctuator
};

wstring scan_files(int fileCount, char const *files[])
{
    ifstream fin;
    string file;

    for (int i = 1; i < fileCount; i++)
    {
        int linesCount = 0;
        fin.open(files[i]);

        // 파일 여는데 실패했을 경우 처리
        if (!fin.is_open())
        {
            cerr << "Error opening file: " << files[i] << endl;
            return nullptr;
        }

        // file += '\n';
        string line;
        while (getline(fin, line))
        {
            file += line;
            file += "\n";
        }

        fin.close();
    }

    return wstring(file.begin(), file.end());
}

CharType get_char_type(wchar_t c)
{
    if (L' ' == c || L'\t' == c || L'\r' == c || L'\n' == c)
        return CharType::WhiteSpace;
    if (L'0' <= c && L'9' >= c)
        return CharType::NumberLiteral;
    if (L'\'' == c || L'\"' == c)
        return CharType::StringLiteral;
    if (L'가' <= c && L'힣' >= c)
        return CharType::IdentifierAndKeyword;
    return CharType::Unknown;
}

bool is_char_type(wchar_t c, CharType type)
{
    switch (type)
    {
    case CharType::NumberLiteral:
        return L'.' || L'0' <= c && L'9' >= c;
    case CharType::StringLiteral:
        return L'\'' != c && L'\"' != c;
    case CharType::IdentifierAndKeyword:
        return L'0' <= c && L'9' >= c ||
               L'가' <= c && L'힣' >= c;
    default:
        return false;
    }
}

Token scan_number_literal()
{
    wstring s;
    while (is_char_type(*current, CharType::NumberLiteral))
        s += *current++;
    return Token{Kind::NumberLiteral, s};
}

Token scan_string_literal()
{
    wstring s;
    current++;
    while (is_char_type(*current, CharType::StringLiteral))
        s += *current++;
    if (L'\'' != *current && L'\"' != *current)
    {
        cout << "문자열이 종료되지 않았습니다." << endl;
        exit(1);
    }
    return Token{Kind::StringLiteral, s};
}

Token scan_identifier_and_Keyword()
{
    wstring s;
    while (is_char_type(*current, CharType::StringLiteral))
        s += *current++;
    
}

vector<Token> scan_token(int fileCount, char const *files[])
{
    wstring code = scan_files(fileCount, files);
    vector<Token> result;
    code += L'\0';
    current = code.begin();
    while (*current != L'\0')
    {
        // wprintf(L"%c",*current++);
        switch (get_char_type(*current))
        {
        case CharType::WhiteSpace:
            current++;
            break;
        case CharType::NumberLiteral:
            result.push_back(scan_number_literal());
            break;
        case CharType::StringLiteral:
            result.push_back(scan_string_literal());
            break;
        case CharType::IdentifierAndKeyword:
            result.push_back(scan_identifier_and_Keyword());
        default:
            break;
        }
    }
    result.push_back({Kind::EndOfCode});
    return result;
}
