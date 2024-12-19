/*
문제
    자연수 n이 주어졌을 때, GCD(n, k) = 1을 만족하는 자연수 1 ≤ k ≤ n 의 개수를 구하는 프로그램을 작성하시오.

입력
    첫째 줄에 자연수 n (1 ≤ n ≤ 1012)이 주어진다.

출력
    GCD(n, k) = 1을 만족하는 자연수 1 ≤ k ≤ n 의 개수를 출력한다.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n;
    cin >> n;
    long result = n;
    for (long p = 2; p <= sqrt(n); p++) { 
        if (n % p == 0) { 
            result = result - result / p; 
            while (n % p == 0) { 
                n /= p;
            }
        }
    }
    if (n > 1) { 
        result = result - result / n;
    }
    cout << result;

    return 0;
}