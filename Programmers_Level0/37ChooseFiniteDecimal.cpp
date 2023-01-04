/*
문제:
    소수점 아래 숫자가 계속되지 않고 유한개인 소수를 
    유한소수라고 합니다. 분수를 소수로 고칠 때 유한소수로 
    나타낼 수 있는 분수인지 판별하려고 합니다. 
    유한소수가 되기 위한 분수의 조건은 다음과 같습니다.
        기약분수로 나타내었을 때, 분모의 소인수가 2와 5만 
        존재해야 합니다.
    두 정수 a와 b가 매개변수로 주어질 때, a/b가 유한소수이면 
    1을, 무한소수라면 2를 return하도록 
    solution 함수를 완성해주세요.

제한 사항:
    a, b는 정수
    0 < a ≤ 1,000
    0 < b ≤ 1,000
*/

#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 1;
    for(int i=2;i<=a;i++){
        if(a%i==0&&b%i==0){
            a/=i;
            b/=i;
            i=2;
        }
    }
    while(b!=1){
        if(b%2==0){
            b/=2;
        }
        else if(b%5==0){
            b/=5;
        }
        else{
            return 2;
        }
    }
    return answer;
}

/*
개선 사항:
    1. 기약 분수를 만들 때 gcd 함수를 사용해서 만든다. 

배운 점:
    1. gcd 함수는 최대 공약수를 구해주는 함수로 numeric 라이브러리에 있다. 
    2. lcm 함수는 최소 공배수를 구해주는 함수로 numeric 라이브러리에 있다.
*/