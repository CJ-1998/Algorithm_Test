#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
    한 아이 사탕 뺐으면 그 아이 친구들 사탕도 뺐음
    k명 이상 울면 어른들 나옴
    어른들에게 들키지 않고 최대로 뺐을 수 있는 사탕 양 구하라

    n = 거리에 있는 아이들 수 30000
    m = 아이들의 친구 관계 수 100000
    k = 어른들 거리 나오는 최소 아이들 수 3000
    아이들 받은 사탕 수
    아이들 친구 관계
*/

vector<int> candyCount;
vector<pair<int, pair<int, int>>> relCandyCount;
vector<vector<int>> rel;
vector<int> visited;
vector<vector<int>> realRel;

bool compare(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
    if (a.second.first == b.second.first) {
        if (a.second.second < b.second.second) {
            return a.second.second > b.second.second;
        }
    }
    return a.second.first > b.second.first;
}

pair<int, int> dfs(int pushIndex, int index) {
    if (visited[index] == 1) {
        return make_pair(0, 0);
    }

    visited[index] = 1;
    int count = candyCount[index];
    int friendCount = 1;

    for (int i = 0; i < rel[index].size(); i++) {
        pair<int, int> t = dfs(pushIndex, rel[index][i]);
        count += t.first;
        friendCount += t.second;
    }
    if (pushIndex != index)
        realRel[pushIndex].push_back(index);
    return make_pair(count, friendCount);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int children = 0;
    int relCount = 0;
    int cryCount = 0;

    cin >> children >> relCount >> cryCount;

    for (int i = 0; i < children; i++) {
        int temp = 0;
        cin >> temp;
        candyCount.push_back(temp);

        relCandyCount.push_back(make_pair(i, make_pair(0, 0)));
        visited.push_back(0);

        vector<int> tempVec;
        rel.push_back(tempVec);

        vector<int> ttempVec;
        realRel.push_back(ttempVec);
    }

    for (int i = 0; i < relCount; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b;
        rel[a - 1].push_back(b - 1);
        rel[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < children; i++) {
        for (int j = 0; j < children; j++) {
            visited[j] = 0;
        }
        pair<int, int> t = dfs(i, i);
        relCandyCount[i].second.first = t.first;
        relCandyCount[i].second.second = t.second;
    }

    cout << endl;

    sort(relCandyCount.begin(), relCandyCount.end(), compare);

    for (int i = 0; i < relCandyCount.size(); i++) {
        cout << relCandyCount[i].first + 1 << " " << relCandyCount[i].second.first << " "
             << relCandyCount[i].second.second << endl;
    }

    cout << endl;

    for (int i = 0; i < realRel.size(); i++) {
        cout << i + 1 << ": ";
        for (int j = 0; j < realRel[i].size(); j++) {
            cout << realRel[i][j] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}