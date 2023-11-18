//---------------풀이 중-----------------
//전부 다 보면서 체크해서 시간 초과 남
//소인수분해로 풀어도 제한시간 초과 남

/*
문제:
    어떤 자연수 A가 주어진다. 
    여기에 자연수 B를 곱한 결과가 거듭제곱수가 되는 최소의 B를 구하는 프로그램을 작성하라. 
    여기서 자연수는 1이상인 정수를 뜻한다.

입력:
    첫 번째 줄에 테스트 케이스의 수 T 가 주어진다.
    각 테스트 케이스의 첫 번째 줄에는 하나의 자연수 A(1≤A≤10^7) 가 주어진다.

출력:
    각 테스트 케이스마다 A에 곱한 결과가 거듭제곱수가 되는 최소의 자연수를 출력한다.
*/

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        // int num=0;
        // cin>>num;
        
        // for(int i=1;i<=num;i++){
        //     int mult=i*num;
        //     double t=sqrt(mult);
        //     if(t==(int)t){
        //         cout<<"#"<<test_case<<" "<<i<<"\n";
        //         break;
        //     }
        // }

        int num=0;
        cin>>num;
        
        if(num==1){
            cout<<"#"<<test_case<<" "<<1<<endl;
            continue;
        }
        
        int div=num;
        
        vector<int> ans;
        
        for(int i=2;i*i<=num;i++){
         	while(div%i==0){
                ans.push_back(i);
                div/=i;
            }
        }
        
        if(div!=1){
            ans.push_back(div);
        }
        
        vector<int> answer;
        
        for(int i=0;i<=ans[ans.size()-1];i++){
            answer.push_back(0);
        }
        
        for(int i=0;i<ans.size();i++){
            answer[ans[i]]++;
        }
        
        int realAnswer=1;
        for(int i=0;i<answer.size();i++){
         	if(answer[i]!=0){
             	if(answer[i]%2!=0){
                 	realAnswer*=i;   
                }
            }
        }
        
        cout<<"#"<<test_case<<" "<<realAnswer<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}