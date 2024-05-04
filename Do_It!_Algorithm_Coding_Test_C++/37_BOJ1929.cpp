/*
문제
    M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
    첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) 
    M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
    한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
*/

#include<iostream>
#include<cmath> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m=0;
    int n=0;
    cin >> m >> n;

    for(int i=m; i<=n; i++){
        bool check = false;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                check = true;
                break;
            }
        }

        if(i==1)
            check = true;

        if(check)
            continue;
        else 
            cout << i << "\n";
    }

    return 0;
}

/*
배운 점:
    1. 소수 판별은 2부터 sqrt(n)까지만 확인하면 된다.
    2. 1은 소수가 아니다. 
    3. 소수 판별에 빠른 방법 에라토스네스의 체 있는데 숫자 너무 많지 않으면 이 방법도 괜찮은 것 같다. 
*/