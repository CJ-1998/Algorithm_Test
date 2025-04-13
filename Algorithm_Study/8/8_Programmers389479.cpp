#include <string>
#include <utility>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int nowServer = 0;

    vector<pair<int, int>> serverDeleteTime;

    for (int i = 0; i < players.size(); i++) {
        for (int j = 0; j < serverDeleteTime.size(); j++) {
            if (serverDeleteTime[j].second == i) {
                nowServer -= serverDeleteTime[j].first;
            }
        }

        int nowPlayer = players[i];
        int needServer = nowPlayer / m;
        if (needServer > nowServer) {
            int plusServer = needServer - nowServer;
            answer += plusServer;
            nowServer = needServer;
            pair<int, int> temp = make_pair(plusServer, i + k);
            serverDeleteTime.push_back(temp);
        }
    }

    return answer;
}