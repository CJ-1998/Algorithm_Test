/*
문제:
    어떤 세균은 1시간에 두배만큼 증식한다고 합니다. 
    처음 세균의 마리수 n과 경과한 시간 t가 매개변수로 
    주어질 때 t시간 후 세균의 수를 return하도록 
    solution 함수를 완성해주세요.

제한 사항:
    1 ≤ n ≤ 10
    1 ≤ t ≤ 15
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, int t) {
    int answer = 0;
    for(int i=0;i<t;i++){
        n*=2;
    }
    answer=n;
    return answer;
}

/*
개선 사항:
    1. shift 연산 (<<)
    2. pow(2, t) 사용

배운 점:
    1. shift 연산 왼쪽으로 하면 2를 곱하는, 오른쪽으로 하면 2를 나누는 효과가 있다. 
    2. pow 함수는 제곱 수를 구해주는 함수다. pow(n, t) 하면 n^t를 반환해준다. 반환형은 double이다.
*/