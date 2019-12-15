// 1288. Remove Covered Intervals
class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
                if(intervals.length == 0 || intervals == null) return 0;

        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        /*
        int size = intervals.length;
        */
        int start = intervals[0][0];
        int end = intervals[0][1];


        int count = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] <= end && intervals[i][1] <= end) {
                if (start <= intervals[i][0]) {
/*
                    System.out.println("\n[" + start + "," + end + "]");
                    System.out.println("[" + intervals[i][0] + "," + intervals[i][1] + "]\n");
                    */
                    count++;
                }
            } else {
                start = intervals[i][0];
                end = intervals[i][1];
            }

        }
        return intervals.length - count;
    }
}
