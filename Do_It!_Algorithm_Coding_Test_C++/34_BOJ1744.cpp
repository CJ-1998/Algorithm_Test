#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt=0;
    cin>>cnt;

    vector<int> v1;
    vector<int> v2;

    for(int i=0;i<cnt;i++){
        int temp=0;
        cin>>temp;
        if(temp>0)
            v1.push_back(temp);
        else    
            v2.push_back(temp);
    }

    sort(v1.begin(),v1.end(),greater<int>());
    sort(v2.begin(),v2.end());

    int answer=0;
    
    int index=0;

    while(index<v1.size()){
        int start = v1[index];

        if(index+1==v1.size()){
            answer+=start;
            break;
        }

        int end = v1[index+1];
        
        if(start==1||end==1){
            answer+=start+end;
            index+=2;
            continue;
        }

        answer+=start*end;
        index+=2;
    }

    index=0;

    while(index<v2.size()){
        int start = v2[index];

        if(index+1==v2.size()){
            answer+=start;
            break;
        }

        int end = v2[index+1];
        
        answer+=start*end;
        index+=2;
    }

    cout<<answer<<"\n";

    return 0;
}