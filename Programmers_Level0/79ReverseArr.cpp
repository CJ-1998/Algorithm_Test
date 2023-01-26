/*
문제:   
    정수가 들어 있는 배열 num_list가 매개변수로 주어집니다. num_list의 원소의 순서를 거꾸로 뒤집은 배열을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ num_list의 길이 ≤ 1,000
    0 ≤ num_list의 원소 ≤ 1,000
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    reverse(num_list.begin(), num_list.end());
    return num_list;
}

/*
배운 점:
    1. reverse 함수 사용법
*/