#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> one = {1, 2, 3, 4, 5};
    vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int answersCount = answers.size();

    int oneCount = one.size();
    int twoCount = two.size();
    int threeCount = three.size();

    int oneAddCount = 0;
    int twoAddCount = 0;
    int threeAddCount = 0;

    if (answersCount % oneCount != 0) {
        oneAddCount = answersCount / oneCount + 1;
    } else {
        oneAddCount = answersCount / oneCount;
    }

    if (answersCount % twoCount != 0) {
        twoAddCount = answersCount / twoCount + 1;
    } else {
        twoAddCount = answersCount / twoCount;
    }

    if (answersCount % threeCount != 0) {
        threeAddCount = answersCount / threeCount + 1;
    } else {
        threeAddCount = answersCount / threeCount;
    }

    vector<int> newOne;
    vector<int> newTwo;
    vector<int> newThree;

    for (int i = 0; i < oneAddCount; i++) {
        for (int j = 0; j < one.size(); j++) {
            newOne.push_back(one[j]);
            if (newOne.size() == answersCount) {
                break;
            }
        }
        if (newOne.size() == answersCount) {
            break;
        }
    }

    for (int i = 0; i < twoAddCount; i++) {
        for (int j = 0; j < two.size(); j++) {
            newTwo.push_back(two[j]);
            if (newTwo.size() == answersCount) {
                break;
            }
        }
        if (newTwo.size() == answersCount) {
            break;
        }
    }

    for (int i = 0; i < threeAddCount; i++) {
        for (int j = 0; j < three.size(); j++) {
            newThree.push_back(three[j]);
            if (newThree.size() == answersCount) {
                break;
            }
        }
        if (newThree.size() == answersCount) {
            break;
        }
    }

    // cout << newOne.size() << " " << newTwo.size() << " " << newThree.size() << " " << endl;

    int oneAnswerCount = 0;
    int twoAnswerCount = 0;
    int threeAnswerCount = 0;

    for (int i = 0; i < answersCount; i++) {
        if (newOne[i] == answers[i]) {
            oneAnswerCount++;
        }
        if (newTwo[i] == answers[i]) {
            twoAnswerCount++;
        }
        if (newThree[i] == answers[i]) {
            threeAnswerCount++;
        }
    }

    vector<int> index = {oneAnswerCount, twoAnswerCount, threeAnswerCount};

    vector<int> counts = {oneAnswerCount, twoAnswerCount, threeAnswerCount};
    sort(counts.begin(), counts.end(), greater<>());

    vector<int> answer;
    for (int i = 0; i < index.size(); i++) {
        if (index[i] == counts[0]) {
            answer.push_back(i + 1);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

/*
    문제 이해
        수학 문제 전부 찍기
        1번 수포자 : 1, 2, 3, 4, 5 반복
        2번 수포자 : 2, 1, 2, 3, 2, 4, 2, 5 반복
        3번 수포자 : 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 반복

        정답 배열 answers 주어짐
        가장 많은 문제 맞힌 사람 누군지?
        그 사람 번호 배열로 반환

        최대 10000문제
        정답은 1~5
        높은 점수 사람 여러명이면 오름차순
*/

/*
    풀이 생각
        각 수포자 패턴을 저장해 둠
        정답 배열 개수보다 클 때까지 추가함 (벡터 더하기?)
        개수 동시에 체크
*/

/*
    문제 이해 시간 : 3m 30s
    풀이 생각 시간 : 2m
    문제 구현 시간 : 23m 30s
    디버깅 시간 : 7m
    총 시간 : 36m
*/

/*
이전 코드

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> counts;
    vector<int> one={1,2,3,4,5};
    vector<int> two={2,1,2,3,2,4,2,5};
    vector<int> three={3,3,1,1,2,2,4,4,5,5};

    vector<int> num={0,0,0};

    int temp1=0;
    int temp2=0;
    int temp3=0;

    for(int i=0;i<answers.size();i++){
        if(one[temp1]==answers[i]){
            num[0]++;
        }
        if(two[temp2]==answers[i]){
            num[1]++;
        }
        if(three[temp3]==answers[i]){
            num[2]++;
        }
        temp1++;
        temp2++;
        temp3++;

        if(temp1==one.size()){
            temp1=0;
        }
        if(temp2==two.size()){
            temp2=0;
        }
        if(temp3==three.size()){
            temp3=0;
        }
    }

    vector<int> tnum=num;
    sort(num.begin(),num.end(),greater<int>());

    for(int i=0;i<num.size();i++)
    {
        if(tnum[i]==num[0]){
            counts.push_back(i+1);
        }
    }

    return counts;
}
*/