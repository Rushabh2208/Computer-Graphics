#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//structure declarati
    void back() ;
//global variables
union REGS i,o;
char buff[80];
int hit=0,life=1;
int m1=1,m2=1,m3=1,m4=1,m5=1,gover=0;
int level1=1,check=0,score=0,mid,flag=0;
char buffer1[80],buffer[80];
int count=0,ascii,z1=625,scan,m=60,n=70,p=80,q=50,r;
int left=10,top=285,right=63,bottom=285;
unsigned int size,size1,size2,size3,size4,globalsize,handsize,eyesize;
void *pball,*pball1,*pball2,*pball3,*pball4,*handimage,*peye;
void *iball,*iball1,*iball2,*iball3;
   void hand()
   {
   setcolor(8);
   setlinestyle(0,1,3);
   setfillstyle(1,8);
   bar(14,197,19,215);
   line(19,198,23,198);
   line(22,200,29,192);
   line(29,192,38,192);
   line(37,192,37,197);
   line(32,197,54,197);
   line(54,197,54,202);
   line(32,202,54,202);
   line(32,207,42,207);
   line(32,212,42,212);
   line(42,212,42,202);
   line(38,212,38,217);
   line(38,217,14,217);
   handsize= imagesize(14,190,56,220);
   /* allocate memory to hold the image */
   handimage= malloc(handsize);
   /* grab the image */
   getimage(14,190, 56,220, handimage);
   cleardevice();
   }

void getkey()
{
	 i.h.ah=0x00;
	 int86(0x16,&i,&o);
	 ascii=o.h.al;
	 scan=o.h.ah;
}

void DDA()
{
clearviewport();
cout<<"Digital Differential Analyzer(DDA)"<<endl<<endl<<endl;
cout<<"A digital differential analyzer (DDA) is hardware or software used for linear interpolation of variables over an interval between start and end point. DDAs are used for rasterization of lines, triangles and polygons. In its simplest implementation, the DDA algorithm interpolates values in interval by computing for each xi the equations xi = xi-1+1/m, yi = yi-1 + m, where ?x = xend - xstart and ?y = yend - ystart and m = ?y/?x";
cout<<"This slope can be expressed in DDA as:"<<endl;
cout<<"m=yend-ystart/xend-xstart"<<endl;
cout<<"Steps:"<<endl;
cout<< "1. Set M = (YN - Y1) / (XN - X1) [Calculate slope of line]"<<endl;
cout<< "2. Repeat For I = X1 to XN"                                <<endl;
cout<< "3. If (M <= 1) Then"                                       <<endl;
cout<<  "4. Set DX = 1"                                            <<endl;
cout<< "5. Set DY = M * DX"                                        <<endl;
cout<<  "6. Else"                                                  <<endl;
cout<<  "7. Set DY = 1"                                            <<endl;
cout<< "8. Set DX = DY / M"                                        <<endl;
cout<< "[End of If]"                                               <<endl;
cout<< "9. Set X1 = X1 + DX"                                       <<endl;
cout<< "10. Set Y1 = Y1 + DY"                                      <<endl;
cout<<  "11. Call PutPixel(X1, Y1)"                                <<endl;
cout<<    "[End of For]"                                           <<endl;
cout<<  "12. Exit"        <<endl;


    getkey();
    if(ascii==8)
    {
    back();
    }
    if(ascii==13)
    {
   cleardevice();
int x1,x2,y1,y2,dx,dy,len;
float delx,dely,x,y;
cout<<"Enter Values for x1,y1 followed by x2,y2"<<endl;
cin>>x1>>y1>>x2>>y2;
dx=x2-x1;
dy=y2-y1;
if(abs(dx)>=abs(dy))
len=abs(dx);
else
len=abs(dy);
delx=dx/len;
dely=dy/len;
x=x1;y=y1;
int i=1;
putpixel((x+0.5),(y+0.5),15);
while(i<=len)
{
x+=delx;
y+=dely;
delay(50);
putpixel((x+0.5),(y+0.5),15);
i++;

}
delay(10000);
}
else
if(ascii==8)
{
back();
}

}


