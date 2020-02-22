# `（中等）` [406.queue-reconstruction-by-height 根据身高重建队列](https://leetcode-cn.com/problems/queue-reconstruction-by-height/)

### 题目描述
<p>假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对<code>(h, k)</code>表示，其中<code>h</code>是这个人的身高，<code>k</code>是排在这个人前面且身高大于或等于<code>h</code>的人数。 编写一个算法来重建这个队列。</p>
<p><strong>注意：</strong><br>
总人数少于1100人。</p>

<p><strong>示例</strong></p>
<pre>输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
</pre>

---
### 思路
```

```

[发布的题解](https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/406-by-ikaruga/)

### 答题
``` C++
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end());
    vector<int> cnt(people.size(), 0);
    for (int i = 0; i < people.size(); i++)
    {
        cnt[i] = people[i][1];
    }

    vector<vector<int>> ans;
    size_t sz = 0;
    while (sz++ <= people.size())
    {
        int lastNum = -1;
        for (int i = 0; i < people.size(); i++)
        {
            if (lastNum != -1 && lastNum != people[i][0]) break;
            if (cnt[i] == -1) continue;
            cnt[i]--;
            if (cnt[i] != -1) continue;
            ans.push_back(people[i]);
            lastNum = people[i][0];
        }
    }

    return ans;
}
```




