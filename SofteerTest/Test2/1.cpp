#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>

using namespace std;

int cmp (string a, string b){

    double t = (double)a.length()-(double)b.length();

    int len=abs(t);
    if(a.length()<b.length()){
        char t = a[a.length()-1];
        for(int i=0;i<len;i++){
            a+=t;
        }
    }
    else if(a.length()>b.length()){
        char t = b[b.length()-1];
        for(int i=0;i<len;i++){
            b+=t;
        }
    }

    if(a[0]!=b[0]){
        if(a[0]>b[0]){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(a[1]>b[1]){
            return 1;
        }
        else if(a[1]==b[1]){
            if(a[2]>b[2]){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input = "";
    getline(cin,input);

    stringstream stream;
    stream.str(input);

    vector<string> v;
    string temp;
    while(stream>>temp){
        v.push_back(temp);
    }

    if(v.size()>9){
        cout<<-1;
        return 0;
    }

    if(v.size()<=9&&v.size()>=7){
        for(int i=0;i<v.size();i++){
            if(v[i].length()==3){
                cout<<-1;
                return 0;
            }
        }
    }

    sort(v.begin(),v.end(),cmp);

    string small;
    string big;

    for(int i=0;i<v.size();i++){
        small+=v[i];
    }

    for(int i=v.size()-1;i>=0;i--){
        big+=v[i];
    }

    long long smallNum=stoll(small);
    long long bigNum=stoll(big);
    long long answer=smallNum+bigNum;

    cout<<answer<<endl;

    return 0;
}