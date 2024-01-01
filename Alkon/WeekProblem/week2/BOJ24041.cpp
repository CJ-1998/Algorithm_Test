/*
요구사항:
    재료마다 유통기한이 다르다.
    밀키트 유통기한은 재료 중 가장 이른 것으로 결정된다.
    밀키트에는 N개의 재료가 있다. 
    i번째 재료의 유통기한은 밀키트 구매한 후 Li일까지다. 
    부패 속도는 Si이다.
    구매 후 x일에 i번째 재료에 있는 세균수는 Si*max(1,x-Li)다. 
    모든 재료의 세균수의 합이 G마리 이하일 경우 먹을 수 있다. 
    재료 최대 K개까지 빼서 세균수가 G마리 이하면 먹는다. 
    밀키트 산 날부터 며칠 후까지 먹기 가능한지 구하자. 
*/

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int N;
int G;
int K;

vector<int> Si;
vector<int> Li;
vector<int> Oi;

unsigned long long check(long long mid){
    vector<pair<unsigned long long,int>> germ;
    for(int i=0;i<N;i++){
        if(Li[i]+1<mid){
            //cout<<"germ: "<<(unsigned long long)Si[i]*(mid-Li[i])<<" ";
            germ.push_back(make_pair((unsigned long long)Si[i]*(mid-Li[i]),Oi[i]));
        }
        else{
            //cout<<"germ: "<<Si[i]<<" ";
            germ.push_back(make_pair((unsigned long long)Si[i],Oi[i]));
        }
    }
    //cout<<endl;
    sort(germ.begin(),germ.end(),greater<>());

    // cout<<"================"<<endl;
    // for(int i=0;i<N;i++){
    //     cout<<germ[i].first<<" "<<germ[i].second<<" ";
    // }
    // cout<<endl<<"================"<<endl;

    unsigned long long allGerm=0;
    for(int i=0;i<N;i++){
        allGerm+=germ[i].first;
    }

    int index=0;
    for(int i=0;i<K;i++){
        if(index==N){
            break;
        }
        if(germ[index].second==1){
            allGerm-=germ[index].first;
        }
        else{
            i--;
        }
        index++;
    }

    return allGerm;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>G>>K;

    for(int i=0;i<N;i++){
        int temp1, temp2, temp3;
        cin>>temp1>>temp2>>temp3;

        Si.push_back(temp1);
        Li.push_back(temp2);
        Oi.push_back(temp3);
    }

    long long low=1;
    long long high=400000000;
    while(low+1<high){
        long long mid=(low+high)/2;

        unsigned long long l=check(low);
        unsigned long long m=check(mid);
        unsigned long long h=check(high);

        // cout<<"-------------"<<endl;
        // cout<<l<<" "<<m<<" "<<h<<endl;
        // cout<<"-------------"<<endl;

        if(h>G&&m>G){
            high=mid;
        }
        if(h>G&&m<=G){
            low=mid;
        }
        if(l<=G&&m>G){
            high=mid;
        }
        if(l<=G&&m<=G){
            low=mid;
        }

    }

    cout<<low;

    return 0;
}