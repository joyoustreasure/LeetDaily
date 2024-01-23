bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (n == 0) return true;

    for (int i = 0; i < flowerbedSize; i++) {

        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbedSize - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1; 
            n -= 1; 
        }
        if (n == 0) return true;
    }

    

    return false;
}