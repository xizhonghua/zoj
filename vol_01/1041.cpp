//3109883	2012-11-01 01:49:07	 Accepted	1041	C++	0	184	花花的表世界
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SQR(x) ((x)*(x))
#define PI 3.14159265358

struct Point
{
   int x;
   int y;
   double angle;
};

int compare_point(const void* p1, const void*  p2)
{
    return ((Point*)p1)->angle - ((Point*)p2)->angle;
}

double dis(int x0, int y0, int x1, int y1)
{
    return sqrt((double)SQR(x0-x1) + (double)SQR(y0-y1));
}

double angle(int x0, int y0, int x1, int y1)
{
    if(x0 == x1)
    {
	return y1>=y0 ? 90.0 : 270.0;
    }
    else if(y1 == y0)
    {
	return x1<=x0 ? 0.0 : 180.0;
    }
    else
    {
    	double a = atan2((y1-y0), (x1-x0))*180/PI;
	if(a<0) a = 360 + a;
        return a;
    }
}

int inRange(int start, int target, int current)
{
    if(start > target)
        return ((current >= start && current <=360) || (current <= target));
    return (current <= target && current >=start);
}

int main()
{
    int x,y,x1,y1,t,c;
    Point pt[150];
    double r;
    while(1)
    {
        scanf("%d %d %lf", &x, &y, &r);
        if(r<0) break;
        scanf("%d", &t);
	    c = 0;
	    for(int i=0;i<t;i++)
	    {
	        scanf("%d %d", &x1, &y1);
	        if(dis(x, y, x1, y1) > r) continue;
	        pt[c].x = x1;
	        pt[c].y = y1;
	        pt[c].angle = angle(x, y, x1, y1);
	        c++;
	    }
        if(c == 0) { printf("0\n"); continue; }
	    qsort(pt, c, sizeof(Point), compare_point);
      //  for(int i=0;i<c;i++)
     //       printf("%d %d %lf\n", pt[i].x, pt[i].y, pt[i].angle);
	    int max = 1;
	    int count = 1;
	    int j = 1;
        int r = 1;
        for(int k=0;k<c;k++)
        {
            if(j>=c) break;
            double start = pt[k].angle;
            double target = start + 180;
            if (target > 360) target -= 360;
          //  printf("start = %lf target = %lf\n", start, target);
            while(inRange(start, target, pt[j].angle) && (j!=k)){
                count++;
                if(count > max) max = count;
            //    printf("j = %d angle = %lf\n", j, pt[j].angle);
                j++;
                j%=c;
            }
            count--;
        }
	    printf("%d\n", max);
    }
}