// 1119. Remove Vowels from a String
class Solution {
public:
string removeVowels(string s)
{
	string ret = "";
	int size = s.size();
	unordered_set<char> contains;
	contains.insert('a');
	contains.insert('e');
	contains.insert('i');
	contains.insert('o');
	contains.insert('u');

	for (int i = 0; i < size; i++) {
		if (contains.count(s[i]) == 0) {
			if (ret.empty()) {
				ret = s[i];
			} else {
				ret += s[i];
			}
		}
	}

	return ret;
}
};
