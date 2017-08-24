#include<iostream>
#include<vector>
#include<algorithm>
#include<stdint.h>
using namespace std;

int coin_change(int n,int m, vector<int>& c)
{
	uint64_t T[n+1][m+1];
    if(m==0){
        if(n==0)
            return 1;
        else
            return 0;
    }
	for(int j=0;j<=m;j++)
		T[0][j]=1;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			// when we have no c[j] coin in count
			int64_t x=(j>1)?T[i][j-1]:0;    //if we have more than one coin to choose from, then go for j-1, else 0
		
			// when we have atleast one c[j] coin in count
			int64_t y=(i-c[j-1]>=0)?T[i-c[j-1]][j]:0;
			cout<<"x="<<x<<" y="<<y<<" x+y = "<<x+y<<endl;
			T[i][j]=x+y;
			cout<<"T[i][j] = "<<T[i][j]<<endl<<endl;
			
		}
	return T[n][m];	
}

int main()
{
	unsigned long long int n, m;
	cin>>n>>m;
	vector<int> c(m);
	//cout<<"\nCoins: ";
	for(int i=0;i<m;i++)
		{ cin>>c[i];  }
	//cout<<"\nn="<<n<<endl<<endl;
	sort(c.begin(), c.end());
	
	cout<<coin_change(n, m, c)<<endl;
	
	return 0;
}