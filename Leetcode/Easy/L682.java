public int calPoints(String[] ops) {
                if (ops == null || ops.length == 0)
            return 0;

        Stack<Integer> st = new Stack<>();
        for (String s: ops) {
            if (s.equals("C")) {
                if (!st.isEmpty())
                    st.pop();
            } else if (s.equals("D")) {
                if (!st.isEmpty()) {
                    int top = st.peek();
                    st.push(2*top);
                }
            } else if (s.equals("+")) {
                int a = 0, b = 0, sum = 0;
                if (!st.isEmpty()) 
                    a = st.pop();
                if (!st.isEmpty())
                    b = st.pop();
                sum = a+b;
                st.push(b);
                st.push(a);
                st.push(sum);
            } else {
                st.push(Integer.valueOf(s));
            }
        }
        
        int tot = 0;
        while (!st.isEmpty()) {
            tot += st.pop();
        }
        
        return tot;
    }
