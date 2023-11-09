/*
문제:
    바이러스가 숙주의 몸속에서 1초당 P배씩 증가한다.
    처음에 바이러스 K마리가 있었다면 N초 후에는 총 몇 마리의 바이러스로 불어날까? 
    N초 동안 죽는 바이러스는 없다고 가정한다.

제약 조건:
    1 ≤ K ≤ 10^8인 정수
    1 ≤ P ≤ 10^8인 정수
    1 ≤ N ≤ 10^6인 정수

입력 형식:
    첫 번째 줄에 처음 바이러스의 수 K, 증가율 P, 총 시간 N(초)이 주어진다.

출력 형식:
    최종 바이러스 개수를 1000000007로 나눈 나머지를 출력하라.
*/

#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
  int k=0;
  int p=0;
  int n=0;
  cin>>k>>p>>n;

  int constant=1000000007;

  long long temp=k;
  
  for(int i=0;i<n;i++){
    temp=((temp%constant)*(p%constant))%constant;
    }
  
  cout<<temp;
  
   return 0;
}

/*
배운 점:
    1. (A*B)%C = ((A%C)*(B%C))%C
*/