
#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;

map <char, int> table;

string intToBinary(int num){
 	string binary="";   
    for(int i=0;i<6;i++){
        binary+=to_string(num%2);
        num/=2;
    }
    reverse(binary.begin(),binary.end());
    return binary;
}

int binaryToInt (string binary){
    int num=0;
    for(int i=0;i<8;i++){
        num+=(binary[i]-'0')*((int)pow(2,7-i));
    }
    return num;
}

void initTable(){
	char one='A';
    char two='a';
    char three='0';
    int oneStart=0;
    int twoStart=26;
    int threeStart=52;
    int fourStart=62;
    
    for(oneStart; oneStart<26; oneStart++){
        table.insert(make_pair(one++,oneStart));
    }
    
    for(twoStart; twoStart<52; twoStart++){
        table.insert(make_pair(two++,twoStart));
    }
    
    for(threeStart; threeStart<62; threeStart++){
        table.insert(make_pair(three++,threeStart));
    }
    
    table.insert(make_pair('+',fourStart++));
    table.insert(make_pair('/', fourStart));
    
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
    
    initTable();
    
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string inputString;
        cin>>inputString;
        
        int iter=inputString.length()/4;
        int startIndex=0;
        
        string answer="";
        
        for(int i=0;i<iter;i++){
            string binaryString="";
        	for(int j=0;j<4;j++){
                char temp=inputString[startIndex++];
                //cout<<temp<<endl;
                int num=table[temp];
                //cout<<num<<endl;
                string tempString=intToBinary(num);
                //cout<<tempString<<endl;
             	binaryString+=tempString;
            }
            
            int cutIndex=0;
            for(int k=0;k<3;k++){
                int binaryNum=binaryToInt(binaryString.substr(cutIndex,cutIndex+8));
                cutIndex=cutIndex+8;
                answer+=(char)binaryNum;
            }
        }
        
		cout<<"#"<<test_case<<" "<<answer<<"\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

/*
배운 점:
    1. map 사용법. map에 값을 넣는 make_pair()부터 map[key]를 이용해 value 꺼내는 것 확인.
    2. Int To Binary, Binary To Int 코드 작성 방법 확인.
    3. string a~b까지 자르려면 string.substr(a,b+1); 하면 됨.
    4. 아스키코드표에서 숫자 값을 (char)하면 해당 문자 나옴.
    5. string에 char, string 다 더할 수 있음 확인.
*/