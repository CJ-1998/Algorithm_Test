/*
문제:
    어떤 자연수를 제곱했을 때 나오는 정수를 제곱수라고 합니다. 
    정수 n이 매개변수로 주어질 때, n이 제곱수라면 1을 
    아니라면 2를 return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ n ≤ 1,000,000
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int result=(int)sqrt(n);
    if(result*result==n){
        answer=1;
    }
    else{
        answer=2;
    }
    return answer;
}

/*
개선 사항:
    1. 3항 연산자 사용하면 조금 더 간단히 가능할 것 같다. 

배운 점:
    1. double sqrt(double)은 루트 씌운 값을 반환해준다. cmath 라이브러리에 있다. 
*/