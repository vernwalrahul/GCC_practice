#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct trainer_{
	int D,T,S;     //D->no of days he will be staying.
};

bool sort_by_sadness(const trainer_ &lhs, const trainer_ &rhs)
{
	return lhs.S>rhs.S;
}
int  main()
{
	unsigned long long int T, N,D, res_D=0, curr_d, curr_l, curr_s;
	unsigned long long int sadness=0, poss_lecture;
	cin>>T;
	while(T--)
	{

		cin>>N>>D;
		vector<int> lec_value(D+1,0);
		vector<int> reserved_more(D+1,1);
		vector<trainer_> trainer(N);
		sadness=0; 
		for(int temp=0;temp<N;temp++)
		{
			cin>>trainer[temp].D>>trainer[temp].T>>trainer[temp].S;
		}
		sort(trainer.begin(), trainer.end(), sort_by_sadness);
		for(int temp=0;temp<N;temp++)
			{ 
				curr_d=trainer[temp].D;
				curr_l=trainer[temp].T;
				curr_s=trainer[temp].S;
				sadness+=curr_l*curr_s;
				int lectures_given=0, i;
				for(i=curr_d;i<=D&&(lectures_given<curr_l);)
					if(lec_value[i]==0)
						{ lec_value[i]=curr_s; lectures_given++; i++; }
					else
						i+=reserved_more[i];
				reserved_more[curr_d]=i-curr_d;	
			}
       //cout<<"N="<<N<<endl;
       for(int i=1;i<=D;i++)
       	{ sadness-=lec_value[i];  }
       cout<<sadness<<endl; 
	}
	return 0;
}