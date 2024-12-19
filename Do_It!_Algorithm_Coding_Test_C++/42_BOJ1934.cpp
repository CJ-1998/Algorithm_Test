/*
문제
    두 자연수 A와 B에 대해서, A의 배수이면서 B의 배수인 자연수를 A와 B의 공배수라고 한다. 
    이런 공배수 중에서 가장 작은 수를 최소공배수라고 한다. 
    예를 들어, 6과 15의 공배수는 30, 60, 90등이 있으며, 최소 공배수는 30이다.

    두 자연수 A와 B가 주어졌을 때, A와 B의 최소공배수를 구하는 프로그램을 작성하시오.

입력
    첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다. 
    둘째 줄부터 T개의 줄에 걸쳐서 A와 B가 주어진다. (1 ≤ A, B ≤ 45,000)

출력
    첫째 줄부터 T개의 줄에 A와 B의 최소공배수를 입력받은 순서대로 한 줄에 하나씩 출력한다.
*/

#include<iostream>

using namespace std;

int gcd(int a, int b){
    int c;
    while (b != 0)
		{
			c = a % b;
			a = b;
			b = c;
		}
	return a;
}

int lcm(int a, int b){
    return a*b/gcd(a, b);
}

int main(){

    int count = 0;
    cin>>count;

    for(int i=0;i<count;i++){
        int a=0;
        int b=0;
        cin>>a>>b;
        int answer=lcm(a,b);
        cout<<answer<<"\n";
    }

    return 0;
}