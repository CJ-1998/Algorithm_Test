#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
    칵테일에 들어가는 재료 N개
    재료 쌍 N-1개의 비율 알아냄
    이 비율로 칵테일 전체 재료 비율 알아낼 수 있음

    칵테일 만드는데 필요한 재료의 양 구하기
    필요한 재료의 질량을 모두 더한 값이 최소가 되어야 함

    a b p q = a번 재료 질량 b번 재료 질량으로 나눈 값이 p/q

    N = 재료의 개수, 10미만


*/

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<pair<int, int>>> ratio;

    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(make_pair(0, 0));
        }
        ratio.push_back(temp);
    }

    vector<int> answer;
    for (int i = 0; i < n; i++) {
        answer.push_back(0);
    }

    for (int i = 0; i < n - 1; i++) {
        int a = 0;
        int b = 0;
        int p = 0;
        int q = 0;
        cin >> a >> b >> p >> q;

        if (answer[a] == 0 && answer[b] == 0) {
            answer[a] = p;
            answer[b] = q;
        } else {
            if (answer[a] != 0 && answer[b] == 0) {
                int lcmValue = lcm(answer[a], p);
                int oneValue = lcmValue / answer[a];
                int twoValue = lcmValue / p;

                for (int j = 0; j < n; j++) {
                    if (ratio[a][j].first != 0 && ratio[a][j].second != 0) {
                    }
                }
            }
        }

        ratio[a][b].first = p;
        ratio[a][b].second = q;

        ratio[b][a].first = q;
        ratio[b][a].second = p;
    }

    return 0;
}
