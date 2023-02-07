/*
문제:
    수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다. 둘째 줄에는 N개의 수가 주어진다. 수는 1,000보다 작거나 같은 자연수이다. 셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가 주어진다.

출력:
    총 M개의 줄에 입력으로 주어진 i번째 수부터 j번째 수까지 합을 출력한다.
*/

#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num=0;
    cin>>num;
    int time=0;
    cin>>time;

    int* arr=new int[num];
    int* addArr=new int[num];

    for(int i=0;i<num;i++){
        int temp=0;
        cin>>temp;
        arr[i]=temp;
    }

    addArr[0]=arr[0];
    for(int i=1;i<num;i++){
        addArr[i]=(addArr[i-1]+arr[i]);
    }

    for(int i=0;i<time;i++){
        int start=0;
        int end=0;
        cin>>start>>end;
        if(start>1)
            cout<<addArr[end-1]-addArr[start-2]<<"\n";
        else
            cout<<addArr[end-1]-0<<"\n";
    }

    return 0;
}

/*
개선 사항:
    1. 합배열 만들 때 index 1부터 시작하게 하면 더 간단하게 할 수 있다. 

배운 점:
    1. 합 배열 S 만드는 공식 : S[i] = S[i-1] + A[i].
    2. i~j까지 구간 합 구하는 공식: S[j] - S[i-1].
    3. endl 쓰면 시간 오래 걸리니 “\n” 사용하자.
*/