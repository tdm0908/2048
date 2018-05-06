#include"xuly.h"


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
