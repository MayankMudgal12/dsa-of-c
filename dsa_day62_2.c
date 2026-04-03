#include <stdbool.h>

void dfs(int** rooms, int* roomsColSize, int* visited, int i) {
    visited[i] = 1;
    for (int j = 0; j < roomsColSize[i]; j++) {
        int key = rooms[i][j];
        if (!visited[key])
            dfs(rooms, roomsColSize, visited, key);
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int visited[1000] = {0};

    dfs(rooms, roomsColSize, visited, 0);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i])
            return false;
    }

    return true;
}