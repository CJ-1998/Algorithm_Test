#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){

    int n=0;
    cin>>n;
    
    vector<int> v(n);
    vector<int> cnt(8001);

    double sum=0;

    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
        if(v[i]>=0){    
            cnt[v[i]+4000]++;
        }
        else{
            cnt[(-1*v[i])-1]++;
        }
    }

    double avg=0;
    int middle=0;
    int freq=0;
    int range=0;

    sort(v.begin(),v.end());
    
    avg=sum/(double)n;
    avg=round(avg);
    
    if(avg==-0){
        avg=0;
    }

    int mid=(n-1)/2;
    middle=v[mid];
    range=v[n-1]-v[0];

    vector<int> freqVec;
    int max=0;
    for(int i=0;i<8001;i++){
        if(max<cnt[i]){
            max=cnt[i];
        }
    }

    // cout<<max<<endl;

    for(int i=0;i<8001;i++){
        if(cnt[i]==max){
            if(i<4000){
                freqVec.push_back(-1*(i+1));
            }
            else{
                freqVec.push_back(i-4000);
            }
        }
    }

    sort(freqVec.begin(),freqVec.end());
    // for(int i=0;i<freqVec.size();i++){
    //     cout<<freqVec[i]<<" ";
    // }
    // cout<<endl;

    if(freqVec.size()>1)
        freq=freqVec[1];
    else
        freq=freqVec[0];

    cout<<avg<<"\n"<<middle<<"\n"<<freq<<"\n"<<range<<"\n";

    return 0;
}