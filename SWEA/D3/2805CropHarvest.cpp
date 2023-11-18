/*
문제:
    N X N크기의 농장이 있다.
    이 농장에는 이상한 규칙이 있다.
    규칙은 다음과 같다.
        ① 농장은 크기는 항상 홀수이다. (1 X 1, 3 X 3 … 49 X 49)
        ② 수확은 항상 농장의 크기에 딱 맞는 정사각형 마름모 형태로만 가능하다.
    1 X 1크기의 농장에서 자라는 농작물을 수확하여 얻을 수 있는 수익은 3이다.
    3 X 3크기의 농장에서 자라는 농작물을 수확하여 얻을 수 있는 수익은 16 (3 + 2 + 5 + 4 + 2)이다.
    5 X 5크기의 농장에서 자라는 농작물의 수확하여 얻을 수 있는 수익은 25 (3 + 2 + 1 + 1 + 2 + 5 + 1 + 1 + 3 + 3 + 2 + 1)이다.
    농장의 크기 N와 농작물의 가치가 주어질 때, 규칙에 따라 얻을 수 있는 수익은 얼마인지 구하여라.

제약사항:
    농장의 크기 N은 1 이상 49 이하의 홀수이다. (1 ≤ N ≤ 49)
    농작물의 가치는 0~5이다.

입력:
    가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
    각 테스트 케이스에는 농장의 크기 N과 농장 내 농작물의 가치가 주어진다.

출력:
    각 줄은 '#t'로 시작하고, 공백으로 농장의 규칙에 따라 얻을 수 있는 수익을 출력한다.
    (t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int farmCnt=0;
        scanf("%d",&farmCnt);
        
        vector<vector<int>> farm;
        for(int i=0;i<farmCnt;i++){
            vector<int> temp;
             string t="";
             cin>>t;
             for(int k=0;k<farmCnt;k++){
                 temp.push_back(t[k]-'0');
             }
            farm.push_back(temp);
        }
        
        int answer=0;
              
        int cnt=farmCnt/2;
        
        //위쪽 계산하는 곳
        int up=cnt;
        
        for(int i=0;i<cnt;i++){
            int upEnd=farmCnt-(up*2);
         	for(int j=up;j<up+upEnd;j++){
             	answer+=farm[i][j];
            }
            up--;
        }
		
        //제일 긴 줄 계산하는 곳
        for(int i=0;i<farmCnt;i++){
         	answer+=farm[cnt][i];   
        }
        
        //아래쪽 계산하는 곳
        for(int i=1;i<=cnt;i++){
         	int downEnd=farmCnt-(i*2);
            for(int j=i;j<i+downEnd;j++){
             	answer+=farm[cnt+i][j];   
            }
        }
        
        cout<<"#"<<test_case<<" "<<answer<<endl;
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}