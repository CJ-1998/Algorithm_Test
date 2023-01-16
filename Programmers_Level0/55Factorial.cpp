/*
문제:
    i팩토리얼 (i!)은 1부터 i까지 정수의 곱을 의미합니다. 예를들어 5! = 5 * 4 * 3 * 2 * 1 = 120 입니다. 정수 n이 주어질 때 다음 조건을 만족하는 가장 큰 정수 i를 return 하도록 solution 함수를 완성해주세요.
        i! ≤ n

제한 사항:
    0 < n ≤ 3,628,800
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int fact=1;
    int index=1;
    while(true){
        fact*=index;
        if(fact>n){
            answer=index-1;
            break;
        }
        index++;
    }
    return answer;
}

/*
개선 사항 & 배운 점:
    1. while문 안의 if문을 while문의 조건으로 넣으면 좋다. 
    2. 변수도 index를 그냥 answer로 사용해도 된다.
*/