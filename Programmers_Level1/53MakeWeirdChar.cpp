/*
문제:
    문자열 s는 한 개 이상의 단어로 구성되어 있습니다. 각 단어는 하나 이상의 공백문자로 구분되어 있습니다. 각 단어의 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로 바꾼 문자열을 리턴하는 함수, solution을 완성하세요.

제한 사항:
    문자열 전체의 짝/홀수 인덱스가 아니라, 단어(공백을 기준)별로 짝/홀수 인덱스를 판단해야합니다.
    첫 번째 글자는 0번째 인덱스로 보아 짝수번째 알파벳으로 처리해야 합니다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int index=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            if(index%2==0){
                if('a'<=s[i]&&s[i]<='z')
                    s[i]-=('a'-'A');
            }
            else{
                if('A'<=s[i]&&s[i]<='Z')
                    s[i]+=('a'-'A'); 
            }
            index++;
        }
        else{
            index=0;
        }
    }
    return s;
}

/*
개선 사항:
    1. toupper(char), tolower(char) 사용하면 쉽다. 

배운 점:
    1. char를 대문자로 하려면 toupper(char), 소문자로 하려면 tolower(char) 사용하면 된다. 
*/