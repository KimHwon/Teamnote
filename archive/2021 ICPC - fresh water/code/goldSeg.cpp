inline ll safe_add (const ll& a, const ll& b) {
    if (a > -LINF && b > -LINF) return a+b;
    if (a > -LINF) return a;
    if (b > -LINF) return b;
    return -LINF;
}
struct Node {
    ll lval = -LINF, rval = -LINF, val = -LINF, all = 0;
    Node operator+ (const Node& n) const { return {safe_add(lval,n.lval), safe_add(rval,n.rval), safe_add(val,n.val), safe_add(all,n.all)}; }
} seg[MAX*4];
Node func(Node a, Node b) {
    return {
            max({a.lval, safe_add(a.all,b.lval)}),
            max({safe_add(a.rval,b.all), b.rval}),
            max({a.val, b.val, safe_add(a.rval,b.lval)}),
            max({safe_add(a.all,b.all)})
    };
}