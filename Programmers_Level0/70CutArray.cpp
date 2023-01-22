/*
문제:
    정수 배열 numbers와 정수 num1, num2가 매개변수로 주어질 때, numbers의 num1번 째 인덱스부터 num2번째 인덱스까지 자른 정수 배열을 return 하도록 solution 함수를 완성해보세요.

제한 사항:
    2 ≤ numbers의 길이 ≤ 30
    0 ≤ numbers의 원소 ≤ 1,000
    0 ≤num1 < num2 < numbers의 길이
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2) {
    vector<int> answer;
    for(int i=num1;i<=num2;i++){
        answer.push_back(numbers[i]);
    }
    return answer;
}

/*
개선 사항:
    1. 벡터 생성자에 벡터의 iterator 넣어서 하면 된다. 

배운 점:
    1. 벡터 초기화 시 생성자에 벡터의 iterator 넣어서 초기화 할 수 있다. 
*/