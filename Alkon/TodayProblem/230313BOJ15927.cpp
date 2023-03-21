/*
(아직 못 품)
문제:
    팰린드롬이란 앞으로 읽으나 뒤로 읽으나 같은 문자열을 말한다. 팰린드롬의 예시로 POP, ABBA 등이 있고, 팰린드롬이 아닌 것의 예시로 ABCA, PALINDROME 등이 있다.
    뭔가 이상한 점이 보이지 않는가? 그 어떤 언어에서도 팰린드롬을 뜻하는 단어는 팰린드롬이 아니다! 많은 사람들이 추구하는 “대칭의 아름다움”은 그저 허상에 불과하다.
    알파벳 대문자로 이루어진 문자열이 주어졌을 때, 팰린드롬이 아닌 가장 긴 부분문자열의 길이를 구해 보자. 이때 부분문자열을 이루는 글자는 연속해야 한다. AB는 ABCD의 부분문자열이지만, AC는 아니다.

입력:
    길이가 1 이상 50만 이하인 문자열이 주어진다.

출력:
    팰린드롬이 아닌 가장 긴 부분문자열의 길이를 출력한다. 그런 부분문자열이 없으면 -1을 출력한다.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int answer=-1;
    string pal;
    cin>>pal;
    
    int len=pal.length();
    vector<char> str;

    bool check=false;
    int big=0;

    for(int i=1;i<len;i++){
        if(str.size()==0){
            str.push_back(pal[0]);
        }
        else if(str.size()>1){
            if(str[str.size()-1]==pal[i]){
                if(big<str.size()){
                    big=str.size();
                }
                str.clear();
                continue;
            }
            if(str[str.size()-2]==pal[i]){
                if(big<str.size()){
                    big=str.size();
                }
                str.clear();
                continue;
            }
        }
        else{
            if(str[str.size()-1]==pal[i]){
                if(big<str.size()){
                    big=str.size();
                }
                str.clear();
                continue;
            }
        }
    }
    
    cout<<big<<endl;
    return 0;
}