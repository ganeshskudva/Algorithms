class Solution {
public:
    bool check(vector<int>& v, int m, int k,int mid)
	{
		int tot=0,c=0;
		for(int i=0;i<v.size();i++)
		{
			if(v[i]<=mid)
			{
				c++;
				if(c==k)
				{
					tot++;
					c=0;
				}
			}
			else c=0;
		}
		if(tot>=m)return true;
		return false;
	}
	int minDays(vector<int>& bloomDay, int m, int k)
	{
		int s=0,e=INT_MAX-1;
		int ans=-1;
		while(s<=e)
		{
			int mid=s+(e-s)/2;
			if(check(bloomDay,m,k,mid))
			{
				ans=mid;
				e=mid-1;
			}
			else
			{
				s=mid+1;
			}
		}
		return ans;
	}
};
