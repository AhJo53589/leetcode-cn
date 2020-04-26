# `（简单）` [401.binary-watch 二进制手表](https://leetcode-cn.com/problems/binary-watch/)

### 题目描述
<p>二进制手表顶部有 4 个 LED 代表<strong>小时（0-11）</strong>，底部的 6 个 LED 代表<strong>分钟（0-59）</strong>。</p>

<p>每个 LED 代表一个 0 或 1，最低位在右侧。</p>

<p><img style="height:300px" src="https://upload.wikimedia.org/wikipedia/commons/8/8b/Binary_clock_samui_moon.jpg"></p>

<p>例如，上面的二进制手表读取 “3:25”。</p>

<p>给定一个非负整数 <em>n&nbsp;</em>代表当前 LED 亮着的数量，返回所有可能的时间。</p>

<p><strong>案例:</strong></p>

<pre>输入: n = 1
返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]</pre>

<p>&nbsp;</p>

<p><strong>注意事项:</strong></p>

<ul>
	<li>输出的顺序没有要求。</li>
	<li>小时不会以零开头，比如 “01:00”&nbsp;是不允许的，应为 “1:00”。</li>
	<li>分钟必须由两位数组成，可能会以零开头，比如 “10:2”&nbsp;是无效的，应为 “10:02”。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<string> readBinaryWatch(int num) 
    {
        vector<string> ans;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 60; j++) 
            {
                if (count1(i) + count1(j) != num) continue;
                ans.push_back(to_string(i) + ":" + (j < 10 ? "0" + to_string(j) : to_string(j)));
            }
        }
        return ans;
    }

    int count1(int n)
    {
        int cnt = 0;
        while (n != 0)
        {
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }
};

```




