/*
문제:
    수직선에 n개의 점이 찍혀 있다. 
    각각의 점의 x좌표가 주어졌을 때, n2개의 모든 쌍에 대해서 거리를 더한 값을 구하는 프로그램을 작성하시오.
    즉, 모든 i, j에 대해서 |x[i] - x[j]|의 합을 구하는 것이다.

입력:
    첫째 줄에 n(1 ≤ n ≤ 10,000)이 주어진다. 
    다음 줄에는 x[1], x[2], x[3], …, x[n]이 주어진다. 
    각각은 0 이상 1,000,000,000 이하의 정수이다.

출력:
    첫째 줄에 답을 출력한다.
*/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){

    int num=0;
    cin>>num;

    vector<int> v;
    for(int i=0;i<num;i++){
        int temp=0;
        cin>>temp;
        v.push_back(temp);
    }

    long answer=0;

    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            answer+=abs(v[i]-v[j]);
        }
    }

    cout<<answer<<endl;

    return 0;
}