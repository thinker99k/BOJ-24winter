arr = []

row0 = [0] * 10
row1 = [1] * 10

arr.append(row0)
arr.append(row1)

for row in range(2, 66):
    line = [1]

    for col in range(1, 10):
        line.append(line[col - 1] + arr[row - 1][col])
    arr.append(line)

t = int(input())

ans = []

for i in range(0, t):
    x = int(input())
    ans.append(arr[x + 1][9])

for i in range(0, t):
    print(ans[i])
