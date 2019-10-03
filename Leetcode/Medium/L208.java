// 208. Implement Trie (Prefix Tree)
class Trie {

    private class Node {
        char key;
        Node[] children;
        boolean isWord;

        Node(char key) {
            this.children = new Node[26];
            this.key = key;
            isWord = false;
        }
    }

    Node root;

    /** Initialize your data structure here. */
    public Trie() {
        root = new Node(' ');
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        Node curr = this.root;

        for(int i = 0; i < word.length(); ++i) {
            int nextIndex = index(word.charAt(i));
            if(curr.children[nextIndex] != null) {
                curr = curr.children[nextIndex];
            } else {
                //if letter is null, set it to not be null! fill the char
                curr.children[nextIndex] = new Node(word.charAt(i));
                //and set curr to be that next letter we just created
                curr = curr.children[nextIndex];
            }
        }
        curr.isWord = true;
    }

    public int index(char c) {
        return c - 'a';
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Node curr = root;
        for(int i = 0; i < word.length(); ++i) {
            int nextIndex = index(word.charAt(i));
            if(curr.children[nextIndex] != null) {
                curr = curr.children[nextIndex];
            } else {
                return false;
            }
        }
        if(curr.isWord)
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String word) {
        Node curr = root;
        for(int i = 0; i < word.length(); ++i) {
            int nextIndex = index(word.charAt(i));
            if(curr.children[nextIndex] != null) {
                curr = curr.children[nextIndex];
            } else {
                return false;
            }
        }
        return true;
    }
}
