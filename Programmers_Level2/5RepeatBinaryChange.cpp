/*
문제:
   0과 1로 이루어진 어떤 문자열 x에 대한 이진 변환을 다음과 같이 정의합니다.
        x의 모든 0을 제거합니다.
        x의 길이를 c라고 하면, x를 "c를 2진법으로 표현한 문자열"로 바꿉니다.
    예를 들어, x = "0111010"이라면, x에 이진 변환을 가하면 x = "0111010" -> "1111" -> "100" 이 됩니다.
    0과 1로 이루어진 문자열 s가 매개변수로 주어집니다. 
    s가 "1"이 될 때까지 계속해서 s에 이진 변환을 가했을 때, 이진 변환의 횟수와 변환 과정에서 제거된 모든 0의 개수를 각각 배열에 담아 return 하도록 solution 함수를 완성해주세요. 

제한 사항:
    s의 길이는 1 이상 150,000 이하입니다.
    s에는 '1'이 최소 하나 이상 포함되어 있습니다.
*/

#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

vector<int> change (string temp){
    int before=temp.length();
    int zero=0;
    for(int i=0;i<temp.length();i++){
        if(temp[i]=='0'){
            zero++;
        }
    }
    
    vector<int> v;
    v.push_back(zero);
    v.push_back(before-zero);
    return v;
}

vector<int> solution(string s) {
    vector<int> answer;
    int zero=0;
    int cnt=0;
    string str=s;
    cout<<s<<endl;
    while(str.length()>1){
        vector<int>temp=change(str);
        zero+=temp[0];
	    bitset<150000> bs(temp[1]);
	    str = bs.to_string();
	    str = str.substr(str.find('1'));
        cnt++;
    }
    
    answer.push_back(cnt);
    answer.push_back(zero);
    
    return answer;
}

/*
배운 점:
    1. integer to binary string 하는 방법에 bitset 사용하는 방법이 있다. 
    2. #include<bitset>에 들어있다. 
    3. bitset<자리수> bs(int); string s=bs.to_string(); s=s.substr(s.find(’1’)); 하면 된다. 
    4. 또는 to_binary(int); 함수 사용하면 된다.
*/