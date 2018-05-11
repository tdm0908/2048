#include"vekhung.h"

/*ham tao cac o vuong va to mau tren man hinh console */
int vekhung(char kh[][55])
{
	for(int i=0;i<17;i++) // cho i chay tu 0 den 16 theo truc Oy man hinh console
	{
		for(int j=0;j<25;j++) // cho j chay tu 0 den 24 theo truc Ox cua man hinh console
		{
			if(i==0||i==4||i==8||i==12||i==16||j==0||j==6||j==12||j==18||j==24) // tai cac vi tri i,j tren thi to mau 21 de tao thanh 16 o vuong co mau 35
				textcolor(21);
			else
				textcolor(35);

			cout<<" ";
		}
		cout<<endl;
	}
	// di chuyen toi vi tri co toa do(30;4) to mau thu 11 vao chu huong dan
	gotoxy(30,4);
	textcolor(11);
	cout<<"Huong Dan:";
	//tuong tu tren
	gotoxy(30,5);
	textcolor(7);
	cout<<"nhan a de di chuyen sang trai";
	// tuong tu tren
	gotoxy(30,6);
	textcolor(13);
	cout<<"nhan d de di chuyen sang phai";
	// tuong tu tren
	gotoxy(30,7);
	textcolor(14);
	// tuong tu trrn
	cout<<"nhan w de di chuyen len";
	gotoxy(30,8);
	textcolor(10);
	cout<<"nhan s de di chuyen xuong";
	gotoxy(30,9);
	textcolor(15);
	cout<<"Nhan X de thoat chuong trinh";
	gotoxy(30,10);
	textcolor(15);
	cout<<"Nhan R de choi lai game ";



	return 0;
}


/*khoi tao 2 vi tri bat ki co gia tri bang 2*/
int taovitri(int ViTri[],int toado[][4])
{
	srand(time(0));
	//random gia tri bat ki tu 0 den 3
	ViTri[0] = rand()%4;
	ViTri[1] = rand()%4;
	do
		{   // random gia tri bat ki tu 0 den 3
			ViTri[2] = rand()%4;;
			ViTri[3] = rand()%4;
		}
	while
		(ViTri[0]==ViTri[2] && ViTri[1]==ViTri[3]); // dieu kien dung giup cho 2 toa do sau khong bi trung nhau
	// khoi tao gia tri o hai toa do bang 2
	toado[ViTri[2]][ViTri[3]]=2;
	toado[ViTri[0]][ViTri[1]]=2;
	return 0;
}


/*in va to mau tai cac vi tri co gia tri 2,4,8,..*/
int intoado(int toado[][4],char kh[][55])
{
	int a=4;
	int b=3;
	// duyet mang 2 chieu 4*4
	for(int i=0;i<4;i++)
	{	for(int j=0;j<4;j++)
			{
				if(toado[i][j]!=0){
				switch (toado[i][j])
				{
				    // khi tao do[1][j] cos gia tri bang 2 thi di chuyen den vi tri cos toa do a,b tren man hinh console de to mau
				case 2:
				{	Draw(a,b,63,toado[i][j]);
					break;
				}
				// tupng tu tren
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
					Draw(a-1,b,57,toado[i][j]);
					break;
				}
			case 256:
				{
					Draw(a-1,b,49,toado[i][j]);
					break;
				}
			case 512:
				{
					Draw(a-1,b,50,toado[i][j]);
					break;
				}
			case 1024:
				{
					Draw(a-2,b,52,toado[i][j]);
					break;
				}
			case 2048:
				{	Draw(a-2,b,48,toado[i][j]);
					break;
				}
				}     //dong ngoac switch
			}

			a+=6; // sau moi lan chay cua j thi tang toa do cua truc ox len 6 de xet den o tiep theo theo 1 hang
			}
			b+=4; // xet toa do theo truc oy cua man hinh console de xet hang tiep theo
			a=4;    // khoi tao lai gia tri cua a de xet lai toa do theo truc ox cua man hinh console
}
return 0;
}

void Intro()
{


	gotoxy(1,5);
	textcolor(11);
	cout<<"        =======\n";
	Sleep(10);
	cout<<"     ===      ====\n";
	Sleep(10);
	cout<<"    ==       ====\n";
	Sleep(10);
	cout<<"           ====\n";
	Sleep(10);
	cout<<"         ====\n";
	Sleep(10);
	cout<<"       ====\n";
	Sleep(10);
	cout<<"     ====\n";
	Sleep(10);
	cout<<"   =====\n";
	Sleep(10);
	cout<<"  =============\n";
	Sleep(10);
	cout<<"  =============\n";
	gotoxy(20,5);
	Sleep(100);
	textcolor(12);
	cout<<"      =====\n";
	Sleep(10);
	gotoxy(20,6);
	cout<<"   ===     ===\n";
	Sleep(10);
	gotoxy(20,7);
	cout<<"  ===       ===\n";
	Sleep(10);
	gotoxy(20,8);
	cout<<" ===         ===\n";
	Sleep(10);
	gotoxy(20,9);
	cout<<" ===         ===\n";
	Sleep(10);
	gotoxy(20,10);
	cout<<" ===         ===\n";
	Sleep(10);
	gotoxy(20,11);
	cout<<" ===         ===\n";
	Sleep(10);
	gotoxy(20,12);
	cout<<"  ===       ===\n";
	Sleep(10);
	gotoxy(20,13);
	cout<<"   ===     ===\n";
	Sleep(10);
	gotoxy(20,14);
	cout<<"      =====\n";
	Sleep(10);
	gotoxy(36,5);
	Sleep(100);
	textcolor(14);
	cout<<"          ===\n";
	Sleep(10);
	gotoxy(36,6);
	cout<<"        ===\n";
	Sleep(10);
	gotoxy(36,7);
	cout<<"      ===     \n";
	Sleep(10);
	gotoxy(36,8);
	cout<<"    ===       ===\n";
	Sleep(10);
	gotoxy(36,9);
	cout<<"    ==============\n";
	Sleep(10);
	gotoxy(36,10);
	cout<<"    ==============\n";
	Sleep(10);
	gotoxy(36,11);
	cout<<"              ===\n";
	Sleep(10);
	gotoxy(36,12);
	cout<<"              ===\n";
	Sleep(10);
	gotoxy(36,13);
	cout<<"              ===\n";
	Sleep(10);
	gotoxy(36,14);
	cout<<"              ===\n";
	Sleep(10);
	gotoxy(54,5);
	Sleep(100);
	textcolor(10);
	cout<<"        ====\n";
	Sleep(10);
	gotoxy(55,6);
	cout<<"    ===    ===\n";
	Sleep(10);
	gotoxy(55,7);
	cout<<"   ===      ===\n";
	Sleep(10);
	gotoxy(55,8);
	cout<<"    ===    ===\n";
	Sleep(10);
	gotoxy(55,9);
	cout<<"       ====\n";
	Sleep(10);
	gotoxy(55,10);
	cout<<"    ===    ===\n";
	Sleep(10);
	gotoxy(55,11);
	cout<<"   ===      ===\n";
	Sleep(10);
	gotoxy(55,12);
	cout<<"   ===      ===\n";
	Sleep(10);
	gotoxy(55,13);
	cout<<"    ===    ===\n";
	Sleep(10);
	gotoxy(55,14);
	cout<<"       ====\n";
	Sleep(10);
	textcolor(13);
	cout<<"Nhan phim bat ky de bat dau choi...";
}

