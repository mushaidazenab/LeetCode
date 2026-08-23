class Solution {
public:
int addDigits(int num)
{
    // the trick for this probem so that it has constant time complexity is
    // dividing num by 9
    // notice that for all num < 9; num % 9 is num itself
    // now for num > 9, num % 9  is always equal to the sum of its digits
    // edge cases: '9' and '0'
    // 9 % 9 = 0 => we'd want to return 9
    // 0 % 9 = 0 => we'd want to return 0

    if (num == 0)
        return 0;
    if (num % 9 == 0)
    {
        return 9;
    }
    return num % 9;
}
};