#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 4;
const int SIDES = 4;
const int MASK = (1 << N) - 1;
int possible[N * N], s[SIDES * N], e[SIDES * N], inc[SIDES * N];
int results[N][N];
int* my_clues;
vector<int> order;

int _clues[SIDES * N];
void print_binary(int x) {
    for (int i = N - 1; i >= 0; i--) printf("%d", (x & (1 << i)) ? 1 : 0);
}

void print_possible() {
    for (int i = 0; i < N * N; i++) {
        print_binary(possible[i]);
        printf(" ");
        if (i % N == N - 1) printf("\n");
    }
}

void set_value(int x, int v) {
    int m = MASK ^ (1 << v);
    int s_row = x - x % N;
    int s_col = x % N;
    for (int i = 0; i < N; i++) {
        possible[s_row + i] &= m;
        possible[s_col + i * N] &= m;
    }
    possible[x] = 1 << v;
}

int check_unique() {
    int n_decides = 0;
    for (int i = 0; i < SIDES / 2 * N; i++) {

        map<int, vector<int> > possible_indices;
        for (int j = s[i], k = 0; k < N; j += inc[i], k++) {
            for (int l = 0; l < N; l++) 
                if ((1 << l) & possible[j]) {
                    possible_indices[l].push_back(j);
                }
        }

        for (auto const &iter : possible_indices) {
            int val = iter.first;
            if (iter.second.size() == 1) {
                int idx = iter.second[0];
                if (possible[idx] != (1 << val)) {
                    n_decides++;
                    set_value(idx, val);
                }
            }
        }
    }
    return n_decides;
}

int count_possible(int val) {
    int n = 0;
    while (val) {
        n += val & 1;
        val >>= 1;
    }
    return n;
}

bool valid() {
    for (int i = 0; i < SIDES * N; i++) {
        if (my_clues[i] == 0) continue;

        bool is_decided = true;
        for (int j = s[i], k = 0; k < N; j += inc[i], k++) {
            if (count_possible(possible[j]) != 1) {
                is_decided = false;
                break;
            }
        }

        if (is_decided) {
            int largest = 0, n_clue = 0;
            for (int j = s[i], k = 0; k < N; j += inc[i], k++) {
                if (largest < possible[j]) {
                    n_clue++;
                    largest = possible[j];
                }
            }
            if (n_clue != my_clues[i]) return false;
        }
    }

    return true;
}

void write_results() {
    for (int i = 0; i < N * N; i++) {
        int x = i / N, y = i % N;
        for (int j = 0; j < N; j++) {
            if ((1 << j) == possible[i]) {
                results[x][y] = j + 1;
                break;
            }
        }
    }
}

bool dfs(int idx) {
    // printf("%d %d\n", idx, order[idx]);
    if (idx >= order.size()) {
        if (valid()) {
            write_results();
            return true;
        }
        return false;
    }

    int i = order[idx];
    int possible_bak[N * N];
    memcpy(possible_bak, possible, sizeof(int) * N * N);

    for (int j = 0; j < N; j++) {
        int m = (1 << j) & possible[i];
        if (m == 0) continue;

        set_value(i, j);
        bool found = false;
        if (valid()) {
            found = dfs(idx + 1);
        }
        if (found) {
            return true;
        }
        memcpy(possible, possible_bak, sizeof(int) * N * N);
    }
    return false;
}

int** SolvePuzzle(int *clues) {
    my_clues = clues;
    for (int i = 0; i < N * N; i++) possible[i] = MASK;

    for (int i = 0; i < N; i++) {
        s[i] = i;
        e[i] = 3 * N + i;
        inc[i] = N;
    }

    for (int i = 0, j = N; i < N; i++, j++) {
        s[j] = i * N + N - 1;
        e[j] = i * N;
        inc[j] = -1;
    }

    for (int i = 0, j = 2 * N; i < N; i++, j++) {
        s[j] = 4 * N - 1 - i;
        e[j] = N - 1 - i;
        inc[j] = -N;
    }

    for (int i = 0, j = 3 * N; i < N; i++, j++) {
        s[j] = (N - i - 1) * N;
        e[j] = (N - i) * N - 1;
        inc[j] = 1;
    }

    for (int i = 0; i < SIDES * N; i++) {
        if (my_clues[i] == 0) continue;
        for (int j = s[i], k = 0; k < N; j += inc[i], k++) {
            int m = MASK;
            for (int l = N + k - my_clues[i] + 1; l < N; l++) m ^= 1 << l;
            possible[j] &= m;
        }
    }

    while (check_unique() > 0);

    vector<pair<int, int>> idx_npos;
    for (int i = 0; i < N * N; i++) {
        int n_possible = count_possible(possible[i]);
        if (n_possible > 1) {
            idx_npos.push_back(make_pair(n_possible, i));
        }
    }

    sort(idx_npos.begin(), idx_npos.end());
    for (int i = 0; i < idx_npos.size(); i++) {
        order.push_back(idx_npos[i].second);
    }
    dfs(0);

    int** p = new int*[N];
    for (int i = 0; i < N; i++) p[i] = results[i];
    return p;
}












/* BEST CODE

#include <set>
#include <array>
#include <vector>
#include <numeric>
#include <algorithm>

using one_row = std::vector<int>;
std::array<std::array<std::vector<one_row>, 5>, 5> pre;
int* map[4];

int calc(one_row const& v)
{
    auto ret = 0;
    auto tallest = 0;
    std::for_each(v.begin(), v.end(), [&](int x) {
        if (x > tallest) {
            tallest = x;
            ret++;
        }
    });
    return ret;
}

bool check(int* clues)
{
    for (int i = 0; i < 4; i++) {
        one_row v;
        for (int j = 0; j < 4; j++) v.push_back(map[i][j]);

        std::set<int> check_dul(v.begin(), v.end());
        if (check_dul.size() != 4) return false;

        auto left  = calc(v);
        auto cleft = clues[15 - i];
        if (cleft && left != cleft) return false;

        std::reverse(v.begin(), v.end());
        auto right  = calc(v);
        auto cright = clues[4 + i];
        if (cright && right != cright) return false;
    }
    return true;
}

bool dfs(int dep, int* clues)
{
    if (dep == 4) return check(clues);
    auto left = clues[dep];
    auto right = clues[11 - dep];
    for (auto const& v : pre[left][right]) {
        for (int i = 0; i < 4; i++)
            map[i][dep] = v[i];
        if (dfs(dep + 1, clues)) return true;
    }
    return false;
}

int** SolvePuzzle(int *clues)
{
    for (int i = 0; i < 4; i++) map[i] = new int[4];

    for (auto & i : pre)
        for (auto & j : i) j = std::vector<one_row>();

    one_row p(4);
    std::iota(p.begin(), p.end(), 1);

    do {
        auto left = calc(p);
        std::reverse(p.begin(), p.end());
        auto right = calc(p);
        std::reverse(p.begin(), p.end());

        pre[left][right].push_back(p);
        pre[left][0].push_back(p);
        pre[0][right].push_back(p);
        pre[0][0].push_back(p);
    } while (std::next_permutation(p.begin(), p.end()));

    dfs(0, clues);
    return map;
}



*/
