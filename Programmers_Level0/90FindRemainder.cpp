/*
문제:
    정수 num1, num2가 매개변수로 주어질 때, num1를 num2로 나눈 나머지를 return 하도록 solution 함수를 완성해주세요.

제한 사항:
    0 < num1 ≤ 100
    0 < num2 ≤ 100
*/

#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = num1%num2;
    return answer;
}

/*
배운 점:
    1. 나머지 연산자
*/