void BresL()
{
clearviewport();
cout<<"Bresenham's line algorithm is an algorithm that determines the points of an n-dimensional raster that should be selected in order to form a close approximation to a straight line between two points. It is commonly used to draw lines on a computer screen, as it uses only integer addition, subtraction and bit shifting, all of which are very cheap operations in standard computer architectures. It is one of the earliest algorithms developed in the field of computer graphics. An extension to the original algorithm may be used for drawing circles."<<endl<<endl;
cout<<"Steps:"<<endl<<endl;
cout<<"1. Set DX = XN – X1 and DY = YN – Y1"<<endl;
cout<<"2. Set Di = 2DY - DX"<<endl;
cout<<"3. Set DS = 2DY and DT = 2(DY – DX)"<<endl;
cout<<"4. Call PutPixel(X1, Y1)"<<endl;
cout<<"5. Repeat While (X1 < XN)"<<endl;
cout<<"6. Set X1 = X1 + 1"<<endl;
cout<<"7. If (Di < 0) Then"<<endl;
cout<<"8. Set Di = Di + DS"<<endl;
cout<<"9. Else"<<endl;
cout<<"10. Set Y1 = Y1 + 1"<<endl;
cout<<"11. Set Di = Di + DT"<<endl;
cout<<"[End of If]"<<endl;
cout<<"12. Call PutPixel(X1, Y1)"<<endl;
cout<<"[End of While]"<<endl;
cout<<"13. Exit"<<endl;


    getkey();
    if(ascii==13)
    {


		    cleardevice();
	 float x1,x2,y1,y2,x,y,e,dx,dy,n;
	 cout<<"Enter (x1,y1) :\n";
	 cin>>x1>>y1;
	 cout<<"Enter (x2,y2) :\n";
	 cin>>x2>>y2;

	 if((x1==x2)&&(y1==y2))
	     {}
	 else
	  {
	 dx=x2-x1;
	 if(dx<0)
	   dx=dx*(-1);
	 dy=y2-y1;
	 if(dy<0)
	   dy=dy*(-1);

	 x=x1;
	 y=y1;
	 e=2*(dy-dx);
	  int i=1;

	   while(i<=dx)
	    {
	    delay(50);
	     putpixel(x,y,5);
	      while(e>=0)
	      {
	       y+=1;
	       e=e-2*dx;
	      }
	   x+=	1;
	   e=e+2*dy;
	   i=i+1;
	    }
	    }
	  delay(10000);
 }
   }
   void MidC()
{  clearviewport();
cout<<"In computer graphics, the midpoint circle algorithm is an algorithm used to determine the points needed for drawing a circle. Bresenham's circle algorithm is derived from the midpoint circle algorithm."<<endl<<endl;
cout<<"1. Set X = 0 and Y = R"<<endl;
cout<<"2. Set P = 1 – R"<<endl;
cout<<"3. Repeat While (X < Y)"<<endl;
cout<<"4. Call Draw Circle(Xc, Yc, X, Y)"<<endl;
cout<<"5. Set X = X + 1"<<endl;
cout<<"6. If (P < 0) Then"<<endl;
cout<<"7. P = P + 2X + 6"<<endl;
cout<<"8. Else"<<endl;
cout<<"9. Set Y = Y – 1"<<endl;
cout<<"10. P = P + 2(X – Y) + 1"<<endl;
cout<<"[End of If]"<<endl;
cout<<"11. Call DrawCircle(Xc, Yc, X, Y)"<<endl;
cout<<"[End of While]"<<endl;
cout<<"12. Exit"<<endl;
cout<<"DrawCircle (Xc, Yc, X, Y):"<<endl;
cout<<"1. Call PutPixel(Xc + X, Yc, + Y)"<<endl;
cout<<"2. Call PutPixel(Xc - X, Yc, + Y)"<<endl;
cout<<"3. Call PutPixel(Xc + X, Yc, - Y)"<<endl;
cout<<"4. Call PutPixel(Xc - X, Yc, - Y)"<<endl;
cout<<"5. Call PutPixel(Xc + Y, Yc, + X)"<<endl;
cout<<"6. Call PutPixel(Xc - Y, Yc, + X)"<<endl;
cout<<"7. Call PutPixel(Xc + Y, Yc, - X)"<<endl;
cout<<"8. Call PutPixel(Xc - Y, Yc, - X)"<<endl;
cout<<"9. Exit."<<endl;
      getkey()  ;
       if(ascii==8)
    {
    back();
    }

if(ascii==13)
{ cleardevice();
   float d;
   int r,x,y;
   cout<<"Enter radius: ";
   cin>>r;
   x=0;
   y=r;
   d=1.25-r;
   do
   {
    putpixel(200+x,200+y,5);
    putpixel(200+x,200-y,5);
    putpixel(200-x,200+y,5);
    putpixel(200-x,200-y,5);
    putpixel(200+y,200+x,5);
    putpixel(200+y,200-x,5);
    putpixel(200-y,200+x,5);
    putpixel(200-y,200-x,5);
    if(d<0)
    {
    x=x+1;
    y=y;
    d=d+2*x+1;
    }
    else
    {
    x=x+1;
    y=y-1;
    d=d+2*x-2*y+1;
    }
     delay(100);
    }
    while(x<y);
    }
 }
    int k;
	float xmin,ymin,xmax,ymax,arr[30],zz;

		int round(int a)
		{
			return ((int)(a+0.5));

		}

	void clipl(float x1,float y1,float x2,float y2)
	{
	    if(x2-x1)
		zz=(y2-y1)/(x2-x1);
	    else
		zz=100000;
	    if(x1>=xmin && x2>=xmin)
	    {
		arr[k]=x2;
		arr[k+1]=y2;
		k+=2;
	    }
	    if(x1<xmin && x2>=xmin)
	    {
		arr[k]=xmin;
		arr[k+1]=y1+zz*(xmin-x1);
		arr[k+2]=x2;
		arr[k+3]=y2;
		k+=4;
	    }
	    if(x1>=xmin  && x2<xmin)
	    {
		arr[k]=xmin;
		arr[k+1]=y1+zz*(xmin-x1);
		k+=2;
	    }
	}

	void clipt(float x1,float y1,float x2,float y2)
	{
	    if(y1-y2)
		zz=(x2-x1)/(y2-y1);
	    else
		zz=100000;
	    if(y1<=ymax && y2<=ymax)
	    {
		arr[k]=x2;
		arr[k+1]=y2;
		k+=2;
	    }
	    if(y1>ymax && y2<=ymax)
	    {
		arr[k]=x1+zz*(ymax-y1);
		arr[k+1]=ymax;
		arr[k+2]=x2;
		arr[k+3]=y2;
		k+=4;
	    }
	    if(y1<=ymax  && y2>ymax)
	    {
		arr[k]=x1+zz*(ymax-y1);
		arr[k+1]=ymax;
		k+=2;
	    }
	}

	void clipr(float x1,float y1,float x2,float y2)
	{
	    if(x2-x1)
		zz=(y2-y1)/(x2-x1);
	    else
		zz=100000;
	    if(x1<=xmax && x2<=xmax)
	    {
		arr[k]=x2;
		arr[k+1]=y2;
		k+=2;
	    }
	    if(x1>xmax && x2<=xmax)
	    {
		arr[k]=xmax;
		arr[k+1]=y1+zz*(xmax-x1);
		arr[k+2]=x2;
		arr[k+3]=y2;
		k+=4;
	    }
	    if(x1<=xmax  && x2>xmax)
	    {
		arr[k]=xmax;
		arr[k+1]=y1+zz*(xmax-x1);
		k+=2;
	    }
	}

	void clipb(float x1,float y1,float x2,float y2)
	{
	    if(y2-y1)
		zz=(x2-x1)/(y2-y1);
	    else
		zz=10;
	    if(y1>=ymin && y2>=ymin)
	    {
		arr[k]=x2;
		arr[k+1]=y2;
		k+=2;
	    }
	    if(y1<ymin && y2>=ymin)
	    {
		arr[k]=x1+zz*(ymin-y1);
		arr[k+1]=ymin;
		arr[k+2]=x2;
		arr[k+3]=y2;
		k+=4;
	    }
	    if(y1>=ymin  && y2<ymin)
	    {
		arr[k]=x1+zz*(ymin-y1);
		arr[k+1]=ymin;
		k+=2;
	    }
	}
