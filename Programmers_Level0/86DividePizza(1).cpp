/*
문제:
    머쓱이네 피자가게는 피자를 일곱 조각으로 잘라 줍니다. 피자를 나눠먹을 사람의 수 n이 주어질 때, 모든 사람이 피자를 한 조각 이상 먹기 위해 필요한 피자의 수를 return 하는 solution 함수를 완성해보세요.

제한 사항:
    1 ≤ n ≤ 100
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    if(n<=7){
        answer=1;
    }
    else{
        answer=n/7;
        if(n%7!=0){
            answer++;
        }
    }
    return answer;
}

/*
개선 사항:
    1. (n+slice-1)/slice하면 된다. 
*/