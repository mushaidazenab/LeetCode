class Solution {
public:
int addDigits(int num)
{
    // recursive soln
    if (num <= 9)
        return num;
    int total = 0;
    while (num != 0)
    {
        total += num % 10;
        num /= 10;
    }
    return addDigits(total);
}
};
