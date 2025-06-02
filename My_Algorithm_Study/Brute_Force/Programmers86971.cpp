#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dfs(int index, int cnt, vector<vector<int>> graph, vector<int> &visited) {
    if (visited[index] == 1) {
        return -1;
    }

    visited[index] = 1;

    cnt++;

    for (int i = 0; i < graph[index].size(); i++) {
        if (graph[index][i] == 1 && visited[i] == 0) {
            // 여기에 cnt 그대로 넣어서 계속 안 됐음
            // 0 넣어야 됌
            // why? -> ...
            int t = dfs(i, 0, graph, visited);
            if (t != -1) {
                cnt += t;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;

    vector<vector<int>> graph;

    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(0);
        }
        graph.push_back(temp);
    }

    for (int i = 0; i < wires.size(); i++) {
        int x = wires[i][0] - 1;
        int y = wires[i][1] - 1;

        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    vector<int> tempAns;

    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> tempGraph = graph;
        vector<int> visited(n, 0);

        int x = wires[i][0] - 1;
        int y = wires[i][1] - 1;

        tempGraph[x][y] = 0;
        tempGraph[y][x] = 0;

        vector<int> cnt;

        for (int j = 0; j < n; j++) {
            int dfsCnt = dfs(j, 0, tempGraph, visited);
            if (dfsCnt != -1) {
                cnt.push_back(dfsCnt);
            }
        }

        sort(cnt.begin(), cnt.end());

        tempAns.push_back(cnt[1] - cnt[0]);
    }

    sort(tempAns.begin(), tempAns.end());
    answer = tempAns[0];

    return answer;
}

/*
    문제 이해
        n개의 전선 통해 하나의 트리 형태
        전선 중 하나 끊어 전력망 2개로 분할
        두 전력망이 갖는 송전탑 개수 최대한 비슷하게

        송전탑 개수 n
        전선 정보 (연결정보) 2차원 배열
        두 전력망이 가지는 송전탑 개수 차이 반환

        2<=n<=100
        2차원 배열 길이 n-1
*/

/*
    풀이 생각
        n-1개 중 하나 끊고 dfs 돌려서 각 개수 파악
        dfs 도는데 시간 복잡도 * n-1 해도 많지 않다고 생각

        wires 있고 복사 2차원 배열 만들어 dfs
*/

/*
    문제 이해 시간 : 3m
    풀이 생각 시간 : 2m 30s
    문제 구현 시간 : 25m
    디버깅 시간 : 36m 30s
    총 시간 : 1h 7m
*/

/*
    다른 사람 풀이
*/