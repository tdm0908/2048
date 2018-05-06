#include"vekhung.h"

int vekhung(char kh[][55])
{
	for(int i=0;i<17;i++)
	{
		for(int j=0;j<25;j++)
		{
			if(i==0 || i==16|| j==0 || j==24 || i==4 || i==8 || i==12 || j==6 || j==12 || j== 18)
				textcolor(21);
			else
				textcolor(35);

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
int intoado(int toado[][4],char kh[][55])
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
