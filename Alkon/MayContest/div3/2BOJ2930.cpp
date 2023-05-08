#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int round=0;
    cin>>round;

    string sang="";
    cin>>sang;

    int fr=0;
    cin>>fr;

    vector<string> str;

    for(int i=0; i<fr;i++){
        string temp;
        cin>>temp;
        str.push_back(temp);
    }

    int answer=0;
    int best=0;

    vector<string> bestsang;
    for(int j=0;j<fr;j++){
        string temp;
        for(int i=0;i<round;i++){
            if(str[j][i]=='S'){
                temp+='R';
            }
            else if(str[j][i]=='P'){
                temp+='S';
            }
            else{
                temp+='P';
            }
        }
        bestsang.push_back(temp);
    }

    for(int i=0;i<fr;i++){
        for(int j=0;j<round;j++){
            if(sang[j]==str[i][j]){
                answer+=1;
            }
            else if(sang[j]=='S'&&str[i][j]=='P'||
            sang[j]=='R'&&str[i][j]=='S'||
            sang[j]=='P'&&str[i][j]=='R'){
                answer+=2;
            }
        }
    }

    vector<int> bt;
    for(int i=0;i<fr;i++){
        string temp=bestsang[i];
        int besttemp=0;
        for(int j=0;j<fr;j++){
            for(int k=0;k<round;k++){
                if(bestsang[i][k]==str[j][k]){
                besttemp+=1;
            }
                else if(bestsang[i][k]=='S'&&str[j][k]=='P'||
                bestsang[i][k]=='R'&&str[j][k]=='S'||
                bestsang[i][k]=='P'&&str[j][k]=='R'){
                    besttemp+=2;
                }
            }
        }
        bt.push_back(besttemp);
    }

    //한명 다 맞는 걸로 하면 안되고 한 round 전체 보고 최상 골라야 한다. 

    sort(bt.begin(),bt.end(),greater<int>());
    best=bt[0];

    cout<<answer<<endl;
    cout<<best<<endl;

    return 0;
}