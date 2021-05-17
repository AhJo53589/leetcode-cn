# leetcode-cn

## Algorithm

### 并查集

```C++
struct DSU {
    DSU(int n) : data(n, -1) {}

    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;

        if (data[y] < data[x]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    bool same(int x, int y) { 
        return root(x) == root(y); 
    }

    int root(int x) { 
        return data[x] < 0 ? x : data[x] = root(data[x]); 
    }

    int size(int x) { 
        return -data[root(x)]; 
    }

    std::vector<int> data;
};
```

### 快速幂取模 大数相乘取模
```C++
    long long qmul(long long x, long long y, long long mod) {
        long long ret = 0;
        while (y) {
            if (y & 1)
                ret = (ret + x) % mod;
            x = x * 2 % mod;
            y >>= 1;
        }
        return ret;
    }

    long long qpow(long long a, long long n, long long mod) {
        long long ret = 1;
        while (n)
        {
            if (n & 1) ret = qmul(ret, a, mod);
            a = qmul(a, a, mod);
            n >>= 1;
        }
        return ret;
    }
```