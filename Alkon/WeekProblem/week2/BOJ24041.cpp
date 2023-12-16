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

int check(int mid){
    vector<pair<int,int>> germ;
    for(int i=0;i<N;i++){
        if(Li[i]+1<mid){
            germ.push_back(make_pair(Si[i]*(mid-Li[i]),Oi[i]));
        }
        else{
            germ.push_back(make_pair(Si[i],Oi[i]));
        }
    }
    sort(germ.begin(),germ.end(),greater<>());

    int allGerm=0;
    for(int i=0;i<N;i++){
        allGerm+=germ[i].first;
    }

    int index=0;
    for(int i=0;i<K;i++){
        if(index==N){
            break;
        }
        if(germ[i].second==1){
            allGerm-=germ[i].first;
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

    int low=0;
    int high=1000000000;
    while(low+1<high){
        int mid=(low+high)/2;
        

        if(check(low)<=G&&check(mid)<=G){
            low=mid;
        }
        else if(check(high)<=G&&check(mid)<=G){
            high=mid;
        }
    }

    cout<<low+1;

    return 0;
}