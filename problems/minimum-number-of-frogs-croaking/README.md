# `（中等）` [1419.minimum-number-of-frogs-croaking 数青蛙](https://leetcode-cn.com/problems/minimum-number-of-frogs-croaking/)

[contest](https://leetcode-cn.com/contest/weekly-contest-185/problems/minimum-number-of-frogs-croaking/)

### 题目描述
<p>给你一个字符串 <code>croakOfFrogs</code>，它表示不同青蛙发出的蛙鸣声（字符串 "croak" ）的组合。由于同一时间可以有多只青蛙呱呱作响，所以&nbsp;<code>croakOfFrogs</code> 中会混合多个 “croak” <em>。</em>请你返回模拟字符串中所有蛙鸣所需不同青蛙的最少数目。</p>

<p><strong>注意：</strong>要想发出蛙鸣 "croak"，青蛙必须 <strong>依序</strong> 输出 <code>‘c’, ’r’, ’o’, ’a’, ’k’</code> 这 5 个字母。如果没有输出全部五个字母，那么它就不会发出声音。</p>

<p>如果字符串 <code>croakOfFrogs</code> 不是由若干有效的 "croak" 字符混合而成，请返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>croakOfFrogs = "croakcroak"
<strong>输出：</strong>1 
<strong>解释：</strong>一只青蛙 “呱呱” 两次
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>croakOfFrogs = "crcoakroak"
<strong>输出：</strong>2 
<strong>解释：</strong>最少需要两只青蛙，“呱呱” 声用黑体标注
第一只青蛙 "<strong>cr</strong>c<strong>oak</strong>roak"
第二只青蛙 "cr<strong>c</strong>oak<strong>roak</strong>"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>croakOfFrogs = "croakcrook"
<strong>输出：</strong>-1
<strong>解释：</strong>给出的字符串不是 "croak<strong>"</strong> 的有效组合。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>croakOfFrogs = "croakcroa"
<strong>输出：</strong>-1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;croakOfFrogs.length &lt;= 10^5</code></li>
	<li>字符串中的字符只有 <code>'c'</code>, <code>'r'</code>, <code>'o'</code>, <code>'a'</code> 或者 <code>'k'</code></li>
</ul>

            

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-number-of-frogs-croaking/solution/minimum-number-of-frogs-croaking-by-ikaruga/)

### 答题
``` C++
    int minNumberOfFrogs(string croakOfFrogs) 
    {
        const string croak = "croak";
        unordered_map<char, int> dic;
        for (int i = 0; i < croak.size(); i++)
        {
            dic[croak[i]] = i;
        }

        vector<int> cnt(croak.size(), 0);
        int ans = 0;
        int start = 0;
        for (auto c : croakOfFrogs)
        {
            if (dic[c] == 0 || cnt[dic[c] - 1] > 0)
            {
                if (dic[c] != 0)
                {
                    cnt[dic[c] - 1]--;
                }
                start += (dic[c] == 0);
                cnt[dic[c]]++;
                ans = dic[c] == 0 ? max(ans, start - cnt[4]) : ans;
                continue;
            }
            return -1;
        }

        for (int i = 0; i < cnt.size() - 1; i++)
        {
            if (cnt[i] != 0) return -1;
        }
        return ans;
    }
```




