
#include<iostream>
#include<vector>

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
		vector<int> answer;
        for(int i=0;i<5;i++){
            int temp=0;
            answer.push_back(temp);
        }
        int num=0;
        cin>>num;
        
        while(true){
         	if(num%2==0){
                answer[0]++;
                num/=2;
            }
            else{
                break;
            }
        }
        while(true){
         	if(num%3==0){
                answer[1]++;
                num/=3;
            }
            else{
                break;
            }
        }
        while(true){
         	if(num%5==0){
                answer[2]++;
                num/=5;
            }
            else{
                break;
            }
        }
        while(true){
         	if(num%7==0){
                answer[3]++;
                num/=7;
            }
            else{
                break;
            }
        }
        while(true){
         	if(num%11==0){
                answer[4]++;
                num/=11;
            }
            else{
                break;
            }
        }
        
        cout<<"#"<<test_case<<" ";
        for(int j=0;j<5;j++){
        	cout<<answer[j]<<" ";
        }
        cout<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}