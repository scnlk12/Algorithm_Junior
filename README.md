# Algorithm_Junior
### 题目描述
罗密欧与朱丽叶的迷宫。罗密欧与朱丽叶身处一个 m×n 的迷宫中。每一个方格表示迷宫中的一个房间。这 m×n 个房间中有一些房间是封闭的，不允许任何人进入。在迷宫中任何位置均可沿 8 个方向进入未封闭的房间。
罗密欧位于迷宫的(p，q)方格中，他必须找出一条通向朱丽叶所在的(r，s)方格的路。在抵达朱丽叶之前，他必须走遍所有未封闭的房间各一次，而且要使到达朱丽叶的转弯次数为最少。每改变一次前进方向算作转弯一次。
请设计一个算法帮助罗密欧找出这样一条道路。 
对于给定的罗密欧与朱丽叶的迷宫，编程计算罗密欧通向朱丽叶的所有最少转弯道路。
### 输入
第一行有 3 个正整数 n，m，k，分别表示迷宫的行数，列数和封闭的房间数。接下来的 k 行中，每行 2 个正整数，表示被封闭的房间所在的行号和列号。最后的 2 行，每行也有 2 个正整数，
分别表示罗密欧所处的方格(p，q)和朱丽叶所处的方格(r，s)。  
### 输出
输出计算出的罗密欧通向朱丽叶的最少转弯次数和有多少条不同的最少转弯道路。
### 输入样例
3 4 2<br>
1 2<br>
3 4<br>
1 1<br>
2 2
### 输出样例
6<br>
7<br>
1 -1 9 8<br>
2 10 6 7<br>
3 4 5 -1
