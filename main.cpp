#include "mouse.h"
#pragma comment(linker, "/STACK:1024000000,1024000000")

int minStep=10000;
struct node
{
	int x,y,pre,step;
};
 
 /*
 * BFS新增的内容 广度优先搜索 
 */ 
class Queue//创建一个队列类（不属于严格意义上的队列） 
{
	private :
		node queue[10000];//定义队列大小 
		Stack best; //用来转换的栈 
		int pIn,pOut;//定义两个指针用以指向队列的入队pIn和出队pOut的位置 
	public :
		void push (int x,int y,int pre,int step)//加入队列中 封装的结构为node 包含 坐标 x, 坐标y, 前驱pre,步数step 
		{
			pOut++;//指针新增空间
			//加入队列中 
			queue[pOut].x=x;
			queue[pOut].y=y;
			queue[pOut].pre=pre;
			queue[pOut].step=step;
		}
		void push (node temp)//同上  
		{
			pOut++;
			queue[pOut]=temp;
		}
		int  pop ()//输出队列 
		{
			pIn++;
			return pIn;
		}
		bool isEmpty()//判断队列是否为空 
		{
			if (pIn>pOut) return true;
			return false;
		}
		node getNode(int e)//获取e这个数组位置上的node，并返回 
		{
			return queue[e];
		}
		void transform(int e)//从终点递归回溯到起点位置，寻找来时的路径 
		{
			//cout<<e<<endl;
			if (0==e) return ;//如果到了起点则退出 
			transform(queue[e].pre);//递归寻找路径 
			best.push(queue[e].x,queue[e].y);//加入到栈中 
			
		}
		Stack toStack(node temp)//将队列转化为栈 
		{
			
			transform(temp.pre);//如上 
			best.push(temp.x,temp.y);//加入终点入栈 
		//	best.outStack(); 
			return best;
			
		}
		
} ;
class MyMaze : public Maze
{
	private :
		Queue qe;
		bool used[200][200];//判断走过的路就不走了 
	public:
		bool isUsed(node temp)
		{
			return used[temp.x][temp.y];
		}
		void setUsed(node temp)
		{
			used[temp.x][temp.y]=true;
		}
		bool isNodeCan(node temp)//判断是否可行 
		{
			if (can(temp.x,temp.y)&&!isUsed(temp)) return true;
			return false;
		}
		bool isNodeOut(node temp)//判断是否为出口 
		{
			return isOut(temp.x,temp.y);
		}
		void BFS()
		{
			
			int dx[4]={1,0,0,-1};//国际惯例四个方向，一定要理解清楚 
			int dy[4]={0,1,-1,0};
			int i,p; 
			node temp;
			qe.push(getMouseX(),getMouseY(),0,0);//将起点加入到队列 
			while (!qe.isEmpty())//当队列不为空时，想想什么时候为空 
			{
				p= qe.pop();//获取需要扩展的节点 
				for (i=0;i<4;i++)//枚举解决问题的所有方法 
				{
					temp=qe.getNode(p);//尝试走一下 
					temp.x=temp.x+dx[i];
					temp.y=temp.y+dy[i];
					
					if (isNodeCan(temp))//判断是否可行 
					{
						setUsed(temp);//可行则标记为走过了 
						temp.pre=p;//记录下是哪个点走到这个点的 
						temp.step++;//步数加一 
						qe.push(temp);//加入到队列 
						if (isNodeOut(temp))//判断是否到出口了 
						{
							//广度优先搜索与深度不同，找到出口必然是最短的，（想想为什么） 
							cout<<temp.step<<endl;
							beginPath(qe.toStack(temp));//输出咱们找的路吧！ 
						}
					}
				}
			}
		}
};
/*
*新增内容结束 
*/
int main(){
	MyMaze *maze=new MyMaze();//新建个迷宫 
	maze->loadMapFromFile("map.txt");//读取地图 
	maze->setName("Sabrina Jiang");
	maze->BFS();
	return 0;
}
