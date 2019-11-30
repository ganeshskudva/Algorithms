// 151. Reverse Words in a String
class Solution {
public String reverseWords(String s) {
        if (s.length() < 1) return s; // empty string
        int startIdx = 0;
        char[] str = s.toCharArray();
        // reverse whole string
        reverse(str, 0, str.length - 1);
        // reverse word one by one
        for (int i = 0; i < str.length; i++) {
            if (str[i] != ' ') {
                if (startIdx != 0) str[startIdx++] = ' ';
                int j = i;
                while (j < str.length && str[j] != ' ')
                    str[startIdx++] = str[j++];
                reverse(str, startIdx - (j - i), startIdx - 1); // startIdx - 1, NOT startIdx; 
                // C++ std::reverse : Reverses the order of the elements in the range [first, last)
                i = j;
            }
        }
        return new String(str, 0, startIdx);
    }

    private void reverse(char[] str, int begin, int end) {
        for (; begin < end; begin++, end--) {
            char tmp = str[begin];
            str[begin] = str[end];
            str[end] = tmp;
        }
    }
}
