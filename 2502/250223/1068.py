from queue import Queue

DEBUG = False


class Node:
    def __init__(self, val: int):
        self.val = val
        self.childs = []  # int


if DEBUG:
    def prnq(q):
        if not q.empty():
            print("<< ", end='')
            for x in list(q.queue):
                print(x, end=' ')
            print(">>")
        else:
            print("<< empty >>")


def bfs(g, q, todel):
    ret = 0

    while not q.empty():
        if DEBUG:
            prnq(q)

        pp = q.get()

        if DEBUG:
            print(f"visited {pp}")
            prnq(q)

        nextcount = 0

        for child in g[pp].childs:
            if child is not None:
                if child != todel:
                    q.put(child)
                    nextcount += 1

        # pp가 leaf인지 아닌지는 다음 전개를 했냐 안했냐로 결정
        if nextcount == 0:
            if DEBUG:
                print(f"{pp} is leaf!")

            ret += 1

    return ret


def main():
    n = int(input())
    graph = [Node(i) for i in range(0, n)]

    root = -1
    todelete = -1

    parents = list(map(int, input().split()))  # 0~n-1번 노드의 부모

    # i는 부모노드의 idx

    for i in range(0, n):
        # i의 부모는 parent[i] = parent[i]의 자식은 i

        if parents[i] == -1:  # 부모가 없을 경우 = 루트 노드인 경우
            root = i
        else:  # 부모가 있을 경우
            graph[parents[i]].childs.append(i)

    todelete = int(input())

    queue = Queue()  # int 큐
    queue.put(root)

    if root == todelete:
        ans = 0
    else:
        ans = bfs(graph, queue, todelete)

    print(ans)


main()
