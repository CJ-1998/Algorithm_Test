/*
문제:
    자연수 n이 매개변수로 주어집니다. n을 x로 나눈 나머지가 1이 되도록 하는 가장 작은 자연수 x를 return 하도록 solution 함수를 완성해주세요. 답이 항상 존재함은 증명될 수 있습니다

제한 사항:
    3 ≤ n ≤ 1,000,000
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=2;i<1000000;i++){
        if(n%i==1){
            answer=i;
            break;
        }
    }
    return answer;
}

/*
개선 사항
    1. for문 탈출조건이 1000000이 아니라 n으로 해야 한다. 
*/