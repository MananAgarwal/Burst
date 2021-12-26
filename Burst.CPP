/*****************************************************************************

				   BURST

	       Created by Manan, Sanit, Kanishk and Shreyas

*****************************************************************************/

#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<bios.h>

int enter=7181, up=18432, down=20480, left=19200, right=19712, esc=283;
int space=14624, one=561, two=818, three=1075, four=1332, five=1589;
int six=1846, seven=2103, eight=2360, nine=2617;
int i,j,k=0,key,hits=0,clr,spd,attempts,count;
 int s;//score return       //
  int x,n=0,last=0;              //
  float arg,accuracy;
float ax11,ax12,ay11,ay12,ax21,ax22,ay21,ay22,bx,by1,by2;

class hiscr
 {
  protected:
    char name[25];
    int score;
  public:
    void getdata();
    void add();
    void record();
 }hi,obj;

void menu();

void hiscr::add()
 {
  cleardevice();
 fstream fin,fout;
 s=pow(hits,2)*accuracy;
 score=s;
 
 fin.open("hiscore.txt",ios::in|ios::out);//open file in input mode
 fin.seekg(0);//set file pointer to first object
 fout.open("temp.txt",ios::out);//open temporary file
 fin.read((char*)&obj,sizeof(obj));

 while(!fin.eof())
  {
   if(obj.score>=score)
    { fout.write((char*)&obj,sizeof(obj));}
   if(obj.score<score)
    { x=fin.tellg();
      break;}
   fin.read((char*)&obj,sizeof(obj));
  }

  getdata();
  fout.write((char*)&hi,sizeof(hi));
  fin.seekg(x);
 while(!fin.eof())
   { fout.write((char*)&obj,sizeof(obj));
     fin.read((char*)&obj,sizeof(obj));}

  fin.close();
  fout.close();
  remove("hiscore.txt");//delete old file
  rename("temp.txt","hiscore.txt");//rename temporary file as master file

 }

void hiscr::getdata()
 { int n;
   fstream fin;
   fin.open("hiscore.txt",ios::in);

   n=9*sizeof(hi);
   fin.read((char*)&hi,sizeof(hi));
   last=obj.score;   //to store the last highscore

   fin.close();
    if(s>last)
    {setcolor(7);
    settextstyle(1,0,4);
    outtextxy(245,180,"Enter Name");
    cin>>name;
    score=s;}
 }

void hiscr::record()
 {
   cleardevice();
   int n;

   fstream fin;
   fin.open("hiscore.txt",ios::in);//open file
   if(fin.fail())
    {
     cout<<"FILE NOT FOUND";
     getch();
    }


   fin.seekg(0,ios::end);
   n=fin.tellg()/sizeof(hi);
   if(n>10)  //to display only top 10 scores
    {n=10;}

   setcolor(5);
   settextstyle(1,0,2);
   outtextxy(0,30," \n <-------------- * LEADERBOARD * --------------->\n");
   setcolor(6);
   settextstyle(1,0,1);
   outtextxy(160,60,"\t\t\t  Name");
   outtextxy(370,60," \t\t\tScore\n");
   cout<<"\n\n\n\n\n";

   fin.seekg(0,ios::beg);//set file pointer to the beginning
   for(int j=0;j<n;j++)
    {
      cout<<endl;
      fin.read((char*)&hi,sizeof(hi));
      cout<<"\t\t\t"<<name<<"\t\t\t"<<score<<'\n';
      last=score;   //to store the last highscore
    }

   fin.close();
   bioskey(0);
   setcolor(0);
   clrscr();
   menu();
 }



void graphinit()
 {
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
  errorcode = graphresult();
  if (errorcode != grOk)
   {
    printf("Graphics error: %s\n", grapherrormsg(errorcode));
    printf("Press any key to halt:");
    bioskey(0);
   exit(1);
  }
 }

