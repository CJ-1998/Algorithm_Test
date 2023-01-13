/*
문제:
    숫자와 "Z"가 공백으로 구분되어 담긴 문자열이 주어집니다. 문자열에 있는 숫자를 차례대로 더하려고 합니다. 이 때 "Z"가 나오면 바로 전에 더했던 숫자를 뺀다는 뜻입니다. 숫자와 "Z"로 이루어진 문자열 s가 주어질 때, 머쓱이가 구한 값을 return 하도록 solution 함수를 완성해보세요.

제한 사항:
    1 ≤ s의 길이 ≤ 200
    -1,000 < s의 원소 중 숫자 < 1,000
    s는 숫자, "Z", 공백으로 이루어져 있습니다.
    s에 있는 숫자와 "Z"는 서로 공백으로 구분됩니다.
    연속된 공백은 주어지지 않습니다.
    0을 제외하고는 0으로 시작하는 숫자는 없습니다.
    s는 "Z"로 시작하지 않습니다.
    s의 시작과 끝에는 공백이 없습니다.
    "Z"가 연속해서 나오는 경우는 없습니다.
*/

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp;
    stringstream stream;
    stream.str(s);
    
    vector<string> str;
    while(stream>>temp){
        str.push_back(temp);
    }
    
    vector<int> num;
    for(int i=0;i<str.size();i++){
        if(str[i].compare("Z")){
            answer+=stoi(str[i]);
            num.push_back(stoi(str[i]));
        }
        else{
            answer-=num[num.size()-1];
        }
            
    }
    
    return answer;
}

/*
개선 사항:
    1. stack 사용해서 Z만나면 stack top에 있는 것 그냥 pop하면 된다. 

배운 점:
    1. stoi 함수는 string으로 -1 이렇게 되어 있어도 -1로 바꿔준다. 
    2. stringstream의 사용법
    3. stack 사용법: stack<int> name. vector와 똑같이 사용하면 된다. 
    4. C++은 split 함수가 없다.
*/