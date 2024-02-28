class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(list)


        for i in range(len(equations)):
            a, b = equations[i]
            graph[a].append((b, values[i]))
            graph[b].append((a, 1/values[i]))

        def dfs(src: str, dst: str, visited: set) -> float:
            if src not in graph or dst not in graph:
                return -1.0  

            if src == dst:
                return 1.0

            visited.add(src)
            result = -1.0

            for nei, val in graph[src]:
                if nei not in visited:
                    subresult = dfs(nei, dst, visited)
                    if subresult != -1.0:
                        result = val * subresult
                        break

            # visited.remove(src)
            return result

        answers = []

        for x, y in queries:
            ans = dfs(x, y, set())
            answers.append(ans)

        return answers