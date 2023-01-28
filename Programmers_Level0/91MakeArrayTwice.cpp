/*
문제:
    정수 배열 numbers가 매개변수로 주어집니다. numbers의 각 원소에 두배한 원소를 가진 배열을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    -10,000 ≤ numbers의 원소 ≤ 10,000
    1 ≤ numbers의 길이 ≤ 1,000
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0;i<numbers.size();i++){
        answer.push_back(numbers[i]*2);
    }
    return answer;
}

/*
개선 사항:
    1. shift 연산자 사용
    2. 벡터 주소로 접근해서 그 주소의 값 2배 시키기

배운 점:
    1. shift 연산자 
    2. auto& 사용법
*/