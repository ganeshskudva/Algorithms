// 557. Reverse Words in a String III
class Solution {
public:
  string reverseWords(string s) {
    vector<string> fullStr;
    vector<char> charVec;
    string opStr;
    for (size_t i = 0; i < s.size(); i++)
    {
      if (s[i] == ' ')
      {
        while(!charVec.empty())
        {
          opStr += charVec.back();
          charVec.pop_back();
        }
        opStr += ' ';
      }
      else
      {
        charVec.push_back(s[i]);
      }
    }
    while (!charVec.empty())
    {
      opStr += charVec.back();
      charVec.pop_back();
    }
    return opStr;
  }
};
