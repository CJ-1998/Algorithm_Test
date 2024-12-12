// 아직 못 품

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long min = 0;
    long long max = 0;

    cin>>min>>max;

    vector<long long> arr(max-min+1,0);

    long long answer = max-min+1;

    for(long long i=2;i*i<=max;i++){
        
        long long p = i*i;

        long long start_index = min/p;

        if(min%p!=0){
            start_index++;
        }
        
        for(long long j=start_index;p*j<=max;j++){
            arr[(int)((p*j)-min)]=1;
        }
    }

    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            answer--;
        }
    }

    cout<<answer;

    return 0;
}