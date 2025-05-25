#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {

        int a = 0;
        int b = 0;

        cin >> a >> b;

        int answer = 0;

        if (a >= 10 || b >= 10) {
            answer = -1;
        } else {
            answer = a * b;
        }

        cout << "#" << test_case << " " << answer << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

/*
    문제 이해
        1~9 자연수 2개 곱셈 가능
        10 이상 곱셈 방법 모름
        두 2 정수 A, B 주어짐
        두 정수 곱셈 가능하면 곱 출력
        아니면 -1 출력
*/

/*
    풀이 생각
        A, B 중 10 이상이면 -1 출력
        A, B 중 10 미만이면 A*B 출력
*/