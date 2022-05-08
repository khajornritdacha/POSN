m, n = input().split()
m = int(m)
n = int(n)

mat = []

for i in range (m):
    tmp2 = [int(j) for j in input().split()]
    mat.append(tmp2)

#print(mat)

for i in range (m):
    tmp2 = [int(j) for j in input().split()]
    for j in range (n):
        mat[i][j] += tmp2[j]

#print(mat)
for i in range (m):
    for j in range (n):
        print(mat[i][j], end = " ")
    print()
