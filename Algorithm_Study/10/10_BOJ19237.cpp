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

    vector<vector<pair<int, int>>> graph;
    vector<int> position;
    vector<vector<vector<int>>> priority;

    int n = 0;
    int shark = 0;
    int k = 0;

    cin >> n >> shark >> k;

    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> temp;
        for (int j = 0; j < n; j++) {
            int t = 0;
            cin >> t;
            if (t != 0) {
                pair<int, int> p = make_pair(t, k);
                temp.push_back(p);
            } else {
                pair<int, int> p = make_pair(t, t);
                temp.push_back(p);
            }
        }
        graph.push_back(temp);
    }

    for (int i = 0; i < shark; i++) {
        int t = 0;
        cin >> t;
        position.push_back(t);
    }

    for (int i = 0; i < shark; i++) {
        vector<vector<int>> temp1;
        for (int j = 0; j < 4; j++) {
            vector<int> temp2;
            for (int k = 0; k < 4; k++) {
                int t = 0;
                cin >> t;
                temp2.push_back(t);
            }
            temp1.push_back(temp2);
        }
        priority.push_back(temp1);
    }

    /*
        숫자 낮을수록 나머지 쫓아냄
        냄새 뿌리고 1초마다 상어 이동
        냄새는 k초 이후 사라짐
        상하좌우 중 이동 방향 결정
            1. 아무 냄새 없는 칸 방향
            2. 자신의 냄새 있는 칸 방향 (우선순위 존재)
        이동한 방향으로 상어 방향 정해짐
        1번 상어만 남는게 몇 초 후인지?
        1000초 넘어도 다른 상어 남아 있으면 -1
    */

    while (true) {
    }

    return 0;
}