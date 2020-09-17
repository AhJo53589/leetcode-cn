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

