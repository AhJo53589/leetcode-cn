# `（简单）` [299.bulls-and-cows 猜数字游戏](https://leetcode-cn.com/problems/bulls-and-cows/)

### 题目描述
<p>你正在和你的朋友玩&nbsp;<a href="https://baike.baidu.com/item/%E7%8C%9C%E6%95%B0%E5%AD%97/83200?fromtitle=Bulls+and+Cows&fromid=12003488&fr=aladdin">猜数字（Bulls and Cows）</a>游戏：你写下一个数字让你的朋友猜。每次他猜测后，你给他一个提示，告诉他有多少位数字和确切位置都猜对了（称为“Bulls”, 公牛），有多少位数字猜对了但是位置不对（称为“Cows”, 奶牛）。你的朋友将会根据提示继续猜，直到猜出秘密数字。</p>

<p>请写出一个根据秘密数字和朋友的猜测数返回提示的函数，用 <code>A</code> 表示公牛，用&nbsp;<code>B</code>&nbsp;表示奶牛。</p>

<p>请注意秘密数字和朋友的猜测数都可能含有重复数字。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> secret = "1807", guess = "7810"

<strong>输出:</strong> "1A3B"

<strong>解释:</strong> <code>1</code>&nbsp;公牛和&nbsp;<code>3</code>&nbsp;奶牛。公牛是 <code>8</code>，奶牛是 <code>0</code>, <code>1</code>&nbsp;和 <code>7</code>。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> secret = "1123", guess = "0111"

<strong>输出:</strong> "1A1B"

<strong>解释: </strong>朋友猜测数中的第一个 <code>1</code>&nbsp;是公牛，第二个或第三个 <code>1</code>&nbsp;可被视为奶牛。</pre>

<p><strong>说明: </strong>你可以假设秘密数字和朋友的猜测数都只包含数字，并且它们的长度永远相等。</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/bulls-and-cows/solution/299-by-ikaruga/)

### 答题
``` C++
string getHint(string secret, string guess) 
{
    int acnt = 0;
    int bcnt = 0;
    unordered_map<char, int> um;
    for (int i = 0; i < secret.size(); i++)
    {
        um[secret[i]]++;
        acnt += (secret[i] == guess[i]);
    }
    for (auto& c : guess)
    {
        bcnt += (um[c]-- > 0);
    }
    bcnt -= acnt;
    return to_string(acnt) + "A" + to_string(bcnt) + "B";
}
```




