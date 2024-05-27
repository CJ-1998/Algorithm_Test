#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string input = "";
    getline(cin,input);

    stringstream stream; 
    stream.str(input);

    vector<string> inputv;

    string temp;
    while(stream>>temp){
        inputv.push_back(temp);
    }

    vector<int> key;
    vector<int> mes;
    for(int i=0;i<inputv[1].size();i++){
        key.push_back(inputv[1][i]-'0');
    }

    for(int i=0;i<inputv[3].size();i++){
        mes.push_back(inputv[3][i]-'0');
    }

    if(inputv[0].compare("encrypt")==0){
        for(int i=0;i<mes.size();i++){
            int t = mes[i]+key[i];
            if(t>74){
                while(true){
                    t-=74;
                    if(t<=74){
                        break;
                    }
                }
            }
            mes[i]=t;
        }
        int rot=stoi(inputv[2]);
        rotate(mes.begin(), mes.begin() + rot, mes.end());

        string answer="";
        for(int i=0;i<mes.size();i++){
            answer+=mes[i]+'0';
        }

        cout<<answer;
    }
    else{

    }


    return 0;
}