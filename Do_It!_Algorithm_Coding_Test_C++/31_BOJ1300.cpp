/*
문제:
    세준이는 크기가 N×N인 배열 A를 만들었다. 
    배열에 들어있는 수 A[i][j] = i×j 이다. 
    이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. 
    B를 오름차순 정렬했을 때, B[k]를 구해보자.
    배열 A와 B의 인덱스는 1부터 시작한다.

입력:
    첫째 줄에 배열의 크기 N이 주어진다. 
    N은 10^5보다 작거나 같은 자연수이다. 
    둘째 줄에 k가 주어진다. 
    k는 min(10^9, N^2)보다 작거나 같은 자연수이다.

출력:
    B[k]를 출력한다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, K;
    cin >> N >> K;
    long start = 1, end = K;
    long answer = 0;

    while (start <= end) {
        long middle = (start + end) / 2;
        long count = 0;

        for (int i = 1; i <= N; i++) {
            count += min(middle/i, N);  
        }

        if (count < K) {
            start = middle + 1;
        }

        else {
            answer = middle;  
            end = middle - 1;
        }
    }

    cout << answer << "\n";
}

/*
배운 점:
    1. 탐색할 때 시간 초과 나면 이분 탐색
    2. 중앙값보다 작은 수의 개수 세어서 범위 줄이는 것
    3. 작은 수의 개수가 주어진 index-1이면 B[index]의 값 구할 수 있음
    4. 작은 수의 개수는 중앙값/i -> i는 각 행의 첫번째 값
    5. 중앙값보다 작은 수의 개수가 k보다 작으면 시작 index를 중앙값 + 1로 설정
    6. 중앙값보다 작은 수의 개수가 k보다 크거나 같으면 종료 index를 중앙값 -1로 설정
    7. 그 후 정답을 중앙값으로 업데이트해 시작 index > 종료 index 일 때까지 이진 탐색
*/