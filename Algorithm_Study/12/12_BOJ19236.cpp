#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

/*
    4*4 공간, 각 칸은 (x,y)
    한 칸에는 물고기 한 마리
    각 물고기는 번호, 방향 가짐
    물고기 번호 1~16, 중복 X
    방향은 상하좌우, 대각선 8가지

    상어가 (0,0)의 물고기 먹고 들어감
    상어 방향 = 물고기 방향

    물고기 번호 작은 것부터 이동
    이동 가능 칸
        빈 칸
        다른 물고기 있는 칸
    이동 불가능 칸
        상어 있는 칸
        공간 넘는 칸

    물고기 방향 45도 반시계 회전 가능 (여러 번 가능)
    물고기 이동할 수 있는 칸 없으면 이동 X
    다른 물고기 있는 칸으로 이동 시 서로 위치 바꿈

    물고기 이동 끝나면 상어가 이동
    상어 방향으로 여러 칸 이동 가능
    물고기 있으면 물고기 먹음
    이동 중 지나가는 칸의 물고기 먹지 않음
    물고기 없는 칸으로 이동 불가능
    이동할 수 있는 칸 없으면 공간 벗어남

    상어가 먹을 수 있는 물고기 번호 합의 최댓값 구하자

    기록해야 할 것
        상어 방향
        상어 먹은 물고기 번호 합
        물고기 번호 + 방향
*/

/*
    TODO :
        상어가 먹을 물고기는 그냥 최대의 값만 선택하면 안됨
        갈 수 있는 모든 물고기에 대해 값을 확인하고 최대 값을 선택해야 함
        따라서 함수로 빼서 재귀로 풀어야 함
        어디 부분을 아직 함수로 뺄지 보이지 않음
*/

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> direction = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

    vector<vector<pair<int, int>>> space;

    // 공간 초기화
    for (int i = 0; i < 4; i++) {
        vector<pair<int, int>> temp;
        for (int j = 0; j < 4; j++) {
            int num = 0;
            int dir = 0;
            cin >> num >> dir;
            pair<int, int> fish = make_pair(num, dir - 1);
            temp.push_back(fish);
        }
        space.push_back(temp);
    }

    int sharkRow = 0;
    int sharkCol = 0;
    int sharkDir = 0;

    int eatFish = 0;

    while (true) {
        // 물고기 먹어서 상어의 방향, 먹은 물고기 수정
        sharkDir = space[sharkRow][sharkCol].second;
        eatFish += space[sharkRow][sharkCol].first;

        // space에 물고기 수정
        // 물고기 방향 = -1 -> 현재 상어 있는 것
        space[sharkRow][sharkCol].second = -1;

        // 물고기 이동
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 4; j++) {
                bool isBreak = false;
                bool isChanged = false;
                for (int k = 0; k < 4; k++) {
                    // 찾으려는 번호 물고기 찾음
                    if (space[j][k].first == i + 1) {
                        // 찾으려는 번호 물고기 있음
                        if (space[j][k].second >= 0) {
                            // 방향 다 바꿨는지 확인 위함 (필요 없는듯?)
                            int firstDir = space[j][k].second;
                            int nowDir = space[j][k].second;

                            // 물고기 방향 바꾸기
                            for (int l = 0; l < 8; l++) {
                                int newRow = j + direction[nowDir].first;
                                int newCol = k + direction[nowDir].second;

                                // 방향 바꿔야 함
                                if (newRow < 0 || newCol < 0 || newRow >= 4 || newCol >= 4 ||
                                    space[newRow][newCol].second < 0) {
                                    // cout << "change direction" << endl;
                                    nowDir++;
                                    if (nowDir == 8) {
                                        nowDir = 0;
                                    }
                                }
                                // 물고기 자리 바꾸기
                                else {
                                    space[j][k].second = nowDir;

                                    int tFirst = space[j][k].first;
                                    space[j][k].first = space[newRow][newCol].first;
                                    space[newRow][newCol].first = tFirst;

                                    int tSecond = space[j][k].second;
                                    space[j][k].second = space[newRow][newCol].second;
                                    space[newRow][newCol].second = tSecond;

                                    isChanged = true;
                                    break;
                                }
                            }
                        }
                        // 찾으려는 번호 물고기 없음
                        else {
                            isBreak = true;
                            break;
                        }
                    }
                    if (isChanged) {
                        break;
                    }
                }
                if (isBreak) {
                    break;
                }
                if (isChanged) {
                    break;
                }
            }
        }

        // 상어가 이동할 방향에서 가장 큰 물고기 위치 찾아
        // 상어 row, col 수정
        vector<int> best;
        vector<pair<int, int>> bestIndex;
        int newSharkRow = sharkRow;
        int newSharkCol = sharkCol;

        // 상어 방향대로 움직이며 물고기 번호 확인
        while (true) {
            newSharkRow += direction[sharkDir].first;
            newSharkCol += direction[sharkDir].second;

            if (newSharkRow >= 4 || newSharkCol >= 4 || newSharkRow < 0 || newSharkCol < 0) {
                break;
            } else {
                if (space[newSharkRow][newSharkCol].second >= 0) {
                    best.push_back(space[newSharkRow][newSharkCol].first);
                    bestIndex.push_back(make_pair(newSharkRow, newSharkCol));
                }
            }
        }
        if (best.size() == 0) {
            break;
        } else {
            // 번호 제일 큰 것만 선택하면 안됨
            // 한번 더 갈 수 있는지 체크
            int bigIndex = -1;
            int maxCount = -1;
            for (int i = 0; i < best.size(); i++) {
                if (maxCount < best[i]) {
                    maxCount = best[i];
                    bigIndex = i;
                }
            }
            space[sharkRow][sharkCol].second = -2;
            sharkRow = bestIndex[bigIndex].first;
            sharkCol = bestIndex[bigIndex].second;
        }
    }

    cout << eatFish;

    return 0;
}