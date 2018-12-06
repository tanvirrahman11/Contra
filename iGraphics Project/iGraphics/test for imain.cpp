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

int dy1,dy2,dy3,dy4; 
int dx1=750;
int dx2=dx1+200;
int dx3=dx2+200;
int dx4=dx3+200;

int dy =0;

//int x1=100,x2=130,x3=60,x4=110;
//int h1=150,h2=125,h3=200,h4=145;

   
char  str[10];
char str1[10];

char str2[10];
char str3[10];


int g=0;
 

int menu =0;

int life = 3;
 
int pil[10];
 
 
void random(){
    
	int i;
    time_t t;
    //n=5;
    srand((unsigned)time(&t));

    printf("random numbers of the pillar \n");
	
	for(i=0;i<=3;i++){
    
		pil[i]  = rand()%70+100;
			printf("%d\n", pil[i]);
    }
} 

void intial(){dy1 = pil[0] +150;	
 	dy2=pil[1]+145;
	dy3=pil[2]+145;
	dy4=pil[3]+150;
 
int dx1=750;		//dy1=pil[0]+150,		dy=0;
int dx2=dx1+200;
int dx3=dx2+200;
int dx4=dx3+200;}

void iDraw()

{
	//place your drawing codes here	

	iClear();
	iShowBMP(0,0,"menu.bmp");
	if((menu==1) && !(life ==0)){


		iShowBMP(0,0,"back.bmp");
	iShowBMP(bird_x, bird_y, "bird.bmp");
	
	
 
	iSetColor(106,16,134);


//	iFilledRectangle(dx1,dy1,32,400-dy1);	 
	iFilledRectangle(dx1,dy,32,pil[0]);
	iFilledRectangle(dx1,dy1,32,400-dy1);	 

//	iFilledRectangle(dx2,dy2,32,400-dy2);         ///dx,x
	iFilledRectangle(dx2,dy,32,pil[1]);          ///dx,h 
	iFilledRectangle(dx2,dy2,32,400-dy2);  

	//iFilledRectangle(dx3,dy3,32,400-dy3);
	iFilledRectangle(dx3,dy,32,pil[2]);
	iFilledRectangle(dx3,dy3,32,400-dy3);

	//iFilledRectangle(dx4,dy4,32,400-dy4);
	iFilledRectangle(dx4,dy,32,pil[3]);
	iFilledRectangle(dx4,dy4,32,400-dy4);
	
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
	
	iPauseTimer(t);}
	
	if((life>0) && (level>2))
	
	{iClear();

	iSetColor(12,243,168);
	//sprintf(str4,"life: %d",life);
	iText(200, 335,"you Win" , GLUT_BITMAP_TIMES_ROMAN_24 );
	

	sprintf(str,"Score: %d",score);
	iText(650, 350, str, GLUT_BITMAP_TIMES_ROMAN_24 );
	
	sprintf(str1,"High Score: %d",highscore);
	iText(650, 380, str1, GLUT_BITMAP_TIMES_ROMAN_24 );
	
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

		if(bird_x==200 && bird_y==0){
		life--,
		
			bird_x=200,bird_y=350;
		//if(life==2||life==1){bird_x=100,bird_y=200;}
		}
	
	dx1--;
	dx2--;
	dx3--;
	dx4--;

	if(dx4+32==00)
		{level=level+1;
	}

	
/*	if(dx1<=0){dx1 =800;dy1=dy1-20;}
	
	if(dx2<=0){dx2 =800;dy2=dy2-10,pil[1]=pil[1]+10;} ///aro hisab korte hobe............


	if(dx3<=0){dx3 =800;dy3=dy3-15;}
	
	if(dx4<=0){dx4 =800;dy4=dy4-20,pil[3]=pil[3]+15;}
 */
		
	
	if((dx1==bird_x)|| (dx2==bird_x)|| (dx3 == bird_x) || (dx4 == bird_x)){        //score...
		score = score + 5;

	
		if((bird_x>= dx1) && ( bird_x<=dx1+32)  && !(bird_y <= pil[0] || bird_y>=dy1-32)) 
		{
		
			}
	
	else if((bird_x>= dx2) && ( bird_x<=dx2+32) && !(bird_y <= pil[1] || bird_y>=dy2-32)) 
		{
		
			}

	else if((bird_x>= dx3) && ( bird_x<=dx3+32) && !(bird_y <= pil[2] || bird_y>=dy3-32))
	{
			}
	
		else if((bird_x>= dx4) && ( bird_x<=dx4+32) && !(bird_y <= pil[3]  || bird_y>=dy4-32))
	{
			}

	else {
		
		life--, 
			level = 1,

 
 bird_x=200, bird_y=350,

 random(),
 dx1=750,		dy1=pil[0]+150,		dy=0,
 dx2=dx1+200,	dy2=pil[1]+145,
 dx3=dx2+200,	dy3=pil[2]+145,
 dx4=dx3+200,	dy4=pil[3]+150;

	}
				
	}
		}

 
	}

	void movebird2(){
		if((menu==1)&& (level==2)){

 	 

			bird_y = bird_y-2;

		if(bird_x==200 && bird_y==0){
		life--,
		
			bird_x=200,bird_y=350;
		//if(life==2||life==1){bird_x=100,bird_y=200;}
		}
	
	dx1--;
	dx2--;
	dx3--;
	dx4--;

	if(dx4+32==bird_x)
		{level=level+1;
	}

	
/* if(dx1<=0){dx1 =800;dy1=dy1-20;}
	
	if(dx2<=0){dx2 =800+200;dy2=dy2-10,pil[1]=pil[1]+10;} ///aro hisab korte hobe............


	if(dx3<=0){dx3 =800+400;dy3=dy3-15;}
	
	if(dx4<=0){dx4 =800+600;dy4=dy4-20,pil[3]=pil[3]+15;}
*/

		
	
	if((dx1==bird_x)|| (dx2==bird_x)|| (dx3 == bird_x) || (dx4 == bird_x)){        //score...
		score = score + 5;

	
		if((bird_x>= dx1) && ( bird_x<=dx1+32)  && !(bird_y <= pil[0] || bird_y>=dy1-32)) 
		{
		
			}
	
	else if((bird_x>= dx2) && ( bird_x<=dx2+32) && !(bird_y <= pil[1] || bird_y>=dy2-32)) 
		{
		
			}

	else if((bird_x>= dx3) && ( bird_x<=dx3+32) && !(bird_y <= pil[2] || bird_y>=dy3-32))
	{
			}
	
		else if((bird_x>= dx4) && ( bird_x<=dx4+32) && !(bird_y <= pil[3]  || bird_y>=dy4-32))
	{
			}

	else {
		
		life--, 
			level = 2,

 
 bird_x=200, bird_y=350,

 random(),
 dx1=750,		dy1=pil[0]+150,		dy=0,
 dx2=dx1+200,	dy2=pil[1]+145,
 dx3=dx2+200,	dy3=pil[2]+145,
 dx4=dx3+200,	dy4=pil[3]+150;

	}
				
	}
		}

 
	}
int main()

{
	//place your own initialization codes here. 
	

 bird_x=200, bird_y=350;

 	//random();

 iSetTimer(15, movebird);
iSetTimer(12,movebird2); 

 random();
 
//	PlaySound("song",NULL,SND_ASYNC);		
	
 //bird_x=200, bird_y=350;
	dy1 = pil[0] +150;	
 	dy2=pil[1]+145;
	dy3=pil[2]+145;
	dy4=pil[3]+150;
 
//int dx1=750;		//dy1=pil[0]+150,		dy=0;
//int dx2=dx1+200;
//int dx3=dx2+200;
//int dx4=dx3+200;
 
  
	//random();
	

	iInitialize(800, 400," Flappy  Bird ");
	 
	return 0;
}
