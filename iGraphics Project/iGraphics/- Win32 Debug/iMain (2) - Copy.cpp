 /*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/

#include "iGraphics.h"

int bird_x, bird_y;
int t;
bool g;
int score = 0;
int highscore = 0;

bool isPaused=false;

int level = 1;

int dy1,dy2,dy3,dy4,dy5; 

int dx1 =   	750;
int dx2 =	dx1+150;
int dx3=	dx2+150;
int dx4 =	dx3+150;
int dx5 =	dx4+150;

int dy =0;

   
char  str[10];
char str1[10];

char str2[10];
char str3[10];

int menu =0;

int life = 3;
 
int again = 01;

int pil[5];
 

void random(){
    
	int i;
    time_t t;
    //n=5;
    srand((unsigned)time(&t));

    printf("random numbers of the pillar \n");
	
	for(i=0;i<=4;i++){
    
		pil[i]  = rand()%70+100;
			printf("%d\n", pil[i]);
    }
} 



void song(){
	PlaySound("gameover",NULL,SND_ASYNC);		
	} 


void iDraw()

{
	//place your drawing codes here	
	if(again ==1){

		iClear();
	iShowBMP(0,0,"StartMenu.bmp");
	
	iSetColor(10,32,107);

	sprintf(str1,"  : %d",highscore);

	iText(570, 245, str1, GLUT_BITMAP_TIMES_ROMAN_24 );}

	if((menu==1) && !(life ==0)){


	iShowBMP(0,0,"Background3.bmp");

	iShowBMP(bird_x, bird_y, "bird.bmp");
 
	iSetColor(190,45,238);

	
	iFilledRectangle(dx1,dy,32,pil[0]);
	iFilledRectangle(dx1,dy1,32,400-dy1);	 

	iFilledRectangle(dx2,dy,32,pil[1]);   
	iFilledRectangle(dx2,dy2,32,400-dy2);  

	iFilledRectangle(dx3,dy,32,pil[2]);
	iFilledRectangle(dx3,dy3,32,400-dy3);


	iFilledRectangle(dx4,dy,32,pil[3]);
	iFilledRectangle(dx4,dy4,32,400-dy4);
	

	iFilledRectangle(dx5,dy,32,pil[4]);
	iFilledRectangle(dx5,dy5,32,400-dy5);

	iSetColor(90,00,60);
 

	sprintf(str,"Score: %d",score);
	iText(650, 350, str, GLUT_BITMAP_TIMES_ROMAN_24 );
	
	sprintf(str1,"High Score: %d",highscore);
	iText(650, 380, str1, GLUT_BITMAP_TIMES_ROMAN_24 );

	sprintf(str2,"level: %d",level);
	iText(20, 370, str2, GLUT_BITMAP_TIMES_ROMAN_24 );
	
	
	sprintf(str3,"life: %d",life);
	iText(20, 335, str3, GLUT_BITMAP_TIMES_ROMAN_24 );

	}
	
	if(life==0)  
	
	{	iShowBMP(0,0,"GameOver.bmp");
	
	
	sprintf(str,"Score: %d",score);
	sprintf(str1,"High Score: %d",highscore);
	iText(550, 310, str1, GLUT_BITMAP_TIMES_ROMAN_24 );

	iPauseTimer(t);
	iText(550, 280, str, GLUT_BITMAP_TIMES_ROMAN_24 );
	
	}
	
	if((life>0) && (level>3))
	
	{
		iClear();

	iSetColor(87,99,242);
	
	iText(150, 235," You Win  !!!" , GLUT_BITMAP_TIMES_ROMAN_24 );
	

	sprintf(str,"Score: %d",score);
	iText(450, 290, str, GLUT_BITMAP_TIMES_ROMAN_24 );
	
	sprintf(str1,"High Score: %d",highscore);
	iText(450, 320, str1, GLUT_BITMAP_TIMES_ROMAN_24 );
	
	iPauseTimer(t);
	
	}
}


void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/


/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		/*if(mx >= 50 && mx <= 300 && my >= 250 && my <= 280 && mode == 0)
		{
			mode = 1;
		}*/
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}	
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/

