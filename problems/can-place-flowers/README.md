# `（简单）` [605.can-place-flowers 种花问题](https://leetcode-cn.com/problems/can-place-flowers/)

### 题目描述
<div class="notranslate"><p>假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。</p>

<p>给你一个整数数组&nbsp;&nbsp;<code>flowerbed</code> 表示花坛，由若干 <code>0</code> 和 <code>1</code> 组成，其中 <code>0</code> 表示没种植花，<code>1</code> 表示种植了花。另有一个数&nbsp;<code>n</code><strong> </strong>，能否在不打破种植规则的情况下种入&nbsp;<code>n</code><strong>&nbsp;</strong>朵花？能则返回 <code>true</code> ，不能则返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>flowerbed = [1,0,0,0,1], n = 1
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>flowerbed = [1,0,0,0,1], n = 2
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= flowerbed.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>flowerbed[i]</code> 为 <code>0</code> 或 <code>1</code></li>
	<li><code>flowerbed</code> 中不存在相邻的两朵花</li>
	<li><code>0 &lt;= n &lt;= flowerbed.length</code></li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size() && n > 0; i++) {
            if (flowerbed[i] == 1) continue;
            if (i > 0 && flowerbed[i - 1] == 1) continue;
            if (i < flowerbed.size() - 1 && flowerbed[i + 1] == 1) continue;
            i++;
            n--;
        }
        return n == 0;
    }
};
```




