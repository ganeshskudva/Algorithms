class Solution {
public:
bool canConstruct(string ransomNote, string magazine) {
        
        //use record array with 26 positions to record how many times each character appears
        vector<int> record(26,0);
        for(int i=0; i<magazine.size(); i++)
        {
            //use index to caculate the corresponding index for each character in magazine array
            int index = magazine[i]-'a';
            record[index]++;
        }
        
        for(int i=0; i<ransomNote.size(); i++)
        {
            int index = ransomNote[i]-'a';
            record[index]--;
            //If the value in this position became -1, it means it have been overused, return false directly. 
            if(record[index] < 0)
                return false;
        }
        
        return true;
    }
};
