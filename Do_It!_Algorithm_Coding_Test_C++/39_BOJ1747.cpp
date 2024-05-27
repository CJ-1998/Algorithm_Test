/*
문제
    어떤 수와 그 수의 숫자 순서를 뒤집은 수가 일치하는 수를 팰린드롬이라 부른다. 
    예를 들어 79,197과 324,423 등이 팰린드롬 수이다.
    어떤 수 N (1 ≤ N ≤ 1,000,000)이 주어졌을 때, N보다 크거나 같고, 소수이면서 팰린드롬인 수 중에서,
     가장 작은 수를 구하는 프로그램을 작성하시오.

입력
    첫째 줄에 N이 주어진다.

출력
    첫째 줄에 조건을 만족하는 수를 출력한다.
*/

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

bool checkNum(string num){
    int l = num.length();
    int len = l/2;
    int index = l-1;

    bool check = true;

    for(int i=0;i<len;i++){
        if(num[i]==num[index-i]){
            continue;
        }
        else{
            check=false;
            break;
        }
    }
    return check;
}

bool checkPrime(int num){
    bool check=true;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            check=false;
            break;
        }
    }
    return check;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num=0;
    cin>>num;

    if(num==1){
        num++;
    }

    int answer=0;

    while(true){
        string sNum=to_string(num);
        if(checkNum(sNum)){
            if(checkPrime(num)){
                answer=num;
                break;
            }
            else{
                num++;
                continue;
            }
        }
        else{
            num++;
            continue;
        }
    }

    cout<<answer;

    return 0;
}