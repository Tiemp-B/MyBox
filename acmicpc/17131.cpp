#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

#define divider 1000000007
#define IMAX 2147483647
using namespace std;

struct pos
{
    int x;
    int y;
    bool operator<(const pos next) const
    {
        if (x == next.x)
            return y < next.y;
        return x > next.x;
    }
};

struct star
{
    int sx = 0;
    int sy = 0;
    int ex = 0;
    int ey = 0;
    int cnt = 0;
};

star* starfield;
queue<int> tray;
vector<pair<int, int>> starBox;

int minX = IMAX, maxX = -IMAX, minY = IMAX, maxY = -IMAX;

pair<int, int> makeField(int N)//N <=2x10^5    2^6 * 3125 < 2^6 * 2^12  Omax(18)
{
    int h = 1;
    int cnt = 0;
    int prev;
    while (N > h)
    {
        cnt += h;
        prev = h;
        h <<= 1;
    }
    starfield = new star[cnt + h + 1];

    return make_pair(prev, h);
}

void insertStar(int N, int last, int last1)
{
    int x, y;
    priority_queue<pos> pq;
    for (int i = 0; i < last; ++i)
    {
        if(i>=N){
            starfield[i+last] = {0, 0, 0, 0, 0};
            continue;
        }
        cin >> x >> y;
        if (minX > x)
            minX = x;
        if (maxX < x)
            maxX = x;
        if (minY > y)
            minY = y;
        if (maxY < y)
            maxY = y;
        starfield[i + last] = {x, y, x, y, 1};
        starBox.push_back(make_pair(x, y));
        //pq.push(pos{ x, y });
    }
    int cnt = 0;
    int temp = last;

    // for(int i=1, t = 1; i<temp*2; ++i){
    //     if(starfield[i].cnt !=0)
    //         printf("|%3d:%3d, %3d:%3d|",starfield[i].sx, starfield[i].ex, starfield[i].sy,starfield[i].ey);
    //     else
    //         printf("|   :   ,    :   |");
    //     if(i+1 == t*2) {
    //         cout<<endl;
    //         t *= 2;
    //     }
    // }
    // cout<<"insert end\n";
}

void calcField2(int last){

    for(int now=last; now <last*2 ;now +=2){
        if (starfield[now].cnt != 0 && starfield[now+1].cnt != 0)
        {
            int sx, ex, sy,ey;
            if(starfield[now].sx < starfield[now + 1].sx) sx = starfield[now].sx;
            else sx = starfield[now + 1].sx;
            if(starfield[now].ex < starfield[now + 1].ex) ex = starfield[now + 1].ex;
            else ex = starfield[now].ex;
            if(starfield[now].sy < starfield[now + 1].sy) sy = starfield[now].sy;
            else sy = starfield[now + 1].sy;
            if(starfield[now].ey < starfield[now + 1].ey) ey = starfield[now + 1].ey;
            else ey = starfield[now].ey;

            starfield[now / 2].sx = sx;
            starfield[now / 2].ex = ex; 
            starfield[now / 2].sy = sy;
            starfield[now / 2].ey = ey;
            starfield[now / 2].cnt = starfield[now].cnt + starfield[now + 1].cnt;
        }
        else if (starfield[now].cnt == 0 && starfield[now + 1].cnt == 0)
        {
            starfield[now/2]={0,0,0,0,0};
        }
        else if (starfield[now].cnt != 0 && starfield[now + 1].cnt == 0)
        {
            starfield[now / 2].sx = starfield[now].sx;
            starfield[now / 2].ex = starfield[now].ex;
            starfield[now / 2].sy = starfield[now].sy;
            starfield[now / 2].ey = starfield[now].ey;
            starfield[now / 2].cnt = starfield[now].cnt;
        }
        else if (starfield[now].cnt == 0 && starfield[now + 1].cnt != 0)
        {
            starfield[now / 2].sx = starfield[now + 1].sx;
            starfield[now / 2].ex = starfield[now + 1].ex;
            starfield[now / 2].sy = starfield[now + 1].sy;
            starfield[now / 2].ey = starfield[now + 1].ey;
            starfield[now / 2].cnt = starfield[now + 1].cnt;
        }
    }
    if(last != 2) calcField2(last/2);
}

