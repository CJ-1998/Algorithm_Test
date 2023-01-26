/*
문제:
    머쓱이네 피자가게는 피자를 여섯 조각으로 잘라 줍니다. 피자를 나눠먹을 사람의 수 n이 매개변수로 주어질 때, n명이 주문한 피자를 남기지 않고 모두 같은 수의 피자 조각을 먹어야 한다면 최소 몇 판을 시켜야 하는지를 return 하도록 solution 함수를 완성해보세요.

제한 사항:
    1 ≤ n ≤ 100
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int temp=1;
    while(true){
        if(n*temp%6==0){
            answer=n*temp;
            break;
        }
        temp++;
    }
    answer/=6;
    return answer;
}
/*
개선 사항:
    1. 6씩 추가하면서 인원수랑 나머지 연산했을 때 0이 되면 똑같이 먹는 것이다. 
*/