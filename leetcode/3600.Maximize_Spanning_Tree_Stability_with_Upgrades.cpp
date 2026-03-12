// Approach: Union Find + Binary Search + Implementation check
class Solution {
public:
    
    struct DSU {
        vector<int> parent, rankv;

        DSU(int n){
            parent.resize(n);
            rankv.resize(n,0);
            for(int i=0;i<n;i++) parent[i]=i;
        }

        int find(int x){
            if(parent[x]==x) return x;
            return parent[x]=find(parent[x]);
        }

        bool unite(int a,int b){
            a=find(a);
            b=find(b);
            if(a==b) return false;

            if(rankv[a] < rankv[b]) swap(a,b);
            parent[b]=a;
            if(rankv[a]==rankv[b]) rankv[a]++;

            return true;
        }
    };

    bool check(int X, int n, vector<vector<int>>& edges, int k){

        DSU dsu(n);
        int used = 0;

        vector<pair<int,int>> good;
        vector<pair<int,int>> upgrade;

        for(auto &e: edges){
            int u=e[0], v=e[1], s=e[2], must=e[3];

            if(must){
                if(s < X) return false;

                if(!dsu.unite(u,v)) 
                    return false;  // cycle among mandatory edges

                used++;
            }
            else{
                if(s >= X)
                    good.push_back({u,v});
                else if(2*s >= X)
                    upgrade.push_back({u,v});
            }
        }

        for(auto &p: good){
            if(dsu.unite(p.first,p.second))
                used++;
        }

        int upgrades = 0;

        for(auto &p: upgrade){
            if(dsu.unite(p.first,p.second)){
                used++;
                upgrades++;
            }
        }

        return used == n-1 && upgrades <= k;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int lo = 1, hi = 200000;
        int ans = -1;

        while(lo <= hi){

            int mid = lo + (hi-lo)/2;

            if(check(mid, n, edges, k)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return ans;
    }
};
