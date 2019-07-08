// 1021. Remove Outermost Parentheses
class Solution {
public:
	string removeOuterParentheses(string S) {
		auto splited = splitToPrimitive(S);

		string ret;
		for (const auto& primitive : splited)
			if (primitive.size()>2)
				ret.append(primitive.substr(1, primitive.size()-2));

		return ret;
	}

	vector<string> splitToPrimitive(const string& S) {
		vector<string> ret;
		int open = 0, psize = 0;

		for (size_t pos = 0, start = 0; pos<S.size(); ++pos) {
			if (S[pos] == '(')
				++open;
			else
				--open;

			++psize;
			if (open == 0) {
				ret.push_back(S.substr(start, psize));
				start = pos+1;
				psize = 0;
			}
		}

		return ret;
	}
};
