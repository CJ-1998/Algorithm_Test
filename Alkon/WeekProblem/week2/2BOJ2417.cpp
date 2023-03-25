/*
(아직 못 품)
문제:
    정수가 주어지면, 그 수의 정수 제곱근을 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 정수 n이 주어진다. (0 ≤ n < 2^63)

출력:
    첫째 줄에 q^2 ≥ n인 가장 작은 음이 아닌 정수 q를 출력한다.
*/

#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    unsigned long long answer=0;
    
    unsigned long long n=0;
    scanf("%llu",&n);

    unsigned long long start=0;
    unsigned long long end=n;

    while(start<=end){
        unsigned long long mid=(start+end)/2;
        unsigned long long temp=mid*mid;

        if(temp==n){
            answer=mid;
            break;
        }
        else if(temp>n){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    if(answer!=0)
        printf("%llu", answer);
    else
        printf("%llu",end+1);

    return 0;
}



