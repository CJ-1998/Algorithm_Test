//--------------풀이 중------------
// 3 2 1 6 4 5 처럼 중간에 높은 것 있으면 틀리는 문제 아직 해결 못함

/*
문제:
    남북으로 흐르는 개울에 동서로 징검다리가 놓여져 있다.
    이 징검다리의 돌은 들쑥날쑥하여 높이가 모두 다르다. 
    철수는 개울의 서쪽에서 동쪽으로 높이가 점점 높은 돌을 밟으면서 개울을 지나가려고 한다.
    돌의 높이가 서쪽의 돌부터 동쪽방향으로 주어졌을 때 철수가 밟을 수 있는 돌의 최대 개수는?

제약조건:
    1 ≤ N ≤ 3×10^3 인 정수
    1 ≤ Ai ≤ 10^8 인 정수

입력형식:
    첫 번째 줄에 돌의 개수 N이 주어진다.
    두 번째 줄에 돌의 높이 Ai (1 ≤ i ≤ N)가 서쪽부터 동쪽으로 차례로 주어진다.

출력형식:
    첫 번째 줄에 철수가 밟을 수 있는 돌의 최대 개수를 출력하라.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{

  int stoneCount=0;
  cin>>stoneCount;

  vector<int> stone;

  for(int i=0;i<stoneCount;i++){
    int temp=0;
    cin>>temp;
    stone.push_back(temp);
  }

  vector<int> answer;

  for(int i=0;i<stoneCount;i++){
    int stepStone=stone[i];
    int stepCount=1;
    for(int j=i+1;j<stoneCount;j++){
      if(stone[j]>stepStone){
        stepStone=stone[j];
        stepCount++;
      }
    }
    answer.push_back(stepCount);
  }

  sort(answer.begin(),answer.end(),greater<>());

  cout<<answer[0];
  
   return 0;
}