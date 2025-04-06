/*
실패 버전
시간 초과남
*/

#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int calculateCase(queue<int> weights, int bagWeight){

    if(bagWeight==0){
        return 1;
    }

    // 넣을 것이 없는 마지막인 경우
    if(weights.empty()){
        return 1;
    }

    int oneWeight = weights.front();
    weights.pop();

    int inCase = 0;
    int notInCase = 0;

    if(bagWeight>=oneWeight){
        // 넣는 경우
        inCase += calculateCase(weights, bagWeight-oneWeight);

    }
    // 안 넣는 경우 
    notInCase += calculateCase(weights, bagWeight);

    return inCase+notInCase;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n=0;
    int c=0;

    cin>>n>>c;

    queue<int> weight;

    for(int i=0;i<n;i++){
        int temp=0;
        cin>>temp;
        weight.push(temp);
    }

    int caseCount = calculateCase(weight, c);

    cout<<caseCount;
    
    return 0;
}