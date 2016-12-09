
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <fstream> 
#include <ctime>
#include <stdlib.h> 
 
using namespace std;
struct box
{
	int x,y;
};
class ConstNum{//常量定义，用以标注各项属性 
	public:
		enum Constants
		{
		 AREA=0x0,//0
		 WALL=0x1,//1
	     MOUSE=0x2,//2
	     INWAY=0x13,//19
	     OUTWAY=0x14,//20
	     UP=0x48,
		 DOWN=0x50,
		 LEFT=0x4B,
		 RIGHT=0x4D
		};
};
class Stack{
		private :
			box stack[3000];
			int length;
		public:
			Stack()
			{
				length=0;	
			} 
			void setBegin(int x,int y)
			{
				stack[0].x=x;
				stack[0].y=y;
				length=0;
			}
			int getLength(){
				return length;
			}
			void pop()
			{
				length--;
			} 
			void pops(int &x,int &y)
			{
				if (0!=length)
				{
					x=stack[length].x;
					y=stack[length].y;
					length--;
				}
				x=0;y=0;
			}
			bool isCan(int x,int y)
			{
				int t=abs(stack[length].x-x)+abs(stack[length].y-y);
				if (1==t)
					return true;
				return false;
			}
			bool push(int x,int y)
			{
				length++;
				stack[length].x=x;
				stack[length].y=y;
				return true; 
			}
			int getX(int i)
			{
				return stack[i].x;
			}
			int getY(int i)
			{
				return stack[i].y;
			} 
			void outStack()
			{
				int i;
				for (i=1;i<=length;i++)
					cout<<stack[i].x<<" "<<stack[i].y<<endl; 
			}
} ;
class Map{//描述地图的各项状态 
	private :
	    int map[110][110];
	   
	public  :
		int n;int m;
		Map()
		{
			clearMap();
		}
		int getMapValue(int x,int y)//获取地图标志 
		{
			return map[x][y];
		}
		void setMapValue(int x,int y,int value)//设置地图标志 
		{
		    map[x][y]=value;
		}
		void clearMap()//清空地图 
		{
			int i,j;
			for (i=0;i<=n;i++)
				for (j=0;j<=m;j++)
				{
					map[i][j]=ConstNum::WALL;
					//used[i][j]=false;
				}
		}
		
	
};

class Maze//描述迷宫 
{
	private:
	     int myX;int myY;//老鼠的坐标 
	     int outX;int outY;//出口的位置 
	     Map map;//地图 
	     bool isAUTO; 
	     int counter;	
	 	 string name;
	     Stack path;//以定义的路径 
	     DWORD beginTime;
	     BOOL InitScreen()
		 {
      		 	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
       		 	COORD  stcMaxScreenSize = GetLargestConsoleWindowSize(StdOut);
        		COORD  stcScreenBufferSize= {stcMaxScreenSize.X+1,stcMaxScreenSize.Y+1};
        		SMALL_RECT stcScreen = {0,0,stcMaxScreenSize.X-1,stcMaxScreenSize.Y-1};
                CONSOLE_SCREEN_BUFFER_INFO  haha;
        		GetConsoleScreenBufferInfo(StdOut,&haha);
        		SetConsoleScreenBufferSize(StdOut,stcScreenBufferSize);
        		SetConsoleWindowInfo(StdOut,TRUE,&stcScreen);
        		stcScreenBufferSize.X-=1;
        		stcScreenBufferSize.Y-=1;
        		//SMALL_RECT rc = {0,0, 80-1, 25-1}; // 重置窗口位置和大小
				//SetConsoleWindowInfo(StdOut,true ,&rc);
        		SetConsoleScreenBufferSize(StdOut,stcScreenBufferSize);
        		return TRUE;
		 }
		void gotoxy(int x,int y)
		{
    		COORD coord={x,y};
    		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
		}
	     void setMouse(int x,int y)//设置老鼠初始位置 
		 {
			myX=x;myY=y;
			map.setMapValue(x,y,ConstNum::MOUSE);
		 } 
		 void setOutWay(int x,int y)//设置出口 
		 {
			outX=x;outY=y;
			map.setMapValue(x,y,ConstNum::OUTWAY);
		 }
public:
	 int dx[4];
	 int dy[4]; 

