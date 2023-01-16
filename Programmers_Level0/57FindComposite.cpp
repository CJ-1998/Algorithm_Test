/*
문제:
    약수의 개수가 세 개 이상인 수를 합성수라고 합니다. 자연수 n이 매개변수로 주어질 때 n이하의 합성수의 개수를 return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ n ≤ 100
*/

#include <string>
#include <vector>

using namespace std;

bool isCollection(int num){
    int temp=2;
    while(true){
        if(num%temp==0){
            if(num!=temp)
                return false;
            else
                return true;
        }
        else{
            temp++;
        }
    }
}

int solution(int n) {
    int answer;
    if(n>3){
        answer = n-3;
        for(int i=4;i<=n;i++){
            if(isCollection(i)){
                answer--;
            }
        }
    }
    else{
        answer=0;
    }
    
    return answer;
}

/*
개선 사항:  
    1. 소수 찾는 것보다 합성수 찾는 것이 더 간단한 것 같다. 
    2. 나눠 떨어지는 수가 즉 약수가 3개 이상이면 합성수이다. 
    3. 그래서 나머지가 0이면 cnt++해서 cnt가 3이상 되면 합성수라고 하면 된다.
*/