/*
문제:
    문자열 s가 매개변수로 주어집니다. 
    s에서 한 번만 등장하는 문자를 사전 순으로 
    정렬한 문자열을 return 하도록 
    solution 함수를 완성해보세요. 
    한 번만 등장하는 문자가 없을 경우 
    빈 문자열을 return 합니다.

제한 사항:
    0 < s의 길이 < 1,000
    s는 소문자로만 이루어져 있습니다.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    for(int i=0;i<s.length()-1;i++){
        bool isSame=false;
        for(int j=i+1;j<s.length();j++){
            if(s[i]==s[j]){
                s.erase(j,j+1);
                j--;
                isSame=true;
            }
        } 
        if(isSame){
            s.erase(i,i+1);
            i--;
        }
    }
    sort(s.begin(),s.end());
    answer=s;
    return answer;
}

/*
개선 사항:
    1. map에 단어를 key로 하고 value를 나온 횟수로 해서 풀면 더 좋을 것 같다. 

배운 점:
    1. erase(a, b)는 index a ~ index b를 지워주는 것이 아니라 index a에서부터 b 길이만큼 지우는 것.
    2. 특정 위치의 값 지우고 싶으면 erase(v.begin()+index) 하면 된다. 
    3. map에서 key는 iterator→.first, value는 iterator→second로 접근할 수 있다. 
    4. 특정 key의 value 값은 map[key]로 접근할 수 있다.
*/