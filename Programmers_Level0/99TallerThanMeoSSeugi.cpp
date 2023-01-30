/*
문제:
    머쓱이는 학교에서 키 순으로 줄을 설 때 몇 번째로 서야 하는지 궁금해졌습니다. 머쓱이네 반 친구들의 키가 담긴 정수 배열 array와 머쓱이의 키 height가 매개변수로 주어질 때, 머쓱이보다 키 큰 사람 수를 return 하도록 solution 함수를 완성해보세요.

제한 사항:
    1 ≤ array의 길이 ≤ 100
    1 ≤ height ≤ 200
    1 ≤ array의 원소 ≤ 200
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    array.push_back(height);
    sort(array.begin(),array.end());
    int temp=0;
    
    for(int i=0;i<array.size();i++){
        if(array[i]==height){
            temp=i;
        }
    }
    
    answer=array.size()-temp-1;
    
    return answer;
}

/*
개선 사항:
    1. 주어진 키보다 큰 값 나오면 answer++ 하면 된다. 
*/