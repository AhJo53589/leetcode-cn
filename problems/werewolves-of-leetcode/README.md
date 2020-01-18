# `（简单）` [100269.werewolves-of-leetcode 狼人杀模拟器](https://leetcode-cn.com/problems/werewolves-of-leetcode/)

[contest](https://leetcode-cn.com/contest/sf-2020/problems/werewolves-of-leetcode/)

### 题目描述
<p>小李的同事们很喜欢玩狼人杀，每次都找他当法官。小李觉得很累，决定写一个程序来跑出狼人杀的结果。</p>

<p>狼人杀是一个桌游。常见局由 12 名玩家和 1 名法官组成。12 名玩家坐成一个圈。每个玩家在游戏开始时随机抽取一张角色卡牌，只能知道自己的身份。 玩家分为两个阵营，狼人和村民。</p>

<ul>
	<li>狼人的胜利条件是 狼人阵营的玩家数 &gt;= 村民阵营的玩家数</li>
	<li>村民的胜利条件是 所有狼人出局</li>
</ul>

<p><strong>游戏过程</strong></p>

<p>游戏分为夜晚和白天。</p>

<ol>
	<li>(夜晚) 拿到狼人身份的玩家睁眼，其他人闭眼。狼人们商量后选择一名玩家击杀；</li>
	<li>(白天) 所有人睁眼；</li>
	<li>法官宣布昨晚出局的玩家，以及熊是否咆哮了；</li>
	<li>出局的玩家离开游戏，发动技能（如果有）；</li>
	<li>法官检查胜利条件，如果任何一个满足则结束游戏；</li>
	<li>在场玩家进行一轮发言，并票选最可疑的玩家出局；</li>
	<li>被选中的玩家离开游戏，发动技能（如果有）；</li>
	<li>法官检查胜利条件，如果任何一个满足则结束游戏；</li>
	<li>重复 1；</li>
</ol>

<p><strong>游戏角色</strong></p>

<p>【村民阵营】x8</p>

<ul>
	<li>村民(villager, 下称<code>"vil"</code>) x5：没有特殊技能</li>
	<li>猎人(<code>"hunter"</code>) x1：技能是在出局时（被投票或被狼人击杀）可以向所有人亮出底牌选择带走一名玩家</li>
	<li>白痴(<code>"idiot"</code>) x1：技能是在白天<strong>被投票出局</strong>后自动亮出底牌并且不出局</li>
	<li>驯熊人(bear tamer, 下称<code>"bear"</code>) x1：（简称熊）每天夜里，如果<strong>相邻</strong>两名存活玩家有任何一个是狼人，熊会发出咆哮。如果驯熊人已经死亡，则这一局熊不再咆哮。驯熊人如果当晚被杀，熊也不会咆哮。（相邻指向左找第一名存活玩家和向右找第一名存活玩家，当晚被杀的玩家也视为死亡）</li>
</ul>

<p>【狼人阵营】x4</p>

<ul>
	<li>狼人(werewolf, 下称<code>"ww"</code>) x4：可以知道同伴，但不知道好人的具体角色。</li>
</ul>

<p>对于所有人：</p>

<ul>
	<li>白天可以投票</li>
	<li>除了发言的环节，玩家不能发言或者交换信息</li>
</ul>

<p><strong>模拟器设定</strong></p>

<ul>
	<li>我们用 <em><strong>c</strong></em> 来模拟每名玩家在游戏开始时在他人眼中的可信度。0 &lt; <em><strong>c</strong></em> &lt; 100 。越小则越像狼人</li>
	<li>狼人只击杀非狼人，并且在场玩家知晓这点</li>
	<li>在投票环节，<em><strong>c </strong></em>最低的玩家出局。如果有多个目标，则座位号小号出局。</li>
	<li>狼人优先击杀熊，其他时候击杀 <em><strong>c</strong></em> 最高的好人（村民阵营），如果有多个目标，则击杀座位号小号。</li>
	<li>玩家的 <em><strong>c </strong></em>变成 0 或者 100 表示已知身份： 铁狼 或者 铁好人</li>
	<li>玩家的 <em><strong>c </strong></em>会根据<strong>大家获取到的信息</strong>发生改变，<strong>所有人看到的可信度 c 一起更新。</strong><em>注意，改变的时机需要遵守游戏过程</em>：
	<ol>
		<li>猎人出局或白痴被投票出局时一定发动技能，使 ta 的&nbsp;<em><strong>c</strong></em> 变为 100；猎人会射杀 <em><strong>c</strong></em> 最低的玩家，如果有多个目标，则射杀座位号小号</li>
		<li>第一天发言时，如果驯熊人依然存活，驯熊人会公布身份，使 ta 的 <em><strong>c</strong></em> 变为 100（在模拟器中狼不会假装自己是熊）
		<ol>
			<li>如果熊咆哮了，人们开始怀疑其左右的未知身份玩家，这使他们的 <em><strong>c</strong></em> 变为原来的一半 (向下取整, 如果原来是 1 则不变 )</li>
			<li>如果熊咆哮了且左右的在局一方为铁好人，则另一方成为铁狼；如果其中一方后来被发现是铁好人，人们也会更新另一方的 <em><strong>c</strong></em>&nbsp;</li>
			<li>如果熊在场且没有咆哮，则左右的在场玩家成为铁好人</li>
		</ol>
		</li>
		<li>如果驯熊人在第一次发言前死亡，则场上玩家不知道其位置，也无法利用熊的咆哮信息</li>
		<li>如果玩家在夜间死亡，则该离场的玩家也被认为是铁好人</li>
	</ol>
	</li>
</ul>

<p><strong>输入：</strong></p>

<p><code>players</code>：一个长度为 12 的 string 数组，坐标代表座位，字符串代表底牌, 有以下可能：<code>"vil"</code>,&nbsp;<code>"hunter"</code>,&nbsp;<code>"idiot"</code>,&nbsp;<code>"bear"</code>&nbsp;和&nbsp;<code>"ww"</code>。 其中&nbsp;<code>"vil"</code>&nbsp;会出现 5 次，&nbsp;<code>"ww"</code>会出现 4 次， 其他每个都是 1 次。 坐标&nbsp;<code>0</code>&nbsp;和&nbsp;<code>11</code>&nbsp;也视为相邻。</p>

<p><code>credibility</code>：一个长度为 12 的 int 数组，坐标代表座位，int 代表玩家初始的可信度</p>

<p><strong>输出：</strong></p>

<p>根据模拟器的设定，村民阵营是否能赢</p>

<p><strong>示例 1：</strong></p>

<pre><strong>Input: </strong>players = ["bear","vil","vil","ww","vil","vil","idiot","ww","hunter","ww","ww","vil"], credibility = [9,55,62,74,43,70,13,23,15,78,61,66]
<strong>Output: </strong>false</pre>

<p><strong>解释：</strong></p>

<p>第一天夜晚，狼人击杀玩家&nbsp;<strong>5</strong>，熊没有咆哮。</p>

<p>第二天白天，玩家&nbsp;<strong>0</strong>&nbsp;公布自己熊的身份。玩家&nbsp;<strong>1</strong>&nbsp;和玩家&nbsp;<strong>11</strong>&nbsp;成为 铁好人。看上去最可疑的玩家<strong>&nbsp;6</strong>&nbsp;被投出，但是因为是 白痴 身份，并没有出局。玩家&nbsp;<strong>6</strong>&nbsp;成为 铁好人。</p>

<p>第二天夜晚，狼人击杀玩家&nbsp;<strong>0</strong>&nbsp;驯熊人。熊没有咆哮。</p>

<p>第三天白天，身份最低的玩家&nbsp;<strong>8</strong>&nbsp;猎人被投票出局。猎人选择带走场上可信度最低的玩家&nbsp;<strong>7</strong>。</p>

<p>第三天夜晚，狼人击杀身份最高的玩家&nbsp;<strong>1 </strong>村民。</p>

<p>第四天白天，身份最低的玩家&nbsp;<strong>4 </strong>村民被投票出局。</p>

<p>第四天夜晚，狼人击杀玩家&nbsp;<strong>6 </strong>白痴, 此时场上狼人数量等于好人数量，狼人胜利。</p>

<p>&nbsp;</p>

<p><strong>示例 2：</strong></p>

<pre><strong>Input: </strong>players = ["vil", "vil", "vil", "ww", "vil", "ww", "ww", "vil", "ww", "bear", "hunter", "idiot"], credibility = [81, 71, 88, 31, 34, 40, 70, 94, 73, 79, 98, 48]
<strong>Output: </strong>true</pre>

<p><strong>解释：</strong></p>

<p>第一回合猎人出局，熊咆哮了，但由于熊没有跳身份，对于猎人是无效信息，不能更新 c ，猎人击杀 3 号位玩家狼人。本回合投票投出 11 号白痴，白痴亮出身份牌， c 变为 100 。</p>

<p>&nbsp;</p>

<p><strong>示例 3：</strong></p>

<pre><strong>Input: </strong>players = ["vil","ww","bear","hunter","ww","idiot","vil","vil","ww","vil","ww","vil"], credibility = [45,67,32,25,1,27,99,85,3,54,3,25]
<strong>Output: </strong>true</pre>

<p><strong>解释：</strong></p>

<p>最后一轮投票，猎人被投出，发动技能。由于此时猎人已经是铁好人，通过第一轮熊咆哮可以得出 1 号位是铁狼，所以本轮猎人击杀 1 号位狼人，游戏结束，村民胜利。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

            

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> die;
    vector<string> a;
    vector<int> w;
    int get(string s) {
        if(s[0] == 'v') return 0;
        if(s[0] == 'h') return 1;
        if(s[0] == 'i') return 2;
        if(s[0] == 'b') return 3;
        if(s[0] == 'w') return 4;
        return -1;
    }
    int check() {
        int b = 0, g = 0;
        for(int i=0;i<12;++i) {
            if(die[i]) continue;
            if(get(a[i]) == 4) b++;
            else g++;
        }
        if(b == 0) return 2;
        if(b >= g) return 1;
        return 0;
    }
    int wolf_find() {
        int cur = -1, mx = -1;
        for(int i=0;i<12;++i) {
            if(die[i]) continue;
            if(get(a[i]) == 4) continue;
            if(w[i] > mx) mx = w[i], cur = i;
        }
        return cur;
    }
    int hunter_find() {
        int cur = -1, mx = 101;
        for(int i=0;i<12;++i) {
            if(die[i]) continue;
            if(get(a[i]) == 1) continue;
            if(w[i] < mx) mx = w[i], cur = i;
        }
        return cur;
    }
    int vote_find() {
        int cur = -1, mx = 101;
        for(int i=0;i<12;++i) {
            if(die[i]) continue;
            if(w[i] < mx) mx = w[i], cur = i;
        }
        return cur;
    }
    int get_left(int x) {
        while(1) {
            x = (x+11)%12;
            if(!die[x]) return x;
        }
        return -1;
    }
    int get_right(int x) {
        while(1) {
            x = (x+1)%12;
            if(!die[x]) return x;
        }
        return -1;
    }
    int l = -1, r = -1, aoao = 0;
    void magic() {
        if(!aoao || l == -1) return;
        if(w[l] == 100) w[r] = 0;
        if(w[r] == 100) w[l] = 0;
    }
    int bear_alive = 1, bear_pos = 0;
    bool know_b = 0;
    int hunter_pos;
    // int hunter_die = 0;
    bool canVillagersWin(vector<string>& players, vector<int>& cred)
    {
        die.resize(12);
        a = players;
        w = cred;
        for(int i=0;i<12;++i) if(get(a[i]) == 3) bear_pos = i;
        for(int ca=1;;++ca)
        {
            cout << "case : " << ca << endl;
            if(bear_alive && ca != 1) {
                int killed = bear_pos;
                die[bear_pos] = 1;
                bear_alive = 0;
                w[bear_pos] = 100;
                cout << "killed by wolf : " << bear_pos << endl;
            } else {
                int killed = wolf_find();
                if(killed == bear_pos) bear_alive = 0;
                die[killed] = 1;
                w[killed] = 100;
                magic();
                cout << "killed by wolf : " << killed << endl;
                if(l == -1) {
                    l = get_left(bear_pos);
                    r = get_right(bear_pos);
                }
                if(get(a[killed]) == 1) {
                    int tmp = hunter_find();
                    die[tmp] = 1;
                    if(tmp == bear_pos) bear_alive = 0;
                    cout << "killed by hunter : " << tmp << endl;
                }
            }
            magic();
            if(check()) return check() == 2;
            
            if(bear_alive) {
                cout << "bear!!" << endl;
                know_b = 1;
                w[bear_pos] = 100;
                magic();
                
                if(get(a[l]) == 4 || get(a[r]) == 4) aoao = 1;
                if(get(a[l]) < 4 && get(a[r]) < 4) w[l] = w[r] = 100;
                else if(w[l] == 100) w[r] = 0;
                else if(w[r] == 100) w[l] = 0;
                else {
                    if(w[l] == 1) w[l] = 1;
                    else w[l] /= 2;
                    if(w[r] == 1) w[r] = 1;
                    else w[r] /= 2;
                }
            }
            magic();
            for(int i=0;i<12;++i) cout<<die[i]<<" ";cout<<endl;
            for(int i=0;i<12;++i) cout<<w[i]<<" ";cout<<endl;
            int tmp = vote_find();
            cout << "vote :" << tmp << endl;
            if(get(a[tmp]) == 2) w[tmp] = 100;
            else die[tmp] = 1;
            if(tmp == bear_pos) bear_alive = 0;
            magic();
            if(get(a[tmp]) == 1) {
                w[tmp] = 100;
                magic();
                int tmp2 = hunter_find();
                die[tmp2] = 1;
                if(tmp2 == bear_pos) bear_alive = 0;
                cout << "killed by hunter : " << tmp2 << endl;
            }
            for(int i=0;i<12;++i) cout<<die[i]<<" ";cout<<endl;
            if(check()) return check() == 2;
        }
        return 1;
    }
};
```




