/*
문제:
    머쓱이는 추운 날에도 아이스 아메리카노만 마십니다. 아이스 아메리카노는 한잔에 5,500원입니다. 머쓱이가 가지고 있는 돈 money가 매개변수로 주어질 때, 머쓱이가 최대로 마실 수 있는 아메리카노의 잔 수와 남는 돈을 순서대로 담은 배열을 return 하도록 solution 함수를 완성해보세요.

제한 사항:
    0 < money ≤ 1,000,000
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer;
    answer.push_back(money/5500);
    answer.push_back(money%5500);
    return answer;
}

/*
개선 사항 & 배운 점:
    1. 벡터 배열처럼 {} 안에 값 넣어서 초기화할 수 있다.
*/