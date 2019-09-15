// 984. String Without AAA or BBB
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string ret;
        while(A>0 && B>0) {
            if(A>B) {
                ret+= "aab";
                A-=2;
                --B;
            } else if (A<B) {
                ret+="abb";
                --A;
                B-=2;
            } else {
                ret += "ab";
                --A;
                --B;
            }
        }
        
        while(A--) {
            ret += "a";
        }
        while(B--) {
            ret= "b" + ret;
        }
        
        return ret;
    }
};
