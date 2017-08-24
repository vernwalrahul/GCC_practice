#include <iostream>
#define R 1000000007
using namespace std;

unsigned long long int find_max(unsigned long long int **M, int n, int x, int s, int f, int m)
{
	int curr=0; unsigned long long int max_amount[2][n];
	
	while(curr<m)
	{
		if(curr%2==0)
		{
			for(int i=0;i<n;i++)
			{

			}
		}
	}

} 

int main()
{
	int n,x,s,f;
	unsigned long long int **m, max_amount;
	cin>>n;
	cin>>x>>s>>f>>m;
	int M = new int(n);
	for(int i=0;i<n;i++)
	{	M[i]=new int(n);
		for(int j=0;j<n;j++)
			cin>>M[i][j];
	}

	max_amount=find_max(M, n, x, s, f, m);	
	return 0;
}