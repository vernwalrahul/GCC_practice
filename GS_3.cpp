#include <iostream>
#include <vector>
using namespace std;

long long int find_maxProfit(int n, vector<int> &A, int k, int curr)
{
	if(curr>=n-1 || k<=0)
		return 0;
	if(curr==n-2)
		return A[n-1]-A[n-2]>0?A[n-1]-A[n-2]:0;

	long long int without_curr=0, with_curr=0, index;
	without_curr = find_maxProfit(n, A, k, curr+1);
	// cout<<"profit without "<<A[curr]<<" = "<<without_curr<<endl;
	for(int i=curr+2;i<=n;i++)
	{
		long long int now=A[i-1]-A[curr];
		if(now > 0 )
		{
			long long int val_return = find_maxProfit(n, A, k-1, i);
			if(now+val_return>with_curr)
				with_curr=now+val_return;
			// cout<<" profit with "<<A[curr]<<" sold on "<<A[i-1]<<" = "<<now+val_return<<endl;
		}
	}
	return with_curr>without_curr?with_curr:without_curr;
}
int main()
{
	int q, k, n; long long int max_profit=0;
	cin>>q;
	while(q--)
	{
		cin>>k>>n;
		vector<int> A(n);
		for(int i=0;i<n;i++)
			cin>>A[i];
		max_profit=find_maxProfit(n, A, k, 0);
		cout<<max_profit<<endl;
	}
	return 0;
}