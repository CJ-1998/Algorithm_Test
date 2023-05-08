#include <iostream>
#include <vector>
#include <deque>
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

    sort(v.begin(),v.end());

    vector<int> len;
    for(int i=0;i<k;i++){
        string str;
        str=to_string(v[i]);
        len.push_back(str.size());
    }

    int* t=new int[n];

    deque <int> one;
    vector<int> notone;

    string answer="";

    for(int i=0;i<n;i++){
        if(i>=k){
            t[i]=v[v.size()-1];
        }
        else{
            t[i]=v[i];
        }
        if(to_string(t[i]).size()!=1){
            notone.push_back(t[i]);
        }
        else{
            one.push_back(t[i]);
        }
    }

    int len1=one.size();
    int len2=notone.size();

    if(len[k-1]==1){
        for(int i=0;i<len1;i++){
            string temp=to_string(one.back());
            answer+=temp;
            one.pop_back();
        }
    }
    else{
        for(int i=0;i<len1;i++){
            string temp=to_string(one.back());
            answer+=temp;
            one.pop_back();
        }
        for(int i=0;i<len2;i++){
            string temp=to_string(notone[i]);
            answer+=temp;
        }
    }
    cout<<answer<<endl;

    return 0;
}