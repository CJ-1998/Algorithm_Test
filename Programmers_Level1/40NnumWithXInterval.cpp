/*
문제:
    함수 solution은 정수 x와 자연수 n을 입력 받아, x부터 시작해 x씩 증가하는 숫자를 n개 지니는 리스트를 리턴해야 합니다. 다음 제한 조건을 보고, 조건을 만족하는 함수, solution을 완성해주세요.

제한 사항:
    x는 -10000000 이상, 10000000 이하인 정수입니다.
    n은 1000 이하인 자연수입니다.
*/

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long temp=0;
    for(int i=0;i<n;i++){
        temp+=x;
        answer.push_back(temp);
    }
    return answer;
}

/*
개선 사항:
    1. 전 값에 x 더하거나 index에 x 곱하면 된다. 
*/