int maxDistance(int* colors, int colorsSize) {
    // 각 색상의 첫 번째 등장 위치와 마지막 등장 위치를 저장하는 배열
    int first[100001] = {0};
    int last[100001] = {0};
    for (int i = 0; i < 100001; i++) {
        first[i] = -1;  // 색상이 아직 등장하지 않았음을 나타내기 위해 -1로 초기화
    }

    // 각 색상의 첫 등장 위치와 마지막 등장 위치를 찾습니다.
    for (int i = 0; i < colorsSize; i++) {
        if (first[colors[i]] == -1) {
            first[colors[i]] = i;
        }
        last[colors[i]] = i;
    }

    int maxDist = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = i + 1; j < 1000; j++) {
            // 두 색상이 모두 등장했는지 확인합니다.
            if (first[i] != -1 && first[j] != -1) {
                // 첫 번째 색상의 마지막 위치와 두 번째 색상의 첫 위치 사이의 거리 계산
                int dist = abs(last[i] - first[j]);
                if (dist > maxDist) maxDist = dist;

                // 두 번째 색상의 마지막 위치와 첫 번째 색상의 첫 위치 사이의 거리 계산
                dist = abs(last[j] - first[i]);
                if (dist > maxDist) maxDist = dist;
            }
        }
    }

    return maxDist;
}
