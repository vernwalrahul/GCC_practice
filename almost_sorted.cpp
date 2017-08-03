#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    int array[n], swap_done=0, rev_poss=0, al=-1, ar=-1, sort_poss=1, start_r=-1, end_r=-1, last_al=0, last_ar=0;
    
    for(int i=0;i<n;i++)
        cin>>array[i];
    
    for(int i=0, j=n-1;i<j; )
    {
        if(array[i+1]>=array[i])
            i++;
        else
        {// cout<<"left_ambiguity at "<<i<<endl;
         al=i; if(start_r==-1) start_r=al;}
        if(array[j-1]<=array[j])
            j--;
        else
        { //cout<<"right ambiguity at "<<j<<endl;
         ar=j; if(end_r==-1) end_r=ar;}
        
        if(al!=-1 && ar!=-1)
        {
            //cout<<" ambiguity at "<<al<<" & "<<ar<<" i,j="<<i<<","<<j<<endl;
            if(al==0)
                array[-1]=array[ar];
            if(ar==n-1)
                array[n]=array[al];
            if(array[al-1]<=array[ar]<=array[al+1] && array[ar-1]<=array[al]<=array[ar+1])
            {i++; j--; swap_done++;
             last_al=al;
             last_ar=ar;
            //cout<<"swap_done="<<swap_done<<endl; 
            }
            else
            {sort_poss=0; break;}
          al=ar=-1;
        }
        
    }
    if(sort_poss==1)
    {cout<<"yes"<<endl;
     if(swap_done==1)
         cout<<"swap "<<last_al+1<<" "<<last_ar+1<<endl;
     else if(swap_done>1)
         cout<<"reverse "<<start_r+1<<" "<<end_r+1<<endl;
    }
    else
        cout<<"no"<<endl;
    return 0;
}
