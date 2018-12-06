#include "iGraphics.h"
#include "bitmap_loader.h"
#include<stdlib.h>
#include<time.h>

#define screenWidth 1366
#define screenHight 768
#define konENEMYNUMBER 3

void scoreUPDATE();
void score();
int x = 300, y = 300, r = 20;
int win_b = 400, win_l = 400;
float delay = 0;
int speed = 0,i=0,j,l;
int mnx=0,mny=0;//menu
int bcX=0,bcY=0,bcX2=1360,picX3=0,picY3=25;//background
int gmox=0,gmoy=0;//game over
int istx=0,isty=0;//instruction;
int lvx=0,lvy=0;//level
int enemy_x=1366, enemy_y=0;
int  XCord=picX3;
 int YCord=-10;
 int bulletTimer = 0;
  int bulletCount = 0;
  int bossX=1366, bossY=0;
  int blx=5;
  int scoreSys=0;
  void levelCR();
  void bulletEnemyFire();
	double scX=0,scY=768;
	int currentScore=0;
  double bombwidth=30;
  double bombheight=100;
  double bombstartpoint;
  double xb=picX3+bombwidth,yb=bombheight;
  bool key2pressed=false;
  void bulletEnemy();
void Score();
void imove();
void iReset();
void enemyMovement();
void enemykill();
void bomb();
void calculation();
char key1,key2;
bool enemyshow;
bool hasShot;
bool blshow;
char buffer[5];
double current_Time,Start_Time;
int t1,t2;
char key3;
void level_change();
void enemykillBomb();
void Score_Reset();
bool key3pressed=false;
void enemyCollision();
void boss();
int tm=1,ts=60;//minute,sec
/*
 function iDraw() is called again and again by the system.

 */
void instruction(){
	if(key3=='i'&&key3pressed==true)
	iShowBMP(istx, isty, "INStruction.bmp");
}
struct Bullet 
{
	int x,y;
	bool hasShot;             // controls if bullet is visible or not
}bullet[100];

