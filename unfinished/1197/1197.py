from queue import Queue
from dataclasses import dataclass

DEBUG = False


@dataclass
class Edge:
    start: int
    end: int
    distance: int


class Node:
    def __init__(self, name: int):
        self.name = name
        self.neighbors = []  # Edge = <int, int>


def main():
    v, e = map(int, input().split())

    edges = []

    for i in range(0, e):
        s, e, d = map(int, input().split())
        edges.append(Edge(s, e, d))



