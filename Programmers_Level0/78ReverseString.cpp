/*
문제:
    문자열 my_string이 매개변수로 주어집니다. my_string을 거꾸로 뒤집은 문자열을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ my_string의 길이 ≤ 1,000
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    reverse(my_string.begin(),my_string.end());
    string answer = my_string;
    return answer;
}

/*
개선 사항:
    1. string 생성자로 문자열 반전할 수 있는데 생성자의 인자로 역 반복자를 주면 된다. 역 반복자는 rbegin(), rend()이다.

배운 점:
    1. reverse 함수의 사용법
        1.1. reverse 함수는 algorithm 라이브러리에 있다. 
        1.2. reverse(str.begin(), str.end()); 하면 str 자체를 뒤집어준다.
    2. string(str.rbegin(), str.rend()); 하면 str을 뒤집은 string을 생성해준다.
*/