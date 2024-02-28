int n;

// 깊이 우선 탐색(DFS) 함수
void dfs(int** isConnected, bool* vis, int num, int n) {
    // 현재 노드 방문 표시
    vis[num] = true;

    // 현재 노드와 연결된 노드들을 확인하면서 DFS 호출
    for (int i = 0; i < n; i++) {
        if (isConnected[num - 1][i] == 1 && !vis[i + 1]) {
            dfs(isConnected, vis, i + 1, n);
        }
    }
}

// 서로 연결된 노드의 그룹 수를 찾는 함수
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    // 노드의 수 저장
    n = isConnectedSize;

    // 그룹의 수를 세기 위한 변수
    int count = 0;

    // 방문 여부를 저장하는 배열 동적 할당
    bool* vis = (bool*)malloc((n + 1) * sizeof(bool));
    
    // 방문 여부 배열 초기화
    for (int i = 1; i < n + 1; i++) {
        vis[i] = false;
    }

    // 모든 노드에 대해서 DFS 수행하면서 그룹 수 카운트
    for (int i = 1; i < n + 1; i++) {
        if (!vis[i]) {
            dfs(isConnected, vis, i, n);
            count++;
        }
    }

    // 동적 할당된 메모리 해제
    free(vis);

    // 최종 그룹의 수 반환
    return count;
}