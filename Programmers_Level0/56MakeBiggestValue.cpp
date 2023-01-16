/*
문제:
    정수 배열 numbers가 매개변수로 주어집니다. numbers의 원소 중 두 개를 곱해 만들 수 있는 최댓값을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    0 ≤ numbers의 원소 ≤ 10,000
    2 ≤ numbers의 길이 ≤ 100
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    sort(numbers.begin(),numbers.end());
    answer=numbers[numbers.size()-1]*numbers[numbers.size()-2];
    return answer;
}

/*
배운 점:
    1. sort 내림차순으로 하려면 3번째 인자로 greater<int>() 주면 된다.
*/
