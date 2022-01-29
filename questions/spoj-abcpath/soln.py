from typing import List


class Solution:
    h: int
    w: int
    matrix: List[List[int]]

    def __init__(self, h, w, count, matrix) -> None:
        self.h = h
        self.w = w
        self.matrix = matrix
        self.count = count
        self.is_visited = [[False for _ in range(w)] for __ in range(h)]

    def get_adjacent(self, i, j):
        return [(i, j), (i, j), (i+1, j-1), (i-1, j), (i+1, j), (i-1, j+1), (i, j+1), (i+1, j+1)]

    def is_valid(self, i, j, char):
        return i in range(self.h) and j in range(self.w) and ord(self.matrix[i][j]) == ord(char) + 1

    def dfs(self, i, j):
        print(self.is_visited)
        self.is_visited[i][j] = True
        self.count += 1

        for nexti, nextj in self.get_adjacent(i, j):
            if self.is_valid(nexti, nextj, self.matrix[i][j]):
                self.dfs(i, j)


def main():
    while True:
        h, w = [int(i) for i in input().split()]
        if not h and not w:
            break
        matrix = []
        # matrix input
        max_count = 0
        for i in range(h):
            matrix.append([i for i in input()])
        for i in range(h):
            for j in range(w):
                if matrix[i][j] == 'A':
                    count = 0
                    s = Solution(h, w, count, matrix)
                    s.dfs(i, j)
                    if count > max_count:
                        max_count = count
        print("max count is", max_count)


main()
