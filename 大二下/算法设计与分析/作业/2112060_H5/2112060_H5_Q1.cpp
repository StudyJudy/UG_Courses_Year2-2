#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int k;//缓存大小k
    cin >> k;
    int n;//缓存中的初始块数n
    cin >> n;
    int s;//请求序列的块数s
    cin >> s;
    vector<int> cache(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> cache[i];//缓存块
    }
    vector<int> requests(s);
    for (int i = 0; i < s; i++) 
    {
        cin >> requests[i];//请求序列
    }
    map<int, int> last_used;//用来记录每个块上次使用的时间,cache[i]->last_used_time
    for (int i = 0; i < n; i++) //初始化已有元素的上次使用时间
    {
        last_used[cache[i]] = i;//缓存中的初始块的上次使用时间就是他们在缓存中的顺序
    }
    vector<int> eviction_schedule;//记录驱逐的块的值
    for (int i = 0; i < s; i++) 
    {
        int block = requests[i];//取出元素request[i]
        if (last_used.count(block)) //检查request[i]是不是已经在cache中，如果已经在了
        {
           // cout << "exist" << endl;
            continue;//进入下个循环，判断下一个块
        }
        if (cache.size() < k) //如果该块不在cache中，检查缓存块里是不是还有位置，如果有位置
        {
           // cout << "insert" << endl;
            cache.push_back(block);//request[i]放进cache去
            last_used[block] = i;//更新上次request[i]对应块上次使用时间
            continue;//进入下个循环，判断下一个块
        }
        // cache满了且不存在，需要替换，找到要清除的块
        map<int, int> next_used;//用来记录cache中每个块下次最近使用的时间,cache[i]->last_used_time
        for (int j = i + 1; j < s; j++)//从request序列中的第i个块之后的块去找cache中元素下次的最近的出现时间
        {
            int m;
            for (m = 0; m < k; m++)//遍历cache中每个元素
            {
                if (cache[m] == requests[j] && !next_used.count(cache[m]))//request[j]==cache[m]，且nest_used中还没有cache[m]
                {
                    next_used[cache[m]] = j;//cache[m]->next_used_time=j
                }
            }
        }
        int flag = 1;
        for (int m = 0; m < k; m++)
        {
            if (last_used[cache[m]] && !next_used.count(cache[m]))//后续序列中该块不再出现
            {
                next_used[cache[m]] = s + 1;//下次最近访问时间统一写成s+1
                flag = 0;
            }
        }
        if (flag == 0)//后续序列中存在不再使用的块
        {
            int evict_block = -1;//初始化
            int evict_time = s;//初始化
            for (auto it = last_used.begin(); it != last_used.end(); it++)
            {
                if (it->second < evict_time && next_used[it->first] == s + 1)//it的上次访问时间比当前记录的最远的访问时间还要久远，且it对应在后续requesr序列中不再出现
                {
                    evict_block = it->first;//更新
                    evict_time = it->second;//更新
                }
            }
            //清除块替换块
            last_used.erase(evict_block);//在记录上次访问时间中清除这个块记录
            for (int j = 0; j < cache.size(); j++) //在缓存中找到要被清除的这个块
            {
                if (cache[j] == evict_block)//用新的去替换 
                {
                    cache[j] = block;
                }
            }
            //cout << "replace" << endl;
            last_used[block] = i;//记录新加入的这个块的上次访问时间
            eviction_schedule.push_back(evict_block);//把被清除的块加入清除块序列的vector中
        }
        else if (flag == 1)//cache中的块在request序列中后续都有访问到
        {
            int evict_block = -1;//初始化记录最远访问的块
            int evict_time = -1;//初始化记录最远访问的块的访问时间
            for (int j = 0; j < n; j++)
            {
                for (auto it = next_used.begin(); it != next_used.end(); it++)
                {
                    if (it->second > evict_time)//更远
                    {
                        evict_block = it->first;//更新最远访问的块
                        evict_time = it->second;//更新最远访问的时间
                    }
                }
            }
            last_used.erase(evict_block);//在记录上次访问时间中清除这个块记录
            for (int j = 0; j < cache.size(); j++) //在缓存中找到要被清除的这个块
            {
                if (cache[j] == evict_block)//用新的去替换 
                {
                    cache[j] = block;
                }
            }
           // cout << "replace" << endl;
            last_used[block] = i;//记录新加入的这个块的上次访问时间
            eviction_schedule.push_back(evict_block);//把被清除的块加入清除块序列的vector中
        }
    }
    // 打印被驱逐块的序列
    for (int i = 0; i < eviction_schedule.size(); i++) 
    {
        cout << eviction_schedule[i] << " ";
    }
    cout << endl;
    return 0;
}
