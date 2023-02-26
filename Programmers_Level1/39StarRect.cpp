/*
문제:
    이 문제에는 표준 입력으로 두 개의 정수 n과 m이 주어집니다.
    별(*) 문자를 이용해 가로의 길이가 n, 세로의 길이가 m인 직사각형 형태를 출력해보세요.

제한 사항:
    n과 m은 각각 1000 이하인 자연수입니다.
*/

#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    for(int i=0;i<b;i++){
        for(int j=0;j<a;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}

/*
개선 사항:
    1. append 함수 사용하면 된다. 

배운 점:
    1. append(개수, ‘char’); 하면 char을 개수만큼 있는 string 만들어준다. 
        1-1. string 라이브러리에 있다. 
        1-2. 인자에 그냥 string만 있으면 뒤에 string을 추가해주는 것이다.
*/