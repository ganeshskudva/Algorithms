// 657. Robot Return to Origin
class Solution {
public:
    bool judgeCircle(string moves) {
        int right = 0, up = 0;
        
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'R')
                right++;
            else if (moves[i] == 'L')
                right--;
            else if (moves[i] == 'U')
                up++;
            else if (moves[i] == 'D')
                up--;
        }
        
        if (!right && !up)
            return true;
        else 
            return false;
    }
};
