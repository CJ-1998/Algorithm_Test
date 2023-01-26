/*
문제:   
    정수 n이 매개변수로 주어질 때, n 이하의 홀수가 오름차순으로 담긴 배열을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ n ≤ 100
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            answer.push_back(i);
        }
    }
    return answer;
}

/*
개선 사항:
    1. 1부터 2씩 증가시키면서 넣으면 된다. 
*/