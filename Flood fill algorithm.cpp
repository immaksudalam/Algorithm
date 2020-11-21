#include <bits/stdc++.h>
using namespace std;
#define mx 101
int flag[mx][mx];
char grid[mx][mx];
int row, col;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void floodfill(int i, int j){
    if(i<0 || j<0 || i>row-1 || j>col-1) return;
    if(grid[i][j] =='.' && flag[i][j] == 0){
        flag[i][j]=1;
        grid[i][j]='+';
        for(int k=0; k<8; k++){
             int y = dy[k]+j;
             int x = dx[k]+i;
             floodfill(x, y);
        }
    }
}
int main()
{
    int cnt=0;
    memset(flag, 0, sizeof(flag));
    cin>>row>>col;
    getchar();
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%c", &grid[i][j]);
        }
        getchar();
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(grid[i][j]=='.' && flag[i][j]==0){
                cnt++;
                floodfill(i,j);
            }
        }
    }
    cout<<"Number of colored region is: "<<cnt<<endl;
    cout<<"New 2D array is :" <<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++) cout<<grid[i][j];
        cout<<endl;
    }
}