void drawRoadLines(int offset)
{
	int len = 10;
	int width = 5;
	int gap = 10;
	int midx = 0, midy = win_l / 2;
	for (int i = 0; i < win_b / (len + gap); i++)
		iFilledRectangle((i * (len + gap) + offset) % win_b, midy, len, width);
}
int k = 0;
int level=1;
char bc[6][20]= {"bc1.bmp","bc11.bmp","bc2.bmp","bc22.bmp","bc3.bmp","bc33.bmp"};
int bcInDex1=0,bcInDex2=1;
char army[7][35] = { "enemy1.bmp", "enemy2.bmp" , "enemy3.bmp","enemy4.bmp", "enemy5.bmp","enemy6.bmp","enemy7.bmp"};
int armyIndex=0;
char pakistan_army[20];
bool showImage=true;
void iDraw()
{
	//place your drawing codes here
	iClear();

	if(key1!='s'){
	iText(50,730,"Press s for play",GLUT_BITMAP_TIMES_ROMAN_24);

	if(showImage==true){
		iShowBMP(mnx, mny, "mainmenu.bmp");
	}

	}
	if(key1=='s'){

	showImage=false;
	//level_change();

	iText(50,730,"Press i for instruction",GLUT_BITMAP_TIMES_ROMAN_24);

	levelCR();

	iShowBMP2(picX3, picY3, "characters.bmp",3877675);
	for(int i = 0; i < bulletCount ; i++)
		if(bullet[i].hasShot == true)
			iShowBMP(bullet[i].x,bullet[i].y,"bullet2.bmp");
	//iShowBMP(XCord,YCord,"characters.bmp");
	bulletEnemy();
	enemyMovement();

	enemykill();

	//enemyCollision();

	printf("Score %d",scoreSys);

	current_Time =clock();

	int timeElapsed =(current_Time - Start_Time)/CLOCKS_PER_SEC;
	char str[20];
	t1=tm-(timeElapsed/60);
	t2=ts-(timeElapsed%60);
	//sprintf(str,"%d:%d",(1-(timeElapsed/60)),(60-(timeElapsed%60)));
	//if(t1!=0&&t2!=0){
	//do{
	if(t1==0&&t2==1){
		level_change();
	}
	else if(t1==0&&t2<=1){
		level_change();
		//exit(0);
	}
	else{
	sprintf(str,"%d:%d",t1,t2);
	}
	//}while(t1==0&&t2==1);}

	iText(50,600,str);
	iSetColor(255,255,255);
	if(key3pressed==true){
		instruction();
	}
	level_change();
	}
	score();
	
	

	
		
		
		
	if(key2=='e' && key2pressed==true)
	{bomb();
	}
	if(key2=='e'&& key2pressed==true){
	enemykillBomb();
	}
	printf("%d\n",key2pressed);
	boss();
}
void imove(){
	
	bcX-=20;
	bcX2-=20;
	//iReset();
}
void iReset(){
	if(bcX2==0){
		bcX=1360;
		return;
		}
	else if(bcX==0){
		bcX2=1360;
		return;
		}
}
void levelCR(){
	if(level==1){
	iShowBMPAlternative(bcX, bcY, bc[bcInDex2]);

	iShowBMPAlternative(bcX2, bcY, bc[bcInDex1]);
	}
	else{
	iShowBMPAlternative(bcX, bcY, bc[bcInDex2]);

	iShowBMPAlternative(bcX2, bcY, bc[bcInDex1]);
	}
	imove();
	iReset();
}
void level_change(){
	if(currentScore>=100){
		level++;
		if(level=2){
		iShowBMP(lvx,lvy,"lv2.bmp");
		bcInDex1+=2;
		bcInDex2+=2;
		Score_Reset();}
		else if(level=3){
			iShowBMP(lvx,lvy,"lv3.bmp");
			bcInDex1+=2;
			bcInDex2+=2;
			Score_Reset();}
		else if(level>=3)
			exit(0);
	}
	else if(currentScore<=100&&(t1==0&&t2<=1)){
		iShowBMP(gmox,gmoy,"Game Over.bmp");
		exit(0);
	}
}
void Score_Reset(){
	if(level++){
		currentScore=0;
	}
}
void Time_Reset(){
	if(level++){
		tm=1;
		ts=60;
	}
}
void BulletShot(){  // Called from isettimer
	for(int i = 0 ; i < bulletCount ; i++)
	{
		if(bullet[i].hasShot)
			bullet[i].x += 160;

		if(bullet[i].x > 1366)
			bullet[i].hasShot = false;
		
	   if(picX3==x++)
		   bullet[i].x=x++;

}
}
char Score1[5];
void score(){
	iSetColor(255,150,98);
	iText(1200,730,"Current Score:",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(120,250,98);
	iText(1300,710,Score1,GLUT_BITMAP_TIMES_ROMAN_24);

}

void scoreUPDATE(){
	currentScore+=5;
	sprintf(Score1,"%d",currentScore);
}

void bomb(){
	iSetColor(255,0,0);
	iFilledCircle(xb,yb,10);
	printf("%lf %lf %d in bomb\n",xb,yb,key2pressed);
	//jump:
	calculation();
	xb+=50;
	if( yb<0.00)
	{ key2pressed=false;
	xb=picX3+bombwidth;
	yb=bombheight;
	 }

	//if(xb<100)
		//goto jump;
	
}
void calculation(){
	double txb=xb-bombstartpoint;
	yb=((-((txb-125)*(txb-125)))/(4*78.125))+250;
}

/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */


struct ENEMY
{
	int enemy_x;
	int enemy_y;
	int enemyIndex;
	bool enemyShow;
	bool enemyBombShow;
	int bullet_x,bullet_y;
}pakistani_enemy[50];


void enemyMovement(){

	for (int i=0;i<7;i++){
		if (pakistani_enemy[i].enemyShow==true){
			iShowBMP2(pakistani_enemy[i].enemy_x,pakistani_enemy[i].enemy_y,army[armyIndex],16777215);
			
		}
		armyIndex++;
		if(armyIndex==7){
			armyIndex=0;
		}
	}
}


void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	//place your codes here
	XCord=mx;
	YCord=my;
}
void iPassiveMouseMove(int mx,int my)
{
	//xCord=mx;
	//yCord=my;
	//place your code here
	
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/
 
}


