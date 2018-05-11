#include"dieukhien.h"


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

