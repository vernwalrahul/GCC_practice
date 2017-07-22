#include <iostream>

using namespace std;

int main()
{
	int T; char sign; unsigned long long int decrease=0, increase=0;
	cin>>T;
	
	while(T--)
	{
		l_increase=0;
		l_decrease=0;
		do{
			cin>>sign;
			if(sign=='<')
			{
				curr_increase++;
				curr_decrease=0;
			}
			else if(sign=='>')
			{
				curr_decrease++;
				curr_increase=0;
			}

		  if(curr_increase>l_increase)
		  l_increase=curr_increase;

		  if(curr_decrease>l_decrease)
		  l_decrease=curr_decrease;	
		}while(sign!='\n')

      l_increase>l_decrease?cout<<l_increase<<"\n":cout<<l_decrease<<"\n";
	 	
	}
}