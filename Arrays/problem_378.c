int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}
int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    int col = matrixColSize[0] * matrixColSize[0];
    int* arr = malloc(col * sizeof(int));
    int ind = 0;
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixColSize[i]; j++){
            arr[ind++] = matrix[i][j];
        }
    }
    qsort(arr, matrixSize * matrixSize, sizeof(int), cmp);
    ind = arr[k - 1];
    free(arr);
    arr = NULL;
    return ind;
}
