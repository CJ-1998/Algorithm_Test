/*
문제:
    문자열 s의 길이가 4 혹은 6이고, 숫자로만 구성돼있는지 확인해주는 함수, solution을 완성하세요. 예를 들어 s가 "a234"이면 False를 리턴하고 "1234"라면 True를 리턴하면 됩니다.

제한 사항:
    s는 길이 1 이상, 길이 8 이하인 문자열입니다.
    s는 영문 알파벳 대소문자 또는 0부터 9까지 숫자로 이루어져 있습니다.
*/

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.length()==4||s.length()==6){
        for(int i=0;i<s.length();i++){
            if('0'<=s[i]&&s[i]<='9'){
                continue;
            }
            else{
                answer=false;
                break;
            }
        }
    }
    else{
        answer=false;
    }
    return answer;
}

/*
개선 사항:
    1. isdigit(char) 사용하면 편하다.

배운 점:
    1. isdigit(char)해서 char이 숫자이면 true 나오고 아니면 false 나온다. 
*/