class Node:
    def __init__(self, val: str):
        self.val = val
        self.childs = [None] * 4


def bfs(q):
    ret = ""

    while q:
        pp = q.pop()

        ret += pp.val

        for child in pp.childs:
            if child is not None:
                q.append(child)

    return ret


def chk(dist, row, col, arr):
    firstcolor = arr[row][col]

    for i in range(row, row + dist):
        for j in range(col, col + dist):
            if arr[i][j] != firstcolor:
                return False

    return True


def quadtree(dist, row, col, node, arr):
    if chk(dist, row, col, arr):  # 현재 영역이 동일하면
        node.val = "0" + str(arr[row][col])
    else:  # 현재 영역이 동일하지 않으면
        node.val = "1"  # 자식이 있다

        for i in range(0, 4):
            node.childs[i] = Node("")

        nextdist = int(dist / 2)

        nextrow = [row, row, row + nextdist, row + nextdist]
        nextcol = [col, col + nextdist, col, col + nextdist]

        for i in range(0, 4):
            quadtree(nextdist, nextrow[i], nextcol[i], node.childs[i], arr)


def bintohex(binstr):
    zfilled = ""

    padding = len(binstr) % 4
    if padding != 0:
        zfilled = "0" * (4 - padding)
    zfilled += binstr

    ret = ""
    for i in range(0, len(zfilled), 4):
        chunk = zfilled[i:i+4]
        digit = int(chunk, 2)
        ret += "0123456789ABCDEF"[digit]

    return ret


def main():
    t = int(input())

    binlist = []

    for i in range(0, t):
        n = int(input())

        arr = [[0 for _ in range(n)] for _ in range(n)]

        for row in range(0, n):
            rowval = list(map(int, input().split()))

            for col in range(0, n):
                arr[row][col] = rowval[col]

        root = Node("")
        quadtree(n, 0, 0, root, arr)

        queue = []  # 사실 리스트임!
        queue.append(root)
        binlist.append(bfs(queue))

    hexlist = []

    for binstr in binlist:
        hexlist.append(bintohex(binstr))

    for hexstr in hexlist:
        print(str(hexstr))


main()
