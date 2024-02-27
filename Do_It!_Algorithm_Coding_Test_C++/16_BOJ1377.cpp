/*
문제:
    버블 소트 알고리즘을 다음과 같이 C++로 작성했다.

        bool changed = false;
        for (int i=1; i<=N+1; i++) {
            changed = false;
            for (int j=1; j<=N-i; j++) {
                if (A[j] > A[j+1]) {
                    changed = true;
                    swap(A[j], A[j+1]);
                }
            }
            if (changed == false) {
                cout << i << '\n';
                break;
            }
        }
    위 소스에서 N은 배열의 크기이고, A는 정렬해야 하는 배열이다. 배열은 A[1]부터 사용한다.
    위와 같은 소스를 실행시켰을 때, 어떤 값이 출력되는지 구해보자.

입력:
    첫째 줄에 N이 주어진다. N은 500,000보다 작거나 같은 자연수이다. 
    둘째 줄부터 N개의 줄에 A[1]부터 A[N]까지 하나씩 주어진다. 
    A에 들어있는 수는 1,000,000보다 작거나 같은 자연수 또는 0이다.

출력:
    정답을 출력한다.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int main(){
    int N=0;
    cin>>N;

    vector<pair<int,int>> A(N);

    for(int i=0;i<N;i++){
        int temp=0;
        cin>>temp;
        A[i].first=temp;
        A[i].second=i;
    }

    sort(A.begin(),A.end());

    vector<int> B(N);
    for(int i=0;i<N;i++){
        B[i]=A[i].second-i+1;
    }

    sort(B.begin(),B.end(),greater<int>());

    cout<<B[0];

    return 0;
}

/*
배운 점:
    1. 이전, 이후 index를 사용할 때에는 pair를 사용해 index를 가지고 있으면 된다. 
*/