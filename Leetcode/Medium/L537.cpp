// 537. Complex Number Multiplication
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int i=0;
        int j=0;
        while(1){
            if(a[i]=='+'){
                break;
            }
            i++;
        }
        j=i;
        int count=0;
        while(1){
            if(a[j]=='i'){
                break;
            }
            j++;
            count++;
        }
    
        int A = stoi(a.substr(0, i));
        int B = stoi(a.substr(i+1,count-1));
        
        i=0;
        j=0;
        while(1){
            if(b[i]=='+'){
                break;
            }
            i++;
        }
        j=i;
        count=0;
        while(1){
            if(b[j]=='i'){
                break;
            }
            j++;
            count++;
        }
        
        int C = stoi(b.substr(0, i));
        int D = stoi(b.substr(i+1,count-1));
        
        int x = A*C-B*D;
        int y = A*D+B*C;
        
        
        
        
        return to_string(x)+"+"+to_string(y)+"i";
        
        
    }
};
