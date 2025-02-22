from queue import Queue

DEBUG = False


class Node:
    def __init__(self, val: str, row: int, col: int):
        self.val = val
        self.row = row
        self.col = col
        self.childs = [None for _ in range(0, 4)]


def bfs(q):
    ret = ""

    while not q.empty():
        pp = q.get()
        ret += pp.val

        if DEBUG:
            print(f"({pp.row},{pp.col}): {pp.val}")

        for child in pp.childs:
            if child is not None:
                q.put(child)

    return ret


def chk(dist, node, arr):
    firstcolor = arr[node.row][node.col]

    for i in range(node.row, node.row + dist):
        for j in range(node.col, node.col + dist):
            if arr[i][j] != firstcolor:
                return False

    return True


def quadtree(dist, node, arr):
    if DEBUG:
        print(f"({node.row}, {node.col})", end='')

    if chk(dist, node, arr):  # 현재 영역이 동일하면
        node.val = "0" + str(arr[node.row][node.col])
        if DEBUG:
            print(f" - yes : {node.val}")

    else:  # 현재 영역이 동일하지 않으면
        node.val = "1"  # 자식이 있다
        if DEBUG:
            print(f" - no  : {node.val}")

        nextdist = int(dist // 2)
        nextrow = [node.row, node.row, node.row + nextdist, node.row + nextdist]
        nextcol = [node.col, node.col + nextdist, node.col, node.col + nextdist]

        node.childs = [Node("", nextrow[i], nextcol[i]) for i in range(4)]

        for i in range(0, 4):
            if DEBUG:
                print(f"nextdist : {nextdist}")
            quadtree(nextdist, node.childs[i], arr)


def bintohex(binstr):
    zfilled = ""

    if DEBUG:
        print(f"bin : {binstr}")

    padding = len(binstr) % 4
    if padding != 0:
        zfilled = "0" * (4 - padding)
    zfilled += binstr

    ret = ""
    for i in range(0, len(zfilled), 4):
        chunk = int(zfilled[i:i+4], 2)
        tohex = hex(chunk)[2:].upper()

        if DEBUG:
            print(f"{chunk} -> {tohex}")
        ret += tohex

    if DEBUG:
        print(f"hex : {ret}")

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

        root = Node("", 0, 0)
        quadtree(n, root, arr)

        q = Queue()  # 사실 리스트임!
        q.put(root)
        binlist.append(bfs(q))

    hexlist = []

    for binstr in binlist:
        hexlist.append(bintohex(binstr))

    for hexstr in hexlist:
        print(str(hexstr))


main()
