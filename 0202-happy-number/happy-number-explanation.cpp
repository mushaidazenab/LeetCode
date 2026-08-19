#include <iostream>
#include <unordered_set>

using namespace std;
bool isHappy(int n)
{
    int holder;
    int sum = 0;
    unordered_set<int> seen;
    while (n != 0)
    {
        // computing sum of induvidual digits first
        holder = n % 10;
        sum += (holder * holder);
        n /= 10;
        // after the sums been calculated (i.e. n == 0)
        //  we'd want to update n to sum so that we can repaeat the process
        //  of breaking down the number to perform req. calculation
        // but before we do that, we want to makesure it's not 1
        // becuase if it is, we return true (happy no. found)
        // we notice that for non-happy numbers, a cycle is formed where eventually
        // after a certain point, the series of sum is reqpeated - so we store final
        // sum in a hashmap to make sure it doesnt appear twice - becuase if it does, that
        // means we have reached a cycle - so we return false and exit the otherwise
        // infinite loop
        if (n == 0)
        {
            if (sum == 1)
            {
                return true;
            }
            n = sum;
            if (seen.count(sum) == 1)
                return false;
            seen.insert(sum);
            sum = 0;
        }
    }
    return false;
}
int main()
{
    int h = 3;
    cout << isHappy(h);
    return 0;
}
