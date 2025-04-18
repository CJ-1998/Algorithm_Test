#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
    운송 시스템 규칙
    1. (r,c) 좌표 n개 각각 1~n 번호 가짐
    2. 로봇 운송 경로 존재, 경로는 m개 포인트로 구성, 첫 포인트에서 시작
    3. 로봇 x대, 0초에 동시 출발, 1초마다 좌표 이동
    4. 다음 포인트로 최단 경로로 이동, 최단 경로 여러 개 시 r>c (상하로 먼저 이동 후 좌우)
    5. 마지막 포인트 도착 시 로봇 out

    같은 좌표에 로봇 2대 이상 = 위험 상황
    위험 상황 몇 번인지?

    points = 운송해야 하는 장소
    routes = 로봇 개수, 각 로봇이 가야 하는 장소 list

    각 포인트로 이동할 때 거치는 좌표 전부 저장
    -> 좌표에 겹치는 것 갯수 세면 될 듯?
*/

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    vector<vector<pair<int, int>>> allPoint;
    vector<int> pointCounts;

    for (int i = 0; i < routes.size(); i++) {
        vector<pair<int, int>> robotPoints;
        // 시작점 좌표 추가
        robotPoints.push_back(make_pair(points[routes[i][0] - 1][0], points[routes[i][0] - 1][1]));
        for (int j = 0; j < routes[0].size() - 1; j++) {
            // 출발, 도착 포인트 확인
            int startIndex = routes[i][j] - 1;
            int endIndex = routes[i][j + 1] - 1;

            // 출발, 도착 포인트의 좌표 확인
            int startX = points[startIndex][0];
            int startY = points[startIndex][1];
            int endX = points[endIndex][0];
            int endY = points[endIndex][1];

            // 도착 포인트까지 가는데 몇번 이동 필요한지 확인
            int moveCount = abs(endX - startX) + abs(endY - startY);
            pointCounts.push_back(moveCount);

            // robotPoints.push_back(make_pair(startX,startY));

            // 이동하며 좌표 기록
            for (int k = 0; k < moveCount - 1; k++) {
                // row 좌표 다름 = 상하로 이동해야 함 -> 먼저 이동
                if (startX != endX) {
                    // 아래로 이동
                    if (startX < endX) {
                        robotPoints.push_back(make_pair(++startX, startY));
                    }
                    // 위로 이동
                    else if (startX > endX) {
                        robotPoints.push_back(make_pair(--startX, startY));
                    }
                }
                // row 좌표 같음 = 좌우로 이동해야 함
                else {
                    // 우로 이동
                    if (startY < endY) {
                        robotPoints.push_back(make_pair(startX, ++startY));
                    }
                    // 좌로 이동
                    else if (startY > endY) {
                        robotPoints.push_back(make_pair(startX, --startY));
                    }
                }
            }
            // 도착점 좌표 추가
            robotPoints.push_back(make_pair(endX, endY));
        }
        allPoint.push_back(robotPoints);
        pointCounts[i]++;
    }

    // 제일 오래 이동하는 것 찾아 갯수 확인
    int maxMoveCount = *max_element(pointCounts.begin(), pointCounts.end());

    // 벡터 오류 안 나게 나머지 채워주기
    for (int i = 0; i < allPoint.size(); i++) {
        int plusCount = maxMoveCount - pointCounts[i];
        for (int j = 0; j < plusCount; j++) {
            allPoint[i].push_back(make_pair(-1, -1));
        }
    }

    // for(int i=0;i<allPoint.size();i++){
    //     cout<<i<<"번 로봇 움직이는 좌표들:";
    //     for(int j=0;j<allPoint[i].size();j++){
    //         cout<<allPoint[i][j].first<<" "<<allPoint[i][j].second<<", ";
    //     }
    //     cout<<endl;
    // }

    // 이동한 횟수만큼 좌표들 확인
    for (int i = 0; i < maxMoveCount; i++) {
        for (int j = 0; j < allPoint.size() - 1; j++) {
            bool hasSame = false;

            // 기준 좌표
            int x = allPoint[j][i].first;
            int y = allPoint[j][i].second;

            if (x == -1 && y == -1) {
                continue;
            }

            // 2중 for문 돌면서 아래 같은 좌표 있는지 확인
            for (int k = j + 1; k < allPoint.size(); k++) {
                int xx = allPoint[k][i].first;
                int yy = allPoint[k][i].second;

                if (x == xx && y == yy) {
                    hasSame = true;
                    allPoint[k][i].first = -1;
                    allPoint[k][i].second = -1;
                }
            }
            if (hasSame) {
                answer++;
                allPoint[j][i].first = -1;
                allPoint[j][i].second = -1;
                // cout<<"answer: "<<answer<<endl;
            }
        }

        // cout<<endl;
        // for(int a=0;a<allPoint.size();a++){
        //     cout<<a<<"번 로봇 움직이는 좌표들:";
        //     for(int b=0;b<allPoint[a].size();b++){
        //         cout<<allPoint[a][b].first<<" "<<allPoint[a][b].second<<", ";
        //     }
        //     cout<<endl;
        // }
    }

    return answer;
}