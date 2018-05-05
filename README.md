#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<time.h>
#include<cstdlib>
#include <fstream>
#include<string>
using namespace std;
char khung[50][55];
int ViTri[4];

// ham thay doi kich thuoc man hinh console
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// ham tao mau
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Ham dich chuyen con tro toi toa do x,y
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

// Ham xoa man hinh
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}


void Draw(int x, int y,int codeCol,int a)
{
	gotoxy(x,y);
	textcolor(codeCol);
	cout<<a;
}



int vekhung(char khung[][55])
{
	for(int i=0;i<17;i++)
	{
		for(int j=0;j<25;j++)
		{
			if(i==0 || i==16|| j==0 || j==24 || i==4 || i==8 || i==12 || j==6 || j==12 || j== 18)
				textcolor(112);
			else
				textcolor(51);

			cout<<" ";
		}
		cout<<endl;
	}
	textcolor(11);
	gotoxy(30,4);
	cout<<"Huong Dan:";
	textcolor(7);
	gotoxy(30,5);
	cout<<"phim A: Sang Trai";
	textcolor(13);
	gotoxy(30,6);
	cout<<"phim D: Sang Phai";
	textcolor(14);
	gotoxy(30,7);
	cout<<"phim W: di chuyen len ";
	gotoxy(30,8);
	textcolor(10);
	cout<<"phim S: di chuyen xuong";
	gotoxy(27,10);
	textcolor(15);
	cout<<"Nhan X de thoat chuong trinh.";
	textcolor(10);
	return 0;
}

int toado[4][4]={0};


int taovitri(int ViTri[],int toado[][4])
{
	srand(time(0));
	ViTri[0] = rand()%4;		
	ViTri[1] = rand()%4;
	do 
		{
			ViTri[2] = rand()%4;;		
			ViTri[3] = rand()%4;
		}
	while
		(ViTri[0]==ViTri[2] || ViTri[1]==ViTri[3]);
	toado[ViTri[2]][ViTri[3]]=2;
	toado[ViTri[0]][ViTri[1]]=2;
	return 0;
}


int intoado(int toado[][4],char khung[][55])
{
	int a=4;
	int b=3;
	for(int i=0;i<4;i++)
	{	for(int j=0;j<4;j++)
			{
				if(toado[i][j]!=0){
				switch (toado[i][j])
				{
				case 2:
				{	Draw(a,b,63,toado[i][j]);      
					break;
				}
			case 4:
				{Draw(a,b,62,toado[i][j]);
				break;}
			case 8:
				{	Draw(a,b,61,toado[i][j]);
					break;
				}
			case 16:
				{	Draw(a,b,60,toado[i][j]);
					break;
				}
			case 32:
				{	Draw(a,b,59,toado[i][j]);
					break;
				}
			case 64:
				{	Draw(a,b,58,toado[i][j]);
					break;
				}
			case 128:
				{	
					Draw(a,b,57,toado[i][j]);
					break;
				}
			case 256:
				{	
					Draw(a,b,49,toado[i][j]);
					break;
				}
			case 512:
				{
					Draw(a,b,50,toado[i][j]);
					break;
				}
			case 1024:
				{
					Draw(a,b,52,toado[i][j]);
					break;
				}
			case 2048:
				{	Draw(a,b,48,toado[i][j]);
					break;
				}
				}     //dong ngoac switch
			}
			
			a+=6;
			}
			b+=4;		
			a=4;
			
			
			}

return 0;
}


int a[4][4],check=0;
void dichuyensangtrai(int toado[][4],int &diem,int a[][4],int &check)
{	// dich chuyen cac phan tu khac 0 ve ben trai 
	for(int hang=0;hang<4;hang++)
		{
			for(int j=1;j<4;j++)
				{
					for(int i=j-1;i>=0;i--)		
						{
							if(toado[hang][i]==0)
							{	
								toado[hang][i]=toado[hang][i+1];    
								toado[hang][i+1]=0;
								diem+=toado[hang][i+1];
							}
						}
				}
		}
	//Xet 2 gia tri ke nhau ma bang nhau thi cong 2 so lai roi xoa di 1 so
	for(int h=0;h<4;h++)
	{
		for(int c=0;c<4;c++)
		{
			if(toado[h][c] == toado[h][c+1])
			{
				toado[h][c]+=toado[h][c];
				diem+=toado[h][c];
				toado[h][c+1]=0;
			}
		}
	}
	//Di chuyen lai 1 lan nua cac phan tu trong hang
	for(int hang=0;hang<4;hang++)
		{
			for(int j=1;j<4;j++)
			{
				for(int i=j-1;i>=0;i--)		
				{
					if(toado[hang][i]==0)
					{
						toado[hang][i]=toado[hang][i+1];
						toado[hang][i+1]=0;
					}
				}
			}
		}
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(a[i][j]!=toado[i][j])
			{
				check=1;
			}
		}
	}
}


