#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

#define MIN(x,y) ((x)<(y)?(x):(y))

const int MAX = 2505;
class FlippingBitsDiv2
{
	public:
		int getmin(vector <string> S, int M)
		{
			int n = 0;
			string str = "";
			
			for(int i=0;i<S.size();i++)
			{
				str += S[i];
			}
			n = str.length();
			
			int dp[MAX][2];
			int cnt[MAX][2];
			int flag[MAX]; 
			
			memset(dp,0,sizeof(dp));
			memset(cnt,0,sizeof(cnt));
			memset(flag,0,sizeof(flag));
			
			for(int i=0; i<n/M; i++)
			{
				for(int j=0; j<M; j++)
				{
					if(str[i*M+j] == '0') cnt[i][1]++;
					else cnt[i][0]++;
				}
			}
			
			dp[0][0] = cnt[0][0]+1;
			flag[0] = 1;
			dp[0][1] = cnt[0][1];			
			
			for(int i=1; i<n/M; i++)
			{				
				dp[i][0] = cnt[i][0]+MIN(dp[i-1][0],dp[i-1][1]+2);
				dp[i][1] = cnt[i][1]+MIN(dp[i-1][1],dp[i-1][0]);
				
				if(dp[i-1][0] < dp[i-1][1]+2) flag[i] = flag[i-1];
			}
			if(flag[n/M-1] == 0)
				dp[n/M-1][0]--;
			/*
			for(int i=0; i<2; i++)
			{
				for(int j=0; j<n/M; j++)
					cout<<dp[j][i]<<" ";
				cout<<endl;
			}*/
			
			return MIN(dp[n/M-1][0],dp[n/M-1][1]);
		}
};

int main()
{
	vector<string> s;
	s.push_back("00111000");
	
	FlippingBitsDiv2 t;
	cout << t.getmin(s,2) << endl;
}
