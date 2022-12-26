/*
문제:
    정수 n이 매개변수로 주어질 때 n의 각 자리 숫자의 합을 return하도록 solution 함수를 완성해주세요

제한 사항:
    0 ≤ n ≤ 1,000,000
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    while(n!=0){
        answer+=n%10;
        n/=10;
    }
    return answer;
}

/*
개선 사항:
    1. 대부분 비슷하게 해서 없는 듯하다. 

배운 점:
    숫자가 주어지고 자리수를 구하려면 
    숫자가 0이 될 때까지 반복하며 10으로 나눈 나머지를 구한다. 
    그러면 끝자리 수부터 구해진다. 
    그리고 숫자를 10으로 나눈 몫으로 바꿔주면 된다. 
*/