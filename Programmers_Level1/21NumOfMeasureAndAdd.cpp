/*
문제:
    두 정수 left와 right가 매개변수로 주어집니다. left부터 right까지의 모든 수들 중에서, 약수의 개수가 짝수인 수는 더하고, 약수의 개수가 홀수인 수는 뺀 수를 return 하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ left ≤ right ≤ 1,000
*/

#include <string>
#include <vector>

using namespace std;

int getNum(int num){
    int n=0;
    for(int i=1;i<=num;i++){
        if(num%i==0){
            n++;
        }
    }
    return n;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i=left;i<=right;i++){
        int temp=getNum(i);
        if(temp%2==0){
            answer+=i;
        }
        else{
            answer-=i;
        }
    }
    
    return answer;
}

/*
개선 사항 & 배운 점:
    1. 약수 구하는 것 절반까지만 해도 된다. 
    2. 마지막 bit가 1이면 홀수고 0이면 짝수다.
*/