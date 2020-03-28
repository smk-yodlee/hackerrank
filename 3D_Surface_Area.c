#Given a grid of HxW and the height of cols obtained at each cell of the grid by stacking 1x1x1 cubes (each cell is also 1x1), 
#find the 3D surface area of the figure

#A col at any cell (i,j) will contribute to the side surface area if it is higher than the adjacent col in one of the 4 dirs : 
#(i-1,j),(i+1,j),(i,j-1),(i,j+1)
#Then that col will be visible on that side and will contribute (h1-h2) x 1 to the surface area. Otherwise its contribution will be 0
#Finally, add 2 x H x W to the area as top and bottom surface area is constantly H x W

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[110][110];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            cin >> a[i][j];
        }
    }
    
    int ans = n * m * 2;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            for (int k = 0; k < 4; ++ k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m) ans += a[i][j];
                else if (a[x][y] < a[i][j]) ans += -a[x][y] + a[i][j];
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
