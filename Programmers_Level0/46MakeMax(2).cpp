/*
문제:
    정수 배열 numbers가 매개변수로 주어집니다. numbers의 원소 중 두 개를 곱해 만들 수 있는 최댓값을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    -10,000 ≤ numbers의 원소 ≤ 10,000
    2 ≤ numbers 의 길이 ≤ 100
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(),numbers.end());
    int temp1=numbers[0]*numbers[1];
    int temp2=numbers[numbers.size()-1]*numbers[numbers.size()-2];
    if(temp1>temp2){
        return temp1;
    }
    else{
        return temp2;
    }
}

/*
개선 사항:
    1. max함수 사용하면 큰 것 더 빠르게 찾아낼 수 있다. 

배운 점:
    1. max(a ,b); 하면 a와 b중 큰 값 반환한다. 
*/