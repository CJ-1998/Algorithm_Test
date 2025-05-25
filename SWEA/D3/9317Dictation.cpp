#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int len = 0;
        cin >> len;

        string answer = "";
        string myAnswer = "";

        cin >> answer >> myAnswer;

        int count = 0;

        for (int i = 0; i < len; i++) {
            if (answer[i] == myAnswer[i]) {
                count++;
            }
        }

        cout << "#" << test_case << " " << count << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

/*
    문제 이해
        알파벳 공부
        길이 N의 알파벳 대소문자로 이뤄진 문자열 주어짐
        대소문자 제대로 구분해 문자열 받아 적어야 함

        N개 문자 받아적는데 성공 but 틀리게 적은 문자 존재
        몇 개 문자 올바르게 받아 적었는지 세보자

        1<= 문자열 길이 N <= 100000
        따라 적어야 하는 문자열, 받아 적은 문자열 주어짐
        둘 길이 모두 N
*/

/*
    풀이 생각
        15개 TC 함쳐 1초
        100000 * 15 = 1500000 -> 1초 미만
        for문 돌려가면서 문자열 하나씩 비교 가능
*/