typedef struct heights_data{
    int **heights;
    int **step;
    int heightsSize;
    int heightsColSize;
    int max_effort;
}           t_heights_data;

int     route_backtrack(t_heights_data *cell_datas, int row_idx, int col_idx, int try_effort);
void    route_direction_set(t_heights_data *cell_datas, int row_idx, int col_idx, int dir[4]);

int minimumEffortPath(int** heights, int heightsSize, int *heightsColSize){
    t_heights_data      cell_datas;
    int                 i = 0;
    int                 j = 0;
    
    cell_datas.step = (int **)malloc(sizeof(int *) * heightsSize);
    while (i < heightsSize)
    {
        cell_datas.step[i] = (int *)malloc(sizeof(int) * *heightsColSize);
        j = 0;
        while (j < *heightsColSize)
        {
            cell_datas.step[i][j] = 0;
            j++;
        }
        i++;
    }
    cell_datas.heights = heights;
    cell_datas.heightsSize = heightsSize;
    cell_datas.heightsColSize = *heightsColSize;
    cell_datas.max_effort = pow(10, 6) - 1;
    route_backtrack(&cell_datas, 0, 0, 0);
    return (cell_datas.max_effort);
}

int     route_backtrack(t_heights_data *cell_datas, int row_idx, int col_idx, int try_effort){
        int dir[4]; // top right bottom left // index
        int i = 0;
    
        cell_datas -> step[row_idx][col_idx] = 1;
        route_direction_set(cell_datas, row_idx, col_idx, dir);
        if ((row_idx == cell_datas -> heightsSize - 1) && (col_idx == cell_datas -> heightsColSize - 1))
        {
            if (cell_datas -> max_effort > try_effort)
                cell_datas -> max_effort = try_effort;
            return (0); // 새 루트 개척 종료 - 동일해도 그냥 버린다. 어차피 effort 최소인 루트가 중요함.
        }
        while (i < 4)
        {
            if (dir[i] == 1)
            {
                int now_height;
                int move_effort;
                int tmp_row_idx = row_idx;
                int tmp_col_idx = col_idx;

                now_height = cell_datas -> heights[row_idx][col_idx];
                if (i == 0)
                    tmp_row_idx--;
                else if (i == 1)
                    tmp_col_idx++;
                else if (i == 2)
                    tmp_row_idx++;
                else if (i == 3)
                    tmp_col_idx--;
                if (cell_datas -> step[tmp_row_idx][tmp_col_idx] == 0)
                {
                    move_effort =  abs(cell_datas -> heights[tmp_row_idx][tmp_col_idx] - now_height);
                    if (move_effort <= cell_datas -> max_effort)
                    {
                        if (move_effort > try_effort)
                            route_backtrack(cell_datas, tmp_row_idx, tmp_col_idx, move_effort);
                        else
                            route_backtrack(cell_datas, tmp_row_idx, tmp_col_idx, try_effort); 
                        cell_datas -> step[tmp_row_idx][tmp_col_idx] = 0;
                    }
                }
            }
            i++;
        }
        return (0);
}

void    route_direction_set(t_heights_data *cell_datas, int row_idx, int col_idx, int dir[4]){
    int i = 0;
    
    dir[0] = row_idx == 0 ? 0 : 1;
    dir[1] = col_idx == (cell_datas -> heightsColSize - 1) ? 0 : 1;
    dir[2] = row_idx == (cell_datas -> heightsSize - 1) ? 0 : 1;
    dir[3] = col_idx == 0 ? 0 : 1;
    return ;
}