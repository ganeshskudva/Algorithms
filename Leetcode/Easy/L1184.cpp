// 1184. Distance Between Bus Stops
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start == destination) return 0;              /* shortest distance between the same node is 0. Can save runtime */
        int path1 = 0, path2 = 0, n = distance.size();  /* initialize the distance for both paths to 0 */
        for(int i = start; i != destination; i = (i+1)%n) /* use i = (i+1)%n to iterate and travel back to the start of the vector safely */
            path1 += distance[i];                         /* add the sub-distances between adjacent nodes */
        for(int i = destination; i != start; i = (i+1)%n)
            path2 += distance[i];
        return min(path1, path2); /* return the shortest pathway distance between the nodes */
    }
};
