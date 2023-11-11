/*
문제:
	강변에 빌딩들이 옆으로 빽빽하게 밀집한 지역이 있다.
	이곳에서는 빌딩들이 너무 좌우로 밀집하여, 강에 대한 조망은 모든 세대에서 좋지만 왼쪽 또는 오른쪽 창문을 열었을 때 바로 앞에 옆 건물이 보이는 경우가 허다하였다.
	그래서 이 지역에서는 왼쪽과 오른쪽으로 창문을 열었을 때, 양쪽 모두 거리 2 이상의 공간이 확보될 때 조망권이 확보된다고 말한다.
	빌딩들에 대한 정보가 주어질 때, 조망권이 확보된 세대의 수를 반환하는 프로그램을 작성하시오.
 	아래와 같이 강변에 8채의 빌딩이 있을 때, 연두색으로 색칠된 여섯 세대에서는 좌우로 2칸 이상의 공백이 존재하므로 조망권이 확보된다. 따라서 답은 6이 된다.
	A와 B로 표시된 세대의 경우는 왼쪽 조망은 2칸 이상 확보가 되었지만 오른쪽 조망은 한 칸 밖에 확보가 되지 않으므로 조망권을 확보하지 못하였다.
	C의 경우는 반대로 오른쪽 조망은 2칸이 확보가 되었지만 왼쪽 조망이 한 칸 밖에 확보되지 않았다.

제약 사항:
	가로 길이는 항상 1000이하로 주어진다.
	맨 왼쪽 두 칸과 맨 오른쪽 두 칸에는 건물이 지어지지 않는다. (예시에서 빨간색 땅 부분)
	각 빌딩의 높이는 최대 255이다.

입력:
	총 10개의 테스트케이스가 주어진다.
	각 테스트케이스의 첫 번째 줄에는 건물의 개수 N이 주어진다. (4 ≤ N ≤ 1000)
	그 다음 줄에는 N개의 건물의 높이가 주어진다. (0 ≤ 각 건물의 높이 ≤ 255)
	맨 왼쪽 두 칸과 맨 오른쪽 두 칸에 있는 건물은 항상 높이가 0이다. (예시에서 빨간색 땅 부분)

출력:
	#부호와 함께 테스트케이스의 번호를 출력하고, 공백 문자 후 조망권이 확보된 세대의 수를 출력한다.
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T=10;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int buildingCnt=0;
        cin>>buildingCnt;
        vector<int>building;
        
        for(int i=0;i<buildingCnt;i++){
            int temp=0;
            cin>>temp;
            building.push_back(temp);
        }
        
        int answer=0;
        for(int i=2;i<buildingCnt-2;i++){
            vector<int>leftRight;
            leftRight.push_back(building[i-2]);
            leftRight.push_back(building[i-1]);
            leftRight.push_back(building[i+1]);
            leftRight.push_back(building[i+2]);
            
            sort(leftRight.begin(),leftRight.end(),greater<>());
            
            if(building[i]>leftRight[0]){
                answer+=building[i]-leftRight[0];
            }
        }
        
		cout<<"#"<<test_case<<" "<<answer<<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}