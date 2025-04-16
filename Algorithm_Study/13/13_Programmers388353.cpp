/*
    알파벳 대문자로 종류 구분 컨테이너 n*m
    특정 컨테이너 출고 요청 -> 접근 가능한 해당 종류 컨테이너 모두 꺼냄
    접근 가능 = 4면 중 1면이 창고 외부와 연결된 컨테이너

    창고 외부와 연결되지 않은 컨테이너도 꺼낼 수 있는 크레인 도입
    크레인 사용 시 요청된 종류의 모든 컨테이너 꺼낼 수 있음

    알파벳 1개 = 지게차로 꺼내기
    알파벳 2개 = 크레인으로 꺼내기

    요청 수행 후 남은 컨테이너 수 return

    창고 최대 50*50
    창고 입력 vector<stirng>로 들어옴
    요청 최대 100개
    요청 입력 vector<stirng>로 들어옴
    요청 길이 1 = 지게차, 길이 2 = 크레인
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;

    vector<vector<char>> container;
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int containerRow = storage.size();
    int containerCol = storage[0].size();

    // 창고 초기화
    for (int i = 0; i < storage.size(); i++) {
        vector<char> temp;
        string str = storage[i];
        for (int j = 0; j < storage[0].size(); j++) {
            temp.push_back(str[j]);
        }
        container.push_back(temp);
    }

    for (int i = 0; i < storage.size(); i++) {
        for (int j = 0; j < storage[0].size(); j++) {
            cout << container[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < requests.size(); i++) {
        // 요청 길이 1 = 지게차
        if (requests[i].length() == 1) {
            char ch = requests[i][0];

            vector<pair<int, int>> delCoor;

            // 창고 전부 돌며 찾으려는 컨테이너 찾기
            for (int j = 0; j < storage.size(); j++) {
                for (int k = 0; k < storage[0].size(); k++) {
                    if (container[j][k] == ch) {
                        // 상하좌우 확인
                        for (int l = 0; l < dir.size(); l++) {
                            // 상하좌우의 좌표
                            int newRow = j + dir[l].first;
                            int newCol = k + dir[l].second;
                            // 상하좌우 좌표가 창고 밖이거나 그 좌표가 비어있다면
                            if (newRow < 0 || newCol < 0 || newRow >= containerRow || newCol >= containerCol ||
                                container[newRow][newCol] == '.') {
                                // 현재 좌표 비우고 상하좌우 확인 for문 탈출
                                container[j][k] = '-';
                                delCoor.push_back(make_pair(j, k));
                                break;
                            }
                        }
                    }
                }
            }

            for (int j = 0; j < delCoor.size(); j++) {
                container[delCoor[j].first][delCoor[j].second] = '.';
            }

        }
        // 요청 길이 2 = 크레인
        else {
            char ch = requests[i][0];
            // 창고 전부 돌며 찾기
            for (int j = 0; j < storage.size(); j++) {
                for (int k = 0; k < storage[0].size(); k++) {
                    // 컨테이너 찾음
                    if (container[j][k] == ch) {
                        bool isAllChecked = true;
                        // 상하좌우 보면서 창고 밖이나 창고 밖과 연결된지 확인
                        for (int l = 0; l < dir.size(); l++) {
                            // 상하좌우의 좌표
                            int newRow = j + dir[l].first;
                            int newCol = k + dir[l].second;
                            // 상하좌우 좌표가 창고 밖이거나 창고 밖과 연결되어 있다면
                            if (newRow < 0 || newCol < 0 || newRow >= containerRow || newCol >= containerCol ||
                                container[newRow][newCol] == '.') {
                                // 현재 좌표도 창고 밖과 연결된 것으로 표시
                                // (왜냐하면 다 .로 하면 지게차로 꺼낼 때 중간에 빈 곳도 밖과 연결되었다고 착각하게 됨)
                                container[j][k] = '.';
                                isAllChecked = false;
                            }
                        }
                        // 상하좌우 확인했는데 밖과 연결된 곳이 없는 경우
                        if (isAllChecked) {
                            container[j][k] = '-';
                        }
                    }
                }
            }
        }

        // -로 표시된 곳 추후에 밖이랑 연결되었는지 다시 확인
        for (int j = 0; j < storage.size(); j++) {
            for (int k = 0; k < storage[0].size(); k++) {
                if (container[j][k] == '-') {
                    for (int l = 0; l < dir.size(); l++) {
                        int newRow = j + dir[l].first;
                        int newCol = k + dir[l].second;
                        if (newRow < 0 || newCol < 0 || newRow >= containerRow || newCol >= containerCol ||
                            container[newRow][newCol] == '.') {
                            container[j][k] = '.';
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < storage.size(); i++) {
        for (int j = 0; j < storage[0].size(); j++) {
            cout << container[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < storage.size(); i++) {
        for (int j = 0; j < storage[0].size(); j++) {
            if (container[i][j] != '.' && container[i][j] != '-') {
                answer++;
            }
        }
    }

    return answer;
}