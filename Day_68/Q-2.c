from collections import defaultdict, deque

class Solution:
    def findOrder(self, words):
        # Step 1: Create graph and in-degree dictionary
        graph = defaultdict(set)
        in_degree = {char: 0 for word in words for char in word}

        # Step 2: Build the graph
        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i + 1]
            min_len = min(len(w1), len(w2))

            # Check invalid case: prefix issue
            if len(w1) > len(w2) and w1[:min_len] == w2[:min_len]:
                return ""

            for j in range(min_len):
                if w1[j] != w2[j]:
                    if w2[j] not in graph[w1[j]]:
                        graph[w1[j]].add(w2[j])
                        in_degree[w2[j]] += 1
                    break

        # Step 3: Add all nodes with in-degree 0 to queue
        queue = deque([char for char in in_degree if in_degree[char] == 0])

        # Step 4: Perform BFS (Kahn's Algorithm)
        result = []

        while queue:
            char = queue.popleft()
            result.append(char)

            for neighbor in graph[char]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)

        # Step 5: Check if valid topological ordering exists
        if len(result) != len(in_degree):
            return ""

        return "".join(result)