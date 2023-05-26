#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int len, count1 = 0, count2 = 0;
        // count1 记录 < 的数量,  count2 记录 》 的数量
        cin >> len;  // 输入长度
        char strs[len];  
        vector<int> nums;
        vector<bool> flag(len + 6, true);  // 用来记录有多少个数
        int count = 0;
        for(int i = 0;i < len;i++)
        {
            cin >> strs[i];
            // 判断 > or < 
            if(strs[i] == '<') count1++;
            else count2++;
        }
        // 如果第一个为 < ,那么把第一个值赋值为 < 与  > 差值 加上 一个非零正整数 否者直接为len的长度加非零正整数
        if(strs[0] ==  '<') nums.push_back(abs(count1 - count2) + 5);
        else nums.push_back(len + 5);

        // 对数组的数值进行操作，  如果strs[i] == <,那么nums[i+ 1]就在 nums[i]的基础上加1，否则减1
        for(int i = 0;i < len;++i)
        {
            if(strs[i] ==  '<') nums.push_back(nums[i] + 1);
            else nums.push_back(nums[i] - 1);
        }
        // 遍历有多少个不同的数
        for(int i = 0;i <= len;++i)
        {
            if(flag[nums[i]] == true)
            {
                count++;
                // 修改为 false表示出现过
                flag[nums[i]] = false;
            }
        }
        cout << count << endl;
    }
    return 0;
}