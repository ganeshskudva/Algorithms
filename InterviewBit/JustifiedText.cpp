//https://www.interviewbit.com/problems/justified-text/

vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> result;
    short int k = 0, ls = 0;
    for (short int i = 0; i<A.size(); i+=k)
    {
        /*string line = "";
        short int start = i;
        bool flag = false;*/
        
        k = ls = 0;
        while (i+k<A.size() && ls + k + A[i+k].size() <= B)
        {
            ls += A[i+k].size();
            ++k;
        }
        string tmp = A[i];
        for (int j = 0; j < k - 1; j++) {
            if (i + k >= A.size()) tmp += " ";
            else tmp += string((B - ls) / (k - 1) + (j < (B - ls) % (k - 1)), ' ');
            tmp += A[i+j+1];
        }
        tmp += string(B - tmp.size(), ' ');
        
        /*if (i+k==A.size())
        {
            flag = true;
            --i;
        }
            
        short int noOfGaps = i+k-1 - start; //auto noOfWords = (i+1)-start; auto noOfGaps = noOfWords-1; 
        short int spaces = B - ls;
        //int extraSpaces = spaces%noOfGaps;
        //int evenSpaces = spaces/noOfGaps;
        
        for (short int j = start; j <= i+k; ++j)
        {
            while (line.length() != B)
            {
                line += A[j];
                if (!flag) //middle lines
                {
                    if (j==start)
                        line += string((spaces/noOfGaps)+(spaces%noOfGaps), ' ');
                    else if (line.length() != B)
                        line += string((spaces/noOfGaps), ' ');
                }
                else
                {
                    line += " ";
                    if (j==i+k)
                        line += string(B-line.length(), ' ');
                }
            }
        }*/
        result.emplace_back(tmp);
    }
    return result;
}
