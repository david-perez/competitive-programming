#include <iostream>

using namespace std;

int main() {
    int cows, cars, show;
    while (cin >> cows >> cars >> show) {
        int N = cows + cars;
        double pcar = (double) cars / N, pcow = (double) cows / N;
        printf("%.5f\n", pcar * (((double) cars-1) / (N-show-1)) + pcow * (double) cars / (N-show-1));
    }
    
    return 0;
}
