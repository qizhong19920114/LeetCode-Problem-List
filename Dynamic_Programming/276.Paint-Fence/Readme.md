### 276.Paint-Fence

这种排列组合的题，可能会想到是否有数学的解析方法．但解析方法往往也是由递归得到．所以不妨我们直接考虑递归或者ＤＰ的方法．

如果思考f(n)和f(n-1)的关系，那么解法就呼之欲出了．我们喷涂第ｎ个柱子，就是两种方案：和n-1的颜色一致，和n-1的颜色不一致．对于前者，我们必须保证n-2和n-1的颜色已经不能相同了，而对于后者，我们允许n-2和n-1的颜色相同．于是可以考虑dual status的ＤＰ方案，用same表示最近的两个柱子颜色一致的方案总数，diff表示最近的两个柱子颜色不一致的方案总数．

对于n，如果想喷涂和n-1一样的颜色，那么same(n)就要更新为diff(n-1)，颜色没有选择的余地

对于n，如果想喷涂和n-1不一样的颜色，那么diff(n)就要更新为[diff(n-1)+same(n-1)]*(k-1)，其中k-1表示颜色的选择种类．

上述的递归公式显示，我们只要不断更新两个状态变量same和diff即可．最后的答案就是两者之和．


[Leetcode Link](https://leetcode.com/problems/paint-fence)