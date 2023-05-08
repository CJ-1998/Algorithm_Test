#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    int cnt=0;
    cin>>cnt;

    vector<pair<int,int>> x;
    vector<pair<int,int>> y;

    for(int i=0;i<cnt;i++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        pair<int, int> temp1;
        temp1.first=x1;
        temp1.second=x2;

        pair<int, int> temp2;
        temp2.first=y1;
        temp2.second=y2;

        x.push_back(temp1);
        y.push_back(temp2);
    }

    int x1=501;
    int x2=0;
    int y1=501;
    int y2=0;

    for(int i=0;i<cnt;i++){
        if(x1>x[i].first){
            x1=x[i].first;
        }
        if(x2<x[i].second){
            x2=x[i].second;
        }
        if(y1>y[i].first){
            y1=y[i].first;
        }
        if(y2<y[i].second){
            y2=y[i].second;
        }
    }

    //cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
    cout<<(x2-x1)*(y2-y1)<<endl;
    //튀어 나온 것에 대해서 아직 처리 안했음. 전체 겹치는 경우만 완료.

    return 0;
}