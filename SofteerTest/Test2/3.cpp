#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<numeric>

using namespace std;

long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input = "";
    getline(cin,input);

    input.erase(remove(input.begin(), input.end(), ' '), input.end());

    vector<char> cal;

    for(int i=0;i<input.length();i++){
        if(input[i]=='*'||input[i]=='/'||input[i]=='+'||input[i]=='/'){
            cal.push_back(input[i]);
            input.replace(i,1," ");
        }
    }

    vector<string> temp;
    stringstream stream;
    stream.str(input);
    string t;
    while(stream>>t){
        temp.push_back(t);
    }

    for(int i=0;i<temp.size();i++){
        for(int j=0;j<temp[i].length();j++){
            if(temp[i][j]=='['||temp[i][j]==']'){
                temp[i].replace(j,1,"");
            }
            if(temp[i][j]==','){
                temp[i].replace(j,1," ");
            }
        }
    }

    vector<pair<long long, long long>> v;
    for(int i=0;i<temp.size();i++){
        stringstream s;
        s.str(temp[i]);
        long long t;
        vector<long long> vt;
        while(s>>t){
            vt.push_back(t);
        }

        if(vt.size()==1){
            v.push_back(make_pair(vt[0],1));
        }
        else{
            if(vt[1]==0){
                cout<<"ERR"<<endl;
                return 0;
            }
            v.push_back(make_pair(vt[0],vt[1]));
        }
    }

    int calSize=cal.size();

    for(int i=0;i<calSize;i++){
        if(find(cal.begin(),cal.end(),'*')!=cal.end()){
            int index = find(cal.begin(),cal.end(),'*')-cal.begin();
            long long up=v[index].first*v[index+1].first;
            long long down=v[index].second*v[index+1].second;
            v[index].first=up;
            v[index].second=down;
            v.erase(v.begin()+(index+1));
            continue;
        }

        if(find(cal.begin(),cal.end(),'/')!=cal.end()){
            int index = find(cal.begin(),cal.end(),'/')-cal.begin();
            if(v[index+1].first==0){
                cout<<"ERR"<<endl;
                return 0;
            }
            long long up=v[index].first*v[index+1].second;
            long long down=v[index].second*v[index+1].first;
            v[index].first=up;
            v[index].second=down;
            v.erase(v.begin()+(index+1));
            continue;
        }

        if(find(cal.begin(),cal.end(),'+')!=cal.end()){
            int index = find(cal.begin(),cal.end(),'+')-cal.begin();
            long long up=(v[index].first*v[index+1].second)+(v[index+1].first*v[index].second);
            long long down=v[index].second*v[index+1].second;
            v[index].first=up;
            v[index].second=down;
            v.erase(v.begin()+(index+1));
            continue;
        }

        if(find(cal.begin(),cal.end(),'-')!=cal.end()){
            int index = find(cal.begin(),cal.end(),'-')-cal.begin();
            long long up=(v[index].first*v[index+1].second)-(v[index+1].first*v[index].second);
            long long down=v[index].second*v[index+1].second;
            v[index].first=up;
            v[index].second=down;
            v.erase(v.begin()+(index+1));
            continue;
        }
    }

    long long gcdNum = gcd(v[0].first,v[0].second);

    if(gcdNum!=1){
        v[0].first/=gcdNum;
        v[0].second/=gcdNum;
    }

    if(v[0].second==1){
        cout<<v[0].first<<endl;
    }
    else{
        if(v[0].second<0){
            v[0].first*=-1;
            v[0].second*=-1;
        }

        cout<<"["<<v[0].first<<","<<v[0].second<<"]"<<endl;
    }

    return 0;
}