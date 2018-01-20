int stringnumber(string s){
  int i=0;
  int n=s.length();
  int face=1;
  int answer=0;
  for(i=n-1;i>=0;i--){
    answer+=(s[i]-'0')*face;
    face*=10;
  }
  return answer;
}
bool  isValid(string s){
    int i,j;
    int n=s.length();
    int number;
    int start=0;
    string temp="";
    while(start < n){
        i=start;
        temp="";
        while(i<n && s[i]!='.')i++;
        if(i-start >3 ||i-start==0)
            return false;
        for(j=start;j<i;j++)
            temp+=s[j];
        number=stringnumber(temp);
        if(number > 255)
            return false;
        if(number == 0 && i-start >1)
            return false;
        if(i-start > 1 && s[start]=='0')
            return false;
        start=i+1;
    }
    return true;
}
string copyString(string s,int i,int j,int k){
    string x;
    for(int l=0;l<s.length();l++){
        if(l==i)
            x+='.';
        if(l==j)
            x+='.';
        if(l==k)
            x+='.';
        x+=s[l];
    }
    return x;
}
vector<string> Solution::restoreIpAddresses(string A) {
    vector <string> B;
    int i,j,k;
    string s;
    int l=A.length();
    for(i=0;i<l-1;i++)
        for(j=i+1;j<l-1;j++)
            for(k=j+1;k<l-1;k++){
                s=copyString(A,i+1,j+1,k+1);
                if(isValid(s))
                    B.push_back(s);
            }
    return B;
}
