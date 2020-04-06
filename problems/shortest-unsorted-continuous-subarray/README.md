# `（简单）` [581.shortest-unsorted-continuous-subarray 最短无序连续子数组](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/)

### 题目描述
<p>给定一个整数数组，你需要寻找一个<strong>连续的子数组</strong>，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。</p>

<p>你找到的子数组应是<strong>最短</strong>的，请输出它的长度。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [2, 6, 4, 8, 10, 9, 15]
<strong>输出:</strong> 5
<strong>解释:</strong> 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
</pre>

<p><strong>说明 :</strong></p>

<ol>
	<li>输入的数组长度范围在&nbsp;[1, 10,000]。</li>
	<li>输入的数组可能包含<strong>重复</strong>元素&nbsp;，所以<strong>升序</strong>的意思是<strong><=。</strong></li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/shortest-unsorted-continuous-subarray-by-ikaruga/)

### 答题
``` C++
    int findUnsortedSubarray(vector<int>& nums)
    {
        stack<int> st;
        int l = nums.size() - 1;
        int r = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }
        st = stack<int>();
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] < nums[i])
            {
                r = max(r, st.top());
                st.pop();
            }
            st.push(i);
        }
        return (r > l) ? r - l + 1 : 0;
    }
```


### 其它
``` C++
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int l = 0;
        int r = 0;
        int minNum = nums[nums.size() - 1];
        for (int i = nums.size() - 1; i >= 0; i--) 
        {
            l = (nums[i] > minNum) ? i : l;
            minNum = min(minNum, nums[i]);
        }
        int maxNum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            r = (nums[i] < maxNum) ? i : r;
            maxNum = max(maxNum, nums[i]);
        }
        return (r > l) ? r - l + 1 : 0;
    }
```


