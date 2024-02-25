
### 并查集模板

并查集可以解决的问题有
- connected components
- minimum spanning tree

```c++
// Union Find template
vector<int>Father;
int N = s.size();
Father.resize(N);
for (int i = 0; i < N; i++)
    Father[i] = i;

int FindFather(int x) {
    if (Father[x] != x)
        Father[x] = FindFather(Father[x]);
    return Father[x];
}

void Union(int x, int y) {
    if (FindFather(x)==FindFather(y)) return; // there is a bug w/o this statement when union with the same father
    x = Father[x];
    y = Father[y];
    if (x < y)
        Father[y] = x;
    else
        Father[x] = y;
}
```
