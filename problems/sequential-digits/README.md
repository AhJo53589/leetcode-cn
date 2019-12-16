# `（中等）` [1291.sequential-digits 顺次数](https://leetcode-cn.com/problems/sequential-digits/)

[contest](https://leetcode-cn.com/contest/weekly-contest-167/problems/sequential-digits/)

### 题目描述
<p>我们定义「顺次数」为：每一位上的数字都比前一位上的数字大 <code>1</code> 的整数。</p>

<p>请你返回由&nbsp;<code>[low, high]</code>&nbsp;范围内所有顺次数组成的 <strong>有序</strong> 列表（从小到大排序）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输出：</strong>low = 100, high = 300
<strong>输出：</strong>[123,234]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输出：</strong>low = 1000, high = 13000
<strong>输出：</strong>[1234,2345,3456,4567,5678,6789,12345]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>10 &lt;= low &lt;= high &lt;= 10^9</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
vector<int> sequentialDigits(int low, int high)
{
    vector<int> ans;
    string sn = to_string(low);
    int d = sn.size();
    int b = 1;

    while (true)
    {
        string temp;
        for (int i = 0; i < d; i++)
        {
            temp += to_string(b + i);
        }
        int ti = stoi(temp);

        if (ti > high) break;
        if (ti >= low) 
        {
            ans.push_back(ti);
        }

        b++;
        if (b + d > 10)
        {
            b = 1;
            d++;
        }
        if (b + d > 10) break;
    }

    return ans;
}
```




