#include <stdio.h>
#include <stdlib.h>

#define I_MAX 2147483647

int N, M;

int field[1000][1000];
bool wall[1000][1000];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

typedef struct ghost{
    int y;
    int x;
    struct ghost *next;
} ghost;

int main(){
    scanf("%d %d", &N, &M);
    
    int s_x, s_y, d_x, d_y;
    ghost* g_head = NULL;
    ghost* g_tail = NULL;

    for(int i=0; i<N; i++){
        for(int j=0;j <M; j++){
            char temp;
            scanf(" %c", &temp);
            field[i][j] = I_MAX;

            switch(temp){
                case '#':
                    wall[i][j] = true;
                    break;
                case 'N':
                    s_x = j;
                    s_y = i;
                    break;
                case 'D':
                    d_x = j;
                    d_y = i;
                    break;
                case 'G':
                    if(g_tail){
                        g_tail->next = (ghost*)malloc(sizeof(ghost));
                        g_tail = g_tail->next;
                    }else{
                        g_head = (ghost*)malloc(sizeof(ghost));
                        g_tail = g_head;
                    }
                    g_tail->x = j;
                    g_tail->y = i;
                    g_tail->next = NULL;
                    break;
            }
        }
    }

    // ghost minimum route 
    int ghost_route = I_MAX;
    ghost* temp_ghost = g_head;
    while(temp_ghost){
        int a = abs(d_y - temp_ghost->y) + abs(d_x - temp_ghost->x);
        if(ghost_route>a)
            ghost_route = a;
        temp_ghost = temp_ghost->next;
    }

    // BFS

    typedef struct queue{
        int y;
        int x;
        queue *next;
    } queue;

    queue* now = (queue*)malloc(sizeof(queue));
    now->y = s_y;
    now->x = s_x;
    queue* tail = now;
    queue* next;
    field[s_y][s_x] = 0; 
    while(now){
        //printf("%d %d : %d\n", now->x, now->y, field[now->y][now->x]);
        for(int d=0; d<3; d++){
            int new_x = now->x + dx[d];
            int new_y = now->y + dy[d];
            
            if(new_x < 0 || new_x >= M || new_y <0 || new_y >= N)
                continue;
            if(wall[new_y][new_x])
                continue;
            if(field[now->y][now->x] + 1 >= field[new_y][new_x])
                continue;
            field[new_y][new_x] = field[now->y][now->x] + 1;
            
            //printf("    %d %d : %d\n", new_x, new_y, field[new_y][new_x]);
            tail->next = (queue*)malloc(sizeof(queue));
            tail = tail->next;
            tail->x = new_x;
            tail->y = new_y;
            tail->next = NULL;
        }
        next = now->next;
        free(now);
        now = next;
    }
            
    
    if(field[d_y][d_x] < ghost_route)
        printf("Yes");
    else
        printf("No");


    return 0;
}
