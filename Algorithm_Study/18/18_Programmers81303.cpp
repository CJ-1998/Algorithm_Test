#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
    명령어 기반 표의 행을 선택, 삭제, 복구

    한 번에 한 행만 선택 가능
    U X : 현재 선택 행에서 X칸 위의 행 선택
    D X : 현재 선택 행에서 X칸 아래의 행 선택
    C : 현재 선택 행 삭제, 바로 아래 행 선택 / 마지막 행인 경우 바로 윗 행 선택
    Z : 가장 최근 삭제된 행 복구, 현재 선택 행 유지

    n = 표의 행 개수
    k = 처음 선택 행 위치
    cmd = 명령어 배열

    모든 명령어 수행 후 삭제 안된 행은 O, 삭제된 행은 X로 문자열로 반환

    표의 범위 벗어나는 이동 입력 X
    복구할 행 없을 때 Z 주어지는 경우 X

    기록할 것
        행 위치 가리키는 것
        삭제한 index stack

    벡터
        삽입 - insert
        삭제 - erase

*/

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    // 표 생성 및 초기화
    vector<int> sheet;

    for (int i = 0; i < n; i++) {
        sheet.push_back(i);
    }

    // 삭제 index 넣을 stack 생성
    stack<pair<int, int>> deleteIndex;

    // 현재 index 기록 변수
    int index = k;

    // 명령어 수행
    for (int i = 0; i < cmd.size(); i++) {
        string temp;
        stringstream stream;

        string oneCmd = cmd[i];

        // 명령어 C or Z인 경우
        if (oneCmd.length() == 1) {
            // 명령어 = C
            if (oneCmd == "C") {
                // 현재 선택 행이 마지막인 경우
                if (index == sheet.size() - 1) {
                    int indexValue = sheet[index];
                    sheet.erase(sheet.begin() + index);
                    deleteIndex.push(make_pair(index, indexValue));
                    index--;
                }
                // 현재 선택 행이 마지막 아닌 경우
                else {
                    int indexValue = sheet[index];
                    sheet.erase(sheet.begin() + index);
                    deleteIndex.push(make_pair(index, indexValue));
                }
            }

            // 명령어 = Z
            else {
                int top = deleteIndex.top().first;
                int topValue = deleteIndex.top().second;

                // 복구 되는 행이 현재 선택 행 아래인 경우
                if (top > index) {
                    deleteIndex.pop();
                    sheet.insert(sheet.begin() + top, topValue);
                }
                // 복구 되는 행이 현재 선택 행이거나 위인 경우
                else {
                    deleteIndex.pop();
                    sheet.insert(sheet.begin() + top, topValue);
                    index++;
                }
            }
        }
        // 명령어 D or U인 경우
        else {
            // 명령어 분리
            stream.str(oneCmd);

            stream >> temp;
            string moveCmd = temp;

            stream >> temp;
            int moveCount = stoi(temp);

            // 명령어 = D
            if (moveCmd == "D") {
                index += moveCount;
            }
            // 명령어 = U
            else {
                index -= moveCount;
            }
        }
    }

    // 다 삭제되어서 sheet[i] 하면 오류 터짐
    if (sheet.size() == 0) {
        for (int i = 0; i < n; i++) {
            answer += "X";
        }
    }
    // sheet에 하나라도 남은 경우
    else {
        // 이렇게 하는 이유 = erase 하고 원래 벡터 크기만큼 출력하면 값이 이전 값 남아 있음
        // ex : 1 2 3 4 5 -> 4 삭제 -> 1 2 3 5 5 (이렇게 되어 있어서 n만큼 for문 하면 틀림)
        int realIndex = 0;
        for (int i = 0; i < sheet.size(); i++) {
            if (sheet[i] == realIndex) {
                answer += "O";
                realIndex++;
            } else {
                int count = sheet[i] - realIndex;
                for (int j = 0; j < count; j++) {
                    answer += "X";
                    realIndex++;
                }
                answer += "O";
                realIndex++;
            }
        }
        for (int i = 0; i < n - realIndex; i++) {
            answer += "X";
        }
    }

    return answer;
}