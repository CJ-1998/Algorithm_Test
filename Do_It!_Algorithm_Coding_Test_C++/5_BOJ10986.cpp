#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n=0;
    int m=0;

    cin>>n>>m;

    vector<int> v;

    for(int i=0;i<n;i++){
        int temp=0;
        cin>>temp;
        v.push_back(temp);
    }

    vector<int> sum;
    sum.push_back(v[0]);

    for(int i=1;i<n;i++){
        int t=sum[i-1]+v[i];
        sum.push_back(t);
    }

    for(int i=0;i<sum.size();i++){
        sum[i]=sum[i]%m;
        //cout<<sum[i]<<endl;
    }

    int answer=0;
    sort(sum.begin(),sum.end());
    
    for(int i=0;i<sum.size();i++){
        if(sum[i]==0){
            answer++;
        }
    }

    vector<int> same;
    int first=sum[0];
    int cnt=0;

    for(int i=1;i<sum.size();i++){
        if(sum[i]==first){
            cnt++;
        }
        else{
            same.push_back(cnt+1);
            cnt=0;
            first=sum[i];
        }
    }
    same.push_back(cnt+1);

    for(int i=0;i<same.size();i++){
        same[i]=same[i]*(same[i]-1)/2;
    }

    for(int i=0;i<same.size();i++){
        answer+=same[i];
    }
    cout<<answer<<endl;

    return 0;
}