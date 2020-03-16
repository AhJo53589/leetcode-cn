# `（简单）` [443.string-compression 压缩字符串](https://leetcode-cn.com/problems/string-compression/)

### 题目描述
<p>给定一组字符，使用<a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95">原地算法</a>将其压缩。</p>

<p>压缩后的长度必须始终小于或等于原数组长度。</p>

<p>数组的每个元素应该是长度为1&nbsp;的<strong>字符</strong>（不是 int 整数类型）。</p>

<p>在完成<a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95">原地</a><strong>修改输入数组</strong>后，返回数组的新长度。</p>

<p>&nbsp;</p>

<p><strong>进阶：</strong><br>
你能否仅使用O(1) 空间解决问题？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
["a","a","b","b","c","c","c"]

<strong>输出：</strong>
返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]

<strong>说明：</strong>
"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>
["a"]

<strong>输出：</strong>
返回1，输入数组的前1个字符应该是：["a"]

<strong>说明：</strong>
没有任何字符串被替代。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

<strong>输出：</strong>
返回4，输入数组的前4个字符应该是：["a","b","1","2"]。

<strong>说明：</strong>
由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。
注意每个数字在数组中都有它自己的位置。
</pre>

<p><strong>注意：</strong></p>

<ol>
	<li>所有字符都有一个ASCII值在<code>[35, 126]</code>区间内。</li>
	<li><code>1 <= len(chars) <= 1000</code>。</li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/string-compression/solution/)

### 答题
``` C++
int compress(vector<char>& chars) 
{
    if (chars.empty()) return 0;
        
    size_t j = 0;
    int cnt = 0;
    for (size_t i = 1; i <= chars.size(); i++)
    {
        cnt++;
        if (i == chars.size() || chars[i] != chars[j])
        {
            j++;
            if (cnt != 1)
            {
                string scnt = to_string(cnt);
                for (auto c : scnt)
                {
                    chars[j++] = c;
                }
            }

            if (i == chars.size()) break;
            chars[j] = chars[i];
            cnt = 0;
        }
    }

    return j;
}
```




