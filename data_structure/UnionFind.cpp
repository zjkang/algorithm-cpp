// function template

// python version
// father = [0] * n
// for i in range(n):
//     father[i] = i

// def find_father(x):
//     if father[x] != x:
//         father[x] = find_father(father[x])
//     return father[x]

// def union(x, y):
//     x = find_father(x)
//     y = find_father(y)
//     if x < y:
//         father[y] = x
//     else:
//         father[x] = y
