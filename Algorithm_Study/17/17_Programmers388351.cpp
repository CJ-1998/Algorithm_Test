#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    일주일 간 설정한 출근 희망 시각에 늦지 않은 직원에게 상품 이벤트
    직원들 출근 희망 시각 + 10분까지 출근해야 함
    토, 일요일은 이벤트에 영향 X
    매일 한번 어플로 출근
    시간은 10:13 -> 1013 이렇게 표현

    설정한 출근 희망 시각과 실체 출근 기록 주어짐
    이것으로 상품 받을 직원 몇명인지 구하기

    n = 직원 명 수
    schedules = 출근 희망 시각 1차원 배열
    timelogs = 일주일 간 출근한 시각 2차원 배열
    startday = 이벤트 시작한 요일

    startday -> 7-startday = 일요일, 6-startday = 토요일 timelogs index
*/

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    int saturdayIndex = 0;
    int sundayIndex = 0;

    // 토요일, 일요일 index 구하기
    if (startday <= 5) {
        saturdayIndex = 6 - startday;
        sundayIndex = 7 - startday;
    } else if (startday == 6) {
        saturdayIndex = 0;
        sundayIndex = 1;
    } else {
        saturdayIndex = 6;
        sundayIndex = 0;
    }

    for (int i = 0; i < schedules.size(); i++) {
        int wantHour = schedules[i] / 100;
        int wantMinute = schedules[i] % 100;

        // 인정되는 시간 구하기 (+10분)
        if (wantMinute >= 50) {
            wantHour++;
            wantMinute -= 50;
        } else {
            wantMinute += 10;
        }

        int safeDay = 0;

        // 일주일 출근 시간 확인
        for (int j = 0; j < 7; j++) {
            // 토요일, 일요일이면 pass
            if (j == saturdayIndex || j == sundayIndex) {
                continue;
            }

            // 통과한 날 찾기
            int todayHour = timelogs[i][j] / 100;
            int todayMinute = timelogs[i][j] % 100;

            if (wantHour > todayHour || (wantHour == todayHour && wantMinute >= todayMinute)) {
                safeDay++;
            }
        }

        // 5일 이상 통과면 추가
        if (safeDay == 5) {
            answer++;
        }
    }

    return answer;
}