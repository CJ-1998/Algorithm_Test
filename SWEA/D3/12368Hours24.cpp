/*
문제:
    하루는 24시간이다. 
    24시간제 시계에서는 하루가 자정에서 시작해서 다음 날 자정에서 끝나며, 자정에서부터 지금까지 흐른 시간을 기준으로 시각을 표기한다. 
    예를 들어, 지금이 오후 8시라면 “20시”와 같은 꼴로 표현할 수 있다. 
    자정을 표기하는 유일한 방법은 “0시”임에 유의하라.
    지금은 자정에서부터 정확히 A시간이 지났다. 
    앞으로 정확히 B시간이 더 지난다면, 24시간제 시계에서 그 때는 몇 시일까?

입력:
    첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
    각 테스트 케이스의 첫 번째 줄에는 두 개의 정수 A, B (0 ≤ A, B ≤ 23)이 공백 하나를 사이로 두고 순서대로 주어진다.

출력:
    각 테스트 케이스마다, 현재 A시인 상황에서 앞으로 B시간이 지나면 몇 시가 되는지를 출력한다.
*/



#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int start=0;
        int plus=0;
        cin>>start>>plus;
        
        int sum=start+plus;
        int answer=0;
        
        if(sum<24){
            answer=sum;
        }
        else{
            answer=sum%24;
        }
        
        cout<<"#"<<test_case<<" "<<answer<<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}