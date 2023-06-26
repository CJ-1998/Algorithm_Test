/*
문제:
    JadenCase란 모든 단어의 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다. 
    단, 첫 문자가 알파벳이 아닐 때에는 이어지는 알파벳은 소문자로 쓰면 됩니다. (첫 번째 입출력 예 참고)
    문자열 s가 주어졌을 때, s를 JadenCase로 바꾼 문자열을 리턴하는 함수, solution을 완성해주세요.

제한 사항:
    s는 길이 1 이상 200 이하인 문자열입니다.
    s는 알파벳과 숫자, 공백문자(" ")로 이루어져 있습니다.
        숫자는 단어의 첫 문자로만 나옵니다.
        숫자로만 이루어진 단어는 없습니다.
        공백문자가 연속해서 나올 수 있습니다.
*/

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

string change(string temp){
    for(int i=0;i<temp.length();i++){
        temp[i]=tolower(temp[i]);
    }
    
    if('0'<=temp[0]&&temp[0]<='9'){
        
    }
    else{
        temp[0]=toupper(temp[0]);
    }
    return temp;
}

string solution(string s) {
    string answer = "";
    
    vector<string>v;
    
    string temp;
    
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            temp+=s[i];
            if(i==s.length()-1){
                answer+=change(temp);
            }
        }
        else{
            answer+=change(temp);
            answer+=" ";
            temp="";
        }
    }
    
    return answer;
}

/*
개선 사항:
    1. 전의 것이 공백이면 다음 것 대문자 하고 공백 아니면 소문자 하면 된다. 

배운 점:
    1. stringstream은 공백 몇 개인지 상관하지 않는다. 
*/