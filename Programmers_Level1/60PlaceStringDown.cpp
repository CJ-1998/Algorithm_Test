/*
문제:
    문자열 s에 나타나는 문자를 큰것부터 작은 순으로 정렬해 새로운 문자열을 리턴하는 함수, solution을 완성해주세요.
    s는 영문 대소문자로만 구성되어 있으며, 대문자는 소문자보다 작은 것으로 간주합니다.

제한 사항:
    str은 길이 1 이상인 문자열입니다.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    sort(s.begin(),s.end(),greater<>());
    return s;
}

/*
개선 사항:
    1. 가장 큰 원소 answer에 더하고 그 위치의 index를 NULL로 바꾸면 된다.

배운 점:
    1. max_element 함수 사용법
    2. sort 함수 사용법
*/