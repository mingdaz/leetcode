class Solution(object):
    def shortestDistance(self, maze, start, destination):
        """
        :type maze: List[List[int]]
        :type start: List[int]
        :type destination: List[int]
        :rtype: int
        """
        n = len(maze)
        m = len(maze[0])
        distance = [[float('inf')]*m for _ in range(n)]
        queue = []
        heapq.heappush(queue, (0, start[0], start[1]))
        dirs = ((0, 1), (0, -1), (1, 0), (-1, 0))

        while queue:
            
            curr, i, j = heapq.heappop(queue)
            if i == destination[0] and j == destination[1]:
                return curr
            else:
                for x, y in dirs:
                    row = i + x
                    col = j + y
                    new = curr
                    while 0 <= row < n and 0 <= col < m and maze[row][col] != 1:
                        row += x
                        col += y
                        new += 1
                    row -= x
                    col -= y
                    if distance[row][col] > new:
                        distance[row][col] = new
                        heapq.heappush(queue, (new, row, col))
        
        return -1