int GCD(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int LCM(vector < int > x, int n)
{
    ll ans = x[0];
    for (int i = 1; i < n; i++)
        ans = (((x[i] * ans)) / (gcd(x[i], ans)));
    return ans;
}
