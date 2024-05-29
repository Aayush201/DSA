class Solution
{
public:
    bool lemonadeChange(int N, vector<int> &bills)
    {
        // code here
        int five = 0, ten = 0;
        for (auto x : bills)
        {
            if (x == 5)
                five++;
            else if (x == 10)
            {
                if (five > 0)
                {
                    five--;
                    ten++;
                }
                else
                    return false;
            }
            else
            {
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                }
                else if (five > 3)
                    five -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};3.