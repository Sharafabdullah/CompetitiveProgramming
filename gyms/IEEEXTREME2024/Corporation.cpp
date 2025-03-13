#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegmentTree {
    struct Node {
        ll sum_salary = 0, sum_happiness = 0, lazy_add_salary = 0, lazy_add_happiness = 0;
        bool lazy_set_salary = false;
        ll set_value_salary = 0;
    };

    int n;
    vector<Node> tree;

    SegmentTree(int size) : n(size), tree(4 * n) {}

    void build(const vector<ll>& salaries, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v].sum_salary = salaries[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(salaries, v * 2, tl, tm);
            build(salaries, v * 2 + 1, tm + 1, tr);
            tree[v].sum_salary = tree[v * 2].sum_salary + tree[v * 2 + 1].sum_salary;
        }
    }

    void push(int v, int tl, int tr) {
        if (tree[v].lazy_set_salary) {
            ll old_salary = tree[v].sum_salary / (tr - tl + 1);
            ll new_salary = tree[v].set_value_salary;
            ll happiness_change = (new_salary > old_salary) ? 1 : (new_salary < old_salary ? -1 : 0);
            tree[v].sum_happiness += (tr - tl + 1) * happiness_change;
            
            tree[v].sum_salary = (tr - tl + 1) * new_salary;
            if (tl != tr) {
                propagate_set(v * 2, new_salary);
                propagate_set(v * 2 + 1, new_salary);
            }
            tree[v].lazy_set_salary = false;
            tree[v].lazy_add_salary = 0;
        }
        if (tree[v].lazy_add_salary != 0) {
            ll old_salary = tree[v].sum_salary / (tr - tl + 1);
            ll new_salary = old_salary + tree[v].lazy_add_salary;
            ll happiness_change = (tree[v].lazy_add_salary > 0) ? 1 : -1;
            tree[v].sum_happiness += (tr - tl + 1) * happiness_change;

            tree[v].sum_salary += (tr - tl + 1) * tree[v].lazy_add_salary;
            if (tl != tr) {
                propagate_add(v * 2, tree[v].lazy_add_salary);
                propagate_add(v * 2 + 1, tree[v].lazy_add_salary);
            }
            tree[v].lazy_add_salary = 0;
        }
    }

    void propagate_set(int v, ll value) {
        tree[v].lazy_set_salary = true;
        tree[v].set_value_salary = value;
        tree[v].lazy_add_salary = 0;
    }

    void propagate_add(int v, ll value) {
        if (tree[v].lazy_set_salary) {
            tree[v].set_value_salary += value;
        } else {
            tree[v].lazy_add_salary += value;
        }
    }

    void range_update_set(int v, int tl, int tr, int l, int r, ll value) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && tr == r) {
            propagate_set(v, value);
            push(v, tl, tr);
        } else {
            int tm = (tl + tr) / 2;
            range_update_set(v * 2, tl, tm, l, min(r, tm), value);
            range_update_set(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, value);
            tree[v].sum_salary = tree[v * 2].sum_salary + tree[v * 2 + 1].sum_salary;
            tree[v].sum_happiness = tree[v * 2].sum_happiness + tree[v * 2 + 1].sum_happiness;
        }
    }

    void range_update_add(int v, int tl, int tr, int l, int r, ll value) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && tr == r) {
            propagate_add(v, value);
            push(v, tl, tr);
        } else {
            int tm = (tl + tr) / 2;
            range_update_add(v * 2, tl, tm, l, min(r, tm), value);
            range_update_add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, value);
            tree[v].sum_salary = tree[v * 2].sum_salary + tree[v * 2 + 1].sum_salary;
            tree[v].sum_happiness = tree[v * 2].sum_happiness + tree[v * 2 + 1].sum_happiness;
        }
    }

    ll range_query_sum(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l > r) return 0;
        if (l == tl && tr == r) return tree[v].sum_salary;
        int tm = (tl + tr) / 2;
        return range_query_sum(v * 2, tl, tm, l, min(r, tm)) +
               range_query_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    ll range_query_happiness(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l > r) return 0;
        if (l == tl && tr == r) return tree[v].sum_happiness;
        int tm = (tl + tr) / 2;
        return range_query_happiness(v * 2, tl, tm, l, min(r, tm)) +
               range_query_happiness(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void updSet(int l, int r, ll value) {
        range_update_set(1, 0, n - 1, l, r, value);
    }

    void updAdd(int l, int r, ll value) {
        range_update_add(1, 0, n - 1, l, r, value);
    }

    ll qSum(int l, int r) {
        return range_query_sum(1, 0, n - 1, l, r);
    }

    ll qHap(int l, int r) {
        return range_query_happiness(1, 0, n - 1, l, r);
    }
};

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void print_fraction(ll numerator, ll denominator) {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    ll g = gcd(abs(numerator), abs(denominator));
    numerator /= g;
    denominator /= g;
    cout << numerator << "/" << denominator << endl;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> salaries(N);
    for (int i = 0; i < N; ++i) cin >> salaries[i];

    SegmentTree segtree(N);
    segtree.build(salaries, 1, 0, N - 1);

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        int l, r;
        cin >> l >> r;
        --l, --r;

        if (type == 0) {
            ll c;
            cin >> c;
            segtree.updSet(l, r, c);
        } else if (type == 1) {
            ll c;
            cin >> c;
            segtree.updAdd(l, r, c);
        } else if (type == 2) {
            ll sum = segtree.qSum(l, r);
            ll count = r - l + 1;
            print_fraction(sum, count);
        } else if (type == 3) {
            ll happiness_sum = segtree.qHap(l, r);
            ll count = r - l + 1;
            print_fraction(happiness_sum, count);
        }
    }

    return 0;
}
