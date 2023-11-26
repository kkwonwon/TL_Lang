#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <map>
#include <string>
using namespace std;

/**
 * 함수의 시작위치와 값, 끝위치와 값을 저장
*/
class Func {
    map<int, string> strat;
    map<int, string> end;
};

/**
 * 코드를 해석하기전 분리시켜 
 * 스택에 삽입 후 실행
*/
void build(string **file) {
    stack<string[]> funcStack;
    list<Func> funcList;

    file_analysis(file, funcList);
    find_main(file, funcList, funcStack);
}

/**
 * 파일을 분석하여 함수의 시작부분과 끝부분을 리스트로 받는다.
*/
void file_analysis(string **file, list<Func> funcList) {

}

/**
 * 리스트에서 '시작' 함수를 찾고 그 함수를 스택에 넣어 실행시킨다.
*/
void find_main(string **file, list<Func> funcList, stack<string[]> funcStack) {

}

