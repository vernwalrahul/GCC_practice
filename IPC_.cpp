#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct trainer_{
	int d,T,S;     //D->no of days he will be staying.
};

bool sort_by_sadness(const trainer_ &lhs, const trainer_ &rhs)
{
	return lhs.S>rhs.S;
}
int  main()
{
	unsigned long long int T, N,D, res_D=0;
	unsigned long long int sadness=0, poss_lecture;
	cin>>T;
	while(T--)
	{
		cin>>N>>D;
		vector<trainer_> trainer(N);
		sadness=0; res_D=0;
		for(int temp=0;temp<N;temp++)
			{ 
				cin>>trainer[temp].d>>trainer[temp].T>>trainer[temp].S;
				sadness+=trainer[temp].S*trainer[temp].T;
				trainer[temp].d=D- trainer[temp].d+1;
			}
        cout<<"total sadness="<<sadness<<endl;
		sort(trainer.begin(), trainer.end(), sort_by_sadness);	
        unsigned long long int i=0;
        while(res_D<D&&i<N)
        {
        	if((trainer[i].d-res_D)>0)
        	{
             poss_lecture=(trainer[i].d-res_D)<trainer[i].T?(trainer[i].d-res_D):trainer[i].T;   
             sadness-=trainer[i].S*(poss_lecture);
             cout<<"i="<<i<<" trainer[i].d="<<trainer[i].d<<" res_D="<<res_D<<endl;
             cout<<" subtracting sadness="<<poss_lecture<<"*"<<trainer[i].S<<endl;
        	 res_D+=poss_lecture;
             
            }
        	i++;
        	cout<<" i="<<i<<" res_D="<<res_D<<" N="<<N<<endl;
        }
       cout<<sadness<<endl; 
	}
	return 0;
}