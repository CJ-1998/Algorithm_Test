#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

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
    
    stringstream stream;
    stream.str(s);
    
    string temp;
    
    vector<string> v;
    
    while(stream>>temp){
        //cout<<temp<<endl;
        v.push_back(temp);
    }
    
    for(int i=0;i<v.size();i++){
        answer+=change(v[i]);
        if(i!=v.size()-1)
            answer+=" ";
    }
    
    return answer;
}