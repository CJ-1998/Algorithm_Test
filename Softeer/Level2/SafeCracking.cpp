/*
문제:
  루팡은 배낭을 하나 메고 은행금고에 들어왔다. 
  금고 안에는 값비싼 금, 은, 백금 등의 귀금속 덩어리가 잔뜩 들어있다. 
  배낭은 W ㎏까지 담을 수 있다.
  각 금속의 무게와 무게당 가격이 주어졌을 때 배낭을 채울 수 있는 가장 값비싼 가격은 얼마인가?
  루팡은 전동톱을 가지고 있으며 귀금속은 톱으로 자르면 잘려진 부분의 무게만큼 가치를 가진다.

제약조건:
  1 ≤ N ≤ 10^6인 정수
  1 ≤ W ≤ 10^4인 정수
  1 ≤ Mi, Pi ≤ 10^4인 정수

입력형식:
  첫 번째 줄에 배낭의 무게 W와 귀금속의 종류 N이 주어진다. 
  i + 1 (1 ≤ i ≤ N)번째 줄에는 i번째 금속의 무게 Mi와 무게당 가격 Pi가 주어진다.

출력형식:
  첫 번째 줄에 배낭에 담을 수 있는 가장 비싼 가격을 출력하라.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
  int bagWeight=0;
  int jewelCnt=0;

  cin>>bagWeight>>jewelCnt;
  
  vector<pair<int,int>> bag;

  for(int i=0;i<jewelCnt;i++){
    int value=0;
    int weight=0;
    cin>>weight>>value;
    pair<int,int> temp=make_pair(value,weight);
    bag.push_back(temp);
  }

  sort(bag.begin(),bag.end(),greater<>());

  int answer=0;
  for(int i=0;i<jewelCnt;i++){
    if(bagWeight==0){
      break;
    }
    
    if(bag[i].second>bagWeight){
      answer+=bagWeight*bag[i].first;
      break;
    }
    else{
      answer+=bag[i].second*bag[i].first;
      bagWeight-=bag[i].second;
    }
  }
  
  cout<<answer;
  
   return 0;
}

/*
배운 점:
  1. pair는 first를 기준으로 sort된다. 
  2. sort하면 오름차순으로 정렬된다. 
  3. 가방에 무게 채우는 문제는 Greedy 전략으로 하면 된다. 
*/