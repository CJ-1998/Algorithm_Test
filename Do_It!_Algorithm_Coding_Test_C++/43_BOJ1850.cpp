#include<iostream>
#include<string>

using namespace std;

long long gcd(long long a, long long b){
    long long c;
    while (b != 0)
		{
			c = a % b;
			a = b;
			b = c;
		}
	return a;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a;
    long long b;

    cin>>a>>b;

    long long answer = gcd(a,b);

    for(long long i=0;i<answer;i++){
        cout<<1;
    }

    return 0;
}