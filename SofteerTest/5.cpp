/*
검색 기능에서 도메인 이름으로 검색하면 IP 주소 나오는 기능 미구현
자동 완성 기능에서 우선순위 1, 2 있는데 미구현
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<cctype>

using namespace std;

vector<string> domain;
vector<vector<string>> ip;

vector<string> split(string input, char d) {
    vector<string> splitString;
    stringstream stream(input);
    string temp;
 
    while (getline(stream, temp, d)) {
        splitString.push_back(temp);
    }
 
    return splitString;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        string temp;
        cin>>temp;
        if(cin){
            
        }
        else{
            break;
        }
        if(temp.compare("R")==0){
            string name;
            string address;
            cin>>name>>address;
            domain.push_back(name);
            if(address.find("-")!=string::npos){
                vector<string> cutString=split(address,'-');

                vector<string> startIp=split(cutString[0],'.');
                vector<string> endIp=split(cutString[1],'.');
                string middeIp=startIp[0]+"."+startIp[1]+"."+startIp[2]+".";

                vector<string> tempString;
                for(int i=stoi(startIp[3]);i<=stoi(endIp[3]);i++){
                    string t=middeIp+to_string(i);
                    tempString.push_back(t);
                }
                ip.push_back(tempString);
            }
            else{
                vector<string> tempString;
                tempString.push_back(address);
                ip.push_back(tempString);
            }
        }
        if(temp.compare("S")==0){
            string findIp;
            cin>>findIp;

            if(!isdigit(findIp[0])){}

            else{
                int findIndex=-1;
                for(int i=0;i<ip.size();i++){
                    for(int j=0;j<ip[i].size();j++){
                        if(ip[i][j].compare(findIp)==0){
                            findIndex=i;
                            break;
                        }
                    }
                    if(findIndex!=-1){
                        break;
                    }
                }
                if(findIndex!=-1){
                    cout<<domain[findIndex];
                }
                else{
                    cout<<"not found"<<endl;
                }
            }

        }
        if(temp.compare("A")==0){
            string findName;
            cin>>findName;

            vector<string> nameTemp;
            for(int i=0;i<domain.size();i++){
                if(domain[i].find(findName)!=string::npos){
                    nameTemp.push_back(domain[i]);
                }
            }

            sort(nameTemp.begin(),nameTemp.end(),greater<>());

            for(int i=0;i<nameTemp.size();i++){
                cout<<nameTemp[i]<<endl;
            }
        }
    }

    
    return 0;
}