void  Poly()
  {    clearviewport();
cout<<"The Sutherland–Hodgman algorithm is used for clipping polygons. It works by extending each line of the convex clip polygon in turn and selecting only vertices from the subject polygon that are on the visible side."<<endl<<endl;
cout<<"Steps:"<<endl<<endl;
cout<<"1.	Point S = inputList.last;"<<endl;
cout<<"2.	for (Point E in inputList) do"<<endl;
cout<<"3.	if (E inside clipEdge) then"<<endl;
cout<<"4.	if (S not inside clipEdge) then"<<endl;
cout<<"a.	outputList.add(ComputeIntersection(S,E,clipEdge));"<<endl;
cout<<"5.	end if"<<endl;
cout<<"6.	outputList.add(E);"<<endl;
cout<<"7.	else if (S inside clipEdge) then"<<endl;
cout<<"8.	outputList.add(ComputeIntersection(S,E,clipEdge));"<<endl;
cout<<"9.	end if"<<endl;
cout<<"10.	S = E;"<<endl;
cout<<"11.	done"<<endl;
cout<<"12.	done"<<endl;

 getkey()  ;
  if(ascii==8)
    {
    back();
    }

if(ascii==13)
{


	    int n,poly[20];
	    float xi,yi,xf,yf,polyy[20];
	    clearviewport();
	    cout<<"Coordinates of rectangular clip window :\nxmin,ymin :";
	    cin>>xmin>>ymin;
	    cout<<"xmax,ymax :";
	    cin>>xmax>>ymax;
	    cout<<"\n\nPolygon to be clipped :\nNumber of sides";
	    cin>>n;
	    cout<<"Enter the coordinates :";
	    for(int i=0;i<2*n;i++)
		cin>>polyy[i];
	    polyy[2*n]=polyy[0];
	    polyy[2*n+1]=polyy[1];
	    for(i=0;i<2*n+2;i++)
		poly[i]=round(polyy[i]);
		    setcolor(BLUE);
	    rectangle(xmin,ymax,xmax,ymin);
	    cout<<"\t\tUnclipped Polygon";
	    setcolor(RED);
	    fillpoly(n,poly);
	    getch();
	    cleardevice();
	    k=0;
	    for(i=0;i<2*n;i+=2)
		clipl(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
	    n=k/2;
	    for(i=0;i<k;i++)
		polyy[i]=arr[i];
	    polyy[i]=polyy[0];
	    polyy[i+1]=polyy[1];
	    k=0;
	    for(i=0;i<2*n;i+=2)
		clipt(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
	    n=k/2;
	    for(i=0;i<k;i++)
		polyy[i]=arr[i];
	    polyy[i]=polyy[0];
	    polyy[i+1]=polyy[1];
	    k=0;
	    for(i=0;i<2*n;i+=2)
		clipr(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
	    n=k/2;
	    for(i=0;i<k;i++)
		polyy[i]=arr[i];
	    polyy[i]=polyy[0];
	    polyy[i+1]=polyy[1];
	    k=0;
	    for(i=0;i<2*n;i+=2)
		clipb(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
	    for(i=0;i<k;i++)
		poly[i]=round(arr[i]);
	    if(k)
		fillpoly(k/2,poly);
	    setcolor(RED);
	    rectangle(xmin,ymax,xmax,ymin);
	    cout<<"\tClipped Polygon";

	 }
	 delay(10000);
}

 void Beizer()
  {                 clearviewport();
cout<<"The objective here is to find points in the middle of two nearby points and iterate this until we have no more iterations. The new values of points will give us the curve. The famous Bezier equation is the exact formulation of this idea. Here is the algorithm:"<<endl<<endl;
cout<<"Steps:"<<endl<<endl;
cout<<"1.	Select a value t Î [0,1]. This value remains constant for the rest of the steps."<<endl<<endl;
cout<<"2.	Set Pi[0] (t) = Pi, for i = 0,...,n."<<endl<<endl;
cout<<"3.	For j= 0,...,n, set   for i = j,...,n."<<endl<<endl;
cout<<"4.	. g (t) = Pn[n] (t)"<<endl<<endl;
cout<<""<<endl<<endl;
cout<<""<<endl<<endl;
cout<<""<<endl<<endl;


 getkey()  ;
 if(ascii==8)
    {
    back();
    }

if(ascii==13)
{ cleardevice();
int x1,x2,x3,x4,y1,y2,y3,y4;
 cout<<"Enter all point in (x,y) :";
 cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
 double u=0.0;
 line(x1,y1,x2,y2);
 line(x2,y2,x3,y3);
 line(x3,y3,x4,y4);
 line(x4,y4,x1,y1);
 double x,y;
 for(int i=0;i<1000;i++)
 {
 x=pow((1-u),3)*x1+3*u*pow((1-u),2)*x2+3*pow(u,2)*(1-u)*x3+pow(u,3)*x4;
 y=pow((1-u),3)*y1+3*u*pow((1-u),2)*y2+3*pow(u,2)*(1-u)*y3+pow(u,3)*y4;
 u+=0.001;
 delay(10);
 putpixel(x,y,YELLOW);
 }


}
delay(10000);
}

void FloodFill4(int x,int y,int newcolor,int oldcolor)
{
if(getpixel(x,y)==oldcolor)
{            delay(20);
putpixel(x,y,newcolor);
FloodFill4(x,y+1,newcolor,oldcolor);
FloodFill4(x+1,y,newcolor,oldcolor);
FloodFill4(x,y-1,newcolor,oldcolor);
FloodFill4(x-1,y,newcolor,oldcolor);
}
}

void FF()
{                 clearviewport();
cout<<"Flood fill, also called seed fill, is an algorithm that determines the area connected to a given node in a multi-dimensional array. It is used in the bucket fill tool of paint programs to fill connected, similarly-colored areas with a different color, and in games such as Go and Minesweeper for determining which pieces are cleared. When applied on an image to fill a particular bounded area with color, it is also known as boundary fill."<<endl;
cout<<"Steps:"<<endl<<endl;
cout<<"Flood-fill (node, target-color, replacement-color):"<<endl;
cout<<" 1. If target-color is equal to replacement-color, return."<<endl;
cout<<"2. If the color of node is not equal to target-color, return."<<endl;
cout<<"3. Set the color of node to replacement-color."<<endl;
cout<<"4. Perform Flood-fill (one step to the west of node, target-color, replacement-color)."<<endl;
cout<<"Perform Flood-fill (one step to the east of node, target-color, replacement-color)."<<endl;
cout<<"Perform Flood-fill (one step to the north of node, target-color, replacement-color)."<<endl;
cout<<"Perform Flood-fill (one step to the south of node, target-color, replacement-color)."<<endl;
cout<<"5. Return."<<endl;

 getkey()  ;
 if(ascii==8)
    {
    back();
    }

if(ascii==13)
{ cleardevice();
line(50,50,100,50);
line(100,50,100,100);
line(100,100,50,100);
line(50,100,50,50);
FloodFill4(80,80,YELLOW,BLACK);

}}

void CohenL()
{
clearviewport();

cout<<"The Cohen-Sutherland algorithm uses a divide-and-conquer strategy. The line segment's endpoints are tested to see if the line can be trivally accepted or rejected. If the line cannot be trivally accepted or rejected, an intersection of the line with a window edge is determined and the trivial reject/accept test is repeated. This process is continued until the line is accepted."<<endl;


cout<<"To perform the trivial acceptance and rejection tests, we extend the edges of the window to divide the plane of the window into the nine regions. Each end point of the line segment is then assigned the code of the region in which it lies."<<endl;
cout<<endl<<endl;

cout<<"Steps:"<<endl;

cout<<"1.	Given a line segment with endpoint  and"<<endl  ;
cout<<"2.	Compute the 4-bit codes for each endpoint."<<endl;
cout<<"3.	If both codes are 0000,(bitwise OR of the codes yields 0000 ) line lies completely inside the window: pass the endpoints to the draw routine."<<endl;
cout<<"4.	If both codes have a 1 in the same bit position (bitwise AND of the codes is not 0000), the line lies outside the window. It can be trivially rejected."<<endl;
cout<<"5.	If a line cannot be trivially accepted or rejected, at least one of the two endpoints must lie outside the window and the line segment crosses a window edge. This line must be clipped at the window edge before being passed to the drawing routine."<<endl;
cout<<"6.	Examine one of the endpoints, say .Read  's 4-bit code in order: Left-to-Right, Bottom-to-Top."<<endl;
cout<<"7.	When a set bit (1) is found, compute the intersection I of the corresponding window edge with the line from  to . Replace  with I and repeat the algorithm."<<endl;


 getkey()  ;
 if(ascii==8)
    {
    back();
    }

if(ascii==13)
{
	    int n,poly[20];
		 float xi,yi,xf,yf,polyy[20];
	    clearviewport();
	    cout<<"Coordinates of rectangular clip window :\nxmin,ymin :";
	    cin>>xmin>>ymin;
	    cout<<"xmax,ymax :";
	    cin>>xmax>>ymax;
	    cout<<"\n\nLine to be clipped :\n";
	    n=2  ;
	    cout<<"Enter the coordinates :";
	    for(int i=0;i<2*n;i++)
		cin>>polyy[i];
	    polyy[2*n]=polyy[0];
	    polyy[2*n+1]=polyy[1];
	    for(i=0;i<2*n+2;i++)
		poly[i]=round(polyy[i]);
		    setcolor(BLUE);
	    rectangle(xmin,ymax,xmax,ymin);
	    cout<<"\t\tUnclipped Polygon";
	    setcolor(RED);
	    fillpoly(n,poly);
	    getch();
	    cleardevice();
	    k=0;
	    for(i=0;i<2*n;i+=2)
		clipl(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
	    n=k/2;
	    for(i=0;i<k;i++)
		polyy[i]=arr[i];
	    polyy[i]=polyy[0];
	    polyy[i+1]=polyy[1];
	    k=0;
	    for(i=0;i<2*n;i+=2)
		clipt(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
	    n=k/2;
	    for(i=0;i<k;i++)
		polyy[i]=arr[i];
	    polyy[i]=polyy[0];
	    polyy[i+1]=polyy[1];
	    k=0;
	    for(i=0;i<2*n;i+=2)
		clipr(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
	    n=k/2;
	    for(i=0;i<k;i++)
		polyy[i]=arr[i];
	    polyy[i]=polyy[0];
	    polyy[i+1]=polyy[1];
	    k=0;
	    for(i=0;i<2*n;i+=2)
		clipb(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
	    for(i=0;i<k;i++)
		poly[i]=round(arr[i]);
	    if(k)
		fillpoly(k/2,poly);
	    setcolor(RED);
	    rectangle(xmin,ymax,xmax,ymin);
	    cout<<"\tClipped Polygon";

	 }
	 delay(10000);
}

double mx,my,rx,ry,maxx,maxy,minx,miny,c[10][10],b[10][10],a[10][10];
int mapx(int x)
{
 int max;
 max=(x-minx)*rx;
 return(max);
}
int mapy(int y)
{
 int may;
 may=(miny-y)*ry+my;
 return(may);
}
void tr();
void sc();
void rot();
void ref();
void shear();
void n3D()
{clearviewport();
cout<<"Transformaions are a fundamental part of computer graphics. Transformations are used to position objects, to shape objects, to change viewing positions, and even to change how something is viewed (e.g. the type of perspective that is used)"<<endl;
cout<<endl<<endl;
cout<<"TRANSLATION"<<endl;

cout<<"Assume you are given a point at (x,y)=(2,1). Where will the point be if you move it 3 units to the right and 1 unit up? Ans: (x',y') = (5,2). How was this obtained? - (x',y') = (x+3,y+1). That is, to move a point by some amount dx to the right and dy up, you must add dx to the x-coordinate and add dy to the y-coordinate."<<endl;
cout<<endl<<endl;
cout<<"SCALING"<<endl;

cout<<"Suppose we want to double the size of a 2-D object. What do we mean by double the size of a 2-D object. What do we mean by double? Double in size, width only, height only, along some line only? When we talk about scaling we usually mean some amount of scaling along each dimension. That is, we must specify how much to change the size along each dimension"<<endl;
cout<<endl<<endl ;
cout<<"ROTATION"<<endl;
cout<<"Rotation is when we rotate the line or object about a particular degree either w.r.t x-axis or y-axis."<<endl;
cout<<endl<<endl;
cout<<"SHEARING"<<endl;

cout<<"Distorts the shape of an object such that the transformed shape appears as if the object were composed of internal layer that had been caused to slide over each other."<<endl;
cout<<endl<<endl;
getkey()          ;
if(ascii==13)
{
clearviewport();
 int n=0,i,j,k;
  for(i=1;i<=3;i++)
    a[i][3]=1;
  a[1][1]=10;
  a[1][2]=10;
  a[2][1]=10;
  a[2][2]=110;
  a[3][1]=50;
  a[3][2]=60;

  while(n<6)
  {
  for(i=1;i<=3;i++)
  for(j=1;j<=3;j++)
   b[i][j]=0;
  mx=getmaxx();
  my=getmaxy();
  maxx=mx/2; maxy=my/2; minx=-mx/2; miny=-my/2;
  rx=mx/(maxx-minx);
  ry=my/(maxy-miny);
 line(mapx(a[1][1]),mapy(a[1][2]),mapx(a[2][1]),mapy(a[2][2]));
 line(mapx(a[2][1]),mapy(a[2][2]),mapx(a[3][1]),mapy(a[3][2]));
 line(mapx(a[1][1]),mapy(a[1][2]),mapx(a[3][1]),mapy(a[3][2]));
 cout<<"\n";
 cout<<"Enter option:\n1.Translate\n2.Scaling\n3.Rotation\n4.Reflection\n5.Shearing\n6.Exit\n";
 cin>>n;
 switch(n)
 {
  case 1:
  {
   tr();
    break;
    }
  case 2: sc(); break;
  case 3: rot(); break;
  case 4: ref(); break;
  case 5: shear(); break;
  case 6: back(); break;
  default:break;
 }
 if(n<6)
 {
  for(i=1;i<=3;i++)
 {
 for(j=1;j<=3;j++)
  c[i][j]=0;
 }
 for(i=1;i<=3;i++)
 {
  for(j=1;j<=3;j++)
   for(k=1;k<=3;k++)
   {
    c[i][j]+=a[i][k]*b[k][j];
   }
 }
 line(mapx(c[1][1]),mapy(c[1][2]),mapx(c[2][1]),mapy(c[2][2]));
 line(mapx(c[2][1]),mapy(c[2][2]),mapx(c[3][1]),mapy(c[3][2]));
 line(mapx(c[1][1]),mapy(c[1][2]),mapx(c[3][1]),mapy(c[3][2]));


 }
 }

}
if(ascii==8)
back();
}

void tr()
{
 cout<<"Enter translate co-ordinates\n";
 b[1][1]=1;
 b[2][2]=1;
 b[3][3]=1;
 cout<<"Tx:";
 cin>>b[3][1];
 cout<<"Ty:";
 cin>>b[3][2];
}
void sc()
{
 cout<<"Enter translate co-ordinates\n";
 b[3][3]=1;
 cout<<"Sx:";
 cin>>b[1][1];
 cout<<"Sy:";
 cin>>b[2][2];
}
void rot()
{
	 double t,x;
 cout<<"Enter rotation angle\n";
 cin>>t;
 x=t*(3.14/180);
 b[1][1]=cos(x);
 b[1][2]=sin(x);
 b[2][1]=-sin(x);
 b[2][2]=cos(x);
 b[3][3]=1;
}
void ref()
{
 int n;
 cout<<"Enter option:\n1.Y-axis\n2.X-axis\n3.origin\n4.Y=X\n5.Y=-X\n";
 cin>>n;
 switch(n)
 {
  case 1:
  b[1][1]=-1;
  b[2][2]=1;
  b[3][3]=1;
  break;
  case 2:
  b[1][1]=1;
  b[2][2]=-1;
  b[3][3]=1;
  break;
  case 3:
  b[1][1]=-1;
  b[2][2]=-1;
  b[3][3]=1;
  break;
  case 4:
  b[1][2]=1;
  b[2][1]=1;
  b[3][3]=1;
  break;
  case 5:
  b[1][2]=-1;
  b[2][1]=-1;
  b[3][3]=1;
  break;
  default:break;
 }
}
void shear()
{
 int n;
 double shx,shy;
 b[1][1]=1;
 b[2][2]=1;
 b[3][3]=1;
 cout<<"Enter option:\n1.X-Shear\n2.Y-Shear\n";
 cin>>n;
 switch(n)
 {
  case 1:
  cout<<"Shx: ";
  cin>>shx;
  b[2][1]=shx;
  break;
  case 2:
  cout<<"Shy: ";
  cin>>shy;
  b[1][2]=shy;
  break;
  default:break;
 }

}

void back()
{
	   int mid;
	   static int c=1;
	   char name[30];
	   man:
		while(1)
		{
		    cleardevice();
		    setcolor(WHITE);
		    c=1;
		    setbkcolor(2);
		    setlinestyle(2,1,3);
		    rectangle(4,4,635,475);
		    setlinestyle(0,1,3);
		    rectangle(0,0,640,480);
		    setlinestyle(0,1,3);
		    setcolor(14);
		    settextstyle(1,0,5);
		    outtextxy(200,10,"ALGORITHMS");

		    settextstyle(0,0,2);
		    putimage(80,75,handimage,OR_PUT);
		    setcolor(4);
		    outtextxy(130,80,"DDA");
		    setcolor(14);
		    outtextxy(130,280,"2-D TRANSFORMATIONS");
		    outtextxy(130,120,"BRESENHAM LINE DRAWING");
		    outtextxy(130,160,"MID-POINT CIRCLE DRAWING");
		    outtextxy(130,200,"POLYGON CLIPPING");
		    outtextxy(130,240,"COHEN SUTHERLAND LINE CLIPPING");
		    outtextxy(130,320,"FLOOD FILL");
		    outtextxy(130,360,"BEIZER CURVE");
				     outtextxy(130,400,"EXIT");
		    getkey();
		    if(ascii==27)   //esc
			  exit(0);
		     if(ascii==13)
		      {
			DDA();
		      }
		    else if(((scan==80)||(scan==72))&&(c==1))
		    {
		     b:        setcolor(14);
			       setfillstyle(0,2);
			       bar(70,60,173,430);
			       putimage(80,75,handimage,OR_PUT);
			       settextstyle(0,0,2);
			       outtextxy(130,120,"BRESENHAM LINE DRAWING");
			       outtextxy(130,160,"MID-POINT CIRCLE DRAWING");
			       outtextxy(130,200,"POLYGON CLIPPING");
			       outtextxy(130,240,"COHEN SUTHERLAND LINE CLIPPING");
			       outtextxy(130,280,"2-D TRANSFORMATIONS");
				     outtextxy(130,360,"BEIZER CURVE");
				     outtextxy(130,400,"EXIT");
			       outtextxy(130,320,"FLOOD FILL");
			       setcolor(4);
			       outtextxy(130,80,"DDA");
			       c++;
			       score=0;
			       getkey();
			       if(ascii==13)  {  DDA();}
			       if(scan==72) { c=9; goto l;}
			       else if((scan==80)&&(c==2))
			       {

		     d:            setcolor(14);
				   setfillstyle(0,2);
				   bar(70,60,173,430);
				   putimage(80,115,handimage,OR_PUT);
				   settextstyle(0,0,2);
				   outtextxy(130,80,"DDA");
				   outtextxy(130,160,"MID-POINT CIRCLE DRAWING");
				   outtextxy(130,200,"POLYGON CLIPPING");
				   outtextxy(130,240,"COHEN SUTHERLAND LINE CLIPPING");
				   outtextxy(130,280,"2-D TRANSFORMATIONS");
				     outtextxy(130,360,"BEIZER CURVE");
				     outtextxy(130,400,"EXIT");
				   outtextxy(130,320,"FLOOD FILL");
				   setcolor(4);
				   outtextxy(130,120,"BRESENHAM LINE DRAWING");
				   c++;
				   getkey();
				   if(ascii==13) {BresL();}
				   else if(scan==72){c-=2; goto b;}
				   if((scan==80)&&(c==3))
				   {
		     e:              setcolor(14);
				     setfillstyle(0,2);
				     bar(70,60,173,430);
				     putimage(80,155,handimage,OR_PUT);
				     settextstyle(0,0,2);
				     outtextxy(130,80,"DDA");
				     outtextxy(130,120,"BRESENHAM LINE DRAWING");
				     outtextxy(130,200,"POLYGON CLIPPING");
				     outtextxy(130,240,"COHEN SUTHERLAND LINE CLIPPING");
				     outtextxy(130,320,"FLOOD FILL");
				     outtextxy(130,280,"2-D TRANSFORMATIONS");
				     outtextxy(130,360,"BEIZER CURVE");
				     outtextxy(130,400,"EXIT");
				     setcolor(4);
				     outtextxy(130,160,"MID-POINT CIRCLE DRAWING");
				     c++;
				     getkey();
				     if(ascii==13) {MidC();}
					  if(scan==72) { c-=2; goto d;}
				     if((scan==80)&&(c==4))
				     {
		     f:              setcolor(14);
				     setfillstyle(0,2);
				     bar(70,60,173,430);
				     putimage(80,195,handimage,OR_PUT);
				     settextstyle(0,0,2);
				     outtextxy(130,80,"DDA");
				     outtextxy(130,120,"BRESENHAM LINE DRAWING");
				     outtextxy(130,160,"MID-POINT CIRCLE DRAWING");
				     outtextxy(130,240,"COHEN SUTHERLAND LINE CLIPPING");
				     outtextxy(130,320,"FLOOD FILL");
				     outtextxy(130,280,"2-D TRANSFORMATIONS");
				     outtextxy(130,360,"BEIZER CURVE");
				     outtextxy(130,400,"EXIT");
				     setcolor(4);
				     outtextxy(130,200,"POLYGON CLIPPING");
				     c++;
				     getkey();
					 if(ascii==13) {Poly();}
					 else if(scan==72) { c-=2; goto e;}
				     else if((scan==80)&&(c==5))
				     {
		     g: 		 setcolor(14);
					 setfillstyle(0,2);
					 bar(70,60,173,430);
					 putimage(80,235,handimage,OR_PUT);
					 settextstyle(0,0,2);
					 outtextxy(130,80,"DDA");
					 outtextxy(130,120,"BRESENHAM LINE DRAWING");
					 outtextxy(130,160,"MID-POINT CIRCLE DRAWING");
					 outtextxy(130,280,"2-D TRANSFORMATIONS");
					 outtextxy(130,200,"POLYGON CLIPPING");
					 outtextxy(130,320,"FLOOD FILL");
					 outtextxy(130,360,"BEIZER CURVE");
				     outtextxy(130,400,"EXIT");
					 setcolor(4);
					 outtextxy(130,240,"COHEN SUTHERLAND LINE CLIPPING");
					 c++;
					 getkey();
					 if(ascii==13){CohenL();}
					 else if(scan==72) { c-=2; goto f;}
					 else if((scan==80))
					 {  c=6; goto h;  }
			  h:              setcolor(14);
				     setfillstyle(0,2);
				     bar(70,60,173,430);
				     putimage(80,275,handimage,OR_PUT);
				     settextstyle(0,0,2);
				     outtextxy(130,80,"DDA");
				     outtextxy(130,120,"BRESENHAM LINE DRAWING");
				     outtextxy(130,160,"MID-POINT CIRCLE DRAWING");
				     outtextxy(130,240,"COHEN SUTHERLAND LINE CLIPPING");
				     outtextxy(130,200,"POLYGON CLIPPING");
				     outtextxy(130,320,"FLOOD FILL");
				     outtextxy(130,360,"BEIZER CURVE");
				     outtextxy(130,400,"EXIT");
				     setcolor(4);
				     outtextxy(130,280,"2-D TRANSFORMATIONS");
				     c++;
				     getkey();
					 if(ascii==13) {n3D();}
					 else if(scan==72) { c-=2; goto g;}
				     else if((scan==80))
				     {
		   i:              setcolor(14);
				     setfillstyle(0,2);
				     bar(70,60,173,430);
				     putimage(80,315,handimage,OR_PUT);
				     settextstyle(0,0,2);
				     outtextxy(130,80,"DDA");
				     outtextxy(130,120,"BRESENHAM LINE DRAWING");
				     outtextxy(130,160,"MID-POINT CIRCLE DRAWING");
				     outtextxy(130,240,"COHEN SUTHERLAND LINE CLIPPING");
				     outtextxy(130,200,"POLYGON CLIPPING");
				     outtextxy(130,280,"2-D TRANSFORMATIONS");
				     outtextxy(130,360,"BEIZER CURVE");
				     outtextxy(130,400,"EXIT");
				     setcolor(4);
				     outtextxy(130,320,"FLOOD FILL");
				     c++;
				     getkey();
					 if(ascii==13) {FF();}
					 else if(scan==72) { c-=2; goto h;}
				     else if((scan==80))
				     {
		      j:              setcolor(14);
				     setfillstyle(0,2);
				     bar(70,60,173,430);
				     putimage(80,355,handimage,OR_PUT);
				     settextstyle(0,0,2);
				     outtextxy(130,80,"DDA");
				     outtextxy(130,120,"BRESENHAM LINE DRAWING");
				     outtextxy(130,160,"MID-POINT CIRCLE DRAWING");
				     outtextxy(130,240,"COHEN SUTHERLAND LINE CLIPPING");
				     outtextxy(130,200,"POLYGON CLIPPING");
				     outtextxy(130,320,"FLOOD FILL");
				     outtextxy(130,280,"2-D TRANSFORMATIONS");

				     outtextxy(130,400,"EXIT");
				     setcolor(4);
				      outtextxy(130,360,"BEIZER CURVE");
				     c++;
				     getkey();
					 if(ascii==13) {Beizer();}
					 else if(scan==72) { c-=2; goto i;}
				     else if((scan==80))
				     {

		    l:              setcolor(14);
				     setfillstyle(0,2);
				     bar(70,60,173,430);
				     putimage(80,395,handimage,OR_PUT);
				     settextstyle(0,0,2);
				     outtextxy(130,80,"DDA");
				     outtextxy(130,120,"BRESENHAM LINE DRAWING");
				     outtextxy(130,160,"MID-POINT CIRCLE DRAWING");
				     outtextxy(130,240,"COHEN SUTHERLAND LINE CLIPPING");
				     outtextxy(130,200,"POLYGON CLIPPING");
				     outtextxy(130,320,"FLOOD FILL");
				     outtextxy(130,280,"2-D TRANSFORMATIONS");
				     outtextxy(130,360,"BEIZER CURVE");
				     setcolor(4);
				     outtextxy(130,400,"EXIT");
				     c++;
				     getkey();
					 if(ascii==13) {
					 exit(0);}
					 else if(scan==72) { c-=2; goto j;}
				     else if((scan==80))
				     {



				      }
				   }
				}

		     }



				      } //g if close
				     } //f if
				   }//e if
			       }// d elseif
		    } //b if
	    }	}//while


 void main()
      {    int gdriver = DETECT,gmode, errorcode;
	   count=0; score=0;
	   initgraph(&gdriver, &gmode, "c:\\TurboC3\\bgi");
	   errorcode = graphresult();
	   if (errorcode != grOk)
	   {
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); /* terminate with an error code */
	   }
	   hand();

	   cleardevice();
	   settextstyle(1,0,4)  ;
	   outtextxy(70,100,"DIGITAL CONTENT DEVELOPMENT");
	   outtextxy(100,150,"FOR TEACHING/LEARNING IN ");
	   outtextxy(140,200,"COMPUTER GRAPHICS.");
	   settextstyle(0,0,1);
	   outtextxy(200,300,"BHAVIK M. JHAVERI (68)");
	   outtextxy(200,320,"PRAJESH A. JHUMKHAWALA (127)");
	   outtextxy(200,340,"ZALAK C. MEHTA (128)");
	   outtextxy(200,360,"RUSHABH K. BAGADIA (129)");
	   outtextxy(400,450,"PRESS ENTER TO CONTINUE...");
	   getkey();
	   if(ascii==13)
	   {

back();    }
      }// main