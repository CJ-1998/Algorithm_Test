#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        cout << data[i] << endl;
    }
    return answer;
}