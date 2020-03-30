# `（简单）` [475.heaters 供暖器](https://leetcode-cn.com/problems/heaters/)

### 题目描述
<p>冬季已经来临。&nbsp;你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。</p>

<p>现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。</p>

<p>所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。</p>

<p><strong>说明:</strong></p>

<ol>
	<li>给出的房屋和供暖器的数目是非负数且不会超过 25000。</li>
	<li>给出的房屋和供暖器的位置均是非负数且不会超过10^9。</li>
	<li>只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。</li>
	<li>所有供暖器都遵循你的半径标准，加热的半径也一样。</li>
</ol>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [1,2,3],[2]
<strong>输出:</strong> 1
<strong>解释:</strong> 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [1,2,3,4],[1,4]
<strong>输出:</strong> 1
<strong>解释:</strong> 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/heaters/solution/heaters-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        int l = 0;
        for (int i = 0; i < houses.size(); i++)
        {
            int radius = INT_MAX;
            for (int j = l; j < heaters.size(); j++)
            {
                l = (houses[i] >= heaters[j]) ? j : l;
                radius = min(radius, abs(houses[i] - heaters[j]));
                if (houses[i] < heaters[j]) break;
            }
            ans = max(ans, radius);
        }
        return ans;
    }
};
```


### 其它
``` C++
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int Nh = houses.size();
        sort(heaters.begin(), heaters.end());
        int ans = 0;

        for (auto& x : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), x);
            if (it == heaters.begin()) {
                ans = max(ans, abs(*it - x));
            }
            else if (it == heaters.end()) {
                ans = max(ans, abs(*(it - 1) - x));
            }
            else {
                ans = max(ans, min(abs(*(it - 1) - x), abs(*it - x)));
            }

        }

        return ans;
    }
};
```


