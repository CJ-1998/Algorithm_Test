#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    int m = 0;
    cin >> n >> m;

    int answer = 99999999;

    vector<int> num;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        num.push_back(temp);
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = num[i] + num[j] + num[k];
                int diff = m - sum;
                if (answer == 99999999) {
                    answer = sum;
                } else {
                    int answerDiff = m - answer;
                    if (answerDiff < 0) {
                        answer = sum;
                    } else {
                        if (diff >= 0 && diff < answerDiff) {
                            answer = sum;
                        }
                    }
                }
            }
        }
    }

    cout << answer;

    return 0;
}

/*
    문제 이해
        블랙잭
        카드 합 21 넘지 않는 한도 내에서 카드 합 최대한 크게 만들기
        새로운 블랙잭 규칙 만들기

        각 카드에는 양의 정수
        딜러 N장의 카드를 모두 숫자 보이게 바닥에 놓음
        딜러가 숫자 M을 크게 외침

        플레이어 제한 시간 안에 N장의 카드 중 3장의 카드 고르기
        고른 카드의 합은 M 넘지 않으면서 최대한 가깝게

        N장의 카드의 숫자 주어짐
        M 넘지 않으며 M에 최대한 가까운 카드 3장의 합 출력

        3 <= N <= 100
        1 <= M <= 300000
        각 카드의 수 <= 100000
*/

/*
    풀이 생각
        N개 중 3개 골라서 가장 M에 가깝게
        -> 조합, 순열?
        100C3 = 161700 (최악의 경우)
        다 돌려도 될 것 같음

        모든 조합 다 확인해보기?
        3중 for문으로 돌면서 가장 큰 값 업데이트

*/

/*
    문제 이해 시간 : 2m
    풀이 생각 시간 : 4m
    문제 구현 시간 : 5m
    디버깅 시간 : 8m 30s
    총 시간 : 19m 30s
*/

/*
    다른 사람 풀이
        sum <= m && answer < sum -> answer = sum 하면 됐음;;
*/