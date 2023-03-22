/*
문제:
    선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다. 이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.
    함수 R은 배열에 있는 수의 순서를 뒤집는 함수이고, D는 첫 번째 수를 버리는 함수이다. 배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.  함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 수를 버리는 함수이다.
    배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.
    각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.
    다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)
    다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 정수가 주어진다. (1 ≤ xi ≤ 100)
    전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.

출력:
    각 테스트 케이스에 대해서, 입력으로 주어진 정수 배열에 함수를 수행한 결과를 출력한다. 만약, 에러가 발생한 경우에는 error를 출력한다.
*/

#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

void func(string fun){
    int cnt=0;
    cin>>cnt;

    deque<int> d;

    vector<int> t;

    string num;
    cin>>num;

    string numtostring="";

    for(int i=0;i<num.length();i++){
        if('0'<=num[i]&&num[i]<='9'){
            numtostring+=num[i];
        }
        else if(num[i]=='['){
        }
        else{
            if(numtostring.length()!=0){
                int n=stoi(numtostring);
                t.push_back(n);
            }
            numtostring="";
        }
    }

    for(int i=0;i<cnt;i++){
        int temp=t[i];
        d.push_back(temp);
    }

    bool check=true;
    for(int i=0;i<fun.length();i++){
        if(fun[i]=='R'){
            if(check)
                check=false;
            else    
                check=true;
        }

        if(fun[i]=='D'){
            if(d.empty()){
                cout<<"error"<<endl;
                return; 
            }
            else{
                if(check){
                    d.pop_front();
                }
                else{
                    d.pop_back();
                }
            }
        }
    }
    
    cout<<"[";
    int size=d.size();
    for(int i=0;i<size;i++){
        int temp=0;
        if(check){
            temp=d.front();
            d.pop_front();
        }
        else{
            temp=d.back();
            d.pop_back();
        }
        
        if(i!=size-1){
            cout<<temp<<",";
        }
        else{
            cout<<temp;
        }
    }
    cout<<"]"<<endl;
    return ;
}

int main(){

    int testcase=0;
    cin>>testcase;

    for(int i=0;i<testcase;i++){
        string fun;
        cin>>fun;
        func(fun);
    }

    return 0;
}

/*
배운 점:
    1. deque 사용법
    2. stoi에 숫자 아닌 값들이 들어가 있으면 에러가 난다. 
    3. for문에서 stack, queue, deque pop()하는데 stl.size()를 변수로 사용하면 그 변수가 계속 값이 바뀐다. 따라서 for문 밖에다가 따로 변수로 저장해 놓고 써야 한다. 
    4. reverse 함수의 시간 복잡도는 O(n)이라 reverse 함수 사용하면 시간초과난다.
*/