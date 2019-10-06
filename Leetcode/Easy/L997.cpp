// 997. Find the Town Judge
class Solution {
public:
int findJudge(int N, vector<vector<int>>& trust) {
		// Make sure they are allocated to 0
        std::vector<int> outgoing_edges(N, 0);
        std::vector<int> incoming_edges(N, 0);
        
		// Save off the number of incoming and outgoing edges for each person
        for(const auto& p : trust){
            ++(outgoing_edges[p[0] - 1]);
            ++(incoming_edges[p[1] - 1]);
        }
        
		// Initialize judge to -1 for the case where no one meets the 
		// 0 outgoing edges and N - 1 incoming edges criteria
        int judge = -1;
		
		// Loop through each person and look for the correct criteria
        for(int i = 0; i < N; ++i){
			// Check for 0 outgoing edges and N - 1 incoming edges
            if(outgoing_edges[i] == 0 && incoming_edges[i] == N - 1){
				// If this is hit, we've found a second person meeting this criteria
                if(judge != -1){
                    return -1;
                }
                judge = i + 1;
            }
        }
        
        return judge;
    }
};
