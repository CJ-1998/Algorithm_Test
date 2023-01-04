/*
문제:
    정수 n을 기준으로 n과 가까운 수부터 정렬하려고 합니다. 
    이때 n으로부터의 거리가 같다면 더 큰 수를 앞에 오도록 
    배치합니다. 정수가 담긴 배열 numlist와 정수 n이 주어질 때
    numlist의 원소를 n으로부터 가까운 순서대로 정렬한 배열을
    return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ n ≤ 10,000
    1 ≤ numlist의 원소 ≤ 10,000
    1 ≤ numlist의 길이 ≤ 100
    numlist는 중복된 원소를 갖지 않습니다
*/

#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    sort(numlist.begin(),numlist.end(),greater<>());
    
    vector<int> minus;
    for(int i=0;i<numlist.size();i++){
        minus.push_back(abs(n-numlist[i]));
    }
    
    vector<int> temp=minus;
    sort(temp.begin(),temp.end());
    
    for(int i=0;i<numlist.size();i++){
        for(int j=0;j<numlist.size();j++){
            if(temp[i]==minus[j]){
                answer.push_back(numlist[j]);
                minus[j]=10000;
                break;
            }
        }
    }
    return answer;
}

/*
개선 사항:
    1. 새로운 sort 함수를 만들어서 절대 값이 같으면 이전 값이 
       크게 하고 절대 값이 큰 것을 선택하게 만들면 된다. 

배운 점:
    1. sort에 3번째 인자로 함수를 넣으면 해당 함수의 반환 값에 맞게 정렬이 동작한다. 
*/