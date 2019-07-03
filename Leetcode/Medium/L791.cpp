// 791. Custom Sort String

static auto fast=[]{ios_base::sync_with_stdio(false); cin.tie(nullptr);return 0;}();
int cust_val[26];
struct custom_sort
{
    inline bool operator()(const char a,const char b)
    {
        return cust_val[a-'a']<cust_val[b-'a'];
    }
};
class Solution 
{
public:
    string customSortString(string s, string t) 
    {
        memset(cust_val,0,26);
        int val=1;
        for(int i=0;i<s.size();i++)
            cust_val[s[i]-'a']=val++;
        sort(t.begin(),t.end(),custom_sort());
        return t;
    }
};
