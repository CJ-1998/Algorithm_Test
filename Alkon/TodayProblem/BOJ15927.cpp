#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int answer=-1;
    string pal;
    cin>>pal;
    
    int len=pal.length();
    stack<char> str;

    if(len%2==0){
        bool check=false;
        int big=0;
        for(int i=0;i<len;i++){
            if(str.size()==0){
                str.push(pal[i]);
            }
            else{
                if(str.top()==pal[i]){
                    check=true;
                    str.pop();
                }
                else{
                    if(check){
                        if(str.size()>big)
                            big=str.size();

                        while(!str.empty()) 
                            str.pop();

                        check=false;
                        str.push(pal[i]);
                    }
                    else{
                        str.push(pal[i]);
                    }
                }
            }
        }
        if(str.size()>big)
            big=str.size();
        if(str.size()!=0)
            answer=big;
    }
    else{
        for(int i=0;i<len;i++){
            if(i<len/2){
                str.push(pal[i]);
            }
            else if(i>len/2){
                if(str.top()==pal[i]){
                    str.pop();
                }
            }
        }
        if(str.size()==0){
            if(pal[len/2-1]!=pal[len/2])
                answer=len-1;
            else
                answer=-1;
        }
        else{
            while(!str.empty()) 
                str.pop();

           bool check=false;
            int big=0;
            for(int i=0;i<len;i++){
                if(str.size()==0){
                    str.push(pal[i]);
                }
                else{
                    if(str.top()==pal[i]){
                        check=true;
                        str.pop();
                    }
                    else{
                        if(check){
                            if(str.size()>big)
                                big=str.size();

                            while(!str.empty()) 
                                str.pop();

                            check=false;
                            str.push(pal[i]);
                        }
                        else{
                            str.push(pal[i]);
                        }
                    }
                }
            }
            if(str.size()>big)
                big=str.size();
            if(str.size()!=0)
                answer=big;
        }
    }
    
    cout<<answer<<endl;
    return 0;
}