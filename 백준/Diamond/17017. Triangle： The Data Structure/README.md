# [Diamond V] Triangle: The Data Structure - 17017 

[문제 링크](https://www.acmicpc.net/problem/17017) 

### 성능 요약

메모리: 38072 KB, 시간: 672 ms

### 분류

Empty

### 문제 설명

<p>In a parallel universe, the most important data structure in computer science is the triangle. A triangle of size M consists of M rows, with the i<sup>th</sup> row containing i elements. Furthermore, these rows must be arranged to form the shape of an equilateral triangule. That is, each row is centred around a vertical line of symmetry through the middle of the triangle. For example, the diagram below shows a triangle of size 4:</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/17017/1.svg" style="width: 198px; height: 186px;"></p>

<p>A triangle contains sub-triangles. For example, the triangle above contains ten sub-triangles of size 1, six sub-triangles of size 2 (two of which are the triangle containing (3,1,2) and the triangle containing (4,6,1)), three sub-triangles of size 3 (one of which contains (2,2,1,1,4,2)). Note that every triangle is a sub-triangle of itself.</p>

<p>You are given a triangle of size N and must find the sum of the maximum elements of every sub-triangle of size K.</p>

### 입력 

 <p>The first line contains two space-separated integers N and K (1 ≤ K ≤ N ≤ 3000).</p>

<p>Following this are N lines describing the triangle. The i<sup>th</sup> of these lines contains 𝑖 space-separated integers a<sub>i,j</sub> (0 ≤ a<sub>i,j</sub> ≤ 10<sup>9</sup>), representing the i<sup>th</sup> row of the triangle.</p>

<p>For 4 of the 15 available marks, N ≤ 1000.</p>

### 출력 

 <p>Output the integer sum of the maximum elements of every sub-triangle of size K.</p>

