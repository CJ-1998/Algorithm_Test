#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
    셔틀 버스 규칙
    1. 9시부터 n회 t분 간격으로 역에 도착
    2. 하나의 셔틀에 최대 m명 승객 가능
    3. 도착 순간에 도착한 사람까지 탈 수 있음

    같은 시간에 도착한 크루 중 제일 뒤에 섬

    셔틀 타고 갈 수 있는 도착 시간 중 제일 늦은 시간 구하기

    생각
        셔틀 횟수에 9시도 포함
        마지막 셔틀에 타는 것이 베스트
        마지막 셔틀에 타는데
            m명 이상 대기 중이면 m번째 사람보다 1분 일찍오면 됨
            m명 미만 대기 중이면 마지막 셔틀 도착 시간에 타면 됨

        마지막 셔틀-1 도착 시간 이전 사람은 버리면 됨 (n이 몇인지 확인)
            but m 이상이면 남아 있는 것 생각해야 함
            -> 시간마다 확인하며 사람 줄여나가야 할 듯?
        마지막 셔틀 도착 시간 이후 사람 버리면 됨
*/

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        if (a.second < b.second) {
            return a.second < b.second;
        }
    }
    return a.first < b.first;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    vector<pair<int, int>> arrivalTime;
    vector<pair<int, int>> busArrivalTime;

    // 사람들 도착 시간 숫자화
    for (int i = 0; i < timetable.size(); i++) {

        int hour = stoi(timetable[i].substr(0, 2));
        int minute = stoi(timetable[i].substr(3));

        arrivalTime.push_back(make_pair(hour, minute));
    }

    // 첫번째 버스 도착 시간 추가
    busArrivalTime.push_back(make_pair(9, 0));

    // 버스 도착 시간 숫자화
    int nowHour = 9;
    int sumMinute = 0;
    for (int i = 0; i < n - 1; i++) {
        sumMinute += t;
        if (sumMinute >= 60) {
            nowHour++;
            sumMinute -= 60;
        }

        busArrivalTime.push_back(make_pair(nowHour, sumMinute));
    }

    // 사람들 도착 시간 도착 순서대로 정렬
    sort(arrivalTime.begin(), arrivalTime.end(), compare);

    // 마지막 버스 전까지 사람들 태워서 보냄
    for (int i = 0; i < busArrivalTime.size() - 1; i++) {
        int nowPeople = 0;
        int nowBusHour = busArrivalTime[i].first;
        int nowBusMinute = busArrivalTime[i].second;

        for (int j = 0; j < arrivalTime.size(); j++) {
            // 버스 꽉참
            if (nowPeople == m) {
                break;
            }

            int personHour = arrivalTime[j].first;
            int personMinute = arrivalTime[j].second;

            // 아직 사람 도착 안 한 것, 버스 시간보다 사람 도착 시간이 늦은 경우
            if (nowBusHour < personHour || (nowBusHour == personHour && nowBusMinute < personMinute)) {
                break;
            }

            // 버스 탈 수 있는 사람 태움
            if (nowBusHour > personHour || (nowBusHour == personHour && nowBusMinute >= personMinute)) {
                nowPeople++;
                arrivalTime.erase(arrivalTime.begin());
                j--;
            }
        }
    }

    int lastBusHour = busArrivalTime[busArrivalTime.size() - 1].first;
    int lastBusMinute = busArrivalTime[busArrivalTime.size() - 1].second;

    int nowPeople = 0;
    for (int i = 0; i < arrivalTime.size(); i++) {
        if (nowPeople == m - 1) {
            break;
        }

        int personHour = arrivalTime[i].first;
        int personMinute = arrivalTime[i].second;

        // 아직 사람 도착 안 한 것, 버스 시간보다 사람 도착 시간이 늦은 경우
        if (lastBusHour < personHour || (lastBusHour == personHour && lastBusMinute < personMinute)) {
            break;
        }

        // 버스 탈 수 있는 사람 태움
        if (lastBusHour > personHour || (lastBusHour == personHour && lastBusMinute >= personMinute)) {
            nowPeople++;
            arrivalTime.erase(arrivalTime.begin());
            i--;
        }
    }

    int myHour = 0;
    int myMinute = 0;

    if (arrivalTime.size() != 0) {
        int lastPersonHour = arrivalTime[0].first;
        int lastPersonMinute = arrivalTime[0].second;

        if (lastBusHour > lastPersonHour || (lastBusHour == lastPersonHour && lastBusMinute >= lastPersonMinute)) {
            if (lastPersonMinute == 0) {
                myHour = lastPersonHour - 1;
                myMinute = 59;
            } else {
                myHour = lastPersonHour;
                myMinute = lastPersonMinute - 1;
            }
        } else {
            myHour = lastBusHour;
            myMinute = lastBusMinute;
        }
    } else {
        myHour = lastBusHour;
        myMinute = lastBusMinute;
    }

    string myHourStr = "";
    string myMinuteStr = "";

    if (myHour < 10) {
        myHourStr += "0";
    }
    myHourStr += to_string(myHour);

    if (myMinute < 10) {
        myMinuteStr += "0";
    }
    myMinuteStr += to_string(myMinute);

    answer = myHourStr + ":" + myMinuteStr;

    return answer;
}