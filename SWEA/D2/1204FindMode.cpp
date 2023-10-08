
#include<iostream>
#include<algorithm>
#include<cstdio>

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
        int* arr=new int [101];
        for(int i=0;i<1000;i++){
            int temp=0;
            cin>>temp;
            arr[temp]++;
        }
        
        int max=1;
        for(int i=2;i<101;i++){
            if(arr[max]<=arr[i]){
                max=i;
            }
        }
        //int index=max_element(arr,arr+101)-arr;
        cout<<"#"<<num<<" "<<max<<endl;
        
		/////////////////////////////////////////////////////////////////////////////////////////////

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}