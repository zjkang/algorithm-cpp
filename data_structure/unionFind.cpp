// function template

vector<int>Father;
int N = s.size();
Father.resize(N);
for (int i=0; i<N; i++)
    Father[i] = i;

int FindFather(int x) {
    if (Father[x]!=x)
        Father[x] = FindFather(Father[x]);
    return Father[x];
}

void Union(int x, int y) {
    x = Father[x];
    y = Father[y];
    if (x<y)
        Father[y] = x;
    else
        Father[x] = y;
}
