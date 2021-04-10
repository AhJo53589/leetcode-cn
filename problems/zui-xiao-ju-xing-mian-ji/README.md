# `（困难）` [LCP_37.zui-xiao-ju-xing-mian-ji 最小矩形面积](https://leetcode-cn.com/problems/zui-xiao-ju-xing-mian-ji/)

[contest](https://leetcode-cn.com/contest/season/2021-spring/problems/zui-xiao-ju-xing-mian-ji/)

### 题目描述
<p>二维平面上有 <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>N</mi></mrow><annotation encoding="application/x-tex">N</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.68333em;vertical-align:0em;"></span><span class="mord mathdefault" style="margin-right:0.10903em;">N</span></span></span></span> 条直线，形式为 <code>y = kx + b</code>，其中 <code>k</code>、<code>b</code>为整数 且 <code>k &gt; 0</code>。所有直线以 <code>[k,b]</code> 的形式存于二维数组 <code>lines</code> 中，不存在重合的两条直线。两两直线之间可能存在一个交点，最多会有 <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><msubsup><mi>C</mi><mi>N</mi><mn>2</mn></msubsup></mrow><annotation encoding="application/x-tex">C_N^2</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1.089439em;vertical-align:-0.275331em;"></span><span class="mord"><span class="mord mathdefault" style="margin-right:0.07153em;">C</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height:0.8141079999999999em;"><span style="top:-2.424669em;margin-left:-0.07153em;margin-right:0.05em;"><span class="pstrut" style="height:2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mathdefault mtight" style="margin-right:0.10903em;">N</span></span></span><span style="top:-3.063em;margin-right:0.05em;"><span class="pstrut" style="height:2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">2</span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height:0.275331em;"><span></span></span></span></span></span></span></span></span></span> 个交点。我们用一个平行于坐标轴的矩形覆盖所有的交点，请问这个矩形最小面积是多少。若直线之间无交点、仅有一个交点或所有交点均在同一条平行坐标轴的直线上，则返回0。</p>
<p>注意：返回结果是浮点数，与标准答案 <strong>绝对误差或相对误差</strong> 在 10^-4 以内的结果都被视为正确结果</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>lines = [[2,3],[3,0],[4,1]]</code></p>
<p>输出：<code>48.00000</code></p>
<p>解释：三条直线的三个交点为 (3, 9) (1, 5) 和 (-1, -3)。最小覆盖矩形左下角为 (-1, -3) 右上角为 (3,9)，面积为 48</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>lines = [[1,1],[2,3]]</code></p>
<p>输出：<code>0.00000</code></p>
<p>解释：仅有一个交点 (-2，-1）</p>
</blockquote>
<p><strong>限制：</strong></p>
<ul>
<li><code>1 &lt;= lines.length &lt;= 10^5 且 lines[i].length == 2</code></li>
<li><code>1 &lt;= lines[0] &lt;= 10000</code></li>
<li><code>-10000 &lt;= lines[1] &lt;= 10000</code></li>
<li><code>与标准答案绝对误差或相对误差在 10^-4 以内的结果都被视为正确结果</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    double minRecSize(vector<vector<int>>& lines) {

    }
};
```




