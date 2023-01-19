/*
문제:
    알파벳 소문자로만 이루어진 어떤 문자열에서, 2회 이상 나타난 알파벳이 2개 이상의 부분으로 나뉘어 있으면 외톨이 알파벳이라고 정의합니다
    문자열 input_string이 주어졌을 때, 외톨이 알파벳들을 알파벳순으로 이어 붙인 문자열을 return 하도록 solution 함수를 완성해주세요. 만약, 외톨이 알파벳이 없다면 문자열 "N"을 return 합니다.

제한 사항:
    1 ≤ input_string의 길이 ≤ 2,600
    input_string은 알파벳 소문자로만 구성되어 있습니다..
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string input_string) {
    string answer = "";
    while(true){
        bool check=true;
        for(int i=0;i<input_string.length()-1;i++){
            if(input_string[i]==input_string[i+1]){
                input_string.erase(input_string.begin()+i);
                check=false;
            }
        }
        if(check){
            break;
        }
    }
    for(int i=0;i<input_string.length()-1;i++){
        for(int j=i+1;j<input_string.length();j++){
            if(input_string[i]==input_string[j]){
                answer+=input_string[i];
            }
        }
    }
    sort(answer.begin(),answer.end());
    answer.erase(unique(answer.begin(),answer.end()),answer.end());
    
    if(!answer.compare("")){
        answer="N";
    }
    return answer;
}

/*
개선 사항:
    1. map을 사용하는 것이다. 연속된 것이 있으면 skip하고 map에 값이 있는데 또 나오면 set에 넣는 것이다.

배운 점:
    1. stirng 특정 위치 지우려면 str.erase(str.begin()+i); 하면 된다. 
    2. string의 중복된 값 지우려면 sort, erase, unique 사용하면 된다.
*/