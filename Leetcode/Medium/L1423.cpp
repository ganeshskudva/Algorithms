class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
               int sum=0, minSum=1e9, cur=0, l=cardPoints.size()-k;
        for(int i=0;i<cardPoints.size();i++) {
            sum+=cardPoints[i];
            cur+=cardPoints[i];
            if(i>=l) {
                cur-=cardPoints[i-l];
                minSum=min(cur, minSum);
            }
            else if(i==l-1) minSum=cur;
        }
        return sum-minSum; 
    }
};
