#include <iostream>
using namespace std;

struct A{
	long long int t;
	long long int p;
	long long int max_sofar;
	long long int max_sofar_r;
};

int binary_search(A stock[], long long int v, long long int n)
{
	int l=0, r=n-1, mid, flag=0;
	while(1)
	{
		// cout<<"l = "<<l<<" r= "<<r<<" v = "<<v<<endl;
		// cout<<stock[r-1].max_sofar<<" "<<v<<" "<<stock[r].max_sofar<<endl;
		if(stock[r-1].max_sofar<v && v<=stock[r].max_sofar)
			return r;
		mid = (l+r)/2;
		if(v<=stock[mid].max_sofar)
			r=mid;
		else
			l=mid;
	}
}	

int binary_search2(A stock[], long long int v, long long int n)
{
	int l=0, r=n-1, mid, flag=0;
	while(1)
	{
		// cout<<"l = "<<l<<" r= "<<r<<" v = "<<v<<endl;
		// cout<<stock[r-1].max_sofar<<" "<<v<<" "<<stock[r].max_sofar<<endl;
		if(stock[r-1].t<v && v<=stock[r].t)
			return r;
		mid = (l+r)/2;
		if(v<=stock[mid].t)
			r=mid;
		else
			l=mid;
	}
}	

long long int query1(long long int n, A stock[], long long int v, long long int gmax_price)
{
	long long int min_t=1000000001; int flag=0;
	if(v>gmax_price)
		return -1;
	if(v<=stock[0].p)
		return stock[0].t;

	int i=binary_search(stock, v, n);
	// cout<<" got i = "<<i<<endl;
	return stock[i].t;	
}

long long int query2(long long int n, A stock[], long long int v, long long int gmax_price)
{
	long long int max_p=0; 
	if(v<=stock[0].t)
		return gmax_price;
	if(v>stock[n-1].t)
		return -1;
	
	int i=binary_search2(stock, v, n);

	return stock[i].max_sofar_r;	
}

int main()
{
	long long int n, q, v, gmax_price=0; int q_no;
	cin>>n>>q;
	A stock[n];
	for(int i=0;i<n;i++)
		{ 
			cin>>stock[i].t;
		}
	for(int i=0;i<n;i++)
		{ 
			cin>>stock[i].p;
			if(stock[i].p>gmax_price)
				gmax_price=stock[i].p;
			stock[i].max_sofar=gmax_price;
			// cout<<"max_sofar i = "<<i<<" is "<<gmax_price<<endl;
		}	
	gmax_price=0;	
	for(int i=n-1;i>=0;i--)
		{ 
			if(stock[i].p>=gmax_price)
				gmax_price=stock[i].p;
			stock[i].max_sofar_r=gmax_price;
		}	
	while(q--)
	{
		cin>>q_no>>v;
		if(q_no==1)
			cout<<query1(n, stock, v, gmax_price)<<endl;
		else
			cout<<query2(n, stock, v, gmax_price)<<endl;
	}	
	return 0;
}