/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
	XCord=mx;
			YCord=my;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		/*x += 10;
		y += 10;*/
		/*if(bulletCount < 100)
			bulletCount++;
		else if (bulletCount == 100)
			bulletCount = 0;

		bullet[bulletCount-1].hasShot = true;
		bullet[bulletCount-1].y = YCord + 105;
		bullet[bulletCount-1].x = picX3;*/
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		
		x -= 10;
		y -= 10;
	}
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	if(key=='s'){
		key1='s';
	}
	else if(key == 'd'){
		//picX-=30;
	    //picX2-=30;
		picX3+=15;
		xb=picX3+bombwidth;
		bombstartpoint=xb;
		
		iReset();
	}
	else if(key=='a'){
		//picX+=30;
		//picX2+=30;
		picX3-=15;
		xb=picX3+bombwidth;
		bombstartpoint=xb;
	}
	else if(key=='q')
		exit(0);
	else if(key=='i'){
		key3='i';
		key3pressed=true;}
	else if(key=='b'){
		key3='b';
		key3pressed=false;}
	else if (key == 'e'){
		key2='e';
		key2pressed=true;
	}
	
		if (key == 'z')
	{
		if(bulletCount < 100)
			bulletCount++;
		else if (bulletCount == 100)
			bulletCount = 0;

		bullet[bulletCount-1].hasShot = true;
		bullet[bulletCount-1].y = YCord + 50;
		bullet[bulletCount-1].x = picX3;
	}


	
	//else if(key=='z'){
	// picY3+=30;
	// iReset();
}
	//place your codes for other keys here
//}

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

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(key == GLUT_KEY_UP)
	{
		YCord+=10;	
	}
	if(key == GLUT_KEY_DOWN)
	{
		YCord-=10;	
	}
	if(key == GLUT_KEY_LEFT)
	{
		XCord-=10;;	
	}
	if(key == GLUT_KEY_RIGHT)
	{
		XCord+=10;	
	}
	
	//place your codes for other keys here
}
void change_enemy()
{
	for (i=0;i<50;i++){
		pakistani_enemy[i].enemy_x-=20;
		if (pakistani_enemy[i].enemy_x<=0){
			if (i==0){
				pakistani_enemy[i].enemy_x=1366 + (150 + rand() % 150); 
			}
			else
			{
				pakistani_enemy[i].enemy_x=pakistani_enemy[i-1].enemy_x + (150 + rand()% 150);
				
			}
		}
		pakistani_enemy[i].enemyIndex++;
		if (pakistani_enemy[i].enemyIndex>=50){
			pakistani_enemy[i].enemyIndex=0;
		}
	}
}
void setEnemyVariables(){
	for(i=0;i<50;i++){
		if (i==0){
			pakistani_enemy[i].enemy_x=1366+ (150 + rand() % 150);
			pakistani_enemy[i].enemy_y=(30 + rand() % 150);
			pakistani_enemy[i].enemyIndex=50;
			pakistani_enemy[i].enemyShow=true;
			pakistani_enemy[i].enemyBombShow=true;
			pakistani_enemy[i].bullet_x=pakistani_enemy[i].enemy_x;
		}
		else{
			pakistani_enemy[i].enemy_x=pakistani_enemy[i-1].enemy_x + (150 + rand()% 150);
			pakistani_enemy[i].enemy_y=(30 + rand() % 150);
			pakistani_enemy[i].enemyIndex=50;
			pakistani_enemy[i].enemyShow=true;
			pakistani_enemy[i].enemyBombShow=true;
			pakistani_enemy[i].bullet_x=pakistani_enemy[i].enemy_x;
			pakistani_enemy[i].bullet_y=pakistani_enemy[i].enemy_y;
		}
	}
}

