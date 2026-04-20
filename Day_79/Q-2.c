class Solution:
    
    def kosaraju(self, V, edges):
        # Step 1: Create adjacency list
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
        
        # Step 2: DFS to fill stack (based on finishing time)
        visited = [False] * V
        stack = []
        
        def dfs(u):
            visited[u] = True
            for v in adj[u]:
                if not visited[v]:
                    dfs(v)
            stack.append(u)
        
        for i in range(V):
            if not visited[i]:
                dfs(i)
        
        # Step 3: Reverse the graph
        rev_adj = [[] for _ in range(V)]
        for u, v in edges:
            rev_adj[v].append(u)
        
        # Step 4: DFS on reversed graph using stack
        visited = [False] * V
        scc_count = 0
        
        def rev_dfs(u):
            visited[u] = True
            for v in rev_adj[u]:
                if not visited[v]:
                    rev_dfs(v)
        
        while stack:
            node = stack.pop()
            if not visited[node]:
                rev_dfs(node)
                scc_count += 1
        
        return scc_count