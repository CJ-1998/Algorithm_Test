/*
문제:
    피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.
    이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다.
    n=17일때 까지 피보나치 수를 써보면 다음과 같다.
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
    n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 n이 주어진다. n은 1,000,000보다 작거나 같은 자연수 또는 0이다.

출력:
    첫째 줄에 n번째 피보나치 수를 1,000,000,007으로 나눈 나머지를 출력한다.
*/

#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n=0;
    scanf("%d",&n);

    vector<unsigned long long> v;
    v.push_back(0);
    v.push_back(1);

    unsigned long long t=1000000007;

    for(int i=2;i<=n;i++){
        unsigned long long temp=v[i-2]%t+v[i-1]%t;
        v.push_back(temp);
    }

    if(v.size()>2)
        printf("%llu",v[v.size()-1]%t);
    else 
        printf("%lld", v[n]);

    return 0;
}

/*
배운 점:
    1. 다이나믹 프로그래밍 bottom up 방식
*/