	 Maze()
	 {
	 	dx[0]=-1;dy[0]=0;
		dx[1]=0;dy[1]=-1;
		dx[2]=1;dy[2]=0;
		dx[3]=0;dy[3]=1;
		myX=-1;myY=-1;
	    outX=-2;outY=-2;
	    isAUTO=true;
	 }
	 	DWORD getRunTime()//获取程序运行时间 单位毫秒 
		 {
		 	return GetTickCount()-beginTime; 
		 } 
	 	void setName(string name)
		 {
		 	this->name=name;
		 } 
	 	int getStep()
	 	{
	 		return path.getLength();
	 	}
	 	Stack getPath()
	 	{
	 		return path;
	 	}
	 	int getMapN()
		{
			return map.n;
		}
		int getMapM()
		{
			return map.m;
		} 
		int getMouseX()//获取老鼠的X 
		{
			return myX;	
		}
		int getMouseY()//获取老鼠的Y 
		{
			return myY;	
		}
		bool isOut()//判断是否到达终点 
		{
			if (myX==outX&& myY==outY) return true;
			return false;
		}
		bool isOut(int x,int y)//判断是否到达终点 
		{
			if (x==outX&& y==outY) return true;
			return false;
		}
		bool can(int x,int y)//判断是否可行 
		{
			if (x<1||x>getMapN()) return false;//老鼠是否出边界 
			if (y<1||y>getMapM()) return false;
			if (map.getMapValue(x,y)==ConstNum::WALL) return false;
			return true;
		}
		void drawMessage()
		{
			gotoxy(0,0);
			cout<<"我是"<<name<<"  已经走过的步数: "<< counter<<endl; 
			cout<<endl; 
		} 
		void drawMap()//绘制地图 
		{
			int i,j,x;
			int n=map.n;
			int m=map.m;
			system("cls");//清空界面 
		
			drawMessage(); 
			for (i=1;i<=getMapN();i++)
			{
				for (j=1;j<=getMapM();j++)
				{
					x=map.getMapValue(i,j);
					switch (x)
					{
						case ConstNum::AREA:
							cout<<"□";
							break;
							
						case ConstNum::WALL:{
							cout<<"■"; 
							break;
						}
						case ConstNum::MOUSE:{
							cout<<"☆";
							break;
						}
						case ConstNum::INWAY:{
							cout<<"";
							break;
						}
						case ConstNum::OUTWAY:{
							cout<<"×"; 
							break;
						}
					}
				}
				cout<<endl;
		
			}			
		}
		void loadMapFromFile(string file)//从文件读取地图 
		{
			int i,j,x,beginX,beginY,outX,outY;
			
			ifstream fin(file.c_str() );
			fin>>map.n>>map.m>>beginX>>beginY>>outX>>outY;
			
			for (i=1;i<=map.n;i++)
				for (j=1;j<=map.m;j++)
				{
					
					fin>>x;
					map.setMapValue(i,j,x);
				}
			setBegin(beginX,beginY,outX,outY);
			fin.close();
			cout<<"读入地图完成"<<endl;
		}
		void drict(int key)//判断按键 
		{
				int tx,ty;
				switch (key)
				{
				case (ConstNum::UP):{//处理上下左右不同按键的结果 
					tx=myX+dx[0];
					ty=myY+dy[0];
					break;
				}
				case ConstNum::LEFT:{
					tx=myX+dx[1];
					ty=myY+dy[1];
					break;
				}
				case ConstNum::DOWN:{
					tx=myX+dx[2];
					ty=myY+dy[2];
					break;
				}

				case ConstNum::RIGHT:{
					tx=myX+dx[3];
					ty=myY+dy[3];
					break;
				}
				}
				if (can(tx,ty))
				{
					moveTo(tx,ty); 
				}
		}
	
		void gomove(int x,int y)
		{
			path.push(x,y);
		}
		void backmove(int x,int y)
		{
			path.pop();
		}
		void changeMapValue(int x,int y,int num)
		{
			string array[4]={"□","■","☆"};
			map.setMapValue(x,y,num);
			gotoxy((y-1)*2,x+1);
			cout<<array[num]; 
		}
		void moveTo(int x,int y)
		{
			changeMapValue(myX,myY,ConstNum::AREA);
			setMouse(x,y);
			changeMapValue(x,y,ConstNum::MOUSE);
			drawMessage();
			//drawMap();//绘制地图 
			counter++;
			if  (isOut()) outMessage();//判断到没到出口 
			if(isAUTO) 
				Sleep(300);
		}
	void setBegin(int mouseX,int mouseY,int outX,int outY)//设置开始状态 
	{
		setMouse(mouseX,mouseY);
		setOutWay(outX,outY);
		path.setBegin(mouseX,mouseY);
		beginTime=GetTickCount();
		InitScreen();
	}
		void begin()
		{
			isAUTO=false;
			drawMap();//绘制地图 
			while (1)
			{
				
				if (isOut()) 	outMessage();
				drict(_getch());//控制按键方向 
				
			}
		}
	void beginPath()
	{
		int i;
		counter=1; 
		for (i=1;i<=path.getLength();i++)
		{
			
			drawMap();//绘制地图 
			if (isOut()) 	outMessage();
			if (can(path.getX(i),path.getY(i)))
				{
					moveTo(path.getX(i),path.getY(i)); 
				}
		}
	}
		void beginPath(Stack path)
	{
		int i;
		counter=1; 
			drawMap();//绘制地图 
		for (i=1;i<=path.getLength();i++)
		{
			
		
			if (isOut()) 	outMessage();
			if (can(path.getX(i),path.getY(i)))
				{
					moveTo(path.getX(i),path.getY(i)); 
				}
		}
	}
	void outPath()
	{
		path.outStack();
	}
	void outMessage()
	{
		gotoxy(getMapN()+2,getMapM());
		cout<<endl<<"恭喜你已走出迷宫！"<<endl; 
		exit(0);
	}
};
