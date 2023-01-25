/*
문제:
    문자열 my_string과 정수 n이 매개변수로 주어질 때, my_string에 들어있는 각 문자를 n만큼 반복한 문자열을 return 하도록 solution 함수를 완성해보세요.

제한 사항:
    2 ≤ my_string 길이 ≤ 5
    2 ≤ n ≤ 10
    "my_string"은 영어 대소문자로 이루어져 있습니다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    for(int i=0;i<my_string.length();i++){
        for(int j=0;j<n;j++){
            answer+=my_string[i];
        }
    }
    return answer;
}

/*
개선 사항 & 배운 점:
    1. string 생성자 중에 (숫자, char) 주면 숫자만큼의 char을 가진 string 만들어준다. 
*/