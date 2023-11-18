/*
문제:
    어떤 국가에서는 자국 내 방송국에서 스파이가 활동하는 사실을 알아냈다. 
    스파이는 영상물에 암호 코드를 삽입하여 송출하고 있었다. 
    스파이의 암호 코드에 다음과 같은 규칙이 있음을 발견했다.
    1. 암호코드는 8개의 숫자로 이루어져 있다.
    2. 올바른 암호코드는 (홀수 자리의 합 x 3) + (짝수 자리의 합)이 10의 배수가 되어야 한다. 
    ex) 암호코드가 88012346일 경우,
    ( ( 8 + 0 + 2 + 4 ) x 3 ) + ( 8 + 1 + 3 + 6) = 60은 10의 배수이므로 올바른 암호코드다.
    ex) 암호코드가 19960409일 경우,
    ( ( 1 + 9 + 0 + 0 ) x 3 ) + ( 9 + 6 + 4 + 9) = 58은 10의 배수가 아니므로 잘못된 암호코드다. 
    이 암호코드들을 빠르고 정확하게 인식할 수 있는 스캐너를 개발하려고 한다.
    스캐너는 암호코드 1개가 포함된 직사각형 배열을 읽는다.
    직사각형 배열은 1, 0으로만 이루어져 있고, 암호코드 이외의 부분은 전부 0으로 주어진다.
    암호코드에서 숫자 하나는 7개의 비트로 암호화되어 주어진다. 따라서 암호코드의 가로 길이는 56이다. 
    암호코드의 각 숫자가 암호화되는 규칙은 다음과 같다.
    비정상적인 암호코드(가로 길이가 56이 아닌 경우, 아래 규칙대로 해독할 수 없는 경우)는 주어지지 않는다.
    암호코드 정보가 포함된 2차원 배열을 입력으로 받아 올바른 암호코드인지 판별하는 프로그램을 작성하라.

입력:
    가장 첫줄은 전체 테스트 케이스의 수이다.
    각 테스트 케이스의 첫 줄에 두 자연수가 주어지는데 각각 배열의 세로 크기 N, 배열의 가로크기 M이다 (1≤N≤50, 56≤M≤100).
    그 다음 N개의 줄에 걸쳐 N x M 크기의 직사각형 배열이 주어진다.

출력:   
    각 테스트 케이스의 답을 순서대로 표준출력으로 출력하며, 각 케이스마다 줄의 시작에 “#C”를 출력하여야 한다. 이때 C는 케이스의 번호이다.
    주어진 암호코드가 올바른 암호코드일 경우, 암호코드에 포함된 숫자의 합을 출력하라. 만약 잘못된 암호코드일 경우 대신 0을 출력하라.
*/

#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

string zero="0001101";
string one="0011001";
string two="0010011";
string three="0111101";
string four="0100011";
string five="0110001";
string six="0101111";
string seven="0111011";
string eight="0110111";
string nine="0001011";

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int height=0;
        int width=0;
        scanf("%d %d",&height,&width);
        //cin>>height>>width;
        string code="";
        
        for(int i=0;i<height;i++){
         	string temp="";
            //scanf("%s",temp);
            cin>>temp;
            if(temp.find("1")!=string::npos){
				code=temp;
            }
        }
        
        string findCode="";
        for(int i=width-1;i>=0;i--){
            if(code[i]=='1'){
                for(int j=0;j<56;j++){
                 	findCode+=code[i-j];   
                }
                break;
            }
        }
        reverse(findCode.begin(),findCode.end());
        
        string numCode="";
        int answer=-1;
        for(int i=0;i<findCode.length();i+=7){
            string temp="";
         	for(int j=0;j<7;j++){
                temp+=findCode[i+j];
            }
            //cout<<temp<<endl;
            if(temp.compare(zero)==0){
             	numCode+="0";   
            }else if(temp.compare(one)==0){
                numCode+="1"; 
            }else if(temp.compare(two)==0){
                numCode+="2"; 
            }else if(temp.compare(three)==0){
                numCode+="3"; 
            }else if(temp.compare(four)==0){
                numCode+="4"; 
            }else if(temp.compare(five)==0){
                numCode+="5"; 
            }else if(temp.compare(six)==0){
                numCode+="6"; 
            }else if(temp.compare(seven)==0){
                numCode+="7"; 
            }else if(temp.compare(eight)==0){
                numCode+="8"; 
            }else if(temp.compare(nine)==0){
                numCode+="9"; 
            }else{
                answer=0;
                break;
            }
            //cout<<numCode<<endl;
        }
        
        if(answer==0){
         	cout<<"#"<<test_case<<" "<<answer<<endl;
            continue;
        }
        int even=0;
        int odd=0;
        for(int i=0;i<numCode.length();i++){
         	if(i%2==0){
             	odd+=numCode[i]-'0';  
            }
            else{
             	even+=numCode[i]-'0';
            }
        }
        
        if((odd*3+even)%10==0){
            answer=odd+even;
        }
        else{
            answer=0;
        }

        cout<<"#"<<test_case<<" "<<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

/*
배운 점:
    1. cin 되게 느려서 시간초과 많이 난다. 
    2. 문자열에 특정 문자열 있는지 찾으려면 find(str)!=string::npos 하면 된다. 
    3. c++ 문자열 비교하려면 str.compare(str)==0 해야 같은 것이다. 같으면 0이라 if문에 넣으면 이상해진다. 
*/