class Solution:
    def tsp(self, cost):
        n = len(cost)
        VISITED_ALL = (1 << n) - 1
        
        # dp[mask][pos]
        dp = [[-1] * n for _ in range(1 << n)]
        
        def solve(mask, pos):
            # If all cities visited, return cost to go back to start
            if mask == VISITED_ALL:
                return cost[pos][0]
            
            # If already computed
            if dp[mask][pos] != -1:
                return dp[mask][pos]
            
            ans = float('inf')
            
            # Try visiting all unvisited cities
            for city in range(n):
                if (mask & (1 << city)) == 0:
                    new_cost = cost[pos][city] + solve(mask | (1 << city), city)
                    ans = min(ans, new_cost)
            
            dp[mask][pos] = ans
            return ans
        
        # Start from city 0 with mask having only city 0 visited
        return solve(1, 0)