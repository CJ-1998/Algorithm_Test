#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> make_str(vector<string> t) {
    vector<string> temp;

    vector<string> alp = {"A", "E", "I", "O", "U"};

    for (int i = 0; i < alp.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            temp.push_back(alp[i] + t[j]);
        }
    }

    return temp;
}

int solution(string word) {

    vector<string> ans;
    vector<string> alp1 = {"A", "E", "I", "O", "U"};
    vector<string> alp2 = make_str(alp1);
    vector<string> alp3 = make_str(alp2);
    vector<string> alp4 = make_str(alp3);
    vector<string> alp5 = make_str(alp4);

    ans.insert(ans.end(), alp1.begin(), alp1.end());
    ans.insert(ans.end(), alp2.begin(), alp2.end());
    ans.insert(ans.end(), alp3.begin(), alp3.end());
    ans.insert(ans.end(), alp4.begin(), alp4.end());
    ans.insert(ans.end(), alp5.begin(), alp5.end());

    sort(ans.begin(), ans.end());

    int answer = find(ans.begin(), ans.end(), word) - ans.begin() + 1;

    return answer;
}

/*
    문제 이해
        알파벳 모음만 사용해 만들 수 있는 길이 5이하의 모든 단어 수록
        사전 단어 A~UUUUU
        단어 매개변수로 주어질 때 이 단어가 몇번째 단어인지 반환
*/

/*
    풀이 생각
        모든 경우의 수 구하는 방법은 5^15 -> 너무 큼

        AEIOU로 next_permutation 돌리면 같은 문자 나오는 경우 포함 안됨
        AAAAAEEEEEIIIIIOOOOOUUUUU 로 next_permutation 돌리고 substr 5까지?
        -> 25!?

        재귀로 모든 문자열 만든 후 vector에 저장
        그리고 find 함수로??
        -> 재귀로 어떻게 만들지 안 떠오름

        길이 1인 것
        길이 2인 것 = A~U + 길이 1인 것
        길이 3인 것 = A~U + 길이 2인 것
        ...
        이렇게 전체 만들기?
        -> 의외로 1.5ms 안에 다 됐음
*/

/*
    문제 이해 시간 : 1m
    풀이 생각 시간 : 17m
    문제 구현 시간 : 17m 30s
    디버깅 시간 : 0m
    총 시간 : 23m 30s
*/

/*
    다른 사람 풀이
        아래 같은 아이디어는 떠올리기 어려울듯
        그냥 시간 복잡도 안에 노가다로 할 수 있는지 판단하는게...

        AEIOU에서 각각 0, 1, 2, 3, 4
        A에서 E 까지는 5^4 + 5^3 + 5^2 + 5 + 1만큼 차이
        AA에서 AE 까지는 5^3 + 5^2 + 5 + 1만큼 차이
        AAA에서 AAE 까지는 5^2 + 5 + 1만큼 차이
        AAAA에서 AAAE 까지는 5 + 1만큼 차이
        AAAAA에서 AAAAE 까지는 1만큼 차이

        #include <assert.h>
        #include <string>
        #include <vector>

        using namespace std;

        int solution(string word)
        {
            const int weights[5] = { 781, 156, 31, 6, 1 };
            int answer = 0;
            for (int i = 0; i < word.length(); ++i)
            {
                int current;
                switch (word[i])
                {
                case 'A':
                    current = 0;
                    break;
                case 'E':
                    current = 1;
                    break;
                case 'I':
                    current = 2;
                    break;
                case 'O':
                    current = 3;
                    break;
                case 'U':
                    current = 4;
                    break;
                default:
                    assert(false);
                }
                ++answer;
                answer += current * weights[i];
            }
            return answer;
        }
*/