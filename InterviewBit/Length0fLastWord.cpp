/*https://www.interviewbit.com/problems/length-of-last-word/*/

int Solution::lengthOfLastWord(const string A) {
        int n=A.length();
    int i;
    int current_length=0;
    int last_length=0;
    for(i=0;i<n;i++){
        if(A[i]!=' ')
            current_length++;
        else if(A[i]==' '){
            if(current_length >0)
                last_length=current_length;
            current_length=0;
        }
    }
    if(current_length >0)
        last_length=current_length;
    return last_length;
}
