#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>


int main() {
	clrscr();
	int gd=DETECT,gm;
	int arr[84][4]={0},l=0,i;
	int topb=399,t1,t2,t3;
	int k=4,areab,areaball,left=290,top=410,temp=0,te=0,scr=0;
	float n,up,down,leftb=315;

	char c,sc[20];
	void *p,*pb;

	initgraph(&gd,&gm,"C:\\tc\\bgi");
	int font=10,font1=4;


	setbkcolor(WHITE);
	setcolor(BLUE);

	for(i=0 ;i<=100 ;i++) {
	   settextstyle(font,HORIZ_DIR,6);
	   outtextxy(200,i,"DX-Ball");
	   delay(30);

	   if(i!=100)
	   cleardevice();
	}

	delay(1000);

	setcolor(RED);
	settextstyle(font1,HORIZ_DIR,5);
	outtextxy(260,250,"The Game");

	getch();

	cleardevice();

	setcolor(GREEN);


	outtextxy(30,200,"Press any key to Start the Game");

	getch();
	cleardevice();



	setbkcolor(BLACK);
	rectangle(1,1,638,418);

	for(int j=2;j<getmaxy()/6;j+=30) {//bricks
         for(int i=2;i<getmaxx()-10;i+=30) {
              bar(i+k,j+k,i+30,j+30);
              arr[l][0]=i+k;
              arr[l][1]=j+k;
              arr[l][2]=i+30;
              arr[l][3]=j+30;
              l++;
         }
	}


	setcolor(RED);
	settextstyle(font1,HORIZ_DIR,4);
	outtextxy(10,425,"Score:");

	//itoa(scr,sc,10);
	//outtextxy(100,425,sc);

	setcolor(WHITE);
	rectangle(290,410,350,417);
	setfillstyle(1,WHITE);
	floodfill(306,412,WHITE);

	setcolor(BROWN);
	circle(320,404,5);
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(318,407,BROWN);

	areab=imagesize(left,top,left+60,top+7);
	p=malloc(areab);

	areaball=imagesize(leftb,topb,leftb+10,topb+10);
	pb=malloc(areaball);

	getch();

	while(1) //move
	{
	  n=(left+left+60)/2;

	  if((leftb>=n)&&(leftb<=n+10))
	  up=0.2;
	  else if((leftb>=n+10)&&(leftb<=n+20))
	  up=0.4;
	  else if((leftb>=n+20)&&(leftb<=n+30))
	  up=0.6;
	  else if((leftb>=n+30)&&(leftb<=n+40))
	  up=0.8;
	  else
	  up=0;

	  if((leftb+10>=n-10)&&(leftb+10<=n))
	  down=0.2;
	  else if((leftb+10>=n-20)&&(leftb+10<=n-10))
	  down=0.4;
	  else if((leftb+10>=n-30)&&(leftb+10<=n-20))
	  down=0.6;
	  else if((leftb+10>=n-40)&&(leftb+10<=n-30))
	  down=0.8;
	  else
	  down=0;


	  while(1)//up
	  {
	   temp=te=0;



	   for(i=0;i<65;i++) //up down
	   {
	     t1=(leftb+leftb+10)/2;

	     if((arr[i][3]==topb-2)&&(((t1>=arr[i][0]-2)&&(t1<=arr[i][2]+2))||((t1-5>=arr[i][0]-2)&&(t1-5<=arr[i][2]+2))||((t1+5>=arr[i][0]-2)&&(t1+5<=arr[i][2]+2)))||(topb==2))//||((leftb+10>=arr[i][0])&&(leftb+10<=arr[i][2])))//lef)//||((leftb+10==arr[i][0])&&(topb>=arr[i][1])&&(topb<=arr[i][3]))||(topb==2))
	     {
	       if(topb!=2)
	       {
		 setcolor(BLACK);
		 rectangle(arr[i][0],arr[i][1],arr[i][2],arr[i][3]);
		 setfillstyle(1,BLACK);
		 floodfill(arr[i][0]+1,arr[i][1]+1,BLACK);

		 itoa(scr,sc,10);
		 outtextxy(100,425,sc);

		 setcolor(RED);
		 scr=scr+5;
		 itoa(scr,sc,10);
		 outtextxy(100,425,sc);

		 for(int m=i;m<65;m++)
		 {
		   arr[m][0]=arr[m+1][0];
		   arr[m][1]=arr[m+1][1];
		   arr[m][2]=arr[m+1][2];
		   arr[m][3]=arr[m+1][3];
		 }
	       }
	     break;
	    }
	   }

	   if(i<65)
	   break;

	   else
	   {
	     if(leftb+10>=635)
	     {
	       down=up;
	       up=0;
	     }

	     else if(leftb<=5)
	     {
	       up=down;
	       down=0;
	     }

	     delay(10);

	     getimage(leftb,topb,leftb+10,topb+10,pb);
	     putimage(leftb,topb,pb,XOR_PUT);
	     putimage(leftb=leftb+up-down,--topb,pb,XOR_PUT);

	     if(kbhit())
	     {
	       c=getch();

	       if(c==77)
	       {
		 if(left+60>=635);

		 else
		 {
		   temp=temp+5;
		   getimage(left,top,left+60,top+7,p);
		   putimage(left,top,p,XOR_PUT);
		   putimage(left+temp,top,p,XOR_PUT);
		   left=left+temp;
		 }
	       }

	       else if(c==75)
	       {
		 if(left<=5);

		 else
		 {
		   te=te+5;
		   getimage(left,top,left+60,top+7,p);
		   putimage(left,top,p,XOR_PUT);
		   putimage(left-te,top,p,XOR_PUT);
		   left=left-te;
		 }
	       }

	       else  if(c==97)
	       break;
	     }
	    }
	   }

	   while(1)//down
	   {
	     temp=te=0;

	     if(top==topb+11)//&&((leftb>=left)||(leftb+10<=left+30)))
	     break;

	     if(leftb<=5)
	     {
	       up=down;
	       down=0;
	     }

	     else if(leftb+10>=635)
	     {
	       down=up;
	       up=0;
	     }


	     delay(10);

	     getimage(leftb,topb,leftb+10,topb+10,pb);
	     putimage(leftb,topb,pb,XOR_PUT);
	     putimage(leftb=leftb+up-down,++topb,pb,XOR_PUT);

	    if(kbhit())
	    {
	      c=getch();
	      if(c==77)
	      {
	       if(left+60>=635);
	       else
	       {
		  temp=temp+5;
		  getimage(left,top,left+60,top+7,p);
		  putimage(left,top,p,XOR_PUT);
		  putimage(left+temp,top,p,XOR_PUT);
		  left=left+temp;
	       }
	      }
	      else if(c==75)
	      {
	       if(left<=5);
	       else
	       {
		  te=te+5;
		  getimage(left,top,left+60,top+7,p);
		  putimage(left,top,p,XOR_PUT);
		  putimage(left-te,top,p,XOR_PUT);
		  left=left-te;
	       }
	      }
	      else  if(c==97)
	      break;

	   }
	  }
	  if(((leftb<left-5)||(leftb+10>left+65))||(scr==315))
	  break;
	}

	cleardevice();
	delay(100);

	if(scr==315)
	{
	  setcolor(RED);
	  settextstyle(font1,HORIZ_DIR,5);
	  outtextxy(70,125,"Congratulation you have just");
	  outtextxy(70,180,"finished the game successfully");
	}

	else
	{
	  setcolor(RED);
	  settextstyle(font,HORIZ_DIR,6);
	  outtextxy(125,125,"Game Over");
	  getch();

	  cleardevice();
	  settextstyle(font1,HORIZ_DIR,5);
	  outtextxy(250,200,"Score:");
	  itoa(scr,sc,10);
	  outtextxy(370,200,sc);
	}
	getch();
	closegraph();
	return 0;
}
