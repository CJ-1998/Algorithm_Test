/*
문제:   
    머쓱이는 친구에게 모스부호를 이용한 편지를 받았습니다. 그냥은 읽을 수 없어 이를 해독하는 프로그램을 만들려고 합니다. 문자열 letter가 매개변수로 주어질 때, letter를 영어 소문자로 바꾼 문자열을 return 하도록 solution 함수를 완성해보세요.

제한 사항:
    1 ≤ letter의 길이 ≤ 1,000
    return값은 소문자입니다.
    letter의 모스부호는 공백으로 나누어져 있습니다.
    letter에 공백은 연속으로 두 개 이상 존재하지 않습니다.
    해독할 수 없는 편지는 주어지지 않습니다.
    편지의 시작과 끝에는 공백이 없습니다.
*/

#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string letter) {
    string answer = "";
    string mos[26]={ 
        ".-","-...","-.-.","-..",".","..-.",
        "--.","....","..",".---","-.-",".-..",
        "--","-.","---",".--.","--.-",".-.",
        "...","-","..-","...-",".--","-..-",
        "-.--","--.."
    };
    
    stringstream stream;
    stream.str(letter);
    string temp;
    
    while(stream>>temp){
        for(int i=0;i<26;i++){
            if(!mos[i].compare(temp)){
                answer+=i+97;
            }
        }
    }
    
    
    return answer;
}

/*
개선 사항:
    1. map으로 풀면 배열처럼 쉽게 찾을 수 있다. 

배운 점:
    1. stringstream 사용법
    2. compare 함수 사용법
    3. map 사용법
*/