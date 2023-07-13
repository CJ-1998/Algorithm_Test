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
            zero--;
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
    while(s.length()>1){
        vector<int>temp=change(s);
        zero+=temp[0];
        bitset<150000> bs(temp[1]);
        s = bs.to_string();
	    s = s.substr(s.find('1'));
        cnt++;
    }
    
    answer.push_back(cnt);
    answer.push_back(zero);
    
    return answer;
}
