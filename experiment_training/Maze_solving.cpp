#include<bits/stdc++.h>
using namespace std;

int width_maze,height_maze; //set the width and height of maze
pair<int,int> enter,out; //entrance and exit
vector<vector<int>> maze_map; //map of maze
vector<pair<int,int>> path_stack,path_bfs;//DFS path stack and BFS reverse path
deque<pair<int,int>> path_queue;//BFS path queue
vector<vector<pair<int,int>>> parent;//path reverse,record parent position

/*paraments:row,col:enter position*/
bool findpath_DFS(int row,int col)
{
    if((row<0 || col<0 || row>=height_maze || col>=width_maze) || (maze_map[row][col]==1 || maze_map[row][col]==2)) //if current is out of boundary
    {return false;}
    if(row==out.first && col==out.second) //if current is exit
    {
        pair<int,int> back={row,col}; path_stack.push_back(back); //push into path stack
        return true;
    }

    maze_map[row][col]=2; //accessed lable
    pair<int,int> back={row,col}; path_stack.push_back(back); //push into path stack

    int dx[4] = {-1, 1, 0, 0},dy[4] = {0, 0, -1, 1}; //neighbor position
    for(int i=0;i<4;i++) //traverse neighbors gracefully
    {
        int cx=row+dx[i],cy=col+dy[i]; if(findpath_DFS(cx,cy)) {return true;}
    }

    path_stack.pop_back(); //all neighbors traversed,not suitable
    return false;  //pop out current
}

void findpath_BFS(int row,int col)
{
    pair<int,int> current={row,col}; path_queue.push_back(current); maze_map[row][col]=2; parent[row][col] = {row, col};
    while(!path_queue.empty())
    {
        current=path_queue.front(); path_queue.pop_front(); //get head element then pop out
        if(current.first==out.first && current.second==out.second)  //found out
        {
            pair<int,int> cur=out;
            while(!(cur.first==enter.first && cur.second==enter.second)) //if current is entrace
            {
                path_bfs.push_back(cur); cur=parent[cur.first][cur.second]; //push current into path stack and refresh current to its parent
            }
            path_bfs.push_back(enter); //push entrace into path stack
            reverse(path_bfs.begin(),path_bfs.end()); //reverse the position of path stack
            
            break; //break outof cycle
        }

        int dx[4] = {-1, 1, 0, 0},dy[4] = {0, 0, -1, 1}; //neighbor position
        for(int i=0;i<4;i++) //traverse neighbors gracefully
        {
            int cx=current.first+dx[i],cy=current.second+dy[i];
            if((cx>=0 && cy>=0 && cx<height_maze && cy<width_maze) && (maze_map[cx][cy]==0)) //if current is out of boundary
            {
                pair<int,int> neighbor={cx,cy}; path_queue.push_back(neighbor); //push current into path stack
                maze_map[cx][cy]=2; parent[cx][cy]=current; //record its parent
            }
        }
    }
}

/*void findpath_ASTAR(int row,int col)
{
    int walkedpast=0,manhattandistance=abs(row-out.first)+abs(col-out.second),total=walkedpast+manhattandistance; //f=g+h,manhattan_distance = |x1-x2|+|y1-y2|
    pair<int,int> current={row,col}; maze_map[row][col]=2; parent[row][col] = {row, col};

    while(current!=out)
    {
        if(current==out)
        {
            break;
        }
        
        int dx[4] = {-1, 1, 0, 0},dy[4] = {0, 0, -1, 1},tx,ty;
        for(int i=0;i<4;i++)
        {
            int cx=current.first+dx[i],cy=current.second+dy[i];
            if((cx>=0 && cy>=0 && cx<height_maze && cy<width_maze) && (maze_map[cx][cy]==0))
            {
                manhattandistance=abs(cx-out.first)+abs(cy-out.second);
                if(total>(walkedpast+manhattandistance))
                {
                    total=walkedpast+manhattandistance; tx=cx,ty=cy;
                }
            }
        }

        walkedpast++; maze_map[tx][ty]=2; parent[tx][ty]=current; current.first=tx,current.second=ty;
    }
}*/


int main(void)
{
    cin >> width_maze >> height_maze;
    maze_map.assign(height_maze,vector<int>(width_maze,0)); parent.assign(height_maze,vector<pair<int,int>>(width_maze,{0,0}));  //resize map and parent recorder
    
    for(int row=0;row<height_maze;row++) //input map of maze
    {
        for(int col=0;col<width_maze;col++)
        {
            cin >> maze_map[row][col];
        }
    }
    vector<vector<int>> maze_map_backup=maze_map; //backup of map,used to reset map after DFS
    cin >> enter.first >> enter.second >> out.first >> out.second; //setup entrance and exit,first:row,second:col

    findpath_DFS(enter.first,enter.second);
    for(auto output:path_stack) {cout <<'(' << output.first << ',' << output.second << ')' << ' ';} cout << endl << endl;
    maze_map=maze_map_backup; 

    findpath_BFS(enter.first,enter.second);
    for(auto output:path_bfs) {cout <<'(' << output.first << ',' << output.second << ')' << ' ';} cout << endl <<endl;
    maze_map=maze_map_backup; parent.clear(); 

    return 0;
}