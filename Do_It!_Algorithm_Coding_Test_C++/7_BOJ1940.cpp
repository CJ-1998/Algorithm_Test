#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n=0;
    int m=0;
    cin>>n>>m;

    vector<long> v;

    for(int i=0;i<n;i++){
        long temp=0;
        cin>>temp;
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    int start=0;
    int end=0;
    long sum=0;
    int answer=1;

    sum+=v[end];

    while(end!=n){
        if(sum<n){
            end++;
            sum+=v[end];
        }
        else if(sum>n){
            sum-=v[start];
            start++;
        }
        else{
            end++;
            sum+=v[end];
            answer++;
        }
    }

    cout<<answer<<endl;

    return 0;
}