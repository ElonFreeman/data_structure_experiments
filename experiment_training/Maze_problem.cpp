#include<bits/stdc++.h>
using namespace std;

int width_maze,height_maze;
pair<int,int> enter,out;
vector<vector<int>> maze_map;
vector<pair<int,int>> path_stack,path_bfs;//DFS path stack and BFS reverse path
deque<pair<int,int>> path_queue;//BFS
vector<vector<pair<int,int>>> parent;//path reverse,record parent position

/*paraments:row,col:enter position*/
bool findpath_DFS(int row,int col)
{
    if((row<0 || col<0 || row>=height_maze || col>=width_maze) || (maze_map[row][col]==1 || maze_map[row][col]==2))
    {return false;}
    if(row==out.first && col==out.second)
    {
        pair<int,int> back; back.first=row,back.second=col;
        path_stack.push_back(back);
        return true;
    }

    maze_map[row][col]=2; //accessed lable
    pair<int,int> back; back.first=row,back.second=col; path_stack.push_back(back); //push path stack

    if(findpath_DFS(row-1,col)) return true; //north
    if(findpath_DFS(row,col+1)) return true; //east
    if(findpath_DFS(row+1,col)) return true; //south
    if(findpath_DFS(row,col-1)) return true; //west

    path_stack.pop_back();
    return false;
}

void findpath_BFS(int row,int col)
{
    pair<int,int> current; current.first=row,current.second=col; path_queue.push_back(current); maze_map[row][col]=2; parent[row][col] = {row, col};
    while(!path_queue.empty())
    {
        current=path_queue.front(); path_queue.pop_front();
        if(current.first==out.first && current.second==out.second)  //found out
        {
            pair<int,int> cur=out;
            while(!(cur.first==enter.first && cur.second==enter.second))
            {
                path_bfs.push_back(cur); cur=parent[cur.first][cur.second];
            }
            path_bfs.push_back(enter);
            reverse(path_bfs.begin(),path_bfs.end());

            break;
        }

        //north
        if((current.first-1>=0 && current.second>=0 && current.first-1<height_maze && current.second<width_maze) && (maze_map[current.first-1][current.second]!=1 && maze_map[current.first-1][current.second]!=2))
        {
            pair<int,int> neighbor; neighbor.first=current.first-1,neighbor.second=current.second; path_queue.push_back(neighbor);
            maze_map[neighbor.first][neighbor.second]=2;
            parent[neighbor.first][neighbor.second].first=current.first,parent[neighbor.first][neighbor.second].second=current.second;
        }
        //east
        if((current.first>=0 && current.second+1>=0 && current.first<height_maze && current.second+1<width_maze) && (maze_map[current.first][current.second+1]!=1 && maze_map[current.first][current.second+1]!=2))
        {
            pair<int,int> neighbor; neighbor.first=current.first,neighbor.second=current.second+1; path_queue.push_back(neighbor);
            maze_map[neighbor.first][neighbor.second]=2;
            parent[neighbor.first][neighbor.second].first=current.first,parent[neighbor.first][neighbor.second].second=current.second;
        }
        //south
        if((current.first+1>=0 && current.second>=0 && current.first+1<height_maze && current.second<width_maze) && (maze_map[current.first+1][current.second]!=1 && maze_map[current.first+1][current.second]!=2))
        {
            pair<int,int> neighbor; neighbor.first=current.first+1,neighbor.second=current.second; path_queue.push_back(neighbor);
            maze_map[neighbor.first][neighbor.second]=2;
            parent[neighbor.first][neighbor.second].first=current.first,parent[neighbor.first][neighbor.second].second=current.second;
        }
        //west
        if((current.first>=0 && current.second-1>=0 && current.first<height_maze && current.second-1<width_maze) && (maze_map[current.first][current.second-1]!=1 && maze_map[current.first][current.second-1]!=2))
        {
            pair<int,int> neighbor; neighbor.first=current.first,neighbor.second=current.second-1; path_queue.push_back(neighbor);
            maze_map[neighbor.first][neighbor.second]=2;
            parent[neighbor.first][neighbor.second].first=current.first,parent[neighbor.first][neighbor.second].second=current.second;
        }
    }    
}

void findpath_ASTAR(int row,int col)
{

}

int main(void)
{
    cin >> width_maze >> height_maze;
    maze_map.assign(height_maze,vector<int>(width_maze,0)); parent.assign(height_maze,vector<pair<int,int>>(width_maze,{0,0}));
    
    for(int row=0;row<height_maze;row++)
    {
        for(int col=0;col<width_maze;col++)
        {
            cin >> maze_map[row][col];
        }
    }
    vector<vector<int>> maze_map_backup=maze_map;
    cin >> enter.first >> enter.second >> out.first >> out.second; //first:row,second:col

    findpath_DFS(enter.first,enter.second);
    for(auto output:path_stack) {cout <<'(' << output.first << ',' << output.second << ')' << ' ';} cout << endl << endl;
    maze_map=maze_map_backup; 
    findpath_BFS(enter.first,enter.second);
    for(auto output:path_bfs) {cout <<'(' << output.first << ',' << output.second << ')' << ' ';} cout << endl << endl;
    maze_map=maze_map_backup; 

    

    return 0;
}