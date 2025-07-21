#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// int binarySearch(int num, vector<int> v) {
//     int start = 0;
//     int end = v.size() - 1;
//     int mid = (start + end) / 2;

//     while (start <= end) {
//         if (num == v[mid]) {
//             return mid;
//         }
//         if (v[mid] < num) {
//             start = mid + 1;
//             mid = (start + end) / 2;
//         } else {
//             end = mid - 1;
//             mid = (start + end) / 2;
//         }
//     }
//     return mid;
// }

vector<int> lis;

int binarySearch(int num) {
    int start = 0;
    int end = lis.size() - 1;
    int mid;

    while (start < end) {
        mid = start + (end - start) / 2;
        if (lis[mid] < num) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num = 0;
    cin >> num;

    vector<int> v;
    for (int i = 0; i < num; i++) {
        int temp = 0;
        cin >> temp;
        v.push_back(temp);
    }

    lis.push_back(v[0]);

    for (int i = 1; i < num; i++) {
        int lastIndex = lis.size() - 1;

        if (lis[lastIndex] < v[i]) {
            lis.push_back(v[i]);
        } else {
            int changeIndex = binarySearch(v[i]);
            lis[changeIndex] = v[i];
        }

        // for (int i : lis) {
        //     cout << i << " ";
        // }
        // cout << endl;
    }

    cout << lis.size();

    return 0;
}

/*
    문제 이해
    가장 긴 증가하는 부분 수열 구하기
    수열 크기 <= 백만
    수열 요소 <= 백만
*/

/*
    풀이 생각
    LIS
        DP -> 백만^2 -> 불가
        이진 탐색 -> O

    벡터 이진 탐색 함수 넘기는 형식으로 하니까 시간초과 남
    벡터 함수로 넘기면 어떤 일 생겨서 시간 더 걸리는 듯

    이진 탐색도 이진 탐색 함수 구현이 아니라 lower_bound 느낌 함수여야 하는 듯
    위에 처음에 구현한 이진 탐색 함수로 하면 틀림
*/

/*
    문제 이해 시간 :
    풀이 생각 시간 :
    문제 구현 시간 :
    디버깅 시간 :
    총 시간 :
*/

/*
    다른 사람 풀이
*/