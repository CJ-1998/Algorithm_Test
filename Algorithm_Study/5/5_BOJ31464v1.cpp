#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int chocolateCount = 0;
int answerCount = 0;
int n = 0;
vector<vector<int>> graph;
vector<pair<int, int>> answer;
vector<vector<int>> visited;

int dfs(int row, int col) {
    if (visited[row][col] == 1) {
        return 0;
    }
    if (graph[row][col] == 0) {
        return 0;
    }

    visited[row][col] = 1;
    int count = 1;

    if (row - 1 >= 0) {
        count += dfs(row - 1, col);
    }
    if (row + 1 < n) {
        count += dfs(row + 1, col);
    }
    if (col - 1 >= 0) {
        count += dfs(row, col - 1);
    }
    if (col + 1 < n) {
        count += dfs(row, col + 1);
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string temp = "";
        cin >> temp;
        vector<int> tempVec;
        for (int j = 0; j < n; j++) {
            if (temp[i] == '#') {
                chocolateCount++;
                tempVec.push_back(1);
            } else {
                tempVec.push_back(0);
            }
        }
        graph.push_back(tempVec);
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {

    //     }
    // }

    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(0);
        }
        visited.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 0) {
                continue;
            } else {
                graph[i][j] = 0;
                int passCount = 0;
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (graph[k][l] == 0) {
                            continue;
                        } else {
                            graph[k][l] = 0;
                            /*
                                돌았을 때 연결된 것이 2덩이여야 함
                            */
                            int dummy = 0;
                            for (int x = 0; x < n; x++) {
                                for (int y = 0; y < n; y++) {
                                    if (dfs(x, y) > 0) {
                                        dummy++;
                                    }
                                }
                            }
                            if (dummy == 2) {
                                passCount++;
                                // answerCount++;
                                // pair<int, int> t = make_pair(i, j);
                                // answer.push_back(t);
                            }
                            for (int x = 0; x < n; x++) {
                                for (int y = 0; y < n; y++) {
                                    visited[x][y] = 0;
                                }
                            }
                            graph[k][l] = 1;
                        }
                    }
                }
                if (passCount == chocolateCount - 1) {
                    answerCount++;
                    pair<int, int> t = make_pair(i, j);
                    answer.push_back(t);
                }
                graph[i][j] = 1;
            }
        }
    }

    cout << answerCount << "\n";
    for (int x = 0; x < answer.size(); x++) {
        cout << answer[x].first + 1 << " " << answer[x].second + 1 << "\n";
    }

    return 0;
}