/*
문제:
    정수 num이 짝수일 경우 "Even"을 반환하고 홀수인 경우 "Odd"를 반환하는 함수, solution을 완성해주세요.

제한 사항: 
    num은 int 범위의 정수입니다.
    0은 짝수입니다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    if(num%2==0){
        answer="Even";
    }
    else{
        answer="Odd";
    }
    return answer;
}

/*
개선 사항:
    1. 홀수를 비트로 바꾸면 1의 자리에 1이 있으니 이것을 조건으로 해서 3항 연산자 쓰면 된다.

배운 점:
    1. 홀수는 1과 AND 연산 = &하면 1이 나온다. 
*/