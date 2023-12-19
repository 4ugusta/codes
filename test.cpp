#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    double v = pow(x, 2);
    return v;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    double x1 = a, delta = (double)(b - a) / n;
    double x2 = x1 + delta, x3 = x2 + delta;
    int i = 1;
    while (x3 <= b) {
        cout<<"Iteration"<<" "<<i<<endl;
        cout<<f(x1)<<" at "<<x1<<endl;
        cout<<f(x2)<<" at "<<x2<<endl;
        cout<<f(x3)<<" at "<<x3<<endl;
        if (f(x1) >= f(x2) && f(x2) <= f(x3)) {
            cout << x2;
            break;
        } 
        else if (x3 == b) {
            cout << min(a,b);
            break;
        } 
        else {
            x1 = x2;
            x2 = x3;
            x3 = x2 + delta;
        }
        i++;
    }

    return 0;
}
