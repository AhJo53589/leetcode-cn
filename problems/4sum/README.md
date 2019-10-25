# `（中等）` [18.4sum 四数之和](https://leetcode-cn.com/problems/4sum/)

### 题目描述
<p>给定一个包含&nbsp;<em>n</em> 个整数的数组&nbsp;<code>nums</code>&nbsp;和一个目标值&nbsp;<code>target</code>，判断&nbsp;<code>nums</code>&nbsp;中是否存在四个元素 <em>a，</em><em>b，c</em>&nbsp;和 <em>d</em>&nbsp;，使得&nbsp;<em>a</em> + <em>b</em> + <em>c</em> + <em>d</em>&nbsp;的值与&nbsp;<code>target</code>&nbsp;相等？找出所有满足条件且不重复的四元组。</p>

<p><strong>注意：</strong></p>

<p>答案中不可以包含重复的四元组。</p>

<p><strong>示例：</strong></p>

<pre>给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
</pre>


---
### 思路
```
```

### 答题
``` C++
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if(nums.size()<4) return {};
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    set<vector<int>> a;
    for(int i=0;i<nums.size()-3;i++)
    {
        if(nums[i]>target&&target>0) break;
        for(int j=i+1;j<nums.size()-2;j++)
        {
            int l=j+1;
            int r=nums.size()-1;
            while(l<r)
            {
                if(nums[i]+nums[j]+nums[l]+nums[r]<target)
                    l++;
                else if(nums[i]+nums[j]+nums[l]+nums[r]>target)
                    r--;
                else 
                {
                    vector<int> temp{nums[i],nums[j],nums[l],nums[r]};
                    a.insert(temp);
                    l++;
                    r--;
                }
            }
        }
    }
    for(auto c:a)
    {
        res.push_back(c);
    }
    return res;
}
```

### 其它
这么去重，没问题吗
``` C++
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> res;
	int size = nums.size();
	if (size < 4) return res;

	sort(nums.begin(), nums.end());
	for (int i = 0; i < size - 3; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
		if (nums[i] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target) continue;

		for (int j = i + 1; j < size - 2; j++)
		{
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;
			if (nums[i] + nums[j] + nums[size - 2] + nums[size - 1] < target) continue;
			if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;

			int k = j + 1;
			int m = size - 1;
			while (k < m)
			{
				int sum = nums[i] + nums[j] + nums[k] + nums[m];
				if (sum < target) k++;
				else if (sum > target) m--;
				else
				{
					res.push_back(vector<int> {nums[i], nums[j], nums[k], nums[m]});
					do { k++; } while (nums[k] == nums[k - 1] && k < m);
					do { m--; } while (nums[m] == nums[m + 1] && k < m);
				}
			}
		}
	}
	return res;
}
```

