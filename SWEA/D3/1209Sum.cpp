/*
문제:
    다음 100X100의 2차원 배열이 주어질 때, 각 행의 합, 각 열의 합, 각 대각선의 합 중 최댓값을 구하는 프로그램을 작성하여라.
    다음과 같은 5X5 배열에서 최댓값은 29이다.

제약사항:
    총 10개의 테스트 케이스가 주어진다.
    배열의 크기는 100X100으로 동일하다.
    각 행의 합은 integer 범위를 넘어가지 않는다.
    동일한 최댓값이 있을 경우, 하나의 값만 출력한다.

입력:
    각 테스트 케이스의 첫 줄에는 테스트 케이스 번호가 주어지고 그 다음 줄부터는 2차원 배열의 각 행 값이 주어진다.

출력:
    #부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 테스트 케이스의 답을 출력한다.
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T=10;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int cnt=0;
        scanf("%d",&cnt); 
        
        int arr[100][100]{};
        for(int i=0;i<100;i++){
         	for(int j=0;j<100;j++){
             	int temp=0;
                scanf("%d",&temp);
                arr[i][j]=temp;
            }
        }
        
        vector<int>answer;
        for(int i=0;i<100;i++){
            int a=0;
            int b=0;
         	for(int j=0;j<100;j++){
             	a+=arr[i][j];
                b+=arr[j][i];
            }
            answer.push_back(a);
            answer.push_back(b);
        }
        
        int c=0;
        int d=0;
        for(int i=0;i<100;i++){
			c+=arr[i][i];
            d+=arr[i][99-i];
        }
        answer.push_back(c);
        answer.push_back(d);
 
        sort(answer.begin(),answer.end(),greater<>());
        cout<<"#"<<test_case<<" "<<answer[0]<<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}