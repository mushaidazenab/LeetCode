class Solution {
public:
vector<int> plusOne(vector<int> &digits)
{
    // reversing the array
    int left = 0;
    int right = digits.size() - 1;

    while (left < right)
    {
        swap(digits[left], digits[right]);
        left++;
        right--;
    }
    int carry = 1;
    int i = 0; // index

    while (carry)
    {
        if (i < digits.size())
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i] += 1;
                carry = 0;
            }
        }
        else
        {
            digits.push_back(1);
            carry = 0;
        }
        i++;
    }
    reverse(digits.begin(), digits.end()); // built in func to reverse
    return digits;
}
};