/*
문제: 
    문자열 str1, str2가 매개변수로 주어집니다. 
    str1 안에 str2가 있다면 1을 없다면 2를 return하도록 
    solution 함수를 완성해주세요.

제한 사항:
    1 ≤ str1의 길이 ≤ 100
    1 ≤ str2의 길이 ≤ 100
*/

#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    if(str1.find(str2)!=string::npos){
        return 1;
    }
    return 2;
}

/*
개선 사항:
    1. 3항 연산자 사용하면 조금 더 코드 길이 줄일 수 있다. 

배운 점:
    1. find 함수는 찾지 못하면 string::npos를 반환한다. 
*/