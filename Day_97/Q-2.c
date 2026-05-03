class Solution:
    def minMeetingRooms(self, start, end):
        n = len(start)
        
        # Step 1: Sort both arrays
        start.sort()
        end.sort()
        
        i = 0  # start pointer
        j = 0  # end pointer
        
        rooms = 0
        max_rooms = 0
        
        while i < n:
            # Need new room
            if start[i] < end[j]:
                rooms += 1
                max_rooms = max(max_rooms, rooms)
                i += 1
            else:
                # Free a room
                rooms -= 1
                j += 1
        
        return max_rooms