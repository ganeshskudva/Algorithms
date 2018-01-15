bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    map<int,int> mp;
    map<int,int>::iterator itr;
    
    for(int i=0;i<arrive.size();i++)
    {
        int a = arrive[i];
        int b = depart[i];
        if(mp.find(a) != mp.end())
        {
            mp[a]++;
        }
        else
        {
            mp.insert(make_pair(a,1));
        }
        if(mp.find(b) != mp.end())
        {
            mp[b]--;
        }
        else
        {
           mp.insert(make_pair(b,-1)); 
        }
    }
    
    
    
    itr = mp.begin();
    
    int s=0;
    while(itr != mp.end())
    {
        s+=itr->second;
        if(s>K)
        {
            return 0;
        }
        itr++;
    }
    return 1;
}