void iKeyboard(unsigned char key)
{
	if(key == 'x')
	{
		//do something with 'x'
		//exit(0);
	}

	 
	if(key == 'p'){

		iPauseTimer(t);
		
		isPaused=true;
	}


	if(key == 'r'){
		iResumeTimer(t);
		
		isPaused=false;
	}

	
	if(key == 's'){
		menu =1;}
	
	
	if(life==0){
		if(key == 'a'){
			again = 1,
			life =3,
			level =1,
			bird_x=200, bird_y=350,

 random(),
  
  dx1 =	   750,	  dy1=pil[0]+150,		dy=0,
  dx2 =dx1+150,	  dy2=pil[1]+145,
  dx3 =dx2+150,   dy3=pil[2]+145,
  dx4 =dx3+150,	  dy4=pil[3]+150,
  dx5 =dx4+150,	  dy5=pil[4]+145,
			
			score =0,
		iResumeTimer(t);
		
	}
		}
	
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	
	if(key == GLUT_KEY_UP)
	{
     if((!isPaused) && (bird_y<400-32))
	
		 bird_y = bird_y+15;	
	}

	if(key == GLUT_KEY_DOWN)
	{
		
	}
		}



	//place your codes for other keys here


	void movebird(){
		if(menu==1){
			bird_y = bird_y-2;

		if(bird_y==0){
	
		life--, 

 
 bird_x=200, bird_y=350,

 random(),
  dy  = 0,
  dx1 = 750,				
  dx2 = dx1+150,	
  dx3 = dx2+150,	
  dx4 = dx3+150,	
  dx5 = dx4+150;	


	if(level ==1){
 dy1=pil[0]+150,		
 dy2=pil[1]+150,
 dy3=pil[2]+145,
 dy4=pil[3]+150,
 dy5=pil[4]+145;}

	if(level ==2){
 dy1=pil[0]+125,		
 dy2=pil[1]+120,
 dy3=pil[2]+115,
 dy4=pil[3]+120,
 dy5=pil[4]+105;}
		

	if(level ==3){
 dy1=pil[0]+100,		
 dy2=pil[1]+95,
 dy3=pil[2]+90,
 dy4=pil[3]+95,
 dy5=pil[4]+90;
		}
	}
		
	dx1=dx1-2;
	dx2=dx2-2;
	dx3=dx3-2;
	dx4=dx4-2; 
	dx5=dx5-2;
	 
	
		if(dx5+32==bird_x)
		{
			level=level+1;
	}

		

	//if(dx1<=0){dx1 =800,dy1=dy1-30;}
	if(dx1<=0){dx1 =800,    dy1=dy1-20, pil[0]=pil[0]+10;}
	
	if(dx2<=0){dx2 =dx1+150,dy2=dy2-20, pil[1]=pil[1]+10;} 


	//if(dx3<=0){dx3 =dx2+150,dy3=dy3-25;}
	if(dx3<=0){dx3 =dx2+150, dy3=dy3-15, pil[2]=pil[2]+15;}

	if(dx4<=0){dx4 =dx3+150, dy4=dy4-15, pil[3]=pil[3]+15;}
			
	if(dx5<=0){dx5 =dx4+150, dy5=dy5-15, pil[4]=pil[4]+15;}
	
	//if(dx5<=0){dx5 =dx4+150, dy5=dy4-20;}
		


	if((dx1==bird_x)|| (dx2==bird_x)|| (dx3 == bird_x) || (dx4 == bird_x)||(dx5 == bird_x)){        //score...
		score = score + 5;

	
		if((bird_x>= dx1) && ( bird_x<=dx1+32)  && !((bird_y <= pil[0]) || (bird_y>=dy1-32))) 
		{
		g=true;
			}
	
	else if((bird_x>= dx2) && ( bird_x<=dx2+32) && !(bird_y <= pil[1] || bird_y>=dy2-32)) 
		{
		g=true;
			}

	else if((bird_x>= dx3) && ( bird_x<=dx3+32) && !(bird_y <= pil[2] || bird_y>=dy3-32))
	{
			g=true;
	}
	
		else if((bird_x>= dx4) && ( bird_x<=dx4+32) && !(bird_y <= pil[3]  || bird_y>=dy4-32))
	{
		g=true;
		
		}

		else if((bird_x>= dx5) && ( bird_x<=dx5+32) && !(bird_y <= pil[4]  || bird_y>=dy5-32))
	{
		g=true;
	
		}


	else {
		g=false,
		life--, 

 
 bird_x=200, bird_y=350,

 random(),
 
 dy=0,
  dx1 =750,		 		
  dx2 =dx1+150,	
  dx3 =dx2+150,	
  dx4 =dx3+150,	
  dx5 =dx4+150;	


	if(level ==1){
 dy1=pil[0]+150,		
 dy2=pil[1]+150,
 dy3=pil[2]+145,
 dy4=pil[3]+150,
 dy5=pil[4]+145;}


	if(level ==2){
 dy1=pil[0]+125,		
 dy2=pil[1]+120,
 dy3=pil[2]+115,
 dy4=pil[3]+120,
 dy5=pil[4]+105;}
		

	if(level ==3){
 dy1=pil[0]+100;	
 dy2=pil[1]+95;
 dy3=pil[2]+90;
 dy4=pil[3]+95;
 dy5=pil[4]+90;
		}
	}
				
	}
		}
	
		FILE *f;
	f=fopen("highscore.txt", "r");
	fscanf(f, "%d",&highscore);
	//printf("%d",highScore);
	//highScore=0;
	if (score>highscore)
		highscore=score;
	FILE *fp;
	fp=fopen("highscore.txt", "w+");
	fprintf(fp, "%d",highscore);
	
	fclose(f);
	fclose(fp);
	
}
 
		
int main()

{
	//place your own initialization codes here. 
	

 bird_x=200, bird_y=350;


 iSetTimer(5, movebird);
 
 random();
 
	//PlaySound("gameover",NULL,SND_ASYNC);		
	
 song();

	dy1 = pil[0] +150;	
 	dy2 = pil[1]+145;
	dy3 = pil[2]+145;
	dy4 = pil[3]+150;
	dy5 = pil[4]+145;


	int dx1=    750;	

	int dx2=dx1+150;

	int dx3=dx2+150;

	int dx4=dx3+150;

	int dx5=dx4+150; 
	

	iInitialize(800, 400," Flappy  Bird ");
	 
	return 0;
}