#include<iostream>
#include<vector>
using namespace std;

int find_steps(int n)
{
	return (n/5+(n%5)/2+(n%5)%2);
}

int find_op(vector<int> &A, int reference, int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=find_steps(A[i]-reference);
	return sum;
}

int main()
{
	int T, n, min=100000, min_step;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<int> A(n);
		min=1000;
		for(int i=0;i<n;i++)
			{
				cin>>A[i];
				if(min>A[i])
				min=A[i];
			}

		min_step=find_op(A, min, n);
		cout<<" min="<<min<<" min_step="<<min_step<<endl;
		for(int i=1;i<=4;i++)
		{
			int x=find_op(A, min-i, n);
			if(x<min_step)
			min_step=x;

		cout<<" min="<<min-i<<" min_step="<<x<<endl;
		}

	    cout<<min_step<<endl;	
	}
	return 0;
}