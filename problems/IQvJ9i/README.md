# `（困难）` [LCP 27.IQvJ9i 黑盒光线反射](https://leetcode-cn.com/problems/IQvJ9i/)

### 题目描述
<p>秋日市集上有个奇怪的黑盒，黑盒的主视图为 n*m 的矩形。从黑盒的主视图来看，黑盒的上面和下面各均匀分布有 m 个小孔，黑盒的左面和右面各均匀分布有 n 个小孔。黑盒左上角小孔序号为 0，按顺时针编号，总共有 2*(m+n) 个小孔。每个小孔均可以打开或者关闭，初始时，所有小孔均处于关闭状态。每个小孔上的盖子均为镜面材质。例如一个 2*3 的黑盒主视图与其小孔分布如图所示:</p>
<p align="center"><img src="https://pic.leetcode-cn.com/1598951281-ZCBrif-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " height="200px"></p>
<p>店长告诉小扣，这里是「几何学的快问快答」，店长可能有两种操作：</p>
<ul>
<li><code>open(int index, int direction)</code> - 若小孔处于关闭状态，则打开小孔，照入光线；否则直接照入光线；</li>
<li><code>close(int index)</code> - 关闭处于打开状态小孔，店长保证不会关闭已处于关闭状态的小孔；</li>
</ul>
<p>其中：</p>
<ul>
<li><code>index</code>： 表示小孔序号</li>
<li><code>direction</code>：<code>1</code> 表示光线沿 <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>y</mi><mo>=</mo><mi>x</mi></mrow><annotation encoding="application/x-tex">y=x</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.625em;vertical-align:-0.19444em;"></span><span class="mord mathdefault" style="margin-right:0.03588em;">y</span><span class="mspace" style="margin-right:0.2777777777777778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right:0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height:0.43056em;vertical-align:0em;"></span><span class="mord mathdefault">x</span></span></span></span> 方向，<code>-1</code> 表示光线沿 <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>y</mi><mo>=</mo><mo>−</mo><mi>x</mi></mrow><annotation encoding="application/x-tex">y=-x</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.625em;vertical-align:-0.19444em;"></span><span class="mord mathdefault" style="margin-right:0.03588em;">y</span><span class="mspace" style="margin-right:0.2777777777777778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right:0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height:0.66666em;vertical-align:-0.08333em;"></span><span class="mord">−</span><span class="mord mathdefault">x</span></span></span></span> 方向。</li>
</ul>
<p align="center"><img src="https://pic.leetcode-cn.com/1599620810-HdOlMi-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " height="200px"></p>
<p>当光线照至边界时：若边界上的小孔为开启状态，则光线会射出；否则，光线会在小孔之间进行反射。特别地：</p>
<ol>
<li>若光线射向未打开的拐角（黑盒顶点），则光线会原路反射回去；</li>
<li>光线自拐角处的小孔照入时，只有一种入射方向（如自序号为 0 的小孔照入方向只能为 <code>-1</code>）</li>
</ol>
<p align="center"><img src="https://pic.leetcode-cn.com/1598953840-DLiAsf-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " height="200px"></p>
<p>请帮助小扣判断并返回店长每次照入的光线从几号小孔射出。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<br>
<code>["BlackBox","open","open","open","close","open"]</code><br>
<code>[[2,3],[6,-1],[4,-1],[0,-1],[6],[0,-1]]</code></p>
<p>输出：<code>[null,6,4,6,null,4]</code></p>
<p>解释：<br>
BlackBox b = BlackBox(2,3); // 新建一个 2x3 的黑盒<br>
b.open(6,-1) // 打开 6 号小孔，并沿 y=-x 方向照入光线，光线至 0 号小孔反射，从 6 号小孔射出<br>
b.open(4,-1) // 打开 4 号小孔，并沿 y=-x 方向照入光线，光线轨迹为 4-2-8-2-4，从 4 号小孔射出<br>
b.open(0,-1) // 打开 0 号小孔，并沿 y=-x 方向照入光线，由于 6 号小孔为开启状态，光线从 6 号小孔射出<br>
b.close(6) // 关闭 6 号小孔<br>
b.shoot(0,-1) // 从 0 号小孔沿 y=-x 方向照入光线，由于 6 号小孔为关闭状态，4 号小孔为开启状态，光线轨迹为 0-6-4，从 4 号小孔射出</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<br>
<code>["BlackBox","open","open","open","open","close","open","close","open"]</code><br>
<code>[[3,3],[1,-1],[5,1],[11,-1],[11,1],[1],[11,1],[5],[11,-1]]</code></p>
<p>输出：<code>[null,1,1,5,1,null,5,null,11]</code></p>
<p>解释：</p>
<p align="center"><img src="https://pic.leetcode-cn.com/1599204202-yGDMVk-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " height="300px"></p>
<p>BlackBox b = BlackBox(3,3); // 新建一个 3x3 的黑盒<br>
b.open(1,-1) // 打开 1 号小孔，并沿 y=-x 方向照入光线，光线轨迹为 1-5-7-11-1，从 1 号小孔射出<br>
b.open(5,1) // 打开 5 号小孔，并沿 y=x 方向照入光线，光线轨迹为 5-7-11-1，从 1 号小孔射出<br>
b.open(11,-1) // 打开 11 号小孔，并沿逆 y=-x 方向照入光线，光线轨迹为 11-7-5，从 5 号小孔射出<br>
b.open(11,1) // 从 11 号小孔沿 y=x 方向照入光线，光线轨迹为 11-1，从 1 号小孔射出<br>
b.close(1) // 关闭 1 号小孔<br>
b.open(11,1) // 从 11 号小孔沿 y=x 方向照入光线，光线轨迹为 11-1-5，从 5 号小孔射出<br>
b.close(5) // 关闭 5 号小孔<br>
b.open(11,-1) // 从 11 号小孔沿 y=-x 方向照入光线，光线轨迹为 11-1-5-7-11，从 11 号小孔射出</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= n, m &lt;= 10000</code></li>
<li><code>1 &lt;= 操作次数 &lt;= 10000</code></li>
<li><code>direction</code> 仅为 <code>1</code> 或 <code>-1</code></li>
<li><code>0 &lt;= index &lt; 2*(m+n)</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class BlackBox {
public:
    BlackBox(int n, int m) {

    }
    
    int open(int index, int direction) {

    }
    
    void close(int index) {

    }
};

/**
 * Your BlackBox object will be instantiated and called as such:
 * BlackBox* obj = new BlackBox(n, m);
 * int param_1 = obj->open(index,direction);
 * obj->close(index);
 */
```




