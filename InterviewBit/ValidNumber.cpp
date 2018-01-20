//https://www.interviewbit.com/problems/valid-number/

int Solution::isNumber(const string A) {
    
    int i = 0;
    int n = A.length();
    while (A[i]==' ') { ++i; }
    if(i==n)
        return 0;
        
    if ((A[i]=='-' || A[i]=='+') && ((A[i+1]>='0' && A[i+1]<='9') || A[i+1]=='.'))
        i+=2;
    else if (A[i]=='e')
        return 0;
    
    bool eflag = false;
    
    while (i<n)
    {
        if(A[i]=='.')
        {
            if(eflag)
                return 0;
            else if(A[i+1]>='0' && A[i+1]<='9')
                i+=2;
            else
                return 0;
        }
        else if (A[i]=='e')
        {
            if(eflag)
                return 0;
            eflag = true;
            if ((A[i+1]=='-' || A[i+1]=='+') && (A[i+2]>='0' && A[i+2]<='9'))
                i+=3;
            else if (A[i+1]>='0' && A[i+1]<='9')
                i+=2;
            else
                return 0;
        }
        else if (A[i]>='0' && A[i]<='9')
            ++i;
        else if (A[i]==' ')
        {
            ++i;
            while (A[i]==' ') { ++i; }
            if(i==n)
                return 1;
        }
        else
            return 0;
    }
    return 1;
}
