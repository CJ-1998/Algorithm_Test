/*
문제:
    순서쌍이란 두 개의 숫자를 순서를 정하여 짝지어 나타낸 쌍으로 (a, b)로 표기합니다. 자연수 n이 매개변수로 주어질 때 두 숫자의 곱이 n인 자연수 순서쌍의 개수를 return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ n ≤ 1,000,000
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num=1;
    while(num<=n){
        if(n%num==0){
            answer++;
        }
        num++;
    }
    
    return answer;
}

/*
개선 사항:
    1. while문 대신 for문으로 바꾸면 괜찮긴하다. 
*/