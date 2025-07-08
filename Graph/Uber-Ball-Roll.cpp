#include<iostream>
#include<vector>
using namespace std;

// A grid which has 0's and 1's, boundaries beyond is a wall, Out of bound - 1's
/*
    - Ball rolls in 4 - directions - if it hits the wall!!! it can change the direction
    - It should change the direction if it hits 
            - Boundary - beyond is wall
            - 1 is wall in the grid
    - return true if the ball reaches from start to end
    
    **** Ball rolls on and on until hits boundary or the wall

    take a visited array so that you wont visit it again.

    you go ------> one direction and if you hit a wall or boundary, return to the start, **** not the previous step and try all ways !!!!!

      0 1 2 3 4
   0 [0,0,1,0,x]
   1 [0,0,0,0,0]
   2 [0,0,0,1,0]
   3 [1,1,0,1,1]
   4 [0,0,0,0,x]

    Start = [0,4], end = [4,4]

    So, here the optimised path is 0,4 -> 0,3 -> 0,2 (hit wall) -> go 1,3 -> 2,3 (hit wall) -> try all ways -> from 1,3 try left -----> reach 0,1 and hit boundary , try all ways -> go down 0,3 hit wall 
    -> go till 2,2 hit wall -> go down till 2,4 hit wall -> try all ways -> go right 4,4 ... ( success )

    Key Points:
     - if choose one direction go on until reach wall or boundary
     - If you reached wall or boundary change dir

     try all ways from the point where you hit boundary or wall
    
*/

bool dfs(std::vector<std::vector<int>> &grid, std::vector<std::vector<int>> &vis, std::vector<int> start , std::vector<int> dest){
    if(vis[start[0]][start[1]]) return false;

    // if we find the res, return true
    if(start[0] == dest[0] && start[1] == dest[1]) return true;

    vis[start[0]][start[1]] = 1;
    cout<<"from"<<start[0]<<":"<<start[1]<<endl;

    std::vector<std::vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    for(int i=0;i<4;i++){
        int x = start[0];
        int y = start[1];


        while(x+dir[i][0] >= 0 && x+dir[i][0] < 5 &&
            y+dir[i][1] >= 0 && y+dir[i][1] < 5  &&
            grid[x+dir[i][0]][y+dir[i][1]] == 0){


                x += dir[i][0];
                y += dir[i][1];

                // vis[x][y] . --- why can't we make visited all the bloacks along the path....
                /*
                    - This is wrong cause we only make decision at the wall or the border
                    - We might miss the other path that cut through this path, but we only care about the wall or border why another path wont cut through the other path which might also have leads to ans.

                    so we can cut through the already visited path, but not the already hit border or the wall, cause that again leads the same path
                */

            }

                if(dfs(grid, vis, {x, y}, dest) == true) return true; // any where we found the destination
            
            

        

    }
    return false;
}

/*
      0 1 2 3 4
   0 [0,0,1,0,x]
   1 [0,0,0,0,0]
   2 [0,0,0,1,0]
   3 [1,1,0,1,1]
   4 [0,0,0,0,x]

   */
int main(){

    std::vector<std::vector<int>> grid = {
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,1,0},
        {1,1,0,1,1},
        {0,0,0,0,0}
    };

    std::vector<std::vector<int>> vis(5,std::vector<int>(5,0));


    bool ans = dfs(grid, vis, {0,4}, {4,4});


    cout<<(ans ? "true" : "false")<<endl;

return 0;


}