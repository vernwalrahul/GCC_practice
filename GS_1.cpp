#include <iostream>

using namespace std;

int main()
{
	int q, n, k, x, d, temp, flag=0;
	cin>>q;
	while(q--)
	{
		flag=0;
		cin>>n>>k>>x>>d;
		float y=0;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			if(x*temp/100.0>k)
				y+=x*temp/100.0;
			else
				y+=k;
			if(y>d)
				flag=1;
		}
		// cout<<"y="<<y<<endl;
		if(flag==0)
			cout<<"fee\n";
		else
			cout<<"upfront\n";

	}
	return 0;
}