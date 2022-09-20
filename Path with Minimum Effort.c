typedef struct heights_data{
    int **heights;
    int heightsSize;
    int heightColSize;
}           t_heights_data;

typedef struct stored_efforts{
    int     *max_effort;
    int     *try_effort;
}           t_efforts;

int minimumEffortPath(int** heights, int heightsSize, int* heightsColSize){
    // 재귀 함수 호출
    t_heights_data      cell_datas;
    t_efforts           effort_datas;
    
    cell_datas.heights = heights;
    cell_datas.heightsSize = heightsSize;
    cell_datas.heightsColSize = heightsColSize;
    effort_datas.max_effort = pow(10, 6) - 1; // 문제 요건인 heights 범위 간 차이. 이거 아니면 함수 한 번 돌려서 한 루트 밟게 할 수도 있는데 뭐가 좋을지 모르겠음.
    effort_datas.try_effort = 0;
    route_backtrack(&cell_datas, 0, 0, &effort_datas);
    return (effort);
}

// 이미 밟은 cell을 다시 밟지 않기 위해 따로 저장해야할까? 아니면 다시 밟아도 되는 걸까? - 일단 고려하지 않는다.

int     route_backtrack(t_heights_data *cell_datas, int row_idx, int col_idx, t_efforts *efforts){
        int dir[4]; // top right bottom left
        int i = 0;
    
        route_direction_set(cell_datas, row_idx, col_idx, dir);
        if ((row_idx == cell_datas -> heightsSize - 1) && (col_idx == (cell_datas -> heightsColSize - 1))
        {
            if (efforts -> max_effort > efforts -> try_effort)
                efforts -> max_effort = efforts -> try_effort;
            return (0); // 새 루트 개척 종료 - 동일해도 그냥 버린다. 어차피 effort 최소인 루트가 중요함.
        }
        while (i < 4)
        {
            if (dir[i] == 1)
            {
                // 각 방향을 backtrack 인자에 넣기 위한 방안
                route_backtrack()
                dir[i] == 0;
            }
            i++;
        }
        return (0); // 모든 방향 확인 완료
       // 상하좌우 검사(반복문으로 순차적으로 - 해당 idx가 0이 아니라면)해서 각 dir_effort와 max_effort를 비교한다.    
        // max_effort보다 작으면 그 방향으로 재귀한다.
            // 만약 0이 돌아올 경우, 그 방향을 막는다 - 함수 반환값을 해당 방향 배열 index에 넣음
        // max_effort보다 크면 가지 않고 함수를 끝낸다. 0을 반환한다 
}

void    route_direction_set(t_heights_data *cell_datas, int row_idx, int col_idx, int dir[4]){
    dir[0] = row_idx == 0 ? 0 : 1;
    dir[1] = col_idx == (cell_datas -> heightsColSize - 1) ? 0 : 1;
    dir[2] = row_idx == (cell_datas -> heightsSize - 1) ? 0 : 1;
    dir[3] = col_idx == 0 ? 0 : 1;

    /* 삼항연산자 안 쓸 경우
    if (row_idx == 0)
        dir[0] = 0;
    if (col_idx == 0)
        dir[3] = 0;
    if (row_idx == cell_datas -> heightsSize)
        dir[2] = 0;
    if (col_idx == cell_datas -> heightColSize)
        dir[1] = 0;
    // 이러고도 1을 또 채워야 함
    */
}
