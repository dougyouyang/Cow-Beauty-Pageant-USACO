//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <cmath>

using namespace std;
char board[100][100];
int mat[100][100], mat2[100][100], best=1000000, n, m;

void bfs(int row, int col)
{
    if(row<0 || col<0 || row>99 || col>99 || board[row][col]!='X')
        return;
    board[row][col]='.';
    mat[row][col]=1;
    bfs(row, col+1);
    bfs(row, col-1);
    bfs(row+1, col);
    bfs(row-1, col);
}

int main()
{
    int i, j;
    
    cin >> n >> m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j]=='X')
                mat[i][j]=2;
        }
    }
    bool fi=false;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(board[i][j]=='X'){
                bfs(i, j);
                fi=true;
            }
            if(fi)
                break;
        }
        if(fi)
            break;
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(mat[i][j]==1){
                for(int a=0;a<n;a++){
                    for(int b=0;b<m;b++)
                        if(mat[a][b]==2)
                            best=min(abs(a-i)+abs(b-j), best);
                }
            }
        }
    }
    
    cout << best-1 << endl;
    
    return 0;
}
