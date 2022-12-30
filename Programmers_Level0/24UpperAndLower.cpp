/*
문제:
    문자열 my_string이 매개변수로 주어질 때, 
    대문자는 소문자로 소문자는 대문자로 변환한 
    문자열을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ my_string의 길이 ≤ 1,000
    my_string은 영어 대문자와 소문자로만 구성되어 있습니다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    for(int i=0;i<my_string.length();i++){
        if(65<=my_string[i]&&my_string[i]<=90){
            my_string[i]+=32;
        }
        else{
            my_string[i]-=32;
        }
    }
    return my_string;
}

/*
개선 사항:
    1. islower, isupper, toupper, tolower 함수 사용하면 더 편할 것 같다. 

배운 점:
    1. islower, isupper, toupper, tolower 함수는 cctype 라이브러리에 있다고 한다. 
    2. 대문자는 아스키코드 65~90이고 소문자는 97~122이고 차이는 32이다.
*/