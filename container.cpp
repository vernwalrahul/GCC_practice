#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int q, n, flag=1;
    cin>>q;

    while(q--)
    {
    	cin>>n;

    	int temp;
    	int container[n]={0};
    	int balls[n]={0};
    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    		{	cin>>temp;
    			container[i]+=temp;
    			balls[j]+=temp;
    		}
    	sort(container, container+n);
    	sort(balls, balls+n);

    	for(int i=0;i<n;i++)
    	if(container[i]!=balls[i])
    	{ flag=0; break;}	

        if(flag==0)
        	cout<<"Impossible\n";
        else
        	cout<<"Possible\n"
    }

    return 0;
}
