class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0)
            return false;
        for (int[] m: matrix) {
            if (m[0] <=  target && target <= m[m.length-1])
                return binSearch(m, 0, m.length, target);
        }



        return false;
    }
    
    private boolean binSearch(int[] arr, int low, int high, int target) {
        int mid;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (target == arr[mid])
                return true;
            else {
                if (target < arr[mid]) {
                    high = mid -1;
                } else {
                    low = mid +1;
                }
            }
        }
        
        return false;
    }
}
