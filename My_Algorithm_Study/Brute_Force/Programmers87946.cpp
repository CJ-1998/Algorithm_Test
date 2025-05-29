#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first < b.first) {
        return true;
    } else if (a.first == b.first) {
        if (a.second >= b.second) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    vector<pair<int, int>> v;

    for (int i = 0; i < dungeons.size(); i++) {
        pair<int, int> temp = make_pair(dungeons[i][1], dungeons[i][0]);
        v.push_back(temp);
    }

    //     sort(v.begin(),v.end(),compare);

    //     for(int i=0;i<v.size();i++){
    //         cout<<v[i].first<<" "<<v[i].second<<endl;
    //     }

    sort(v.begin(), v.end(), compare);

    vector<int> answerCand;

    do {
        int temp = k;
        int tempAns = 0;
        for (int i = 0; i < v.size(); i++) {
            if (temp >= v[i].second) {
                temp -= v[i].first;
                tempAns++;
            } else {
                break;
            }
        }
        answerCand.push_back(tempAns);
    } while (next_permutation(v.begin(), v.end()));

    // for(int i=0;i<answerCand.size();i++){
    //     cout<<answerCand[i]<<endl;
    // }

    sort(answerCand.begin(), answerCand.end(), greater<>());
    answer = answerCand[0];

    return answer;
}

/*
    문제 이해
        피로도 시스템
        일정 피로도 사용해 던전 탐험
        던전 탐험 시작 위해 필요한 '최소 필요 피로도'
        던전 탐험 마쳤을 때 소모되는 '소모 피로도'
        최대한 던전 많이 탐험하려고 함

        k = 유저의 현재 피로도 1~5000
        dungeons = 각 던전별 최소 필요 피로도, 소모 피로도 2차원 배열 = dungeons[n][2] 1<=n<=8
        유저 탐험 가능한 최대 던전 수 반환
*/

/*
    풀이 생각
        소모 피로도 작은 것 우선
        최소 필요 피로도 큰 것 우선

        pair 비교 함수 만들어 벡터 정렬
        앞부터 하면서 현재 필요도 줄여가며 개수 체크

        -> 최대 던전 수 아님 (잘못된 풀이)

        던전 개수 최대 8개이니 모든 경우의 수 해도 8! = 40320
        순열로 모든 조합 확인하며 최대 던전 수 구하기 가능
        -> 옳은 풀이
*/

/*
    문제 이해 시간 : 3m 30s
    풀이 생각 시간 : 2m 30s
    문제 구현 시간 : 17m 30s
    디버깅 시간 : 0m
    총 시간 : 23m 30s
*/

/*
    다른 사람 풀이
        dfs로 푼 것도 있음
        이해는 잘 안됨....

        #include <string>
        #include <vector>
        #include <iostream>

        using namespace std;

        int answer = 0;
        vector<vector<int>> dungeons;
        int N;

        int visit[8];
        void dfs(int h, int p){
            if(answer < h)
                answer = h;

            for(int i=0; i<N; i++){
                if(visit[i] || dungeons[i][0] > p)
                    continue;

                visit[i] = 1;
                dfs(h+1, p-dungeons[i][1]);
                visit[i] = 0;
            }
        }

        int solution(int k, vector<vector<int>> dungeons_) {
            dungeons = dungeons_;
            N = dungeons.size();

            dfs(0, k);

            return answer;
        }
*/