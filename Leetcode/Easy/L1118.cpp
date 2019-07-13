// 1118. Number of Days in a Month
class Solution {
public:
bool checkYear(int year)
{
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0)
        return false;

    if (year % 4 == 0)
        return true;
    return false;
}

int numberOfDays(int Y, int M)
{
    vector<int> vec = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (checkYear(Y) && M == 2) 
        return 29;
    else 
        return vec[M-1];
}
};
