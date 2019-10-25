// 1233. Remove Sub-Folders from the Filesystem
class Solution {
    public List<String> removeSubfolders(String[] folder) {
        List<String> ret = new ArrayList<String>();
        if(folder == null)
            return ret;
        Trie node = new Trie();
        for(String f : folder){
            node.add(f.split("/"), 0);
        }
        for(String f: folder) {
            if(node.check(f.split("/"),0))
                ret.add(f);
        }
        return ret;
    }
    
    class Trie {
        boolean end = false;
        HashMap<String ,Trie> next = new HashMap<String, Trie>();
        
        void add(String[] path, int pos) {
            if(pos >= path.length) {
                this.end = true;
                return;
            } else {
                if(next.containsKey(path[pos]))
                    next.get(path[pos]).add(path, pos+1);
                else {
                    Trie node = new Trie();
                    node.add(path, pos+1);
                    next.put(path[pos], node);
                }
            }
        }
            
        boolean check(String[] path, int pos){
            if(next.containsKey(path[pos]))
                if(next.get(path[pos]).end)
                    return pos == path.length - 1;
                else 
                    return next.get(path[pos]).check(path, pos + 1);
            else return false;
        }
    }
}
