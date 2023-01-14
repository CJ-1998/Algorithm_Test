/*
문제:
    문자열 my_string이 매개변수로 주어집니다. my_string안의 모든 자연수들의 합을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ my_string의 길이 ≤ 1,000
    my_string은 소문자, 대문자 그리고 한자리 자연수로만 구성되어있습니다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for(int i=0;i<my_string.length();i++){
        if(isdigit(my_string[i])){
            answer+=my_string[i]-'0';
        }
    }
    return answer;
}

/*
배운 점:
    1. isdigit 사용법.
    2. char to int는 -'0'.
    3. stringstream은 공백이나 \n이 있어야 유효하게 사용 가능.
*/