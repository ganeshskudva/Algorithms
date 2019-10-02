// 346. Moving Average from Data Stream
class MovingAverage {
    /** Initialize your data structure here. */
    private int size;
    private ArrayList<Integer> array;
    private int sum;
    
    public MovingAverage(int size) {
        this.size = size;
        this.array = new ArrayList<>();
        this.sum = 0;
    }
    
    public double next(int val) {
        this.sum += val;
        this.array.add(val);
        if(this.array.size() > this.size){
            this.sum -= this.array.remove(0);
        }
        return (1.0 * this.sum) / this.array.size();
    }
}
