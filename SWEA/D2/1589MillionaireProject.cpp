#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int test_case;
	int T;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int num  = 0;
        cin>>num;
        vector<int> v;
        for(int i=0;i<num;i++){
         	int temp=0;
            cin>>temp;
            v.push_back(temp);
        }
        
        int sum=0;
        int cnt=0;
        int real = 0;
        
        int index = max_element(v.begin(),v.end())-v.begin();
        if(index==0){
            cout<<"#"<<test_case<<" "<<real<<endl;
            continue;
        }
        
        int idx = 0;
        while(true){
            if(idx == num){
             	break;   
            }
            int index = max_element(v.begin(),v.end())-v.begin();
            for(int i=0;i<index;i++){
                sum+=v[i];
                cnt++;
                idx++;
            }
            int all = cnt*v[index];
			all-=sum;
			real+=all;
			sum=0;
			cnt=0;
            idx++;
            v.erase(v.begin(),v.begin()+index+1);
        }
        
        /**
        for(int i=0;i<num;i++){
            int index = max_element(v.begin(),v.end())-v.begin();
            if(i==index){
                int all = cnt*v[i];
                all-=sum;
                real+=all;
                sum=0;
                cnt=0;
            }
            else{
             	sum+=v[i];
                cnt++;
            }
             v[i]=-1;
        }
        **/
        
        cout<<"#"<<test_case<<" "<<real<<endl;
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}