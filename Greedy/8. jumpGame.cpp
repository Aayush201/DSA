class Solution
{
public:
    int canReach(int A[], int N)
    {
        // code here
        int maxReach = 0;
        for (int i = 0; i < N; i++)
        {
            maxReach = max(maxReach, i + A[i]);
            if (maxReach >= N - 1)
                return true;
            else if (i >= maxReach && A[i] == 0)
                return false;
        }
        return true;
    }
};