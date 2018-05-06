
#include<conio.h>
#include"xuly.h"



char khung[50][55];
int ViTri[4];
int toado[4][4]={0};
int a[4][4],check=0;
int state=0;
int diem=0;


void dieukhien()
{
	char c=_getch();
	if(c=='d' )
	{
		dichuyensangphai(toado,diem,a,check);
		state=1;
	}
	else if(c=='s')
	{
		dichuyenxuong(toado,diem,a,check);
		state=1;
	}
	else if(c=='w')
	{
		dichuyenlen(toado,diem,a,check);
		state=1;
	}
	else if(c=='a')
	{
		dichuyensangtrai(toado,diem,a,check);
		state=1;
	}
	else if(c== 'x')
	{
		exit(1);
	}
	else
		state=0;

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










