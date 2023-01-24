/*
문제:
    정수 n이 주어질 때, n이하의 짝수를 모두 더한 값을 return 하도록 solution 함수를 작성해주세요.

제한 사항:
    0 < n ≤ 1000
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            answer+=i;
        }
    }
    return answer;
}

/*
개선 사항:
    1. for문에서 2씩 증가시키면 된다. 

배운 점:
    1. 짝수 합은 n^2+n이다. (n은 주어진 정수/2이다.)
*/