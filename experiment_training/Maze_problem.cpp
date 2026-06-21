#include<bits/stdc++.h>
using namespace std;

int weight_maze,height_maze;
vector<vector<int>> maze_structure(height_maze,vector(weight_maze,0));
pair<int,int> enter,out;
vector<pair<int,int>> path_stack;

bool findpath_DFS_recursive(int row,int col)
{
    if((row<0 || col<0 || row>height_maze || col>weight_maze) || (maze_structure[row][col]==1 || maze_structure[row][col]==2))
    {return false;}
    if(row==enter.first && enter.second)
    {
        pair<int,int> back; back.first=row,back.second=col;
        path_stack.push_back(back);
        return true;
    }

    maze_structure[row][col]=2; //accessed lable
    pair<int,int> back; back.first=row,back.second=col; path_stack.push_back(back); //push path stack

    if(findpath_DFS_recursive(row-1,col)) return true; //north
    if(findpath_DFS_recursive(row,col+1)) return true; //east
    if(findpath_DFS_recursive(row+1,col)) return true; //south
    if(findpath_DFS_recursive(row,col-1)) return true; //west

    path_stack.pop_back();
    return false;
}

void findpath_DFS_iterate(int row,int col)
{
    /*函数 基于栈的DFS寻路(迷宫, 起点, 终点):
    初始化一个空栈 stack
    将 起点 入栈
    标记 起点 为已访问 (maze[起点.row][起点.col] = 2)
    
    当 stack 不为空时:
        当前位置 = stack.peek()  // 只看栈顶，但不出栈
        
        // ★★★ 你的核心判断条件 ★★★
        如果 当前位置 == 终点:
            返回 stack  // 栈里的所有元素从底到顶就是完整路径
        
        // 尝试找一个可以走的邻居（顺序：上、下、左、右）
        邻居 = 寻找未访问且不是墙的相邻格子(当前位置)
        
        如果 找到了这样的邻居:
            将 邻居 入栈
            标记 邻居 为已访问 (防止下次又走回来)
        否则:
            // 当前节点四个方向都走不通，是死胡同
            stack.pop()  // 回溯：退回到上一个岔路口
    
    // 如果栈变空了还没找到终点
    返回 "迷宫无解"*/
}

int main(void)
{
    cin >> weight_maze >> height_maze;
    for(int row=0;row<height_maze;row++)
    {
        for(int col=0;col<weight_maze;col++)
        {
            cin >> maze_structure[row][col];
        }
    }
    cin >> enter.first >> enter.second >> out.first >> out.second; //first:row,second:col

    findpath_DFS_recursive(enter.first,enter.second);
    for(pair output:path_stack) cout <<'(' << output.first << ',' << output.second << ')' << ' ';    
    

    return 0;
}