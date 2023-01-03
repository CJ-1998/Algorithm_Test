/*
문제:
    영어 점수와 수학 점수의 평균 점수를 기준으로 
    학생들의 등수를 매기려고 합니다. 
    영어 점수와 수학 점수를 담은 2차원 정수 배열 score가 
    주어질 때, 영어 점수와 수학 점수의 평균을 기준으로 매긴
    등수를 담은 배열을 return하도록 
    solution 함수를 완성해주세요.

제한 사항:
    0 ≤ score[0], score[1] ≤ 100
    1 ≤ score의 길이 ≤ 10
    score의 원소 길이는 2입니다.
    score는 중복된 원소를 갖지 않습니다.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    vector<double> average;
    vector<double> temp;
    
    for(int i=0;i<score.size();i++){
        average.push_back(((double)score[i][0]+(double)score[i][1])/2);
        temp.push_back(((double)score[i][0]+(double)score[i][1])/2);
    }
    sort(average.begin(),average.end(),greater<>());
    
    int rank=101;
    for(int i=0;i<average.size();i++){
        for(int j=0;j<temp.size();j++){
            if(average[i]==temp[j]){
                temp[j]=rank;
            }
        }
        rank++;
    }
    
    for(int i=0;i<temp.size();i++){
        answer.push_back(temp[i]-100);
    }
    
    return answer;
}

/*
배운 점:
    1. 값을 보면서 큰 값이 나오면 count를 늘려가는 식으로 하면 순위를 찾을 수 있다. 
*/