/*
문제:
    학생들은 3주가 지난 기념으로 매점에서 1월 1일이 지나 싸게 파는 폭죽을 사서 터뜨리고 있다.
    폭죽쇼를 하는 동안 N명의 학생들이 폭죽을 터뜨린다. 
    그리고 이 N명의 학생은 각각 일정한 주기로 폭죽을 터뜨린다. 
    물론 이 주기는 학생들마다 같을 수도, 다를 수도 있다. 
    그리고 우리는 초 단위로 관찰을 하고, 폭죽 역시 초 단위로 터진다.
    폭죽쇼가 끝날 때까지 얼마나 많은 시간동안 밤하늘에 폭죽이 터지는 것을 볼 수 있는지 궁금해 하는 조교를 도와주자.

입력:
    첫 줄에 폭죽을 터뜨리는 학생의 수 N(1 ≤ N ≤ 100)과 폭죽쇼가 끝나는 시간 C(1 ≤ C ≤ 2,000,000)가 주어진다. 
    그 다음 N개의 줄에는 학생들이 폭죽을 터뜨리는 주기가 한 줄에 하나씩 주어진다. 
    주기는 1보다 크거나 같고, C보다 작거나 같은 자연수이다.

출력:
    폭죽쇼가 시작되고 끝날 때까지 밤하늘에 폭죽을 볼 수 있는 총 시간을 출력한다.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int student=0;
    int showTime=0;
    cin>>student>>showTime;

    int* arr = new int[showTime];

    for(int i=0;i<showTime;i++){
        arr[i]=0;
    }

    for(int i=0;i<student;i++){
        int temp;
        cin>>temp;

        int t=1;

        while(showTime>=temp*t){
            arr[temp*t-1]++;
            t++;
        }
    }

    int answer=0;

    for(int i=0;i<showTime;i++){
        if(arr[i]!=0)
            answer++;
    }

    cout<<answer;
    return 0;
}

/*
int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int lcm (int a, int b){
    return a*b/gcd(a,b);
}

int main(){

    int student=0;
    int showTime=0;
    cin>>student>>showTime;

    vector<int> term;
    int answer=0;

    for(int i=0;i<student;i++){
        int temp;
        cin>>temp;
        term.push_back(temp);
        answer+=showTime/temp;
    }

    for(int i=0;i<student-1;i++){
        for(int j=i+1;j<student;j++){
            int t=showTime/lcm(term[i],term[j]);
            answer-=t;
        }
    }

    cout<<answer;

    return 0;
}
*/

/*
배운 점:
    1. 최대 공약수, 최소 공배수 이런 것으로 해보려고 했는데 어려움.
    2. 그냥 각 주기를 index로 해서 배열에 값을 넣어서 값이 있는 것 개수 셈.
*/