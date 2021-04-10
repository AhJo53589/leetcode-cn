# `（简单）` [LCP_33.o8SXZn 蓄水](https://leetcode-cn.com/problems/o8SXZn/)

[contest](https://leetcode-cn.com/contest/season/2021-spring/problems/o8SXZn/)

### 题目描述
<p>给定 N 个无限容量且初始均空的水缸，每个水缸配有一个水桶用来打水，第 <code>i</code> 个水缸配备的水桶容量记作 <code>bucket[i]</code>。小扣有以下两种操作：</p>
<ul>
<li>升级水桶：选择任意一个水桶，使其容量增加为 <code>bucket[i]+1</code></li>
<li>蓄水：将全部水桶接满水，倒入各自对应的水缸</li>
</ul>
<p>每个水缸对应最低蓄水量记作 <code>vat[i]</code>，返回小扣至少需要多少次操作可以完成所有水缸蓄水要求。</p>
<p>注意：实际蓄水量 <strong>达到或超过</strong> 最低蓄水量，即完成蓄水要求。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>bucket = [1,3], vat = [6,8]</code></p>
<p>输出：<code>4</code></p>
<p>解释：<br>
第 1 次操作升级 bucket[0]；<br>
第 2 ~ 4 次操作均选择蓄水，即可完成蓄水要求。<br>
<img src="https://pic.leetcode-cn.com/1616122992-RkDxoL-vat1.gif" alt="vat1.gif" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>bucket = [9,0,1], vat = [0,2,2]</code></p>
<p>输出：<code>3</code></p>
<p>解释：<br>
第 1 次操作均选择升级 bucket[1]<br>
第 2~3 次操作选择蓄水，即可完成蓄水要求。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= bucket.length == vat.length &lt;= 100</code></li>
<li><code>0 &lt;= bucket[i], vat[i] &lt;= 10^4</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/o8SXZn/solution/o8sxzn-by-ikaruga-kysx/)

### 答题
``` C++
class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int t = 0;
        priority_queue<vector<int>> pq;
        for (int i = 0; i < bucket.size(); i++) {
            if (vat[i] == 0) continue;
            if (bucket[i] == 0) {
                t++;
                bucket[i] += bucket[i] + 1;
            }
            pq.push({ (vat[i] - 1) / bucket[i] + 1, bucket[i], i });
        }

        int ans = INT_MAX;
        while (!pq.empty()) {
            auto q = pq.top();
            pq.pop();
            if (t >= ans) break;
            ans = min(ans, q[0] + t);

            int i = q[2];
            int nb = q[1] + 1;
            pq.push({ (vat[i] - 1) / nb + 1, nb, i });
            t++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
```




