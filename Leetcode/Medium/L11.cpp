// 11. Container With Most Water
int max_area(std::vector<int>& height) {    // O(N) time complexity

    int max = 0, l = 0, r = height.size() - 1;

    while (l < r) {
        int current = std::min(height[l], height[r]) * (r - l);
        max = std::max(max, current);

        if (height[l] < height[r]) l++;
        else r--;
    }

    return max;
}
