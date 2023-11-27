#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <map>
#include <string>
using namespace std;

/**
 * 함수의 시작위치와 값, 끝위치와 값을 저장
*/
class Func {
public:
    /**함수 시작 부분의 인덱스와 라인*/
    map<int, string> strat;
    /**함수 종료 부분의 인덱스와 라인*/
    map<int, string> end;
};

/**
 * 코드를 해석하기전 분리시켜 
 * 스택에 삽입 후 실행
*/
void build(string **file) {
    stack<string[]> funcStack;
    vector<Func> funcVec;

    file_analysis(file, funcVec);
    find_main(file, funcVec, funcStack);
}

/**
 * 파일을 분석하여 함수의 시작부분과 끝부분을 리스트로 받는다.
*/
void file_analysis(string **file, vector<Func> funcVec) {
    
}

/**
 * 리스트에서 '시작' 함수를 찾고 그 함수를 스택에 넣어 실행시킨다.
*/
void find_main(string **file, vector<Func> funcVec, stack<string[]> funcStack) {

}
