/*
문제:
    머쓱이는 태어난 지 11개월 된 조카를 돌보고 있습니다. 조카는 아직 "aya", "ye", "woo", "ma" 네 가지 발음과 네 가지 발음을 조합해서 만들 수 있는 발음밖에 하지 못하고 연속해서 같은 발음을 하는 것을 어려워합니다. 문자열 배열 babbling이 매개변수로 주어질 때, 머쓱이의 조카가 발음할 수 있는 단어의 개수를 return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ babbling의 길이 ≤ 100
    1 ≤ babbling[i]의 길이 ≤ 30
    문자열은 알파벳 소문자로만 이루어져 있습니다.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for(int i=0;i<babbling.size();i++){
        if(babbling[i].find("ayaaya")!=string::npos||babbling[i].find("yeye")!=string::npos||
          babbling[i].find("woowoo")!=string::npos||babbling[i].find("mama")!=string::npos){
            continue;
        }
        while(true){
            bool check=true;
            if(babbling[i].find("aya")!=string::npos){
                babbling[i].replace(babbling[i].find("aya"),3,"   ");
                check=false;
            }
            if(babbling[i].find("ye")!=string::npos){
                babbling[i].replace(babbling[i].find("ye"),2,"  ");
                check=false;
            }
            if(babbling[i].find("woo")!=string::npos){
                babbling[i].replace(babbling[i].find("woo"),3,"   ");
                check=false;
            }
            if(babbling[i].find("ma")!=string::npos){
                babbling[i].replace(babbling[i].find("ma"),2,"  ");
                check=false;
            }
            if(check){
                break;
            }
        }
        
        bool yn=true;
        for(int j=0;j<babbling[i].length();j++){
            if(babbling[i][j]!=' '){
                yn=false;
            }
        }
        if(yn){
            answer++;
        }
    }
    return answer;
}

/*
개선 사항:
    1. string index 다 돌면서 substr로 있는지 찾고 연속 되어 있는지 찾는다. 찾으면 길이만큼 index 옮기는 것이다.

배운 점:
    1. str.find(”~”) 함수 사용법. 찾으면 시작점 반환, 못 찾으면 string::npos 반환.
    2. str.erase(시작점, 끝점) 함수 사용법.
    3. str.replace(시작점, 길이, “~”) 함수 사용법.
    4. str.substr(시작점, 길이) 함수 사용법. string 반환.
*/