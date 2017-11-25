#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <string.h>
#include <queue>
#include <list>
#include <utility>

#define INF 100000000

using namespace std;

int Find(int subset[], int v){
    if(subset[v] == -1){
        return v;
    }
    return find(subset, subset[v]);
}

bool tem_ciclo(int subset[], int v1, int v2){
    int v1_set = find(subset, v1);
    int v2_set = find(subset, v2);
    if(v1_set != v2_set){
        subset[v1_set] = v2_set;
        return true;
    }
    return false;
}

bool ordena(const pair<int, pair<int, int> > &a, const pair<int, pair<int, int> > &b){
    return a.second.second < b.second.second;
}

bool finaliza(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main(){

    int quantE, quantV;

    scanf("%d %d", &quantE, &quantV);

    vector<pair<int, pair<int, int> > > vet;
    int x, y, z;

    long long int total = 0;

    for(int i = 0; i < quantV; i++){
        scanf("%d %d %d", &x, &y, &z);
        vet.push_back(make_pair(x, make_pair(y, z)));
        vet.push_back(make_pair(y, make_pair(x, z)));
    }

    int *subset = new int[quantE + 1];
    memset(subset, -1, sizeof(int)*(quantE + 1));

    sort(vet.begin(), vet.end(), ordena);

    vector<pair<int, int> > pares;

    for(int i = 0; i < vet.size(); i++){
        if(tem_ciclo(subset, vet[i].first, vet[i].second.first)){
            pares.push_back(make_pair(vet[i].first, vet[i].second.first));
        }
    }

    sort(pares.begin(), pares.end(), finaliza);

    for(int i = 0; i < pares.size(); i++){
        printf("%d -> %d\n", pares[i].first, pares[i].second);
    }




    return 0;
}