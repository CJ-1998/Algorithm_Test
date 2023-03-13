/*
문제:
    단어 s의 가운데 글자를 반환하는 함수, solution을 만들어 보세요. 단어의 길이가 짝수라면 가운데 두글자를 반환하면 됩니다.

제한 사항:
    s는 길이가 1 이상, 100이하인 스트링입니다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len=s.length();
    if(len%2!=0){
        answer+=s[len/2];
    }
    else{
        answer+=s[len/2-1];
        answer+=s[len/2];
    }
    return answer;
}

/*
개선 사항:
    1. substr으로 가져오면 된다.

배운 점:
    1. substr(시작index, 길이); 하면 substring을 받을 수 있다. 
*/