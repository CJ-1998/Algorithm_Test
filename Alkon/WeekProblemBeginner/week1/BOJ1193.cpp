/*
문제:
    무한히 큰 배열에 다음과 같이 분수들이 적혀있다.
    이와 같이 나열된 분수들을 1/1 → 1/2 → 2/1 → 3/1 → 2/2 → … 과 같은 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.
    X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.

입력:   
    첫째 줄에 X(1 ≤ X ≤ 10,000,000)가 주어진다.

출력:
    첫째 줄에 분수를 출력한다.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int cnt=0;
    cin>>cnt;

    int check=0;
    vector<int> one;
    vector<int> two;

    int move=0;
    int line=2;

    one.push_back(1);
    two.push_back(1);
    cnt--;

    while(true){
        if(cnt==0)
            break;

        if(move==0){
            one.push_back(one.back());
            two.push_back(two.back()+1);
        }
        else{
            one.push_back(one.back()+1);
            two.push_back(two.back());
        }
        cnt--;
        if(cnt==0)
            break;
        for(int i=1;i<line;i++){
            if(move==0){
                one.push_back(one.back()+1);
                two.push_back(two.back()-1);
            }
            else{
                one.push_back(one.back()-1);
                two.push_back(two.back()+1);
            }
            cnt--;
            if(cnt==0)
                break;            
        }
        if(cnt==0)
            break;

        if(move==0)
            move=1;
        else
            move=0;
        line++;
    }

    cout<<one.back()<<"/"<<two.back();
    return 0;

}

/*
개선사항:
    분모는 분자의 반대 방향으로 이루어져 있어서, 분자를 구한 후, i+1에서 분자를 뺀 값을 분모로 사용할 수 있다.
    i번째 대각선에는 i개의 원소가 있으므로, N이 몇번째 대각선에 있는지 파악하기 위해 i를 순차적으로 증가시키며 빼준다.
    N이 i보다 작아진 경우 해당 i번째 대각선에 N번째 원소가 존재한다.
    이후 대각선의 홀/짝에 따라 방향을 고려하여 분자, 분모에 해당하는 최종 값을 결정한다.
    출처: https://codesyun.tistory.com/58
*/