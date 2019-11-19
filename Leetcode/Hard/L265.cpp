class Solution {
public:
   // 265. Paint House II
   int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        
        int n = costs.size();
        int k = costs[0].size();
        
        //min 1 and min2 is used to maintain the MINIMUM COLOUR COSTS OF PAINTING "THE LAST HOUSE"
        //min1 is the smallest and min2 little bigger. eg min1 = 1, min2  = 3
        //index1 is used to maintain the index of min1 COLOUR COST OF "LAST HOUSE"
        //so that if you get a minimum cost at same index as previous (same colour) then you just add the min2 instead
        int min1 = 0, min2 = 0, index1 = -1;

        for (int i = 0; i < n; i++) 
        {
            //m1 and m2 used to maintain minimum costs of current house
            //idx1 is index of m1 of the current house
            int m1 = INT_MAX, m2 = INT_MAX, idx1 = -1;

            for (int j = 0; j < k; j++) 
            {
                int cost = costs[i][j] + (j != index1 ? min1 : min2); //just check by index if not same colour

                 if (cost < m1)  // cost < m1 < m2
                 {           
                    m2 = m1; m1 = cost; idx1 = j; 
                 }
                else if (cost < m2)  // m1 < cost < m2
                {   
                    m2 = cost;
                }
            }//j

            //Update the global min1,min2 so that the current can become previous for next
            min1 = m1; min2 = m2; index1 = idx1;
        }//i
        
        return min1;
    }
};
