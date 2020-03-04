class Solution {
public List<List<String>> accountsMerge(List<List<String>> accounts) {
            List<List<String>> result = new ArrayList<>();
            if(accounts==null || accounts.size()==0)
                return result;

            Map<String, String> names = new HashMap<String, String>(); //email - username
            Map<String, Set<String>> map = new HashMap<String, Set<String>>(); //email - neighbors
            Set<String> emails = new HashSet<String>();

            for(List<String> list : accounts){
                String name = list.get(0);
                for(int i=1; i<list.size(); i++){
                    String email = list.get(i);
                    emails.add( email );
                    names.put( email, name );
                    map.putIfAbsent( email, new HashSet<String>() );

                    if(i==1)
                        continue;

                    //build the "edge" between two adjacent email-nodes
                    map.get( list.get(i-1) ).add( email );
                    map.get( email ).add( list.get(i-1) );
                }
            }

            Set<String> seen = new HashSet();
            List<List<String>> ans = new ArrayList();
            for (String email: map.keySet()) {
                if (!seen.contains(email)) {
                    seen.add(email);
                    Stack<String> stack = new Stack();
                    stack.push(email);
                    List<String> component = new ArrayList();
                    while (!stack.empty()) {
                        String node = stack.pop();
                        component.add(node);
                        for (String nei: map.get(node)) {
                            if (!seen.contains(nei)) {
                                seen.add(nei);
                                stack.push(nei);
                            }
                        }
                    }
                    Collections.sort(component);
                    component.add(0, names.get(email));
                    ans.add(component);
                }
            }

            return ans;
        }
}