void man()
      { //face
	setcolor(15);
	ellipse(60-30, 345+30,0,360,11,17);
	setfillstyle(SOLID_FILL,8);
	floodfill(60-30,345+30,15);
	setcolor(8);
	ellipse(60-30, 345+30,0,360,11,17);

	//head band
	setcolor(15);
	ellipse(50-30,325+30,269,353,12,20);
	ellipse(48-30,327+30,275,355,18,22);
	line(49-30,345+30,50-30,350+30);
	line(62-30,328+30,65-30,329+30);
	setfillstyle(SOLID_FILL,4);
	floodfill(62-30,333+30,15);
	setcolor(4);
	ellipse(50-30,325+30,269,353,12,20);
	ellipse(48-30,327+30,275,355,18,22);
	line(49-30,345+30,50-30,350+30);
	line(62-30,328+30,65-30,329+30);

	setcolor(15);
	ellipse(45-30,344+30,0,360,4,2);
	floodfill(45-30,345+30,15);
	setcolor(4);
	ellipse(45-30,344+30,0,360,4,2);
	line(49-30,348+30,44-30,357+30);
	line(49-30,348+30,42-30,354+30);

	//body
	setcolor(15);
	ellipse(60-30, 345+70,0,180,9,21);
	line(60-9-30,395+20,60+9-30,395+20);
	setfillstyle(SOLID_FILL,8);
	floodfill(60-30,345+60,15);
	setcolor(8);
	ellipse(60-30, 345+70,0,180,9,21);
	line(60-9-30,395+20,60+9-30,395+20);
	line(60-9-30,395+20,60-9-30,395+40);
	line(60+9-30,395+20,60+9-30,395+40);
	line(60+9-30,395+40,60-9-30,395+40);
	floodfill(60-30,395+30,8);

	//hand
	setcolor(15);
	ellipse(60-30, 345+63,35,235,6,10);
	line(60-5-1-30,345+69-1,60+7+11-30,345+83-5);
	line(60+6-1-30,345+57-1,72+7-30,348+60);
	line(67+11-30,345+83-5,95+6+3-30,345+50-2);
	line(72+7-30,348+60,95+4+4-30,345+43-2);
	ellipse(99+6-30,388+1,240,170,5,5);
	setcolor(8);
	floodfill(80-30,420,15);

	setcolor(0);
	ellipse(60-30, 345+63,35,235,6,10);
	line(60-5-1-30,345+69-1,60+7+11-30,345+83-5);
	line(60+6-1-30,345+57-1,72+7-30,348+60);
	line(67+11-30,345+83-5,95+6+3-30,345+50-2);
	line(72+7-30,348+60,95+4+4-30,345+43-2);
	ellipse(99+6-30,388+1,240,170,5,5);
	setcolor(15);
	}

void op_bow()
      { int x=8,y=14;
	setcolor(14);
	ellipse(85-25-x, 225-y,330,80,22,45);
	ellipse(66-x, 178-y, 0, 360, 3, 3);
	ellipse(78-x, 251-y, 0, 360, 3, 3);
	floodfill(65-x, 178-y, 14);
	floodfill(78-x, 251-y, 14);
	setcolor(15);
	line(104-25-x,255-y,98-25-x,219-y);
	line(98-25-x,219-y,91-25-x,179-y);
	delay(80);
	setcolor(0);
	line(104-25-x,255-y,98-25-x,219-y);
	line(98-25-x,219-y,91-25-x,179-y);

	setcolor(15);
	line(106-25-x,251-y,89-25-x,226-y);
	line(91-25-x,179-y,89-25-x,226-y);
	delay(80);
	setcolor(0);
	line(106-25-x,251-y,89-25-x,226-y);
	line(91-25-x,179-y,89-25-x,226-y);

	setcolor(15);
	line(106-25-x,251-y,80-25-x,233-y);
	line(91-25-x,179-y,80-25-x,233-y);
	delay(80);
	setcolor(0);
	line(106-25-x,251-y,80-25-x,233-y);
	line(91-25-x,179-y,80-25-x,233-y);

	setcolor(15);
	line(104-25-x,255-y,98-25-x,219-y);
	line(98-25-x,219-y,91-25-x,179-y);
      }


