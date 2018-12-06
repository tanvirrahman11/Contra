 /*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"

int bird_x, bird_y;
int t;

int score = 0;
int highscore = 0;

bool isPaused=false;

int level =1;
 
int dx1=750,dy1=300,dy=0;
int dx2=dx1+200,dy2=270;
int dx3=dx2+200,dy3=340;
int dx4=dx3+200,dy4=290;
int x1=100,x2=130,x3=60,x4=110;
int h1=150,h2=125,h3=200,h4=145;
  
char  str[10];
char str1[10];

char str2[10];
char str3[10];

int g=0;
 

int menu =0;

int life = 3;

/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	

 	iClear();
	iShowBMP(0,0,"menu.bmp");
	if((menu==1) && !(life ==0)){

		iShowBMP(0,0,"back.bmp");
	iShowBMP(bird_x, bird_y, "bird.bmp");
	
	
 
	iSetColor(156,26,234);
	iFilledRectangle(dx1,dy1,32,x1);
	iFilledRectangle(dx1,dy,32,h1);

	iFilledRectangle(dx2,dy2,32,x2);
	iFilledRectangle(dx2,dy,32,h2);

	iFilledRectangle(dx3,dy3,32,x3);
	iFilledRectangle(dx3,dy,32,h3);

	iFilledRectangle(dx4,dy4,32,x4);
	iFilledRectangle(dx4,dy,32,h4);

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
	
	{	iShowBMP(0,0,"game.bmp");
	
	iPauseTimer(t);
	}
	
	if((life>0) && (level>2))
	{iClear();

	iSetColor(12,243,168);
	//sprintf(str4,"life: %d",life);
	iText(200, 335, "YOU WIN !!!" , GLUT_BITMAP_TIMES_ROMAN_24 );
	

	sprintf(str,"Score: %d",score);
	iText(650, 350, str, GLUT_BITMAP_TIMES_ROMAN_24 );
	
	sprintf(str1,"High Score: %d",highscore);
	iText(650, 380, str1, GLUT_BITMAP_TIMES_ROMAN_24 );

	iPauseTimer(t);
	}


}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
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
     if((!isPaused) && (bird_y<400-35))
	
		 bird_y = bird_y+18;	
	}
	 
	if(key == GLUT_KEY_DOWN)
	{
		
	//place your codes for other keys here

	}
}

 
	

void movebird(){
		bird_y = bird_y-2;
	if(bird_x==100 && bird_y==0){
		life--,
		bird_x=200,bird_y=350;
		//if(life==2||life==1){bird_x=100,bird_y=200;}
	}
	
	dx1--;
	dx2--;
	dx3--;
	dx4--;

	if(dx4==bird_x)
		{level=level+1;
	}

	
	if(dx1<=0){dx1 =800;dy1=dy1-20,x1=400-dy1;}
	
	if(dx2<=0){dx2 =800;dy2=dy2-10,h2=h2+10,x2=400-dy2;} ///aro hisab korte hobe............


	if(dx3<=0){dx3 =800;dy3=dy3-15,x3=400-dy3;}
	
	if(dx4<=0){dx4 =800;dy4=dy4-20,h4=h4+15,x4=400-dy4;}
 
		
	
	if((dx1==bird_x)|| (dx2==bird_x)|| (dx3 == bird_x) || (dx4 == bird_x)){        //score...
		score = score + 5;


		if((bird_x>= dx1) && ( bird_x<=dx1+32) && !(bird_y <= h1 || bird_y>=300-32)) 
		{
		
			}
	
	else if((bird_x>= dx2) && ( bird_x<=dx2+32) && !(bird_y <= h2 || bird_y>=270-32)) 
		{
		
			}

	else if((bird_x>= dx3) && ( bird_x<=dx3+32) && !(bird_y <= h3 || bird_y>=340-32))
	{
			}
	
		else if((bird_x>= dx4) && ( bird_x<=dx4+32) && !(bird_y <=h4  || bird_y>=290-32))
	{
			}

	else {
		
		life--, 
			level = 1,

	bird_x=200, bird_y=350,
	dx1=750,dy1=300,dy=0,
	dx2=dx1+200,dy2=270,
	dx3=dx2+200,dy3=340,
	dx4=dx3+200,dy4=290,
	x1=100,x2=130,x3=60,x4=110;
 
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
	
	iSetTimer(15, movebird);
		
 //iSetTimer(18, movebird);
 
 bird_x=200, bird_y=350;
 int dx1=750,dy1=300,dy=0;
int dx2=dx1+200,dy2=270;
int dx3=dx2+200,dy3=340;
int dx4=dx3+200,dy4=290;
int x1=100,x2=130,x3=60,x4=110;
int h1=150,h2=125,h3=200,h4=145;
	//iSetTimer(30, move);
	
	iInitialize(800, 400," Flappy  Bird ");
	return 0;
}	
	
