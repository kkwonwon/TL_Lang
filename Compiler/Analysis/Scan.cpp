#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../Define/Token.h"
using namespace std;

static wstring::iterator current;

enum class CharType {
    Unknown,
    WhiteSpace,
    NumberLiteral,
    StringLiteral,
    IdentifierAndKeyword,
    OperatorAndPunctuator
};

wstring scan_files(int fileCount, char const *files[]) {
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
        while(getline(fin, line)) {
            file += line;
            file += "\n";
        }

        fin.close();
    }

    return wstring(file.begin(), file.end());
}

CharType get_char_type(char c) {
    return CharType::Unknown;
}

vector<Token> scan_token(int fileCount, char const *files[]) {
    wstring code = scan_files(fileCount, files);
    vector<Token> result;
    code += L'\0';
    current = code.begin();
    while (*current != L'\0')
    {
        wprintf(L"%c",*current++);
        // switch (get_char_type(*current))
        // {
        // case /* constant-expression */:
        //     /* code */
        //     break;
        
        // default:
        //     break;
        // }
    }
    result.push_back({Kind::EndOfCode});
    return result;
}