void bow(int n)
      {

	setcolor(14);
	ellipse(85-25, 345+30,320,80,22,45);
	setcolor(15);
	line(104-25,405,98-25,369);
	line(98-25,369,91-25,329);


	if(n==1)
	{
	setcolor(0);
	line(104-25,405,98-25,369);
	line(98-25,369,91-25,329);

	setcolor(15);
	line(106-25,401,89-25,376);
	line(91-25,329,89-25,376);
	delay(80);
	setcolor(0);
	line(106-25,401,89-25,376);
	line(91-25,329,89-25,376);

	setcolor(15);
	line(106-25,401,80-25,383);
	line(91-25,329,80-25,383);
	delay(80);
	setcolor(0);
	line(106-25,401,80-25,383);
	line(91-25,329,80-25,383);

	setcolor(15);
	line(104-25,405,98-25,369);
	line(98-25,369,91-25,329);
      }
  }

void instructions()
  {
  cleardevice();
  man();
  bow(0);
  setcolor(14);
  settextstyle(6, HORIZ_DIR, 4);
  outtextxy(245, 50, "Instructions");
  setcolor(3);
  settextstyle(2, HORIZ_DIR, 4);
  outtextxy(20,120, "* Your aim is to pop as many balloons as possible.");
  outtextxy(20,140, "* You can fire an arrow in six different angles.");
  outtextxy(20,160, "* Fire an arrow by pressing 1, 2, 3, 4, 5 or 6.");
  outtextxy(20,180, "* You only get one chance to shoot a balloon.");
  outtextxy(20,220, "Note: Fire an arrow only when a balloon is in sight.");
  outtextxy(17,230, "      Giving unnecessary commands or multiple commands at once might confuse the archer.");
  setcolor(4);
  float ang;
  ang=5*3.14/12;
  outtextxy(50+30*pow(2,1/2)*cos(ang)+15*pow(2,1/2)*cos(ang)*6,400-30*pow(2,1/2)*sin(ang)-15*pow(2,1/2)*sin(ang)*6,"1");
  ang=3.14/3;
  outtextxy(50+30*pow(2,1/2)*cos(ang)+15*pow(2,1/2)*cos(ang)*6,400-30*pow(2,1/2)*sin(ang)-15*pow(2,1/2)*sin(ang)*6,"2");
  ang=3.14/3.5;
  outtextxy(50+30*pow(2,1/2)*cos(ang)+15*pow(2,1/2)*cos(ang)*6,400-30*pow(2,1/2)*sin(ang)-15*pow(2,1/2)*sin(ang)*6,"3");
  ang=3.14/4.25;
  outtextxy(50+30*pow(2,1/2)*cos(ang)+15*pow(2,1/2)*cos(ang)*6,400-30*pow(2,1/2)*sin(ang)-15*pow(2,1/2)*sin(ang)*6,"4");
  ang=3.14/5.3;
  outtextxy(50+30*pow(2,1/2)*cos(ang)+15*pow(2,1/2)*cos(ang)*6,400-30*pow(2,1/2)*sin(ang)-15*pow(2,1/2)*sin(ang)*6,"5");
   ang=3.14/7.2;
  outtextxy(50+30*pow(2,1/2)*cos(ang)+15*pow(2,1/2)*cos(ang)*6,400-30*pow(2,1/2)*sin(ang)-15*pow(2,1/2)*sin(ang)*6,"6");
  bioskey(0);
  menu();
  }

void balloon()
	{
	 j++;
	 by1=360-spd*j;
	 by2=360-spd*(j+1);
	 setcolor(0);


	 //erase
	setcolor(3); //balloon
	ellipse(bx,by2,0,360,12,20);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(bx,by2,0);
	 setcolor(clr);
	 ellipse(bx,by2,0,360,12,20);
	 setfillstyle(SOLID_FILL,clr);
	 floodfill(bx,by2,clr);

	   setcolor(0); //string erase
	    if(((j-1)*spd)%8==0)
	      {ellipse(bx, by1+29,280,45,6,15);
	       ellipse(bx+4, by1+55,120,250,6,15);}
	    else
	      {setcolor(0);
	       ellipse(bx+2, by1+29,135,250,6,15);
	       ellipse(bx-3, by1+55,280,45,6,15);}


	  //string
	  setcolor(15);
	   if((j*spd)%8==0)
	    {ellipse(bx, by2+29,280,45,6,15);
	     ellipse(bx+4, by2+55,120,250,6,15);}
	   else
	    {ellipse(bx+2, by2+29,135,250,6,15);
	     ellipse(bx-3, by2+55,280,45,6,15);}

	}

