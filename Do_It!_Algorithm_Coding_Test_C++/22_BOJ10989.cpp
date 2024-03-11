/*
문제:
    N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력:
    첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 
    둘째 줄부터 N개의 줄에는 수가 주어진다. 
    이 수는 10,000보다 작거나 같은 자연수이다.

출력:
    첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/

#include<iostream>
#include<vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(10001);

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        v[num]++;
    }

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i];j++){
            cout<<i<<'\n';
        }
    }

    return 0;
}

/*
배운 점:
    1. radix sort
        1.1 큐를 0~9까지 만들고 숫자들의 1의 자리를 index로 해서 각 큐에 넣는다. 
        1.2 ex) 값이 34이면 4번 큐에 넣는다. 
        1.3 그리고 0번째 큐부터 값 꺼내서 배열에 넣는다. 
        1.4 이 과정을 10의 자리, 100의 자리.... 필요한 자리수만큼 반복한다. 
        1.5 마지막에는 정렬된 배열 나온다. 
    2. radix sort는 시간 복잡도 O(kn)으로 k는 데이터 자리수다. 
    3. 정렬해야 하는 데이터 개수 많으면 radix sort 사용해보자. 
    4. counting sort
        1.1 숫자 범위만큼의 배열을 만든다.
        1.2 ex) 10000까지만 10001 크기의 배열 만든다. 
        1.3 숫자 읽으면서 나오면 배열에 ++한다. 
        1.4 마지막에 배열을 읽으면서 0이 아닌 값이 나오면 그 값만큼 index 출력한다.
        1.5 ex) index 1에 3이면 1 1 1 이렇게 출력한다.
    5. cout, cin 빨라지게 하는 것 넣으면 시간 굉장히 빨라지니 꼭 넣자. 
*/