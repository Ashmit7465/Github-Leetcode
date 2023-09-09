class Solution
{
private:
    bool helper(unordered_map<string, int> mp, string temp, int word_len)
    {
        for (int i = 0; i < temp.length(); i += word_len)
        {
            string check = temp.substr(i, word_len);
            if (mp.find(check) != mp.end())
            {
                mp[check] -= 1;
                if (mp[check] == -1)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> res;
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++)
        {
            mp[words[i]] += 1;
        }

        // window size computation
        int k = words[0].length() * words.size();
        int n = s.length();
        int i = 0;
        int j = 0;
        while (j < n)
        {
            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                string temp = s.substr(i, j - i + 1);
                bool decision = helper(mp, temp, words[0].size());
                if (decision)
                {
                    res.push_back(i);
                }
                i++;
                j++;
            }
        }

        return res;
    }
};