class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph = defaultdict(list)
        visited = [float('inf')] * n
        visited[src] = 0

        for flight in flights:
            graph[flight[0]].append((flight[1], flight[2]))

        queue = deque([(src, 0)])  
        k += 1

        while k > 0 and queue:
            size = len(queue) 
            for _ in range(size):
                cur_node, cur_price = queue.popleft()
                for neighbor, price in graph[cur_node]:
                    new_price = cur_price + price
                    if new_price < visited[neighbor]:
                        visited[neighbor] = new_price
                        queue.append((neighbor, new_price))
            k -= 1

        return visited[dst] if visited[dst] != float('inf') else -1