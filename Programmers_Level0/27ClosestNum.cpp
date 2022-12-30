/*
문제:
    정수 배열 array와 정수 n이 매개변수로 주어질 때, 
    array에 들어있는 정수 중 n과 가장 가까운 수를 
    return 하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ array의 길이 ≤ 100
    1 ≤ array의 원소 ≤ 100
    1 ≤ n ≤ 100
    가장 가까운 수가 여러 개일 경우 더 작은 수를 return 합니다.
*/

#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    int answer=0;
    vector<int> distance;
    for(int i=0;i<array.size();i++){
        distance.push_back(abs(n-array[i]));
    }
    
    int min_index=min_element(distance.begin(),distance.end())-distance.begin();
    int temp=distance[min_index];
    
    for(int i=0;i<distance.size();i++){
        if(temp==distance[i]&&i!=min_index){
            if(array[min_index]>array[i]){
                min_index=i;
            }
        }
    }
    answer=array[min_index];
    return answer;
}

/*
개선 사항:
    1. 거리가 같으면 작은 수 반환해야 하니 먼저 sort를 하고 시작하면 더 좋다.

배운 점:
    1. min_element의 사용법
*/