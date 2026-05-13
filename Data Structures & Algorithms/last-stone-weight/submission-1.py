from heapq import heapify, heappush, heappop
class Solution:

    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [- stone for stone in stones]
        heapify(stones)
        while len(stones):
            first = heappop(stones)
            if not stones:
                return - first
            second = heappop(stones)
            remain =  first - second
            if remain:
                heappush(stones, remain)
        return 0

"""
#class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # 1. Create a max-heap by negating all weights
        # O(n) time to heapify
        max_heap = [-stone for stone in stones]
        heapq.heapify(max_heap)
        
        # 2. Smash stones until 0 or 1 remain
        # O(n log n) total time
        while len(max_heap) > 1:
            # Extract the two heaviest stones
            stone1 = heapq.heappop(max_heap)
            stone2 = heapq.heappop(max_heap)
            
            # If they are not equal, the difference remains
            # (stone1 - stone2) works because they are negative
            # Example: -6 and -4 -> -6 - (-4) = -2
            if stone1 != stone2:
                heapq.heappush(max_heap, stone1 - stone2)
        
        # 3. Return the remaining stone or 0
        return -max_heap[0] if max_heap else 0
"""