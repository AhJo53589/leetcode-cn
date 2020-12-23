# `（困难）` [1622.fancy-sequence 奇妙序列](https://leetcode-cn.com/problems/fancy-sequence/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-37/problems/fancy-sequence/)

### 题目描述
<p>请你实现三个 API <code>append</code>，<code>addAll</code>&nbsp;和&nbsp;<code>multAll</code>&nbsp;来实现奇妙序列。</p>

<p>请实现&nbsp;<code>Fancy</code>&nbsp;类 ：</p>

<ul>
	<li><code>Fancy()</code>&nbsp;初始化一个空序列对象。</li>
	<li><code>void append(val)</code> 将整数&nbsp;<code>val</code>&nbsp;添加在序列末尾。</li>
	<li><code>void addAll(inc)</code>&nbsp;将所有序列中的现有数值都增加&nbsp;<code>inc</code>&nbsp;。</li>
	<li><code>void multAll(m)</code>&nbsp;将序列中的所有现有数值都乘以整数&nbsp;<code>m</code>&nbsp;。</li>
	<li><code>int getIndex(idx)</code> 得到下标为&nbsp;<code>idx</code>&nbsp;处的数值（下标从 0 开始），并将结果对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;取余。如果下标大于等于序列的长度，请返回&nbsp;<code>-1</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
<strong>输出：</strong>
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

<strong>解释：</strong>
Fancy fancy = new Fancy();
fancy.append(2);   // 奇妙序列：[2]
fancy.addAll(3);   // 奇妙序列：[2+3] -&gt; [5]
fancy.append(7);   // 奇妙序列：[5, 7]
fancy.multAll(2);  // 奇妙序列：[5*2, 7*2] -&gt; [10, 14]
fancy.getIndex(0); // 返回 10
fancy.addAll(3);   // 奇妙序列：[10+3, 14+3] -&gt; [13, 17]
fancy.append(10);  // 奇妙序列：[13, 17, 10]
fancy.multAll(2);  // 奇妙序列：[13*2, 17*2, 10*2] -&gt; [26, 34, 20]
fancy.getIndex(0); // 返回 26
fancy.getIndex(1); // 返回 34
fancy.getIndex(2); // 返回 20
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= val, inc, m &lt;= 100</code></li>
	<li><code>0 &lt;= idx &lt;= 10<sup>5</sup></code></li>
	<li>总共最多会有&nbsp;<code>10<sup>5</sup></code>&nbsp;次对&nbsp;<code>append</code>，<code>addAll</code>，<code>multAll</code>&nbsp;和&nbsp;<code>getIndex</code>&nbsp;的调用。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Fancy {
public:
    Fancy() {

    }
    
    void append(int val) {

    }
    
    void addAll(int inc) {

    }
    
    void multAll(int m) {

    }
    
    int getIndex(int idx) {

    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
```




