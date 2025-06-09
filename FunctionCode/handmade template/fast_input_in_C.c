// #include <stdio.h>
// #define BUF_SIZE (1<<24)

// char buf[BUF_SIZE];
// 아마 char로 다 받고 분리 가능한 쉬운 형태로 받아서 한 듯 함.
// int main(void){
//     int cursor = -1;
//     fread(buf, sizeof(char), BUF_SIZE, stdin);

//     while(buf[++cursor] & 16); // 16: 00010000  
    

//     return 0;
// }

#include <stdio.h>
#define BUF_SIZE (1 << 24)

char buf[BUF_SIZE];

int main(void)
{
    int cursor = -1;
    
    fread(buf, sizeof(char), BUF_SIZE, stdin);
    while (buf[++cursor] & 16);
    int m = 0;
    while (buf[++cursor] & 16)
        m = m * 10 + (buf[cursor] & 15);
    int k = 0;
    while (buf[++cursor] & 16)
        k = k * 10 + (buf[cursor] & 15);
    
    int tmp;
    
    for (int i = 1; i <= m; i++)
    {
        while (buf[++cursor] & 16);
        tmp = 0;
        while (buf[++cursor] & 16)
            tmp = tmp * 10 + (buf[cursor] & 15);
        if ((k -= tmp) < 0)
        {
            printf("%d 1", i);
            return 0;
        }
    }
    
    printf("-1");
    return 0;
}