#include<fstream>
#include<conio.h>
#include"menu.h"
#include"xuly.h"



char khung[50][55];
int ViTri[4];
int state=0;
int toado[4][4]={0};
int diem=0;
int a[4][4],check=0;

int sc=2;
int fileScore(int s,int &sc)
{
	fstream fileScore;
	//Mo file de luu gia tri diem so hien tai kieu nhi phan
	fileScore.open("Score.txt",ios::out | ios::binary);
	fileScore.write(reinterpret_cast<char *>(&s),sizeof(s));
	fileScore.close();
	//Mo file de lay gia tri diem so gan vao bien sc
	return 0;
}
void bestScore(int &sc)
{
	fstream fileScore;
	//mo file de doc diem so hien tai
	fileScore.open("Score.txt",ios::in | ios:: binary);
	fileScore.read(reinterpret_cast<char *>(&sc),sizeof(sc));// doc du lieu diem so
	fileScore.close(); // dong file
	gotoxy(40,1);
	cout<<"Best: ";
	cout<<sc;
}
/*ham dieu khien tro choi bang ban phim*/
void dieukhien()
{
	char c=_getch(); // nhap ky tu c tu ban phim
	// ban phim nhan d thi tro choi di chuyen sang phai
	if(c=='d' )
	{
		dichuyensangphai(toado,diem,a,check);
		state=1; // neu di chuyen duoc thi gan state bang 1
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

    else if(c=='r')
    {   system("cls");
        diem=0;
        Draw(35,1,12,diem);
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                toado[i][j]=0;
            }
        vekhung(khung);

        taovitri(ViTri,toado);
        bestScore(sc);
        intoado(toado,khung);
        for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = toado[i][j];
		}
	}

    }

	else
		state=0;

}


/*ham random 1 o ngau nhien co gia tri bang 2 hoac bang 4*/
void randomso(int toado[][4],int check)
{

	int vitri1,vitri2;
	srand(time(0));
	// ramdom toa do cua 1 o, neu gai tri cua o khac 0 thi tiep tucj ran dom con bang 0 thi dung random va lay toa do do
	do
	{

		vitri1= rand()%(4);
		vitri2= rand()%(4);
	} while (toado[vitri1][vitri2] !=0);
	// ramdom 1 o co gia tri bang 2 hoac bang 4
	do
	{
		toado[vitri1][vitri2]= 2 + rand()%(3);
	} while (toado[vitri1][vitri2] ==3);    // neu o co gia tri bang 3 thi tiep tuc ran dom neu khac 3 thi o do co gia tri khac 3 do va dung vong lap

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
	bestScore(sc);
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
			if(Score(diem)>sc)
				fileScore(Score(diem),sc);
			break;
		}
		else
		{
			if(check==1)
				randomso(toado,check);
			intoado(toado,khung);
		}
	}
	return 0;
}
