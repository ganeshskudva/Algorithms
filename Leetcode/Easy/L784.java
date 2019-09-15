// 784. Letter Case Permutation
class Solution {
  public List<String> letterCasePermutation(String S) {
    List<String> list = new ArrayList<>();
    permutation(S, new char[S.length()], 0, list);
    return list;
  }
  private void permutation(String S, char[] result, int p, List<String> list) {
    if (p == S.length()) {
      list.add(new String(result));
      return;
    }
    char c = S.charAt(p);
    result[p] = c;
    permutation(S, result, p + 1, list);
    if (c >= 65 && c <= 90) {  // uppercase
      result[p] = (char) (c + 32);
      permutation(S, result, p + 1, list);
    }
    if (c >= 97 && c <= 122) { // lowercase
      result[p] = (char) (c - 32);
      permutation(S, result, p + 1, list);
    }
  }
}
