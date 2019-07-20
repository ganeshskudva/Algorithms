// 1090. Largest Values From Labels
class Solution {
public:    
    struct valueLabelPair
    {
        int value;
        int label;
        valueLabelPair(int val, int lab) : value(val), label(lab) {}
    };    
    
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int answer = 0;
        vector<valueLabelPair> myItems;
        
        for (int i = 0; i < values.size(); ++i)
            myItems.push_back(valueLabelPair(values[i], labels[i]));
        
        sort(myItems.begin(), myItems.end(), [](valueLabelPair& a, valueLabelPair& b) 
             { return a.value > b.value;});
        
        int numUsed = 0;
        int numTimesUsed[20001] {};    // Record how many times we've used each label
        for (int i = 0; i < myItems.size(); ++i)
        {
            valueLabelPair currentPair = myItems[i];
            if (numTimesUsed[currentPair.label] >= use_limit)
                continue;           
            
            answer += currentPair.value;
            numTimesUsed[currentPair.label] += 1;
            numUsed += 1;
            if (numUsed >= num_wanted)
                break;            
        }
        return answer;
    }
};
