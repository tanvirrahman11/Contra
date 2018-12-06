int picX,picY,picX2;
void imove(){
	
	picX-=30;
	picX2-=30;
}
void iReset(){
	if(picX2==0){
		picX=3960;
		return;
		}
	else if(picX==0){
		picX2=3960;
		return;
		}
}