
#include<iostream>

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
		int p,q,r,s,w;
        cin>>p>>q>>r>>s>>w;
        
        int a=p*w;
        int b=0;
        if(r>=w){
            b=q;
        }
        else{
            b=q+(w-r)*s;
        }
        
        if(a>b){
         	cout<<"#"<<test_case<<" "<<b<<endl;   
        }
        else{ 
        	cout<<"#"<<test_case<<" "<<a<<endl;
        }
        
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}