#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdio.h>
using namespace std;

//Function1:
int disp(){
    int i;
cout<<"Play your turn";
cin>>i;
if(i>9|| i<1)cout<<"Invalid position";
cout<<"\n";
return i;}

//Function2:
void msg(){
cout<<"You lose!!";}

//Function3:Row
int Row(int op){
    if(op<4)return 1;
    else if (op<7) return 2;
    else return 3;
}

//Function4:Column
int Column(int op)
{
    if(op%3!=0)return ((op%3));
    else return 3;
}

//Function5:Adjacent1
int Adjacent1(int op){
if(op<4)return 2;
else return 8;}

//Function6:Adjacent2
int Adjacent2(int op){
    if(op%6==1) return 4;
    else return 6;
}

//Function7:MAchinePlot
 void MachinePlot(int m){
     int r,c,temp;
     r=Row(m);
     c=Column(m);
     temp=r;
     r=175+(50*c);
     c=175+(50*temp);
         circle(r,c,5);
 }

 //Function8:OpPlot
 void OpPlot(int m){
     int r,c;
     r=Row(m);
     c=Column(m);
     rectangle(169+(50*c),172+(50*r),181+(50*c),178+(50*r));}

//Function9:EdgeGame
void EdgeGame(int op1){
    int m2,op2,op3,m3,m4;
    if(op1==4)m2=8;
    else m2=(op1+4)%8;
    MachinePlot(m2);
    op2=disp();
    OpPlot(op2);
    if(op2+op1!=6&&(op1+op2!=14))
        {
        m3=10-m2;
        MachinePlot(m3);
        msg();
        return;
    }
    else
        {
        if(op1<5)m3=9;
    else m3=1;
    }
    MachinePlot(m3);
    op3=disp();
    OpPlot(op3);
    if(op1==2)
        {
        if(op3!=1)m4=1;
        else m4=3;
        }
    else if(op1==4) {
        if(op3!=1)m4=1;
        else m4=7;
    }
    else if(op1==6){
        if(op3!=3)m4=3;
        else m4=9;
    }
    else{
        if(op3!=7)m4=7;
        else m4=9;
    }
    MachinePlot(m4);
    msg();
    return;
}

//Function10:CornerGame
void CornerGame(int op1){
int m2,op2,m3,op3,m4,op4,m5,r1,r2,c1,c2;
m2=10-op1;
MachinePlot(m2);
op2=disp();
OpPlot(op2);
//CornerGame:corner-Edge Case:
if(op2%2==0)
  {   //AdjacentEdge to the corner:
      if((Adjacent1(op1)==op2)||(Adjacent2(op1)==op2))
    {
        m3=2*op2-op1;
        MachinePlot(m3);
        op3=disp();
        OpPlot(op3);
        if(op3!=(m2+m3)/2)m4=(m2+m3)/2;
        else m4=10-m3;
        MachinePlot(m4);
        msg();
        return ;
      }
      //Non-Adjacent Case:
    else
     {
         r1=Row(op1);r2=Row(op2);
         c2=Column(op1);c2=Column(op2);
        if (((r1-r2)==1)||((r1-r2)==-1)) m3=(op1+6)%12;
        else{
            if(op1<4)m3=4-op1;
            else m3=16-op1;
        }
        MachinePlot(m3);
        op3=disp();
        OpPlot(op3);
        if(op3!=(m2+m3)/2)m4=(m2+m3)/2;
        else m4=10-m3;
        MachinePlot(m4);
        msg();
        return ;
     }


   }
   //CornerGame-Corner-Corner Case:
   else
   {
       m3=(op1+op2)/2;
       MachinePlot(m3);
       op3=disp();
       OpPlot(op3);
       if(op3!=10-m3){
        m4=10-m3;
        MachinePlot(m4);
        msg();
        return ;
        }
        else{
            if(op3==4||op3==6)m4=2;
            else m4=4;
            MachinePlot(m4);
            op4=disp();
            OpPlot(op4);
            if(op4!=10-m4){
                m5=10-m4;
                MachinePlot(m5);
                msg();
                return ;}
                else{
                    m5=10-op2;
                    MachinePlot(m5);
                    cout<<"Draw!!";
                    return ;
                }
            }
        }

   }


//Function11:Main
int main(){
int op1,m1;
char ch;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c tc bgi");
initwindow(640,400);
ch='y';
while(ch=='y'||ch=='Y'){

line(250,200,250,350);
line(300,200,300,350);
line(200,250,350,250);
line(200,300,350,300);
MachinePlot(5);
op1=disp();
OpPlot(op1);
if(op1%2==0) EdgeGame(op1);
else CornerGame(op1);
cout<<"\nDo you wanna play again?(Y/N)";
cin>>ch;
cleardevice();
system("cls");
}
getch();
return 0;
}
