#include<iostream>
#include<string.h>
using namespace std;

int char_in_string(char a, char x[])
{
	for(int i=0;i<strlen(x);i++)
		if(a==x[i])
			return 1;

	return 0;	
}
int main()
{
	char good_char[26], pattern[100000], query[100000]; int T, flag=1, i,j;
	cin>>good_char;

	cin>>pattern;
	cin>>T;

	while(T--)
	{
		cin>>query;
		//cout<<"pattern="<<pattern<<" "<<strlen(pattern)<<"\nquery="<<query<<" "<<strlen(query)<<"\ngood_char="<<good_char<<endl;
		flag=1;
		for( i=0,j=0;i<strlen(pattern) && flag;i++)
		{
			if(pattern[i]=='?')
 			  { if(!char_in_string(query[j], good_char))
 			  	  {//cout<<"trapped. (i,j)="<<i<<j<<endl;
 			  	   flag=0; break;
 			      }
 			  	else
 			  	j++; 
 			  }
 			else if(pattern[i]=='*')
 			{
 				for(j;j<strlen(query);j++)
 				{
 					if(pattern[i+1]==query[j])
 						break;
 					else if(char_in_string(query[j], good_char))
 							if(query[j]!=pattern[i+1])
 								{ flag=0; break;}
 							else
 								break;

 				}
 			}
 			else if(pattern[i]==query[j]) 
 				{
 					j++;
 				}
 				 else {flag=0; break;}	

		}
		if(flag==1)
		if(j<strlen(query))
			flag=0;

		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}