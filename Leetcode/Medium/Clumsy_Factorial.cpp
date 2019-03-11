/*
* AUTHOR: Ganesh S Kudva
* https://leetcode.com/problems/clumsy-factorial/submissions/
*/

class Solution {
public:
    int clumsy(int N) {
        int sign = 1;
        int i = N; 
        int sum = 0;
        while(i > 0) {
            int prod = i--;
            if (i > 0) {
                prod *= i--;
                
                if (i > 0) {
                    prod = floor(double(prod)/i--);
                }
            }
            
            sum += sign * prod;
            sign = -1;
            
            if (i > 0) {
                sum += i--;
            }
        }
        
        return sum;
    }
};
