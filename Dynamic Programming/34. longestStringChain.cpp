class Solution
{
public:
    static bool cmp(string &x, string &y)
    {
        return x.length() < y.length();
    }
    int check(string &x, string &y)
    {
        int i = 0, j = 0;
        int count = 0;
        while (i < x.length() && j < y.length())
        {
            if (x[i] != y[j])
            {
                count++;
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }
        // cout << y << " " << x << " " << count << endl;
        return count <= 1;
    }
    int longestChain(int n, vector<string> &words)
    {
        // Code here
        sort(words.begin(), words.end(), cmp);
        int ans = 0;
        vector<int> lsc(n, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (1 + words[j].length() == words[i].length() && (check(words[i], words[j]) == 1))
                {
                    lsc[i] = max(lsc[i], 1 + lsc[j]);
                }
            }
            ans = max(lsc[i], ans);
        }
        return ans;
    }
};