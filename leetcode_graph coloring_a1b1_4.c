/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* gardenNoAdj(int n, int** paths, int pathsSize, int* pathsColSize, int* returnSize) {
    int graph[n][4];
    int degree[n];
    int *ans=(int*)malloc(sizeof(int)*n);

    for (int i=0;i<n;i++){
        degree[i]=0;
        ans[i]=0;
    }

    for(int i=0;i<pathsSize;i++){
        int x=paths[i][0]-1;
        int y=paths[i][1]-1;

        graph[x][degree[x]++]=y;
        graph[y][degree[y]++]=x;
    }

        for(int i=0;i<n;i++){
            bool used[5]={0};
            for (int j = 0; j < degree[i]; j++)
                used[ans[graph[i][j]]] = true;
            for (int f = 1; f <= 4; f++) {
                if(!used[f]){
                    ans[i]=f;
                    break;
             }
        }

    }
    *returnSize=n;
    return ans;

}