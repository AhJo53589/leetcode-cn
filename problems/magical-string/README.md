# `（中等）` [481.magical-string 神奇字符串](https://leetcode-cn.com/problems/magical-string/)

### 题目描述
<p>神奇的字符串&nbsp;<strong>S&nbsp;</strong>只包含 '1' 和 '2'，并遵守以下规则：</p>

<p>字符串 <strong>S</strong> 是神奇的，因为串联字符 '1' 和 '2' 的连续出现次数会生成字符串 <strong>S</strong> 本身。</p>

<p>字符串&nbsp;<strong>S&nbsp;</strong>的前几个元素如下：<strong>S </strong>= “1221121221221121122 ......”</p>

<p>如果我们将&nbsp;<strong>S</strong> 中连续的 1 和 2 进行分组，它将变成：</p>

<p>1 22 11 2 1 22 1 22 11 2 11 22 ......</p>

<p>并且每个组中 '1' 或 '2' 的出现次数分别是：</p>

<p>1 2 2 1 1 2 1 2 2 1 2 2 ......</p>

<p>你可以看到上面的出现次数就是 <strong>S</strong> 本身。</p>

<p>给定一个整数 N 作为输入，返回神奇字符串 <strong>S&nbsp;</strong>中前 N 个数字中的 '1' 的数目。</p>

<p><strong>注意：</strong>N 不会超过 100,000。</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>6
<strong>输出：</strong>3
<strong>解释：</strong>神奇字符串 S 的前 6 个元素是 “12211”，它包含三个 1，因此返回 3。
</pre>

<p>&nbsp;</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/magical-string/solution/481-by-ikaruga/)

### 答题
``` C++
int magicalString(int n)
{
    if (n < 1) return 0;
        
    int ans = 1;
    queue<int> que;
    que.push(2);
    int i = 3;
    int num = 2;
    //cout << 1 << "," << 2 << "," << 2 << ",";
    while (i < n)
    {
        num = (num == 1) ? 2 : 1;
            
        auto q = que.front();
        que.pop();

        if (q == 2)
        {
            que.push(num);
            i++;
            ans += (num == 1);
            //cout << num << ",";
        }
        if (i < n)
        {
            que.push(num);
            i++;
            ans += (num == 1);
            //cout << num << ",";
        }
    }
    return ans;
}
```




