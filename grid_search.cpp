#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
int q,R,C,r,c;
int check(string s[], string s1[])
{
    int found=0;
     
        for(int i=0;i<R-r+1;i++)
            for(int j=0;j<C-c+1;j++)
             {  
                int curr_r=i, curr_c=j;
                
                while(s[curr_r].substr(curr_c,c)==s1[curr_r-i])
                {
                   //cout<<"     inside comparing "<<s[curr_r].substr(curr_c,curr_c+c-1)<<","<<s1[curr_r-i]<<endl; 
                   curr_r++;

                   if(curr_r-i==r)
                    return 1;
                }
            }
    return 0;        
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    cin>>q;
    while(q--)
    {
        cin>>R>>C;
        string s[R];
        for(int i=0;i<R;i++)
            cin>>s[i];
       
        cin>>r>>c;
        string s1[r];
        for(int i=0;i<r;i++)
            cin>>s1[i];
        check(s, s1)?cout<<"YES\n":cout<<"NO\n";
                
    }
    return 0;
}
