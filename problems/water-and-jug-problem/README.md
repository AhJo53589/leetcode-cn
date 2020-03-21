# `（中等）` [365.water-and-jug-problem 水壶问题](https://leetcode-cn.com/problems/water-and-jug-problem/)

### 题目描述
<p>有两个容量分别为&nbsp;<em>x</em>升 和<em> y</em>升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好&nbsp;<em>z</em>升 的水？</p>

<p>如果可以，最后请用以上水壶中的一或两个来盛放取得的&nbsp;<em>z升&nbsp;</em>水。</p>

<p>你允许：</p>

<ul>
	<li>装满任意一个水壶</li>
	<li>清空任意一个水壶</li>
	<li>从一个水壶向另外一个水壶倒水，直到装满或者倒空</li>
</ul>

<p><strong>示例 1:</strong> (From the famous <a href="https://www.youtube.com/watch?v=BVtQNK_ZUJg"><em>"Die Hard"</em> example</a>)</p>

<pre>输入: x = 3, y = 5, z = 4
输出: True
</pre>

<p><strong>示例 2:</strong></p>

<pre>输入: x = 2, y = 6, z = 5
输出: False
</pre>


---
### 思路
```
```



### 答题
``` C++
//#include <numeric>  // c++ 17
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == 0 || y == 0) return z == 0 || x + y == z;
        return z % gcd(x, y) == 0;
    }
};
```




