// 155. Min Stack
class MinStack {
    
    private int minVal;
        private List<Integer> lst;
        /** initialize your data structure here. */
        public MinStack() {
            minVal = Integer.MAX_VALUE;
            lst = new ArrayList<Integer>();
        }

        public void push(int x) {
            if (x < minVal)
                minVal = x;
            lst.add(x);
        }

        public void pop() {
            if (lst.get(lst.size() -1) == minVal) {
                minVal = Integer.MAX_VALUE;
            }
            lst.remove(lst.size() - 1);

            if (minVal == Integer.MAX_VALUE)
                calMin();
        }

        private void calMin() {
            for (int itm: lst) {
                if (itm < minVal)
                    minVal = itm;
            }
        }

        public int top() {

            return lst.get(lst.size() - 1);
        }

        public int getMin() {
            /*
            int i, ret = minVal;

            for (i = 0; i < lst.size(); i++) {
                if (lst.get(i) == minVal)
                    lst.remove(i);
            }
            minVal = Integer.MAX_VALUE;
            calMin();
            */
            return minVal;
        }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
