// 1031. Maximum Sum of Two Non-Overlapping Subarrays
class Solution {
public:   
    int maxSumTwoNoOverlap(vector<int>& ar, int l, int m) {
    vector<int> zarray;
	int sum=0;
	for(int x:ar)
	{
		sum+=x;
		zarray.push_back(sum);				//making z-array
	}
		/*
			 or i can simple use partial_sum to make zarray as follow-
			 partial_sum(ar.begin(),ar.end(),zarray.begin());
		*/
	
	int lmax,mmax,res;
	res = zarray[m+l-1];					// first ans will be 0 - l and l+1 to m+l-1 or 0 - m and m+1 to m+l -1 as for the first ans order doesn't matter 
	lmax = zarray[l-1];						// lmax if we start with 0th element
	mmax = zarray[m-1];						// mmax if we start with 0th element
	for(int i =l+m;i<zarray.size();i++)
	{
		lmax = max(lmax,zarray[i-m]- zarray[i-m-l]);// finding lmax (comparing lmax with lmax(1,2,3,4) i,e,. with lmax value if we start with 1th ,2nd..element 
		mmax = max(mmax,zarray[i-l]-zarray[i-m-l]);//doing same as above
		res = max (res,max(lmax + zarray[i]-zarray[i-m],mmax + zarray[i]-zarray[i-l]));	// comparing res(max value) with result obtain when 
																						//"l is before m" and result obtain when "m is before l"
														//i,e,.  in other word we assume "m's subarray" to be at end of resultant subarray and choose lmax then find the resultant sum
														// then do the same with assuming "l's subarray" at the end.. and finally compare these two results with the current max res.

	}
	return res;
    }
};
