
#include<iostream>
#include<cmath>
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

		/////////////////////////////////////////////////////////////////////////////////////////////
		int num=0;
        cin>>num;
        vector<int> arr;
        for(int i=0;i<num;i++){
            int temp=0;
            cin>>temp;
            arr.push_back(abs(temp));
        }
        
        int max=*min_element(arr.begin(),arr.end());
        
        int cnt=0;
        for(int i=0;i<num;i++){
        	if(arr[i]==max){
                cnt++;
            }
        }
        
        cout<<"#"<<test_case<<" "<<max<<" "<<cnt<<endl;
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}