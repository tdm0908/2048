#include"xuly.h"



/* ham di chuyen tro choi sang trai*/
void dichuyensangtrai(int toado[][4],int &diem,int a[][4],int &check)
{	// dich chuyen cac phan tu khac 0 ve ben trai
	for(int hang=0;hang<4;hang++)
		{
			for(int j=1;j<4;j++)
				{
					for(int i=j-1;i>=0;i--)
						{
							if(toado[hang][i]==0)     // neu ttoa do bang 0
							{
								toado[hang][i]=toado[hang][i+1]; // toa do vi tri ben tay trai gan bang toa do vi tri ben tay phai
								toado[hang][i+1]=0;             // toa do vi tri ben phai gan bang 0
							}
						}
				}
		}

	//Xet 2 gia tri ke nhau ma bang nhau thi cong 2 so vao so ben trai va xoa di so ben trai, gan gia tri so ben phai la 0
	for(int h=0;h<4;h++)
	{
		for(int c=0;c<4;c++)
		{
			if(toado[h][c] == toado[h][c+1])       // neu toa do vi tri ben trai bang vi tri ben phai
			{
				toado[h][c]+=toado[h][c];       // toa do vi tri ben trai tang gap doi
				diem+=toado[h][c];              // diem cong them bang gia tri vi tri do
				toado[h][c+1]=0;                //toa do ben phai ban bang 0
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
    /* ham kiem tra con co di chuyen sang trai duoc nua hay khong*/
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

/*ham di chuyen tro chooi sang ben phai */
void dichuyensangphai(int toado[][4],int &diem,int a[][4],int &check)
{
    // dich chuyen cac phan tu khac 0 ve ben phai
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
	////Xet 2 gia tri ke nhau ma bang nhau thi cong 2 so vao so ben trai va xoa di so ben trai, gan gia tri so ben phai la 0

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
    //dich chuyen cac phan tu khac 0 ve ben phai
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
    // kiem tra con co the di chuyen sang phai nua hay k
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

/*ham dich chuyen tro choi len tren(tuong tu 2 ham tren)*/
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
/*ham dich chuyen tro choi xuong duoi(tuong tu 2 ham tren)*/
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

