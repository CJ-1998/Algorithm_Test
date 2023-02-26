/*
문제:
    행렬의 덧셈은 행과 열의 크기가 같은 두 행렬의 같은 행, 같은 열의 값을 서로 더한 결과가 됩니다. 2개의 행렬 arr1과 arr2를 입력받아, 행렬 덧셈의 결과를 반환하는 함수, solution을 완성해주세요.

제한 사항:
    행렬 arr1, arr2의 행과 열의 길이는 500을 넘지 않습니다.
*/

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i=0;i<arr1.size();i++){
        vector<int> temp;
        for(int j=0;j<arr1[0].size();j++){
            int t=arr1[i][j]+arr2[i][j];
            temp.push_back(t);
        }
        answer.push_back(temp);
    }
    return answer;
}

/*
개선 사항 & 배운 점:
    1. vec.clear()로 벡터 비울 수 있다. 
*/