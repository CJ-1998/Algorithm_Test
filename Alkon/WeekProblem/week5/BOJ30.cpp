#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int answer=0;

    string temp;
    cin>>temp;

    vector<int> v;
    for(int i=0;i<temp.length();i++){
        v.push_back(temp[i]-'0');
    }

    sort(v.rbegin(),v.rend());

    if(v[v.size()-1]!=0){
        answer=-1;
    }
    else{
        int sum=0;
        for(int i=0;i<v.size()-1;i++){
            sum+=v[i];
        }

        if(sum%3!=0){
            answer=-1;
        }
        else{
            for(int i=0;i<v.size()-1;i++){
                int ten=1;
                for(int j=0;j<v.size()-1-i;j++){
                    ten*=10;
                }
                answer+=v[i]*ten;
            }
        }
    }

    cout<<answer;

    return 0;
}