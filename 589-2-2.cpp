#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

#define MIN(x,y) (x)<(y)?(x):(y)

const int MAX = 55;
class GearsDiv2
{
	public:		
		int dp[MAX][2];
		bool first[MAX][2]; 
		int getmin(string Directions)
		{
			memset(dp,0,sizeof(dp));
			memset(first,0,sizeof(first));
			
			int n = Directions.length();
			
			dp[0][0] = 1;
			dp[0][1] = 0;
			first[0][0] = 1;
			first[0][1] = 0;
			for(int i=1; i<n; i++)
			{
				if(dp[i-1][0] < dp[i-1][1])
				{
					dp[i][0] = dp[i-1][0]+1;
					first[i][0] = first[i-1][0];
				}
				else if(dp[i-1][0] > dp[i-1][1])
				{				
					dp[i][0] = dp[i-1][1]+1;
					first[i][0] = first[i-1][1];
				}
				else 
				{
					dp[i][0] = dp[i-1][1]+1;
					first[i][0] = first[i-1][1] | first[i-1][0];
				}
				
				if(Directions[i]!=Directions[i-1])
				{
					dp[i][1] = dp[i][0] - 1;
					first[i][1] = first[i][0];
				}
				else
				{
					dp[i][1] = dp[i-1][0];
					first[i][1] = first[i-1][0];
				}
			}
			if(n>2)
			{
				if(Directions[n-1]==Directions[0] && !first[n-1][1])
				{
					dp[n-1][1]++;
				}
			}
			
			return MIN(dp[n-1][0],dp[n-1][1]);
		}
};

int main()
{
	GearsDiv2 t;
	string d = "LRLRL";
	
	cout << t.getmin(d) << endl;
}
