
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
		int inputCnt=0;
        cin>>inputCnt;
        
        int answer=0;
        int speed=0;
        for(int i=0;i<inputCnt;i++){
			int cmd=0;
            cin>>cmd;
            
            int acc=0;
            if(cmd==0){
                answer+=speed;
            }
            else if(cmd==1){
                cin>>acc;
                speed+=acc;
                answer+=speed;
            }
            else{
                cin>>acc;
                speed-=acc;
                if(speed<0)
                    speed=0;
                answer+=speed;
            }
        }
        
        cout<<"#"<<test_case<<" "<<answer<<"\n";
		/////////////////////////////////////////////////////////////////////////////////////////////

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}