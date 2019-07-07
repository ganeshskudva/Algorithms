// 849. Maximize Distance to Closest Person
class Solution {
public:
int maxDistToClosest(vector<int>& seats) {
        int p1=0,p2=0;
        int Max=INT_MIN;
        for(int i=0;i<seats.size();++i){
            if(seats[i]==1){
                p2=i;
                p1=p2;
            }else{
                p2++;
            }
            if(seats[p1]==0 || (seats[p2]==0 && i==seats.size()-1))
            Max=max(Max,p2-p1);
            else if(seats[p2]==0)
            Max=max(Max,(p2-p1)/2+(p2-p1)%2);
            
        }
        return Max;
    }
};
