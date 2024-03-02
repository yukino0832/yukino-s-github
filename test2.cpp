#include <iostream>
#include <vector>
#include <string>

using namespace std;

class LongestIncreasingSubsequence
{
public:
    static pair<int, vector<int>> findLongestIncreasingSubsequence(const vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
        {
            return {0, {}};
        }
        int maxLength = 0;
        vector<int> lenth(len);
        vector<int> pre(len, -1);
        int i, j;
        int end = 0;
        for (i = 0; i < len; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && lenth[j] + 1 > lenth[i])
                {
                    pre[i] = j;
                    lenth[i] = lenth[j] + 1;
                    if (maxLength < lenth[i])
                    {
                        maxLength = lenth[i];
                        end = i;
                    }
                }
            }
        }
        vector<int> longestSubsequence(maxLength);
        for (i = 0; i < maxLength; i++)
        {
            longestSubsequence[maxLength - i - 1] = nums[end];
            end = pre[end];
        }
        return {maxLength, longestSubsequence};
    }
};

int main()
{
    vector<int> input = {10, 22, 9, 33, 21, 50, 41, 60, 80};

    auto result = LongestIncreasingSubsequence::findLongestIncreasingSubsequence(input);

    cout << "Longest Increasing Subsequence: ";
    for (int num : result.second)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Length of Longest Increasing Subsequence: " << result.first << endl;

    return 0;
}
//