/*
문제:
    임의의 양의 정수 n에 대해, n이 어떤 양의 정수 x의 제곱인지 아닌지 판단하려 합니다.
    n이 양의 정수 x의 제곱이라면 x+1의 제곱을 리턴하고, n이 양의 정수 x의 제곱이 아니라면 -1을 리턴하는 함수를 완성하세요.

제한 사항:
    n은 1이상, 50000000000000 이하인 양의 정수입니다.
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    for(int i=1;i<7071068;i++){
        long long temp=pow(i,2);
        if(n==temp){
            answer=pow(i+1,2);
            break;
        }
    }
    return answer;
}

/*
개선 사항:
    1. 우선 제곱근 구하고 다시 이것 제곱했을 때 원래랑 똑같은지 확인하는 것이다. 

배운 점:
    1. ow(n, m); 하면 n^m을 구해준다. double로 반환한다. cmath 라이브러리에 있다. 
    2. sqrt(n); 하면 n의 제곱근 구해준다. double로 반환한다. cmath 라이브러리에 있다.
*/