void arrow()
	{
	 if(i==0)
	  {
	   bow(1);
	  }
	i++;
	setcolor(0);

	ax11=50+18*pow(2,1/2)*cos(arg)*i;
	ax12=50+30*pow(2,1/2)*cos(arg)+18*pow(2,1/2)*cos(arg)*i;
	ax21=50+18*pow(2,1/2)*cos(arg)*(i+1);
	ax22=50+30*pow(2,1/2)*cos(arg)+18*pow(2,1/2)*cos(arg)*(i+1);
	ay11=400-18*pow(2,1/2)*sin(arg)*i;
	ay12=400-30*pow(2,1/2)*sin(arg)-18*pow(2,1/2)*sin(arg)*i;
	ay21=400-18*pow(2,1/2)*sin(arg)*(i+1);
	ay22=400-30*pow(2,1/2)*sin(arg)-18*pow(2,1/2)*sin(arg)*(i+1);

	line(ax11,ay11,ax12,ay12);
	setcolor(11);
	putpixel(ax11,ay11,11);
	line(ax21,ay21,ax22,ay22);

	if(i==1){attempts++;}
	}

void oparrow()
	{
	i++;
	setcolor(0);

	ax11=50+15*pow(2,1/2)*cos(arg)*i;
	ax12=50+30*pow(2,1/2)*cos(arg)+15*pow(2,1/2)*cos(arg)*i;
	ax21=50+15*pow(2,1/2)*cos(arg)*(i+1);
	ax22=50+30*pow(2,1/2)*cos(arg)+15*pow(2,1/2)*cos(arg)*(i+1);
	ay11=205-15*pow(2,1/2)*sin(arg)*i;
	ay12=205-30*pow(2,1/2)*sin(arg)-15*pow(2,1/2)*sin(arg)*i;
	ay21=205-15*pow(2,1/2)*sin(arg)*(i+1);
	ay22=205-30*pow(2,1/2)*sin(arg)-15*pow(2,1/2)*sin(arg)*(i+1);

	line(ax11,ay11,ax12,ay12);
	setcolor(11);
	putpixel(ax11,ay11,11);
	line(ax21,ay21,ax22,ay22);

	if(i==1){attempts++;}
	}

void transition()
 {
  int i;

  setcolor(15);
  setlinestyle(0, 0, 0);
  setfillstyle(1, 15);
  for (i=0; i<500; i++)
   {
    line (0, 1+i, getmaxx(), 1+i);
    floodfill(1, 1, 15);
    delay(2);
   }

  setcolor(0);
  setlinestyle(0, 0, 0);
  setfillstyle(1, 15);
  for (i=500; i>=0; i--)
   {
    line (0, i-1, getmaxx(), i-1);
    floodfill(1, 1, 0);
    delay(2);
   }
 }

void burst()
 {
  int i;
  float xm=getmaxx(), ym=getmaxy();

  settextstyle(1, 0, 5);
  setcolor(15);
  outtextxy(xm/2-73.5+7.5, ym/2-40-20, "B");
  outtextxy(xm/2-50+7.5, ym/2-40-20, "U");
  outtextxy(xm/2-22+7.5, ym/2-40-20, "R");
  outtextxy(xm/2+5+7.5, ym/2-40-20, "S");
  outtextxy(xm/2+27+7.5, ym/2-40-20, "T");
  delay(1200);
  i=0;
  op_bow();
  for(j=0;j<23;j++)
	{arg=0;
	 oparrow();
	 delay(100);}
	 i=0;
  randomize();


  for (i=0; i<500; i++)
   {
    settextstyle(1, 0, 5);
    setcolor(random(15)+1);
    outtextxy(xm/2-73.5-i, ym/2-40-i, "B");
    setcolor(random(15)+1);
    outtextxy(xm/2-50-i, ym/2-40+i, "U");
    setcolor(random(15)+1);
    outtextxy(xm/2-22, ym/2-40-i, "R");
    setcolor(random(15)+1);
    outtextxy(xm/2+5+i, ym/2-40-i, "S");
    setcolor(random(15)+1);
    outtextxy(xm/2+27+i, ym/2-40+i, "T");
    delay(7.5);
    if (i<499)
     {
      cleardevice();
     }
   }

  settextstyle(1, 0, 2);
  setcolor(11);
  outtextxy(69, 216, "Created by Manan, Kanishk, Sanit and Shreyas");

  delay(2000);
 }

