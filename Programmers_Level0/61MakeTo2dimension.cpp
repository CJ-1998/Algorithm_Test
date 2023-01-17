/*
문제:   
    정수 배열 num_list와 정수 n이 매개변수로 주어집니다. num_list를 다음 설명과 같이 2차원 배열로 바꿔 return하도록 solution 함수를 완성해주세요.
    num_list가 [1, 2, 3, 4, 5, 6, 7, 8] 로 길이가 8이고 n이 2이므로 num_list를 2 * 4 배열로 다음과 같이 변경합니다. 2차원으로 바꿀 때에는 num_list의 원소들을 앞에서부터 n개씩 나눠 2차원 배열로 변경합니다.

제한 사항:
    num_list의 길이는 n의 배 수개입니다.
    0 ≤ num_list의 길이 ≤ 150
    2 ≤ n < num_list의 길이
*/

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    for(int i=0;i<num_list.size()/n;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            temp.push_back(num_list[n*i+j]);
        }
        answer.push_back(temp);
    }
    return answer;
}

/*
개선 사항:
    1. 그냥 i+j 했으면 됐다. 
*/