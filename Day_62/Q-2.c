#include <stdbool.h>
#include <stdlib.h>

// DFS function
void dfs(int room, int** rooms, int* roomsColSize, bool* visited) {
    visited[room] = true;

    // Visit all keys in this room
    for (int i = 0; i < roomsColSize[room]; i++) {
        int nextRoom = rooms[room][i];
        if (!visited[nextRoom]) {
            dfs(nextRoom, rooms, roomsColSize, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));

    // Start DFS from room 0
    dfs(0, rooms, roomsColSize, visited);

    // Check if all rooms are visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }

    free(visited);
    return true;
}