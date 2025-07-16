#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int num = 0;
        int limitCal = 0;
        cin >> num >> limitCal;

        vector<pair<int, int>> v;
        for (int i = 0; i < num; i++) {
            int a = 0;
            int b = 0;
            cin >> a >> b;

            v.push_back(make_pair(a, b));
        }

        int **dp = new int *[num];
        for (int i = 0; i < num; i++) {
            dp[i] = new int[limitCal + 1];
        }

        for (int i = 0; i < num; i++) {
            dp[i][0] = 0;
        }

        for (int j = 1; j <= limitCal; j++) {
            if (j < v[0].second) {
                dp[0][j] = 0;
            } else {
                dp[0][j] = v[0].first;
            }
        }

        for (int i = 1; i < num; i++) {
            for (int j = 1; j <= limitCal; j++) {
                if (j < v[i].second) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], v[i].first + dp[i - 1][j - v[i].second]);
                }
            }
        }

        cout << "#" << test_case << " " << dp[num - 1][limitCal] << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

// 문제 풀이
// 배낭 문제 관련 문제
// 배낭 문제를 이해하고 풀이를 적용하면 됨