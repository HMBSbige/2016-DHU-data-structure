#include <cstring>
#include <cstdio>
int items[1000];
int container_size(int size, int value)
{
    int sum = 0, count = 1;
    for (int i = 0; i < size; ++ i) {
        if (items[i] > value) {
            return size;
        }
        if (sum + items[i] > value) {
            sum = items[i];
            count ++;
        }else {
            sum += items[i];
        }
    }
    return count;
}

int main()
{
    int n, m;
    while (~scanf("%d%d",&n,&m)) 
    {
        int sum = 0, max = 0;
        for (int i = 0; i < n; ++ i)
        {
            scanf("%d",&items[i]);
            sum += items[i];
            if (max < items[i]) 
            {
                max = items[i];
            }
        }

        int l = max, r = sum, mid = 0;
        while (l < r) {
            mid = (l+r)/2;
            if (container_size(n, mid) <= m) 
            {
                r = mid;
            }
            else 
            {
                l = mid+1;
            }
        }

        printf("%d\n",l);
    }
    return 0;
}
