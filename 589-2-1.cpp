#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 55;
class GooseTattarrattatDiv2
{
	public:		
		int cnt[MAX];
		int getmin(string S)
		{
			memset(cnt,0,sizeof(cnt));
			int n=S.length();
			
			int ans = 0;
			for(int i=0; i<n; i++)
			{
				cnt[S[i]-'a']++;
				if(cnt[S[i]-'a'] > ans)
					ans = cnt[S[i]-'a'];
			}
			return n-ans;
		}
};

int main()
{
	
}
