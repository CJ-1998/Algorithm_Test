#include<iostream>

using namespace std;

int gcd(int a, int b){
    int c;
    while (b != 0)
		{
			c = a % b;
			a = b;
			b = c;
		}
	return a;
}

int lcm(int a, int b){
    return a*b/gcd(a, b);
}

int main(){

    int count = 0;
    cin>>count;

    for(int i=0;i<count;i++){
        int a=0;
        int b=0;
        cin>>a>>b;
        int answer=lcm(a,b);
        cout<<answer<<"\n";
    }

    return 0;
}