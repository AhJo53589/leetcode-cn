# `（困难）` [100263.happy-new-year-2020-bomb SyM 的 🔑](https://leetcode-cn.com/problems/happy-new-year-2020-bomb/)

[contest](https://leetcode-cn.com/contest/sf-2020/problems/happy-new-year-2020-bomb/)

### 题目描述
<p>力扣团队的一位成员 SyM 用一份来自公元&nbsp;50 年左右的 C 语言代码来存储一个非常重要的 12 位密钥。不幸的是，他忘记了这串密钥，所以需要用这份代码来恢复。由于年代久远，源码已经丢失了，但所幸 SyM 有良好的跨平台意识，我们找到了这份代码在 Windows 10, MacOS, 以及 Linux 上面编译得到的二进制文件（目标平台均为 64 位）：</p>

<p>&nbsp;</p>

<p>Linux: <a href="https://assets.leetcode-cn.com/NewYear2020/bomb">https://assets.leetcode-cn.com/NewYear2020/bomb</a></p>

<p>Windows:&nbsp;<a href="https://assets.leetcode-cn.com/NewYear2020/bomb.exe">https://assets.leetcode-cn.com/NewYear2020/bomb.exe</a>&nbsp;</p>

<p>MacOS:&nbsp;<a href="https://assets.leetcode-cn.com/NewYear2020/bomb_macos">https://assets.leetcode-cn.com/NewYear2020/bomb_macos</a></p>

<p>&nbsp;</p>

<p>SyM 已经忘记如何解出他自己的密钥了，现在请你来帮他！请注意，由于密钥非常珍贵，只有<strong>第一位</strong>解出它的同学才能得到我们的奖励！</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p>1. 如果遇到无法执行（Permission Denied），需要给这个文件加上执行权限，例如在 Linux 中：<code>chmod +x ./bomb</code>；如果被防火墙拦住了，请允许这个软件运行。</p>

<p>2. 程序在执行结束后就会直接退出，建议在 shell 中执行这个程序来持久化结果。</p>

<p>3. 你的竞赛提交的程序只要返回这串密钥即可，没有任何入参。</p>

<p>4. 由于密钥的唯一性，在判定第一位解出的同学时不计罚时。(e.g. 小 A 在 20 分钟解出了这题（但错了一次），小 B 在 23&nbsp;分钟解出本题，只有小 A 能得到奖励)</p>

<p>5. 出题人不负责任地向你推荐一些好帮手：objdump/dumpbin, gdb 。使用合理的参数可以事半功倍 :) 。</p>

<p>&nbsp;</p>

            

---
### 思路
```
```



### 答题
``` C++
string bomb() {
    return "gcCjMlq9j5KD";
}
```




