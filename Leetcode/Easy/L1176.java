class Solution {
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        if(k > calories.length)
            return 0;
        int points = 0, sumCal = 0;
        for(int j = 0; j < calories.length; j++) {
            sumCal += calories[j];
            if(j >= k-1) {
                if(j > k-1) {
                    sumCal -= calories[j - k];
                }
                points += sumCal < lower ? -1 : 
                          ((sumCal > upper) ? 1 : 0);    
            }
        }
        return points;
    }
}
