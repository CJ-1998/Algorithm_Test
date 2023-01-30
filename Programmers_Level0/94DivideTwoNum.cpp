/*
문제:
    정수 num1과 num2가 매개변수로 주어질 때, num1을 num2로 나눈 값에 1,000을 곱한 후 정수 부분을 return 하도록 soltuion 함수를 완성해주세요.

제한 사항:
    0 < num1 ≤ 100
    0 < num2 ≤ 100
*/

#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    double temp=(double)num1/(double)num2;
    answer=temp*1000;
    return answer;
}

/*
개선 사항:
    1. 미리 1000 곱하고 하면 된다. 
*/