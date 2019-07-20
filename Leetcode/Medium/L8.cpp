// 8. String to Integer (atoi)
class Solution {
public:
    int myAtoi(string str) {
      long result = 0;      
      int sign = 1;
      bool readingNums = false;
      for(int i=0;i<str.size();++i)
      {
        if(str[i] >= '0' && str[i] <='9') {
          readingNums = true;
          result *=10;
          if(result < INT_MAX)
            result += (str[i] - '0');
          else {
            if(sign == -1)
              return INT_MIN;
            return INT_MAX;
          }   
        } else if(str[i] == '-' && !readingNums){
          if(!readingNums)
            sign = -1;
          else
            return result*sign;          
          readingNums = true;
        } else if(str[i] == '+' && !readingNums){
          if(!readingNums)
            sign = 1;
          else
            return result*sign;  
          readingNums = true;
        } else if(str[i] == ' ') {
          if(readingNums)
            return result*sign;
        } else {
          if(!readingNums)
            return 0;
          else
            return result*sign;
        }
      }
      
      result *=sign;
      if(result > INT_MAX)
        return INT_MAX;
      else if(result < INT_MIN)
        return INT_MIN;
      
      return result;
    }
};