void bulletEnemy(){
	iShowBMP(bullet[i].x,bullet[i].y,"bullet2.bmp");
	bulletEnemyFire();
}
void bulletEnemyFire(){
	for(i=0;i<7;i++){
		pakistani_enemy[i].bullet_x -=15;
	}
}

void enemykill()
{   for(i=0;i<bulletCount;i++){
     for(j=0;j<50;j++){
		 if(bullet[i].hasShot==true&&pakistani_enemy[j].enemyShow==true){
	if ((bullet[i].x +20>=pakistani_enemy[j].enemy_x&&bullet[i].x+20<=pakistani_enemy[j].enemy_x+100)&&(bullet[i].y+12>=pakistani_enemy[j].enemy_y&&bullet[i].y+12<=pakistani_enemy[j].enemy_y+150)){
	//if(bullet[i].x==pakistani_enemy[j].enemy_x){
			 pakistani_enemy[j].enemyShow=false;
		     bullet[i].hasShot = false;
			 scoreUPDATE();
	}
	else
		{pakistani_enemy[j].enemyShow=true;
		bullet[i].hasShot = true;
}
	 }
}
}
    j=0;
	pakistani_enemy[j].enemyShow=true;
	bullet[i].hasShot = false;
}
void enemykillBomb(){
	for(;j<50;j++){
	if(xb+50>=pakistani_enemy[j].enemy_x&&yb<=pakistani_enemy[j].enemy_y&&pakistani_enemy[j].enemyBombShow==true){
		pakistani_enemy[j].enemyShow=false;
		pakistani_enemy[j].enemyBombShow=false;
		if(pakistani_enemy[j].enemyBombShow==false){
			scoreUPDATE();
		}
	}
		else{
			pakistani_enemy[j].enemyBombShow=true;
		}
	}
}
void enemyCollision(){
	for(;j<50;j++){
	if(picX3==pakistani_enemy[j].enemy_x){
		iShowBMP(gmox,gmoy,"Game Over");
			}
		exit(0);
		}
	}
struct bll //boss lifeline
{
	int blx,bly; 
	bool blshow;            
}bl[6];
void boss(){
	if (level==3){
		for (i = 0; i < 6; i++)
		{
			if (bl[i].blshow == true)break;
		}
		if(i<6)iShowBMPAlternative(bossX,bossY,"maxresdefault1.bmp");
		blx=5;
		blshow=true;
		bossX-=10;
		for (j=0;j<6;j++){
			if (bl[j].blshow==true){
			iShowBMPAlternative(blx,650,"bl1.bmp");
			blx=blx+45;
			}
		
		for (i=0;i<50;i++){
			if (bullet[i].hasShot==true&&bl[j].blshow==true){
				if (bullet[i].x==bossX){
				bl[j].blshow=false;
				bullet[i].hasShot = false;}
			}
			else
				{bl[j].blshow=true;
			bullet[i].hasShot = true;

			}
		}
		}
		
		if (picX3==bossX)
			iShowBMPAlternative(gmox,gmoy,"Game Over.bmp");
		
	}
}

int main(){
	//place your own initialization codes here.
	
	if(key1=='s'){
	Start_Time=clock();
	//levelCR();
	iSetTimer(550,imove);
	iSetTimer(550,iReset);
	}
	
	iSetTimer(20,change_enemy);
	bulletTimer = iSetTimer(10,BulletShot);
	iResumeTimer(bulletTimer);
	setEnemyVariables();
	score();
	iInitialize(screenWidth, screenHight, "Contra");
	return 0;
}
