#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

bool isPrime(int num) {

    if (num <= 1)
        return false;

    int range = sqrt(num);

    for (int i = 2; i <= range; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int solution(string numbers) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_set<int> nums;

    sort(numbers.begin(), numbers.end()); // 숫자들을 정렬하여 순열을 통해 중복된 조합을 피함

    do {
        for (int i = 1; i <= numbers.size(); ++i) {
            string temp = numbers.substr(0, i); // 현재 순열의 부분 문자열 생성
            int num_temp = stoi(temp);          // 부분 문자열을 숫자로 변환
            if (isPrime(num_temp)) {
                nums.insert(num_temp); // 소수인 경우 집합에 추가
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end())); // 다음 순열 생성

    return nums.size(); // 중복을 제거한 소수의 개수 반환
}

/*
    문제 이해
        한자리 숫자 적힌 종이 조각 여러 개
        한자리 숫자 종이 조각 붙여 소수 몇개 만들 수 있는지?

        각 종이 조각에 적힌 문자열 numbers
        종이 조각으로 만들 수 있는 소수 몇개인지 return

        numbers 길이 = 1~7
        numbers는 0~9로만 구성
*/

/*
    풀이 생각
        numbers의 숫자 각각 배열에 저장
        길이 1~7까지 가능한 모든 숫자 조합 배열에 저장

        시간 복잡도 = 7P1 * 7P2 * 7P3 * 7P4 * 7P5 * 7P6 * 7P7
        = 7*42*210*840*2520*5040*5040 = 약 3해?;;

        소수 판별 함수 필요
        전체 배열 돌며 이 숫자 소수인지 판별 후 개수 세기
*/

/*
    문제 이해 시간 : 1m 30s
    풀이 생각 시간 : 3m
    문제 구현 시간 : 31m 30s -> 못 품
    디버깅 시간 : 0m
    총 시간 : 36m
*/

/*
    다른 사람 풀이
        DFS로 만들 수 있는 숫자를 만듬
        순열로 하면 시간 너무 걸리는 것 같음
        next_permutation 사용해서 하는 것도 되기는 하는 것 같음

        위의 풀이는 순열로 하는 것
        모든 순열에서 0~n번째까지 값 하면 모든 조합 나오는 것 같음
        2~3 이런 것은 안해도 다른 순열에서 나오는 것인지 궁금함

        next_permutation 시간 복잡도가 O(2^n) 이라고 함
        생각에는 7개중 n개 고른 다음에 순열 만들어야 하지 않나 싶었음
        7C1 * 2^1 * 7C2 * 2^2 * .... * 7C7 * 2^7
        그러면 우선 2^28 넘는데 문제 생기지 않나 싶음

        그런데 위의 풀이 보니까 그냥 모든 순열 조합에서 0~1, 0~2, ... 0~n 하니까 모든 조합 나오는 듯
        순열의 성질에 대해서 알면 좋을 듯

        모든 순열에서 0~1부터 n까지 하면 모든 조합 찾을 수 있음

        https://houcouonchi.tistory.com/20
        https://jinho082008.tistory.com/126
        https://school.programmers.co.kr/questions/73920
*/