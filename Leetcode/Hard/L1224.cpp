// 1224. Maximum Equal Frequency
class Solution {
public:
int maxEqualFreq(vector<int>& nums) {
	unordered_map<int, int> countMap;
	unordered_map<int, int> freqMap;
	int res = 0;
	for (int i = 0; i < nums.size(); i++) {
		// update counts
		countMap[nums[i]]++;
		int freq = countMap[nums[i]];
		// update counts with that frequency
		freqMap[freq]++;

		int count = freqMap[freq] * freq;
		if (count == i + 1 && i != nums.size() - 1) { // case 1
			res = max(res, i + 2);
		} else if (count == i) { // case 2
			res = max(res, i + 1);
		}
	}
	return res;
}
};
