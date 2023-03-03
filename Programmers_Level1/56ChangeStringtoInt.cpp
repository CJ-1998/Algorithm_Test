/*
문제:
    문자열 s를 숫자로 변환한 결과를 반환하는 함수, solution을 완성하세요.

제한 사항:
    s의 길이는 1 이상 5이하입니다.
    s의 맨앞에는 부호(+, -)가 올 수 있습니다.
    s는 부호와 숫자로만 이루어져있습니다.
    s는 "0"으로 시작하지 않습니다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool isNeg=false;
    if(s[0]=='-'){
        isNeg=true;
        s[0]='0';
    }
    answer=stoi(s);
    if(isNeg){
        answer*=-1;
    }
    return answer;
}

/*
개선 사항:
    1. stoi 함수 부호도 알아서 처리해줬다…

배운 점:
    1. string to int 할 때 stoi 함수 사용하면 된다. 부호도 알아서 처리해준다. 
*/