/*
문제:
    "*"의 높이와 너비를 1이라고 했을 때, "*"을 이용해 직각 이등변 삼각형을 그리려고합니다. 정수 n 이 주어지면 높이와 너비가 n 인 직각 이등변 삼각형을 출력하도록 코드를 작성해보세요.

제한 사항:
    1 ≤ n ≤ 10
*/

#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}

/*
개선 사항:
    1. string(n, ‘*’); 사용하면 된다. 

배운 점:
    1. string(n, ‘*’); 사용법.
*/