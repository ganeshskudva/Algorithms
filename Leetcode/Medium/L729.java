class MyCalendar {

        class Pair {
            int start;
            int end;

            Pair(int st, int end) {
                this.start = st;
                this.end = end;
            }
        }

        List<Pair> lst;

        public MyCalendar() {
            lst = new ArrayList<>();
        }

        public boolean book(int start, int end) {
            for (Pair p: lst) {
                if (p.start < end && start < p.end) 
                    return false;

                
            }

            lst.add(new Pair(start, end));
            
            return true;
        }
    }
