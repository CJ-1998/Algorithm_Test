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

    long long min=0;
    long long max=0;
    cin>>min>>max;

    vector<bool> v(max-min+1);

    int startIndex=2;

    long long cnt=0;

    for(int i=startIndex;i*i<=max;i++){
        long num = i*i;
        long index=min/num;

        if(min%num!=0){
            index++;
        }

        while(true){
            long temp = index*num;
            if(temp>max){
                break;
            }

            if(v[(int)(temp)-min]!=true){
                v[(int)(temp)-min]=true;
                cnt++;
            }
            index++;
        }
    }

    long long answer=max-min+1-cnt;
    cout<<answer;

    return 0;
}