/*
문제:
    N개의 수로 된 수열 A[1], A[2], …, A[N] 이 있다. 이 수열의 i번째 수부터 j번째 수까지의 합 A[i] + A[i+1] + … + A[j-1] + A[j]가 M이 되는 경우의 수를 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 N(1 ≤ N ≤ 10,000), M(1 ≤ M ≤ 300,000,000)이 주어진다. 다음 줄에는 A[1], A[2], …, A[N]이 공백으로 분리되어 주어진다. 각각의 A[x]는 30,000을 넘지 않는 자연수이다.

출력:
    첫째 줄에 경우의 수를 출력한다.

*/

#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

int main(){
    int answer=0;

    int n=0;
    int m=0;
    cin>>n>>m;

    deque<int> d;

    for(int i=0;i<n;i++){
        int temp=0;
        cin>>temp;
        d.push_back(temp);
    }

    deque<int> sum;

    int s=0;
    for(int i=0;i<=n;i++){
        if(s>m){
            int sf=sum.front();
            sum.pop_front();
            s-=sf;
            i--;
            continue;
        }
        else if(s==m){
            answer++;
            int sf=sum.front();
            sum.pop_front();
            s-=sf;
        }
        int f=d.front();
        d.pop_front();
        s+=f;
        sum.push_back(f);
    }

    cout<<answer;

    return 0;
}

/*
개선 사항:
    two pointer로 배열에 앞, 뒤를 가리키는 index 변수를 가지고 sum이 m보다 작으면 뒤의 index를 뒤로 옮기고 m보다 크면 앞의 index를 뒤로 옮긴다. m과 같으면 뒤의 index를 뒤로 옮긴다. 

배운 점:
    1. deque 사용법
    2. two pointer 개념
*/