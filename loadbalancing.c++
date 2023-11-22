#include<iostream>
using namespace std;
#define grid 10
int count=0;
int jumps=0;
bool check(int matrix[][grid][grid],int time,int i,int j)
{
    if((matrix[i][j][0]-time)>0)
        return true;
    else
        return false;
}
void add_task(int matrix[][grid][grid],int time,int i,int j,int *x,int *y,int k,int taskmatrix[][grid])
{
    if((matrix[i][j][0]-time)>0){
    matrix[i][j][0] = matrix[i][j][0]-time;
    cout<<"Task added successfully"<<endl;
    cout<<"number of tasks added are "<<k<<endl;
    count=0;
    *x=i;
    *y=j;
    }
    else
    {
    if(i-1>=0&&check(matrix,time,i-1,j))
    {
        i=i-1;
        matrix[i][j][0] = matrix[i][j][0]-time;
        cout<<"case1 is executed"<<endl;
        cout<<"Task added successfully"<<endl;
        cout<<"number of tasks added are "<<k<<endl;
        count=0;
        *x=i;
        *y=j;
        jumps++;
    }
    else if(j+1<=9&&check(matrix,time,i,j+1))
    {
        j=j+1;
        matrix[i][j][0] =matrix[i][j][0]-time;
        cout<<"case2 is executed"<<endl;
        cout<<"Task added successfully"<<endl;
        cout<<"number of tasks added are "<<k<<endl;
        count=0;
        *x=i;
        *y=j;
        jumps++;
    }
    else if(i+1<=9&&check(matrix,time,i+1,j))
    {
        i=i+1;
        matrix[i][j][0] =matrix[i][j][0]-time;
        cout<<"case3 is executed"<<endl;
        cout<<"Task added successfully"<<endl;
        cout<<"number of tasks added are "<<k<<endl;
        count=0;
        *x=i;
        *y=j;
        jumps++;
    }
    else if(j-1>=0&&check(matrix,time,i,j-1))
    {
        j=j-1;
        matrix[i][j][0] =matrix[i][j][0]-time;
        cout<<"Task added successfully"<<endl;
        cout<<"case4 is executed"<<endl;
        cout<<"number of tasks added are "<<k<<endl;
        count=0;
        *x=i;
        *y=j;
        jumps++;
    }
    else
    {
        count=1;
    }
    }
}
int main() {
    int matrix[grid][grid][grid],taskmatrix[grid][grid],choice,queue[1000][4],z=0,task[1000][2],tmp=0;
    for(int i=0;i<grid;i++)
    {
        for(int j=0;j<grid;j++)
        {
            matrix[i][j][0]=100;
            taskmatrix[i][j]=0;
        }
    }
    for(int i=0;i<grid;i++)
    {
        for(int j=0;j<grid;j++)
        {
            for(int k=1;k<grid;k++)
            {
                matrix[i][j][k]=0;
            }
        }
    }
    do{
        cout<<"1.Give task\n2.Display matrix\n3.Display task queue\n4.display transitions done\n5.display tasks details\n6.display task matrix\n7.Quit"<<endl;
        int time;
        cin>>choice;
        switch(choice)
        {
            case 1: {
                    int x,y;
                    for(int k=0;k<900;k++)
                    {
                    int i = rand()%10;
                    int j = rand()%10;
                    queue[z][0]=i;
                    queue[z][1]=j;
                    time=1+rand()%20;
                    
                    add_task(matrix,time,i,j,&x,&y,k,taskmatrix);
                    if(count==0)
                    {
                        queue[z][2]=x;
                        queue[z][3]=y;
                        z++;
                        taskmatrix[x][y]=taskmatrix[x][y]+1;
                        task[k][0]=k;
                        task[k][1]=time;
                        int temp=1;
                        while(matrix[x][y][temp]!=0)
                        {
                            temp++;
                        }
                        matrix[x][y][temp] =k;
                        x=0;
                        y=0;
                        
                    }
                    int a=j;
                    while(count!=0&&a<9)
                    {
                        a=a+1;
                        add_task(matrix,time,i,a,&x,&y,k,taskmatrix);
                        if(count==0)
                        {
                            queue[z][2]=x;
                            queue[z][3]=y;
                            z++;
                            taskmatrix[x][y]=taskmatrix[x][y]+1;
                            int temp=1;
                            while(matrix[x][y][temp]!=0)
                            {
                                temp++;
                            }
                            matrix[x][y][temp] =k;
                            x=0;
                            y=0;
                        }
                    }
                    if(count==1)
                    {
                        tmp++;
                        cout<<"servers are full"<<endl;
                        cout<<"task "<<k<<" not added"<<endl;
                        cout<<"total number of tasks not added are "<<tmp<<endl;
                    }
                    if(jumps>0)
                    cout<<"number of jumps "<<jumps<<endl;
                    else
                    cout<<"no transtions occured"<<endl;
                    }
                    break;
                    }
            case 2: {for(int i=0;i<grid;i++)
                    {
                        for(int j=0;j<grid;j++)
                        {
                            cout<<matrix[i][j][0]<<" ";
                        }
                        cout<<endl;
                    }
                    break;
                    }
            case 3: {for(int i=0;i<z;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            cout<<queue[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                    break;
                    }
            case 4: {for(int i=0;i<z;i++)
                    {
                        if(queue[i][0]!=queue[i][2]||queue[i][1]!=queue[i][3])
                        {
                            cout<<"transition done from "<<queue[i][0]<<" "<<queue[i][1]<<" to "<<queue[i][2]<<" "<<queue[i][3]<<" for task "<<i<<endl;
                        }
                    }
                    break;
                    }
            case 5:{for(int i=0;i<1000;i++)
                    {
                        cout<<task[i][0]<<" "<<task[i][1]<<endl;
                    }
                    break;
                    }
            case 6:{
                    int sum=0;
                    for(int i=0;i<grid;i++)
                    {
                        for(int j=0;j<grid;j++)
                        {
                            cout<<taskmatrix[i][j]<<" ";
                            sum=sum+taskmatrix[i][j];
                        }
                        cout<<endl;
                    }
                    cout<<"total tasks "<<sum<<endl;
                    break;}
            case 7:{exit(0);
                   break;
                    }
            default:cout<<"Invalid Entry!"<<endl;
        }
    }while(choice);
}