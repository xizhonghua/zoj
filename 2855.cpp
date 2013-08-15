//2894210	2012-05-15 20:30:09	 Accepted	2855	C++	20	180	花花的表世界
#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793

inline double calc_x(double l)
{
    return l * PI / 180.0;
}
inline double calc_y(double l)
{
    return log(tan(PI / 4.0 + (l * PI / 180.0) / 2.0));
}

int main()
{
    double lon, lat;
    int level;
    while(~scanf("%lf %lf %d", &lon, &lat, &level))
    {
        printf("t");
        double x = calc_x(lon), y = calc_y(lat);
        double lon0 = -180, lon1 = 180, lat0 = -85, lat1 = 85;
        double x0 = calc_x(lon0), x1 = calc_x(lon1), y0 = calc_y(lat0), y1 = calc_y(lat1);
        while(level-->0)
        {
            double mx = (x0 + x1)/2.0;
            double my = (y0 + y1)/2.0;
            int t = 0;
            if(x > mx) {
                x0 = mx;
                if(y > my)
                {
                    y0 = my;
                    printf("r");
                }
                else
                {
                    y1 = my;
                    printf("s");
                }
            }else {
                x1 = mx;
                if(y > my){
                    y0 = my;
                    printf("q");
                }
                else
                {
                    y1 = my;
                    printf("t");
                }
            }
        }
        printf("\n");
    }

}