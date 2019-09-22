// 1197. Minimum Knight Moves
class Solution {
public:
    int minKnightMoves(int x2, int y2)
{
    long long int x1 = 0, y1 = 0;
    long long int dx = abs(x2 - x1);
    long long int dy = abs(y2 - y1);
    long long int lb = (dx + 1) / 2;
    lb = max(lb, (dy + 1) / 2);
    lb = max(lb, (dx + dy + 2) / 3);
    while ((lb % 2) != (dx + dy) % 2)
        lb++;
    if (abs(dx) == 1 && dy == 0)
        return 3;
    if (abs(dy) == 1 && dx == 0)
        return 3;
    if (abs(dx) == 2 && abs(dy) == 2)
        return 4;
    return (int)lb;
}
};
