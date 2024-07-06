#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct arr
{
    int list_idx;
    int udt_idx;

    arr(int l_idx, int u_idx) : list_idx(l_idx), udt_idx(u_idx) {}
};

struct update
{
    int prev; //-1이면 첫번째
    int IDX;
    int VAL;
};

unordered_map<string, int> li_name; // 이름 - name_data 번호
vector<int *> li;                   // 배열 li[idx] idx번 배열
vector<arr> name_data;              // li번호, udate_flow 번호
vector<update> update_flow;         // 업데이트 내역

void init()
{
    if (!update_flow.empty())
        update_flow.clear();
    if (!li_name.empty())
        li_name.clear();
    if (!li.empty())
        li.clear();
    if (!name_data.empty())
        name_data.clear();
}

void makeList(char mName[], int mLength, int mListValue[])
{
    li_name.insert({mName, name_data.size()}); // 이름-idx 연결 맵

    int *temp = new int[mLength];
    for (int i = 0; i < mLength; ++i)
        temp[i] = mListValue[i];
    li.push_back(temp); // 배열 자체를 추가;

    update_flow.push_back(update{-1, -1, -1});
    name_data.push_back(arr(li.size() - 1, update_flow.size() - 1));
}

void copyList(char mDest[], char mSrc[], bool mCopy)
{
    if (mCopy)
    { // 깊은 복사
        name_data.push_back({name_data[li_name[mSrc]].list_idx, name_data[li_name[mSrc]].udt_idx});
        li_name.insert({mDest, name_data.size() - 1});
    }
    else
    { // 얕은 복사
        li_name.insert({mDest, li_name[mSrc]});
    }
}

void updateElement(char mName[], int mIndex, int mValue)
{
    int idx_nameData = li_name[mName];
    int idx_updateFlow = name_data[idx_nameData].udt_idx;
    int idx_prev = update_flow[idx_updateFlow].prev;

    update_flow.push_back({idx_updateFlow, mIndex, mValue});
    name_data[idx_nameData].udt_idx = update_flow.size() - 1;
}

int element(char mName[], int mIndex)
{
    int idx_nameData = li_name[mName];
    int idx_li = name_data[idx_nameData].list_idx;
    int idx_updateFlow = name_data[idx_nameData].udt_idx;

    while (update_flow[idx_updateFlow].IDX != mIndex && update_flow[idx_updateFlow].prev != -1)
    {
        idx_updateFlow = update_flow[idx_updateFlow].prev;
    }
    if (update_flow[idx_updateFlow].IDX == mIndex)
    {
        return update_flow[idx_updateFlow].VAL;
    }
    else if (update_flow[idx_updateFlow].prev == -1)
    {
        return li[idx_li][mIndex];
    }
}