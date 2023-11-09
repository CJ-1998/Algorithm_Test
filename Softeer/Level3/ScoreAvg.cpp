/*
문제:
    N명의 학생들의 성적이 학번순서대로 주어졌다.
    학번 구간 [A, B]가 주어졌을 때 이 학생들 성적의 평균을 구하는 프로그램을 작성하라.

제약조건:
    1 ≤ N ≤ 10^6 인 정수
    1 ≤ K ≤ 10^4 인 정수
    1 ≤ Si ≤ 100 인 정수
    1 ≤ Ai ≤ Bi ≤ N

입력형식:
    첫 번째 줄에 학생 수 N과 구간 수 K가 주어진다.
    두 번째 줄에는 학생의 성적 Si (1 ≤ i ≤ N)가 주어진다. 
    i + 2 (1 ≤ i ≤ K)번째 줄에는 i번째 구간 Ai, Bi가 주어진다.

출력형식:
    i번째 줄에 i번째 구간의 성적평균(소수셋째자리에서 반올림)을 출력한다.
    차이가 0.01이하이면 정답으로 채점됨.
*/

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
  int studentNumber=0;
  int round=0;
  cin>>studentNumber>>round;

  vector<int> score;
  for(int i=0;i<studentNumber;i++){
    int temp=0;
    cin>>temp;
    score.push_back(temp);
  }

  for(int i=0;i<round;i++){
    int start=0;
    int end=0;
    cin>>start>>end;

    start--;

    int totalScore=0;
    int cnt=0;
    for(int i=start;i<end;i++){
      totalScore+=score[i];
      cnt++;
    }

    double answer=std::round(100*((double)totalScore/(double)cnt))/100;
    cout<<fixed;
    cout.precision(2);
    cout<<answer<<endl;
  }

   return 0;
}

/*
배운점:
    1. 평균의 경우 int 값 다 double로 타입 변환 후 계산해야 double로 나온다. 
    2. 반올림 하면 cmath 라이브러리 include하고 std::round() 이렇게 사용해야 한다. 
    3. 소수점 2자리에서 반올림하려면 round(100*값)/100 이렇게 하면 된다. 
    4. 정수 소수점 표시하려면 cout<<fixed; cout.precision(소수점 아래 자리); 하면 된다. 
*/