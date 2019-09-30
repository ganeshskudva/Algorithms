// 720. Longest Word in Dictionary
class Solution {
    
public:
    struct TrieNode{
    struct TrieNode *child[26];
    bool eow;
};
struct TrieNode *getNode(void)
{
    struct TrieNode *node = new TrieNode;
    node->eow = false;
    for(int i=0;i<26;i++)
    {
        node->child[i] = NULL;
    }
    return node;
}
bool insert(struct TrieNode *root, string word)
{
    struct TrieNode *pcrawl = root;
    int count = 0;
    for(int i=0;i<word.length();i++)
    {
        int index = word[i] - 'a';
        if(!pcrawl->eow)
            count++;
        if(!pcrawl->child[index])
        {
            pcrawl->child[index] = getNode();
        }
        pcrawl = pcrawl->child[index];
        
    }
    pcrawl->eow = true;
    if(count == 1)
        return true;
    else
        return false;
}
    string longestWord(vector<string>& words) {
        int l = words.size();
        if(l == 1)
            return words[0];
        if(l==0)
            return "";
        struct TrieNode *root = getNode();
        sort(words.begin(),words.end());
        int count = 0;
        string str = "";
        for(int i=0;i<l;i++)
        {
            bool valid = insert(root, words[i]);
            if(valid)
            {
                if(words[i].length() > str.length())
                {
                    str = words[i];
                }
            }
        }
        return str;
    }
};
