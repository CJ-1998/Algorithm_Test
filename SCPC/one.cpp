/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int box(int n, int a, int b){
    
    vector<int> temp;
    
    int anum=0;
    int bnum=0;
    
    while(anum<(n/a)+1){
        if(anum*a+bnum*b==n){
            temp.push_back(anum+bnum);
            bnum++;
        }
        else if(anum*a+bnum*b>n){
            bnum=1;
            anum++;
        }
        else{
            bnum++;
        }
    }
    
    anum=0;
    bnum=0;
    
    while(bnum<(n/b)+1){
        if(anum*a+bnum*b==n){
            temp.push_back(anum+bnum);
            anum++;
        }
        else if(anum*a+bnum*b>n){
            anum=1;
            bnum++;
        }
        else{
            anum++;
        }
    }

    sort(temp.begin(),temp.end(),greater<>());
    return temp[0];
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

// 	freopen("input.txt", "r", stdin);
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n=0;
        int a=0;
        int b=0;
        cin>>n>>a>>b;
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
        Answer=box(n,a,b);
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}