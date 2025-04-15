#include <string>
#include <vector>

using namespace std;

/*
    학생들의 인적사항 주어졌을 때 후보 키의 최대 개수 구하기
    컬럼 1~8
*/

int solution(vector<vector<string>> relation) {
    int answer = 0;

    int colSize = relation[0].size();

    vector<vector<string>> db;

    for (int i = 0; i < colSize; i++) {
        vector<string> temp;
        db.push_back(temp);
    }

    for (int i = 0; i < relation.size(); i++) {
        for (int j = 0; j < colSize; j++) {
            db[j].push_back(relation[i][j]);
        }
    }

    return answer;
}