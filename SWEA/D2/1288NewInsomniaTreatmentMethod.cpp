
#include<iostream>
#include<string>

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
		int arr[10];
        for(int i=0;i<10;i++){
         	arr[i]=0;   
        }
        
        bool check=false;
        int num=1;
        
        int sheep=0;
        cin>>sheep;
        
        while(check==false){
			string temp=to_string(sheep*num);
            for(int j=0;j<temp.length();j++){
                arr[temp[j]-'0']++;
            }
            
            bool zero=true;
            for(int k=0;k<10;k++){
            	if(arr[k]==0) {
                	zero=false;
                    break;
                }
            }
            
            if(zero){
            	check=true;
                cout<<"#"<<test_case<<" "<<sheep*num<<endl;
            }
            else{
            	num++;
            }
        }
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}