void credits()
 {
  transition();
  randomize();

  for(int i=0; i<2400; i++)
   {
    int x=random(2);
    cout<<x;
   }

  setfillstyle(1,0);
  bar(250-35+15, 50, 450-35-17, 100);
  setcolor(RED);
  settextstyle(1, 0, 5);
  outtextxy(234, 47, "CREDITS");
  setfillstyle(1,0);
  bar(240+50-25, 200-30, 400-50+10, 250-30-20);
  setcolor(YELLOW);
  settextstyle(1, 0, 3);
  outtextxy(270+5, 170, "Manan");
  setfillstyle(1,0);
  bar(240+50-25, 200+30, 400-50+10, 250+20-10);
  setcolor(YELLOW);
  outtextxy(268, 230, "Kanishk");
  setfillstyle(1,0);
  bar(240+50-20, 200+90, 400-50, 250+20+40);
  setcolor(YELLOW);
  outtextxy(276+7.5, 280, "Sanit");
  setfillstyle(1,0);
  bar(222, 200+146, 400-50+48, 250+125);
  setcolor(YELLOW);
  outtextxy(233+40, 200+146, "Shreyas");

 // bioskey(0);
  bioskey(0);
  menu();
 }

void new_game()
	{

	 k=0;
	 hits=0;
	 attempts=0;
	 cleardevice();
	 man();
	 bow(0);
	 setcolor(11);
	 randomize();
	 while(k<7)
		{k++;
	 bx=random(250)+150;
	 spd=random(4)+8;
	 clr=random(14)+1;
	 count=0;
	 for(i=0,j=0;j<(360/spd-1);)
		{
		 balloon();
		 if(count<1)
		 key=bioskey(1);
		 if(key!=0)
			{count++;}
		 switch (key)
		 {
		 case 561:
			arg=(5*3.14)/12;
			arrow();
			break;
		 case 818:
			arg=3.14/3;
			arrow();
			break;
		 case 1075:
			arg=3.14/3.5;
			arrow();
			break;
		 case 1332:
			arg=3.14/4.25;
			arrow();
			break;
		 case 1589:
			arg=3.14/5.3;
			arrow();
			break;
		 case 1846:
			arg=3.14/7.2;
			arrow();
			break;
		 default:
			break;
		 }
		 delay(100);
		if(pow(ax22-bx,2)/144+pow(ay22-by2,2)/400-1<0)
		       {hits++;
			break;}
		}
		 if(key!=0)
		 bioskey(0);
		 delay(10);
		 cleardevice();
		 man();
		 bow(0);

		}
	 cleardevice();
	 if(attempts!=0)
	 accuracy=(hits*100)/attempts;
	 else accuracy=0;
	 hi.add();
	 if(s>last)
	   hi.record();
	 else
	   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tYour score is:"<<s;
	 bioskey(0);
	 cleardevice();
	 menu();
	 }

void menu()
 {
  int i;
  float midx=getmaxx()/2, midy=getmaxy()/2, key;

  transition();

  setcolor(RED);
  settextstyle(10, 0, 8);
  outtextxy(150, 40, "BURST");

  setcolor(15);
  settextstyle(4, 0, 4);
  delay(250);
  outtextxy(midx-88, midy-25, "1.Play");
  delay(250);
  outtextxy(midx-88, midy+25, "2.Leaderboard");
  delay(250);
  outtextxy(midx-88, midy+75, "3.Instructions");
  delay(250);
  outtextxy(midx-88, midy+125, "4.Credits");
  delay(250);
  outtextxy(midx-88, midy+175, "5.Exit Game");

  for (i=0;;i++)
   {
    while (bioskey(1)==0);
    key=bioskey(0);
    if (key==one)
     {
      new_game();
     }
    else if (key==two)
     {
      hi.record();
     }
    else if (key==three)
     {
      instructions();
     }
    else if (key==four)
     {
      credits();
     }
    else if (key==five||key==esc)
     {
      closegraph();
      exit(0);
     }
   }
 }


/*****************************************************************************
				    Main
*****************************************************************************/

void main()
 {
  graphinit();
  burst();
  menu();
  bioskey(0);
  cleardevice();
 }















