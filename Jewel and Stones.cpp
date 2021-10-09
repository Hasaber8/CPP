#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	string J,S;
	cin>>t;
	while(t--)
	{
	    int count=0;
		cin>>J;
		cin>>S;
		for(int i=0;i<S.size();i++)
		{
			for(int j=0;j<J.size();j++)
			{
				if(S[i]==J[j])
				{
					count++;
					break;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}