#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int k,n;
    cin>>k>>n;
    
    vector<int> v;
    for(int i=0;i<k;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    sort(v.begin(),v.end(),greater<int>());

    vector<int> len;
    for(int i=0;i<k;i++){
        string str;
        str=to_string(v[i]);
        len.push_back(str.size());
    }

    int* t=new int[n];

    string answer="";
    
    int start=0;
    int end=n-1;

    for(int i=0;i<n;i++){
        if(i>=k){
            t[end]=v[0];
            end--;
        }
        else{
            if(len[i]!=1){
                t[end]=v[i];
                end--;
            }
            else{
                t[start]=v[i];
                start++;
            }
        }
    }

    for(int i=0;i<n;i++){
        string temp=to_string(t[i]);
        answer+=temp;
    }
    cout<<answer<<endl;

    return 0;
}