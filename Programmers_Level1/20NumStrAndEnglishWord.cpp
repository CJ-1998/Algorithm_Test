/*
문제:
    네오와 프로도가 숫자놀이를 하고 있습니다. 네오가 프로도에게 숫자를 건넬 때 일부 자릿수를 영단어로 바꾼 카드를 건네주면 프로도는 원래 숫자를 찾는 게임입니다.
    
    다음은 숫자의 일부 자릿수를 영단어로 바꾸는 예시입니다.
        1478 → "one4seveneight"
        234567 → "23four5six7"
        10203 → "1zerotwozero3"
    
    이렇게 숫자의 일부 자릿수가 영단어로 바뀌어졌거나, 혹은 바뀌지 않고 그대로인 문자열 s가 매개변수로 주어집니다. s가 의미하는 원래 숫자를 return 하도록 solution 함수를 완성해주세요.
    
    참고로 각 숫자에 대응되는 영단어는 다음 표와 같습니다.

    숫자	영단어
    0	zero
    1	one
    2	two
    3	three
    4	four
    5	five
    6	six
    7	seven
    8	eight
    9	nine

제한 사항:
    1 ≤ s의 길이 ≤ 50
    s가 "zero" 또는 "0"으로 시작하는 경우는 주어지지 않습니다.
    return 값이 1 이상 2,000,000,000 이하의 정수가 되는 올바른 입력만 s로 주어집니다.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string str[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int strl[10]={4,3,3,5,4,4,3,5,5,4};
    char num[10]={'0','1','2','3','4','5','6','7','8','9'};
    for(int i=0;i<10;i++){
        int temp=s.find(str[i]);
        if(temp!=string::npos){
            s.erase(s.begin()+temp+1,s.begin()+temp+strl[i]);
            s[temp]=num[i];
            i--;
        }
    }
    answer=stoi(s);
    return answer;
}

/*
개선 사항:
    1. regex_replace 사용하면 더 쉽다.

문제점:
    1. str.find(str) 사용법
    2. str.erase(시작점, 시작점+지울길이) 사용법
    3. stoi(str) 사용법
    4. replace(시작점, 끝점, str) 사용법
    5. regex_replace.(기존문자열, regex(정규식=찾을문자열), 바꿀문자열) 사용법.
        5.1. regex 라이브러리에 있다.
*/