void dichuyensangphai(int toado[][4],int &diem,int a[][4],int &check)
{

	for(int hang=0;hang<4;hang++)
	{
		for(int j=2;j>=0;j--)
		{
			for(int i=j+1;i<=3;i++)
			{
				if(toado[hang][i]==0)
				{
					toado[hang][i]=toado[hang][i-1];
					toado[hang][i-1]=0;
				}
			}
		}
	}
	//Xet 2 gia tri ke nhau ma bang nhau thi cong 2 so lai roi xoa di 1 so

	for(int i=0;i<=3;i++)
	{
		for(int j=2;j>=0;j--)
		{
			if (toado[i][j]==toado[i][j+1])
			{
				toado[i][j+1]+=toado[i][j+1];
				toado[i][j]=0;
				diem+=toado[i][j+1]; 
			}
		}
	}

	for(int hang=0;hang<4;hang++)
	{
		for(int j=2;j>=0;j--)
		{
			for(int i=j+1;i<=3;i++)
			{
				if(toado[hang][i]==0)
				{
					toado[hang][i]=toado[hang][i-1];
					toado[hang][i-1]=0;
				}
			}
		}
	}
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(a[i][j]!=toado[i][j])
			{
				check=1;
			}
		}
	}
}


void dichuyenlen(int toado[][4],int &diem,int a[][4],int &check)
{
	for(int cot=0;cot<4;cot++){
		for(int i=1;i<4;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				//Thay doi cot 1
				if(toado[j][cot]==0)
				{
					toado[j][cot]=toado[j+1][cot];
					toado[j+1][cot]=0;
				}

			}
		}
	}

	//Xet 2 gia tri ke nhau ma bang nhau thi cong 2 so lai roi xoa di 1 so

	for(int j=0;j<4;j++)
	{
		for(int i=1;i<4;i++)
		{
			if(toado[i][j]==toado[i-1][j])
			{
				toado[i-1][j]+=toado[i-1][j];
				diem+=toado[i-1][j];
				toado[i][j]=0;
			}
		}
	}
	for(int cot=0;cot<4;cot++)
	{
		for(int i=1;i<4;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(toado[j][cot]==0)
				{
					toado[j][cot]=toado[j+1][cot];
					toado[j+1][cot]=0;
				}
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(a[i][j]!=toado[i][j])
			{
				check=1;
			}
		}
	}
}

void dichuyenxuong(int toado[][4],int &diem,int a[][4],int &check)
{

	for(int cot=0;cot<4;cot++)
		{
			for(int j=2;j>=0;j--)
			{
				for(int i=j+1;i<=3;i++)
				{
					if(toado[i][cot]==0)
					{
						toado[i][cot]=toado[i-1][cot];
						toado[i-1][cot]=0;
					}
				}
			}
		}
	//Xet 2 gia tri ke nhau ma bang nhau thi cong 2 so lai roi xoa di 1 so

	for(int j=0;j<4;j++)
	{
		for(int i=3;i>=0;i--)
		{
			if(toado[i][j]==toado[i-1][j])
			{
				toado[i][j]+=toado[i][j];
				diem+=toado[i][j];
				toado[i-1][j]=0;
			}
		}
	}
	for(int cot=0;cot<4;cot++)
		{
			for(int j=2;j>=0;j--)
			{
				for(int i=j+1;i<=3;i++)
				{
					if(toado[i][cot]==0)
					{	toado[i][cot]=toado[i-1][cot];
						toado[i-1][cot]=0;
					}
				}
			}
		}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++){
			if(a[i][j]!=toado[i][j])
			{
				check=1;
			}
		}
	}
}


int diem=0;
void dieukhien()
{
	char c=_getch();
	if(c=='d' )
	{
		dichuyensangphai(toado,diem,a,check);
	}
	else if(c=='s')
	{
		dichuyenxuong(toado,diem,a,check);
	}
	else if(c=='w')
	{	
		dichuyenlen(toado,diem,a,check);
	}
	else if(c=='a')
	{
		dichuyensangtrai(toado,diem,a,check);
		
	}
	else if(c== 'x')
	{
		exit(1);
	}

}


void randPosNum(int toado[][4],int check)
{
	
	int vitri1,vitri2;
	srand(time(0));
	do
	{

		vitri1= rand()%(4);
		vitri2= rand()%(4);
	} while (toado[vitri1][vitri2] !=0);
	do
	{ 
		toado[vitri1][vitri2]= 2 + rand()%(3);
	} while (toado[vitri1][vitri2] ==3);

}
//Ham kiem tra xem ket thuc game chua
int kiemtragame(int toado[][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(toado[i][j]==0)
				return 1;	
		}

	}
	return 0;

}

int Score(int diem)
{
	int s=diem;

	return s;
}


int main(){
	system("cls");
	resizeConsole(600,280);
	vekhung(khung);
	taovitri(ViTri,toado);
	intoado(toado,khung);
	while(1){
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				a[i][j]=toado[i][j];
			}
		}
		check=0;
		gotoxy(28,1);
		textcolor(11);
		cout<<"Score :";
		Draw(35,1,12,diem);
		dieukhien();
		if(state==1)
		{
			gotoxy(1,1);
			vekhung(khung);
		}
		if(kiemtragame(toado)==0)
		{
			gotoxy(30,13);
			textcolor(12);
			cout<<"Game Over! ";
			cout<<"Diem Cua Ban :"<<Score(diem);
			break;
		}
		else
		{
			if(check==1)
				randPosNum(toado,check);
			intoado(toado,khung);
		}
	}
	return 0;
}
