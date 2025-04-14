#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
    선물 주고 받은 기록으로 다음 달에 누가 선물 많이 받을지 예측
    두 사람 선물 주고 받은 기록 있으면 더 많은 선물 준 사람이 다음 달에 그 사람에게서 하나 받음
    두 사람 선물 주고 받은 기록 없거나 같으면 선물 지수 더 큰 사람이 작은 사람에게서 하나 받음
    선물 지수 = 이번 달까지 자신이 친구들에게 준 선물 수 - 받은 선물 수
    선물 지수도 같으면 다음 달에 선물 주고 받지 않음

    기록할 것
    선물 지수
    다음 달에 받을 선물 개수
    내가 누군가에게 준 것 & 받은 것
*/

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    map<string, map<string, pair<int, int>>> giveNtake;

    // 주고 받은 선물 저장 map 초기화
    for (int i = 0; i < friends.size(); i++) {
        for (int j = 0; j < friends.size(); j++) {
            if (i != j) {
                pair<int, int> t = make_pair(0, 0);
                string friendName = friends[j];
                map<string, pair<int, int>> tMap;
                tMap[friendName] = t;
                giveNtake[friends[i]] = tMap;
            }
        }
    }

    // 받을 선물 개수, 선물 지수 map 초기화
    map<string, pair<int, int>> data;
    for (int i = 0; i < friends.size(); i++) {
        pair<int, int> t = make_pair(0, 0);
        string myName = friends[i];
        data[myName] = t;
    }

    // gifts 정보로 map들 채우기
    for (int i = 0; i < gifts.size(); i++) {
        string temp;
        stringstream stream;
        stream.str(gifts[i]);

        stream >> temp;
        string give = temp;

        stream >> temp;
        string take = temp;

        // 각각의 선물 지수 갱신
        data[give].second++;
        data[take].second--;

        // 각각의 주고 받은 선물 개수 갱신
        giveNtake[give][take].first++;
        giveNtake[take][give].second++;
    }

    // giveNtake map 돌면서 다음 달 선물 받을 개수 세기
    for (int i = 0; i < friends.size(); i++) {
        for (int j = 0; j < friends.size(); j++) {
            string myName = friends[i];
            string friendName = friends[j];

            if (i != j) {
                int myPresent = giveNtake[myName][friendName].first;
                int friendPresent = giveNtake[myName][friendName].second;

                // 내가 준 선물이 더 많다면 다음 달 받을 선물 ++
                if (myPresent > friendPresent) {
                    data[myName].first++;
                }
                // 주고 받은 선물 개수 같거나 || 주고 받은 기록 없다면 각각 선물 지수 확인
                else if (myPresent == friendPresent) {
                    int myRate = data[myName].second;
                    int friendRate = data[friendName].second;

                    // 내 선물 지숙 크다면 다음 달 받을 선물 ++
                    if (myRate > friendRate) {
                        data[myName].first++;
                    }
                }
            }
        }
    }

    // 다음 달 가장 많이 받는 선물 개수 찾기
    for (int i = 0; i < friends.size(); i++) {
        int present = data[friends[i]].first;
        if (answer < present)
            answer = present;
    }

    return answer;
}