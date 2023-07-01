/*
문제:
    어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다. 
    미르코는 30이란 수를 존경하기 때문에, 그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.
    미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라

입력:
    N을 입력받는다. N는 최대 105개의 숫자로 구성되어 있으며, 0으로 시작하지 않는다.

출력:
    미르코가 만들고 싶어하는 수가 존재한다면 그 수를 출력하라. 
    그 수가 존재하지 않는다면, -1을 출력하라.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    string answer;

    string temp;
    cin>>temp;

    vector<int> v;
    for(int i=0;i<temp.length();i++){
        v.push_back(temp[i]-'0');
    }

    sort(v.rbegin(),v.rend());

    if(v[v.size()-1]!=0){
        answer="-1";
    }
    else{
        int sum=0;
        for(int i=0;i<v.size()-1;i++){
            sum+=v[i];
        }

        if(sum%3!=0){
            answer="-1";
        }
        else{
            for(int i=0;i<v.size();i++){
                answer+=v[i]+'0';
            }
        }
    }

    cout<<answer;

    return 0;
}

/*
개선 사항:
    1. 굳이 string으로 더해서 한번에 출력하지 않고 벡터에 저장한 값을 하나하나 출력하면 시간초과 안나고 할 수 있다. 

배운 점:
    1.숫자로 해서 범위 벗어나거나 시간 초과 뜨면 문자열로 하면 된다. 
*/