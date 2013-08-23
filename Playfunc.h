//Update region code of ikaros
void upregcode()
{
	int oldcode=regcode;
	switch(regcode)
	{
		case 0:	if(ikarosp[4][1]>60.0)
					regcode=1;
				break;
		case 1: if(ikarosp[4][1]<60.0)
					regcode=0;
				else if(ikarosp[4][1]>160.0)
					regcode=2;
				break;
		case 2: if(ikarosp[4][1]<160.0)
					regcode=1;
				else if(ikarosp[4][1]>270.0)
					regcode=3;
				break;
		case 3: if(ikarosp[4][1]<270.0)
					regcode=2;
				else if(ikarosp[4][0]>180.0)
					regcode=4;
				break;
		case 4: if(ikarosp[4][0]<180.0)
					regcode=3;
				else if(ikarosp[4][1]<270.0)
					regcode=5;
				break;
		case 5: if(ikarosp[4][1]>270.0)
					regcode=4;
				else if(ikarosp[4][1]<160.0)
					regcode=6;
				break;
		case 6: if(ikarosp[4][1]>160.0)
					regcode=5;
				else if(ikarosp[4][0]>370.0)
					regcode=7;
				break;
		case 7: if(ikarosp[4][0]<370.0)
					regcode=6;
				else if(ikarosp[4][1]>270.0)
					regcode=8;
				break;
		case 8: if(ikarosp[4][1]<270.0)
					regcode=7;
				else if(ikarosp[4][1]>440.0)
					regcode=9;
				break;
		case 9: if(ikarosp[4][1]<440.0)
					regcode=8;
				break;
		}
}

//Check for collisions
void collicheck()
{
	switch(regcode)
	{
		case 0: if( ikarosp[4][1]<10.0 || ikarosp[4][0]>140.0 || ikarosp[4][0]<60.0 )
					pflag=2;
				break;
		case 1: if( (ikarosp[4][0]<10.0 || ikarosp[4][0]>140.0) )
					pflag=2;
				break;
		case 2: if( ikarosp[4][0]<10.0 || ikarosp[4][0]>140.0 || (ikarosp[4][1]>230.0 && ikarosp[4][0]<110.0) )
					pflag=2;
				break;
		case 3: if( ikarosp[4][0]<10.0 || (ikarosp[4][1]<370.0 && ikarosp[4][0]>140.0) || (ikarosp[4][0]>65.0 && ikarosp[4][1]>370.0 && ikarosp[4][1]<410.0) || ikarosp[4][1]>480.0 )
					pflag=2;
				break;
		case 4: if( ikarosp[4][0]>240.0 || ikarosp[4][1]>470.0 )
					pflag=2;
				break;
		case 5:	if( ikarosp[4][0]<180.0 || (ikarosp[4][1]>270.0 && ikarosp[4][0]>240.0) || (ikarosp[4][1]<200.0 && ikarosp[4][0]<280.0) || ikarosp[4][0]>370.0 )
					pflag=2;
				break;
		case 6: if( ikarosp[4][0]<180.0 || ikarosp[4][1]<10.0 || (ikarosp[4][0]>260.0 && ikarosp[4][1]>70.0 && ikarosp[4][1]<110.0) )
					pflag=2;
				break;
		case 7: if( ikarosp[4][1]<10.0 || ikarosp[4][0]>490.0 || (ikarosp[4][0]<435.0 && ikarosp[4][1]>70.0 && ikarosp[4][1]<110.0) || (ikarosp[4][0]<410.0 && ikarosp[4][1]>110.0 && ikarosp[4][1]<270.0) )
					pflag=2;
				break;
		case 8: if( ikarosp[4][0]<280.0 || (ikarosp[4][1]<310.0 && ikarosp[4][0]<410.0) || (ikarosp[4][0]>330.0 && ikarosp[4][1]>370.0 && ikarosp[4][1]<410.0) || ikarosp[4][0]>490.0 )
					pflag=2;
				break;
		case 9: if( ikarosp[4][0]<280.0 || ikarosp[4][1]>480.0 )
					pflag=2;
				else if (ikarosp[4][0]>440.0)
					pflag=5;
				break;
	}
	if( timerp[2][0]>450.0 )
			pflag=4;
}

//Start or restart game
void restart(int sflag) 
{
	if(!sflag) luck=4;
	if(luck--)
	{
		for(int i=0; i<5; i++)
		{
			for(int j=0; j<3; j++)
			{
				ikarosp[i][j]=ipbkup[i][j];
				if(sflag!=1) 
					timerp[i][j]=tpbkup[i][j];
			}
			ikarosv[i]=ivbkup[i];
		}
		theta=0;
		pflag=1;
		regcode=1;
	}
	else
		pflag=3;
}

//Move Ikaros left
void move_left()
{
	if(ikarosv[0]<0) //Left
		{ }
	else if(ikarosv[0]>0) //Right
		ikarosv[0]=-ikarosv[0];
	else if(ikarosv[1]<0) //Down
		ikarosv[0]=ikarosv[1];
	else if(ikarosv[1]>0) //Top
		ikarosv[0]=-ikarosv[1];
	ikarosv[1]=0;
}

//Move Ikaros right
void move_right()
{
	if(ikarosv[0]<0) //Left
		ikarosv[0]=-ikarosv[0];
	else if(ikarosv[0]>0) //Right
		{ }
	else if(ikarosv[1]<0) //Down
		ikarosv[0]=-ikarosv[1];
	else if(ikarosv[1]>0) //Top
		ikarosv[0]=ikarosv[1];
	ikarosv[1]=0;
}

//Move Ikaros top
void move_top()
{
	if(ikarosv[0]<0) //Left
		ikarosv[1]=-ikarosv[0];
	else if(ikarosv[0]>0) //Right
		ikarosv[1]=ikarosv[0];
	else if(ikarosv[1]<0) //Down
		ikarosv[1]=-ikarosv[1];
	else if(ikarosv[1]>0) //Top
		{ }
	ikarosv[0]=0;
}

//Move Ikaros down
void move_down()
{
	if(ikarosv[0]<0) //Left
		ikarosv[1]=ikarosv[0];
	else if(ikarosv[0]>0) //Right
		ikarosv[1]=-ikarosv[0];
	else if(ikarosv[1]<0) //Down
		{ }
	else if(ikarosv[1]>0) //Top
		ikarosv[1]=-ikarosv[1];
	ikarosv[0]=0;
}
