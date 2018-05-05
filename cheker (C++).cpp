#include <iostream> 
# include <Windows.h>
using namespace std;  
 
char board[8][8];


 
void printboard()
{
	cout<<"   1 2 3 4 5 6 7 8 "<<endl;
    cout<<"   ________________";
    cout<<endl<<endl;
	for(int i=0;i<8;i++)
	{
		cout<<i+1<<" ";
		for(int j=0;j<8;j++)
		{
			cout<<"|";
			cout<<board[i][j];}
		cout<<"|";
		cout<<endl;
		cout<<"   ________________";
		cout<<endl<<endl;
	}
}


int chekingmove(int i, int j, int x, int y, int turn, int chek)
{ 
	
	if(board[x][y]!='X')
	{
		return 0;
	} 
	if(((x==i+1||x==i-1)&&(y==j+1||y==j-1))||((x==i+2||x==i-2)&&(y==j+2||y==j-2)))
	{ 
		if((x==i+2||x==i-2)&&(y==j+2||y==j-2))
		{ 
			if(turn==1&&x<i&&board[i][j]!='3')
			{
				return 0;
			} 
			if(turn==2&&x>i&&board[i][j]!='4')
			{
				return 0;
			} 
			if(x==i+2&&y==j+2)
			{ 
				if(board[i+1][j+1]==turn+48||board[i+1][j+1]=='X'||board[i+1][j+1]==turn+2+48)
				{
					return 0;
				}
				else
				{
					if(chek==0)
					{
						board[i+1][j+1]='X';
					}
					return 2;
				} 
			} 
			if(x==i+2&&y==j-2)
			{ 
				if(board[i+1][j-1]==turn +48||board[i+1][j-1]=='X'||board[i+1][j-1]==turn+2+48)
				{
					return 0;
				}
				else
				{
					if(chek==0)
					{
						board[i+1][j-1]='X';
					}
					return 2;
				} 
			} 
			if(x==i-2&&y==j+2)
			{ 
				if(board[i-1][j+1]==turn+48||board[i-1][j+1]=='X'||board[i-1][j+1]==turn+2+48)
				{
					return 0;
				}
				else
				{
					if(chek==0)
					{
						board[i-1][j+1]='X';
					}
					return 2;
				} 
			} 
			if(x==i-2&&y==j-2){ 
				if(board[i-1][j-1]==turn+48||board[i-1][j-1]=='X'||board[i-1][j-1]==turn+2+48)
				{
					return 0;
				}
				else
				{
					if(chek==0)
					{
						board[i-1][j-1]='X';
					}
					return 2;
				} 
			} 
		} 
	} 
	else
	{
		return 0;
	} 
	return 1; 
} 
 

 
void main() 
{ 
  
cout << endl; 
cout << " ******************************************************************************" << endl; 
cout << " *                                                                            *" << endl; 
cout <<"  *                                                                            *"<< endl; 
cout<<"   *     [[[[[[[[[[[[[[[[[      chekers       ]]]]]]]]]]]]]]]]]]                *"<<endl;
cout <<"  *                                                                            *"<< endl; 
cout << " *                                                                            *  " << endl; 
cout << " ******************************************************************************" << endl; 
cout << endl ;
cout<< endl; 
 
for(int i=0;i<8;i++)
{
	for(int j=0;j<8;j++)
	{
		board[i][j]='X';
	}
} 
for(int i=0;i<8;i++)
{
	for(int j=0;j<8;j++)
	{
		if((i+j)%2==0)
		{
			board[i][j]=' ';
		}
	}
} 
for(int i=0;i<3;i++)
{
	for(int j=0;j<8;j++)
	{
		if((i+j)%2==1)
		{
			board[i][j]='1';
		}
	}
}
for(int i=5;i<8;i++)
{

	for(int j=0;j<8;j++)
	{
		if((i+j)%2==1)
		{
			board[i][j]='2';
		}
	}
} 
	 
	printboard(); 
	int game=1; 
	int end=0; 
	int turn=1; 
	int i, j, x, y, win_p1, win_p2; 
	while(game==1)
	{ 
		cout<<endl; 
		cout<<"Player "<<turn<<":"; 
		int loop=1, loop1=1, loop2=1, loop3=1, loop4=1, loop5=1, loop6=1; 
		while (loop==1)
		{ 
			loop6=1; 
			while (loop6==1)
			{ 
				loop5=1; 
				while (loop5==1)
				{ 
					loop1=1; 
					while (loop1==1)
					{ 
						cout<<endl<<"enter row of piece: "; 
						cin>>i; 
						cout<<endl; 
						if(i>8||i<1)
						{
							cout<<"does not exist"<<endl<<endl;
						}
						else
						{
							loop1=0;
						} 
					} 
					loop2=1; 
					while (loop2==1)
					{ 
						cout<<"enter column of piece: : "; 
						cin>>j; 
						cout<<endl; 
						if(j>8||j<1)
						{
							cout<<"does not exist"<<endl<<endl;
						}
						else
						{
							loop2=0;
						}  
					} 
					if((board[i-1][j-1]!='2'&&board[i-1][j-1]!='4' && turn!=1)||(board[i-1][j-1]!='1'&&(board[i-1][j-1]!='3')&&turn!=2))
					{
						if(board[i-1][j-1]!=' '&&board[i-1][j-1]!='X')
						{
							cout<<"that is not ur piece"<<endl<<endl;
						}
						if(board[i-1][j-1]==' '||board[i-1][j-1]=='X')
						{
							cout<<"no piece there"<<endl<<endl;
						}
					}
					else
					{
						loop5=0;
					} 
				} 
				loop3=1; 
				while (loop3==1)
				{ 
					cout<<"enter movement row: "; 
					cin>>x; 
					cout<<endl; 
					if(x>8||x<1)
					{
						cout<<"not possible"<<endl<<endl;
					}
					else
					{
						loop3=0;
					} 
				} 
				loop4=1; 
				while (loop4==1)
				{ 
					cout<<"enter movement column: "; 
					cin>>y; 
					cout<<endl; 
					if(y>8||y<1)
					{
						cout<<"not possible"<<endl<<endl;
					}
					else
					{
						loop4=0;
					} 
				} 
				if(board[x-1][y-1]!='X')
				{
					if(board[x-1][y-1]==' ')
				{
					cout<<"u can not move there"<<endl<<endl;
				}
				else
				{
					cout<<"no empty place"<<endl<<endl;
				}
				} 
				else if(turn==1&&x<i&&board[i-1][j-1]!='3')
				{
					cout<<"u can not move there"<<endl<<endl;
				} 
				else if(turn==2&&x>i&&board[i-1][j-1]!='4')
				{
					cout<<"u can not move there"<<endl<<endl;
				} 
				else
				{
					loop6=0;
				} 
			} 
			i=i-1;
			j=j-1;
			x=x-1;
			y=y-1; 
			cout<<endl; 
			int flag; 
			flag=chekingmove(i, j, x, y, turn, 0);  
			if (flag!=0)
			{
				board[x][y]=board[i][j];board[i][j]='X';
			} 
			if(turn==1)
			{
				if((flag==1||flag==2)&&(x==7))
				{
					board[x][y]='3';
				}
			} 
			if(turn==2)
			{
				if((flag==1||flag==2)&&(x==0))
				{
					board[x][y]='4';
				}
			} 
	
			if(flag==1||flag==2)
			{
				loop=0;
			} 
			else 
			{ 
				cout<<"u can not move there"<<endl<<endl;
			} 
		}  
		win_p1=0,win_p2=0;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(board[i][j]=='1'||board[i][j]=='3')
				{
					win_p1=win_p1+1;
				}
				if(board[i][j]=='2'||board[i][j]=='4')
				{
					win_p2=win_p2+1;
				}
			}
		} 
		printboard(); 
		if(win_p1==0||win_p2==0)
		{
			game=0;
		} 
		if(turn==1)
		{
			turn=2;
		}
		else
		{
			turn=1;
		} 
	} 
	if(win_p1!=0)
	{
		cout<<endl<<"Player 1 wins....!"<<endl<<endl;
	} 
	if(win_p2!=0)
	{
		cout<<endl<<"Player 2 wins....!"<<endl<<endl;
	} 
	Sleep(3000);
	 
} 

