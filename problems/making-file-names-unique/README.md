# `（中等）` [5441.making-file-names-unique 保证文件名唯一](https://leetcode-cn.com/problems/making-file-names-unique/)

[contest](https://leetcode-cn.com/contest/weekly-contest-194/problems/making-file-names-unique/)

### 题目描述

              <p>给你一个长度为 <code>n</code> 的字符串数组 <code>names</code> 。你将会在文件系统中创建 <code>n</code> 个文件夹：在第 <code>i</code> 分钟，新建名为 <code>names[i]</code> 的文件夹。</p>

<p>由于两个文件 <strong>不能</strong> 共享相同的文件名，因此如果新建文件夹使用的文件名已经被占用，系统会以 <code>(k)</code> 的形式为新文件夹的文件名添加后缀，其中 <code>k</code> 是能保证文件名唯一的 <strong>最小正整数</strong> 。</p>

<p>返回长度为<em> <code>n</code></em> 的字符串数组，其中 <code>ans[i]</code> 是创建第 <code>i</code> 个文件夹时系统分配给该文件夹的实际名称。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>names = ["pes","fifa","gta","pes(2019)"]
<strong>输出：</strong>["pes","fifa","gta","pes(2019)"]
<strong>解释：</strong>文件系统将会这样创建文件名：
"pes" --&gt; 之前未分配，仍为 "pes"
"fifa" --&gt; 之前未分配，仍为 "fifa"
"gta" --&gt; 之前未分配，仍为 "gta"
"pes(2019)" --&gt; 之前未分配，仍为 "pes(2019)"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>names = ["gta","gta(1)","gta","avalon"]
<strong>输出：</strong>["gta","gta(1)","gta(2)","avalon"]
<strong>解释：</strong>文件系统将会这样创建文件名：
"gta" --&gt; 之前未分配，仍为 "gta"
"gta(1)" --&gt; 之前未分配，仍为 "gta(1)"
"gta" --&gt; 文件名被占用，系统为该名称添加后缀 (k)，由于 "gta(1)" 也被占用，所以 k = 2 。实际创建的文件名为 "gta(2)" 。
"avalon" --&gt; 之前未分配，仍为 "avalon"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>names = ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"]
<strong>输出：</strong>["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece(4)"]
<strong>解释：</strong>当创建最后一个文件夹时，最小的正有效 k 为 4 ，文件名变为 "onepiece(4)"。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>names = ["wano","wano","wano","wano"]
<strong>输出：</strong>["wano","wano(1)","wano(2)","wano(3)"]
<strong>解释：</strong>每次创建文件夹 "wano" 时，只需增加后缀中 k 的值即可。</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>names = ["kaido","kaido(1)","kaido","kaido(1)"]
<strong>输出：</strong>["kaido","kaido(1)","kaido(2)","kaido(1)(1)"]
<strong>解释：</strong>注意，如果含后缀文件名被占用，那么系统也会按规则在名称后添加新的后缀 (k) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= names.length &lt;= 5 * 10^4</code></li>
	<li><code>1 &lt;= names[i].length &lt;= 20</code></li>
	<li><code>names[i]</code> 由小写英文字母、数字和/或圆括号组成。</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> dic;

        for (auto& name : names) {
            if (dic.count(name) == 0) {
                dic.insert({ name, 0 });
                continue;
            }
           
            int idx = dic[name];
            while (true) {
                idx++;
                string temp = name + "(" + to_string(idx) + ")";
                if (dic.count(temp) != 0) continue;
                dic[name] = idx;
                name = temp;
                dic[name] = 0;
                break;
            }
        }

        return names;
    }
```




