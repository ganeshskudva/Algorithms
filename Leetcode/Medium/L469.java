public boolean isConvex(List<List<Integer>> points) {
        int flag = 0;
        for (int i = 0; i < points.size(); i++) {
            int angle = getAngle(points, i);
            if (angle == 0) continue;
            if (flag == 0) flag = angle > 0 ? 1 : -1;
            else if (flag > 0 != angle > 0) return false;
        }
        return true;
    }
    
    private int getAngle(List<List<Integer>> points, int i) {
        List<Integer> c = points.get(i % points.size());
        List<Integer> b = points.get((i + 1) % points.size());
        List<Integer> a = points.get((i + 2) % points.size());
        return (a.get(1) - b.get(1)) * (b.get(0) - c.get(0)) - (b.get(1) - c.get(1)) * (a.get(0) - b.get(0));
    }
