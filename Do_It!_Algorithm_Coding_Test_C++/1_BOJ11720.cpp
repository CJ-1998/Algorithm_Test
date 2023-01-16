/*
문제:
    N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.

입력:
    첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에 숫자 N개가 공백없이 주어진다.

출력:
    입력으로 주어진 숫자 N개의 합을 출력한다.
*/

#include <iostream>

using namespace std;

int main(){
    int cnt=0;
    cin>>cnt;

    string num;
    cin>>num;

    int answer=0;

    for(int i=0;i<cnt;i++){
        answer+=(num[i]-'0');
    }

    cout<<answer;
    return 0;
}

/*
배운 점:
    1. string num=0; 이렇게 하면 오류난다.
    2. string 자료형은 #include <string> 안해도 사용 가능하다. 
    3. string to 숫자형은 stoi, stol, stod, stof 함수 사용하면 된다. 
*/