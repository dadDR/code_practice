//547：省份数量 ； 图 ； 时间：2024.9.23

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    //使用广度优先搜索,如果城市未被访问，就从这个城市开始广度优先搜索
    int cities = isConnectedSize;
    int visited[cities];
    memset(visited, 0, sizeof(visited));
    int province = 0;
    //创建队列
    int queue[cities * cities];
    int left = 0;
    int right = 0;
    for(int i = 0 ; i < cities ; i++)
    {
        if(!visited[i])
        {
            queue[right++] = i;
            while(left < right)
            {
                int j = queue[left++];
                visited[j] = true;
                for(int k = 0 ; k < cities ; k++)
                {
                    if(isConnected[j][k] == 1 && !visited[k])
                    {
                        queue[right++] = k;
                    }
                }
            }
            province++;
        }
    }
    return province;
}
