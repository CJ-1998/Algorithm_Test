/*
문제:
    두 배열이 얼마나 유사한지 확인해보려고 합니다. 
    문자열 배열 s1과 s2가 주어질 때 같은 원소의 개수를 
    return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ s1, s2의 길이 ≤ 100
    1 ≤ s1, s2의 원소의 길이 ≤ 10
    s1과 s2의 원소는 알파벳 소문자로만 이루어져 있습니다
    s1과 s2는 각각 중복된 원소를 갖지 않습니다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s2.size();j++){
            if(!s1[i].compare(s2[j])){
                answer++;
            }
        }
    }
    return answer;
}

/*
개선 사항:
    1. algorithm 라이브러리의 find 함수 사용

배운 점:
    1. algorithm 라이브러리에 있는 find(first, last, i) 함수 사용법
    2. first~last에서 i와 같은 첫번째 원소 가리키는 반복자 반환
    3. 일치 원소 없으면 last를 반환
*/