void calcField(int last)
{
    int temp = last;
    int now = last;

    while (last > 1)
    {
        if (starfield[now].cnt != 0 && starfield[now+1].cnt != 0)
        {
            starfield[now / 2].sx = (starfield[now].sx < starfield[now + 1].sx) ? starfield[now].sx : starfield[now + 1].sx;
            starfield[now / 2].ex = (starfield[now].ex < starfield[now + 1].ex) ? starfield[now + 1].ex : starfield[now].ex;
            starfield[now / 2].sy = (starfield[now].sy < starfield[now + 1].sy) ? starfield[now].sy : starfield[now + 1].sy;
            starfield[now / 2].ey = (starfield[now].ey < starfield[now + 1].ey) ? starfield[now + 1].ey : starfield[now].ey;
            starfield[now / 2].cnt = starfield[now].cnt + starfield[now + 1].cnt;
            now += 2;
            if (now >= last * 2)
            {
                last /= 2;
                now = last;
            }
        }
        else if (starfield[now].cnt == 0 && starfield[now + 1].cnt == 0)
        {
            last /= 2;
            now = last;
        }
        else if (starfield[now].cnt != 0 && starfield[now + 1].cnt == 0)
        {
            starfield[now / 2].sx = starfield[now].sx;
            starfield[now / 2].ex = starfield[now].ex;
            starfield[now / 2].sy = starfield[now].sy;
            starfield[now / 2].ey = starfield[now].ey;
            starfield[now / 2].cnt = starfield[now].cnt;

            now += 2;
            if (now >= last * 2)
            {
                last /= 2;
                now = last;
            }
        }
        else if (starfield[now].cnt == 0 && starfield[now + 1].cnt != 0)
        {
            starfield[now / 2].sx = starfield[now + 1].sx;
            starfield[now / 2].ex = starfield[now + 1].ex;
            starfield[now / 2].sy = starfield[now + 1].sy;
            starfield[now / 2].ey = starfield[now + 1].ey;
            starfield[now / 2].cnt = starfield[now + 1].cnt;
            now += 2;
            if (now >= last * 2)
            {
                last /= 2;
                now = last;
            }
        }
    }

    // for(int i=1, t = 1; i<temp*2; ++i){
    //     if(starfield[i].cnt !=0)
    //         printf("|%2d:%2d, %2d:%2d = %2d|",starfield[i].sx, starfield[i].ex, starfield[i].sy,starfield[i].ey, starfield[i].cnt);
    //     else
    //         printf("|  :  ,   :   =   |");
    //     if(i+1 == t*2) {
    //         cout<<endl;
    //         t *= 2;
    //     }
    // }
}

double countLU(int i, int tX, int tY) {
    double ans = 0;
    if (starfield[i].sy > tY && starfield[i].ex < tX) {//좌상에 다 있다
        return starfield[i].cnt;
    }
    else {
        if(starfield[i].cnt == 1) return 0;
        if (starfield[i * 2].cnt >= 1)
            ans += countLU(i * 2, tX, tY);
        if (starfield[i * 2 + 1].cnt >= 1)
            ans += countLU(i * 2 + 1, tX, tY);
    }
    return ans;
}

double countRU(int i, int tX, int tY) {
    double ans = 0;
    if (starfield[i].sy > tY && starfield[i].sx > tX) {//우상에 다 있다
        return starfield[i].cnt;
    }
    else {
        if(starfield[i].cnt == 1) return 0;
        if (starfield[i * 2].cnt >= 1)
            ans += countRU(i * 2, tX, tY);
        if (starfield[i * 2 + 1].cnt >= 1)
            ans += countRU(i * 2 + 1, tX, tY);
    }
    return ans;
}

int cntField(int x, int y)
{
    int ans = 0;
    /* left UP */
    int fromX = minX;
    int toX = x - 1;
    int fromY = y + 1;
    int toY = maxY;

    if (toX<fromX && fromY >toY) return 0;

    double cntLU = countLU(1, x, y);

    /* right Up */
    fromX = x + 1;
    toX = maxX;
    fromY = y + 1;
    toY = maxY;

    if (fromX > toX && fromY > toY) return 0;

    double cntRU = countRU(1, x, y);

    ans = cntLU * cntRU;
    while(ans >= divider) ans -= divider;

    return ans;
}


int main()
{
    int N;
    cin >> N;
    pair<int, int> A = makeField(N);//리턴 마지막 2개 라인의 원소 수
    insertStar(N, A.second, A.first);
    calcField2(A.second);
    int ans = 0;
    for (int i = 0, x, y; i < starBox.size(); ++i)
    {
        x = starBox[i].first;
        y = starBox[i].second;
        ans += cntField(x, y);
    }
    cout << ans;
    return 0;
}
/*
한 별에 대해서 그 별보다 x가 작고, y가 큰 별의 수 * x가 크고, y가 더 큰 별의 수
이중 조건 트리?
트리 2개

x 조건
y 조건
?


4*10^10 + 2*10^5

*/