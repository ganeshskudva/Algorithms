// 263. Ugly Number
class Solution {
public:
bool isUgly(int no) 
{ 
	if(no<=0) return 0;
    if(no%2==0) no /= no & (~(no-1));  // Dividing no by the highest number (that's a power of 2) that is divisible.
    while(no%3==0) // For divisiblity by 3.
        no/=3;
    while(no%5==0) // For divisiblity by 5.
        no/=5;
    return no==1;
}
};
