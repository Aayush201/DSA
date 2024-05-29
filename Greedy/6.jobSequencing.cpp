/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job &a, Job &b)
    {
        if (a.profit > b.profit)
            return true;
        return false;
    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        sort(arr, arr + n, cmp);
        int count = 0, profitEarned = 0;
        vector<int> deadlines(1e5 + 1, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j >= 1; j--)
            {
                if (deadlines[j] == -1)
                {
                    profitEarned += arr[i].profit;
                    count++;
                    deadlines[j] = 1;
                    break;
                }
            }
        }
        return {count, profitEarned};
    }
};