//----------------풀이 중-------------------
//부분합 배열 2중 for문으로 돌아서 시간 초과 남

/*
문제:
    N개의 정수가 입력으로 주어진다.
    이때 연속하여 몇 개의 정수를 골라 합을 구할 수 있다.
    예를 들어, 1 3 -8 18 -8 이 있다고 하자.
    그럼 2번부터 4번까지의 수를 골라 합을 구하면, 3+(-8)+18 = 13이다. 
    이렇게 연속해서 정수를 골라 합을 구할 때, 그 합의 최대가 몇인지 구하는 프로그램을 작성하세요.

입력:
    첫 줄에 테스트케이스의 개수 T가 주어진다. (1 ≤ T ≤ 20)
    각 테스트 케이스 첫째 줄에 숫자 N이 주어진다. (3 ≤ N ≤ 100,000)
    둘째 줄에는 절대값이 1000이하의 정수 N개가 공백을 사이에 두고 입력된다.

출력:
    각 테스트케이스마다 한 줄에 걸쳐, 테스트케이스 수 “#(TC) “를 출력하고, 연속된 정수의 합의 최대값을 출력하시오.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{

        int cnt=0;
        cin>>cnt;
        
        vector<int> num;
        vector<int>sum;
        
        sum.push_back(0);
        
        for(int i=1;i<=cnt;i++){
            int temp=0;
            cin>>temp;
            num.push_back(temp);
            int sumTemp=temp+sum[i-1];
            sum.push_back(sumTemp);
        }
        
        for(int i=0;i<=cnt;i++){
            cout<<sum[i]<<" ";
        }
        
        cout<<endl;
        
        vector<int>answer;
        for(int i=0;i<cnt;i++){
            for(int j=i;j<cnt;j++){
                answer.push_back(sum[j+1]-sum[i]);
            }
        }
        
        for(int i=0;i<answer.size();i++){
            cout<<answer[i]<<" ";
        }
        
        cout<<endl;

        sort(answer.begin(),answer.end(),greater<>());
        cout<<"#"<<test_case<<" "<<answer[0]<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

