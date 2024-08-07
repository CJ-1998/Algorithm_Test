/*
제목
    숫자 문자열과 영단어

문제 설명
    네오와 프로도가 숫자놀이를 하고 있습니다. 
    네오가 프로도에게 숫자를 건넬 때 일부 자릿수를 영단어로 바꾼 카드를 건네주면 프로도는 원래 숫자를 찾는 게임입니다.

    다음은 숫자의 일부 자릿수를 영단어로 바꾸는 예시입니다.
        1478 → "one4seveneight"
        234567 → "23four5six7"
        10203 → "1zerotwozero3"

    이렇게 숫자의 일부 자릿수가 영단어로 바뀌어졌거나, 혹은 바뀌지 않고 그대로인 문자열 s가 매개변수로 주어집니다. 
    s가 의미하는 원래 숫자를 return 하도록 solution 함수를 완성해주세요.

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

제한사항
    1 ≤ s의 길이 ≤ 50
    s가 "zero" 또는 "0"으로 시작하는 경우는 주어지지 않습니다.
    return 값이 1 이상 2,000,000,000 이하의 정수가 되는 올바른 입력만 s로 주어집니다.

입출력 예
    s	result
    "one4seveneight"	1478
    "23four5six7"	234567
    "2three45sixseven"	234567
    "123"	123
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;

    vector<string> eng;
    eng.push_back("zero");
    eng.push_back("one");
    eng.push_back("two");
    eng.push_back("three");
    eng.push_back("four");
    eng.push_back("five");
    eng.push_back("six");
    eng.push_back("seven");
    eng.push_back("eight");
    eng.push_back("nine");
    
    vector<int> num;
    for(int i=0;i<10;i++){
        num.push_back(i);
    }
    
    for(int i=0;i<eng.size();i++){
        while(true){
            if(s.find(eng[i])!=string::npos){
                int index = s.find(eng[i]);
                s.replace(index, 1,to_string(num[i]));
                int len = eng[i].length()-1;
                s.erase(s.begin()+index+1, s.begin()+index+1+len);
            }
            else{
                break;
            }
        }
    }
    
    answer=stoi(s);
    
    return answer;
}

/*
틀린 이유
    같은 영어 숫자가 여러 번일 수 있음 
    sixsix6 같은 string인 경우 틀림
*/