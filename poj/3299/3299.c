#include<stdio.h>
#include<math.h>

/*
T 35 D 15
T 35.0 D 25.0
E
*/

double GetH(double T,double D);
double GetT(double H,double D);
double GetD(double T,double H);
int main()
{
    char ch1=NULL,ch2=NULL,ch=NULL;
    double d1=0.0,d2=0.0;
    scanf("%c",&ch1);
    while(ch1!='E'&&((scanf("%lf %c%lf",&d1,&ch2,&d2))!=EOF))
    {
            if(ch1=='T')
            {
                if(ch2=='D')
                    printf("%c %.1f %c %.1f H %.1f\n",ch1,d1,ch2,d2,GetH(d1,d2));
                else
                    printf("%c %.1f %c %.1f D %.1f\n",ch1,d1,ch2,d2,GetD(d1,d2));
            }
            else if(ch1=='D')
            {
                if(ch2=='T')
                    printf("%c %.1f %c %.1f H %.1f\n",ch1,d1,ch2,d2,GetH(d2,d1));
                else
                    printf("%c %.1f %c %.1f T %.1f\n",ch1,d1,ch2,d2,GetT(d2,d1));
            }
            else
            {
                if(ch2=='T')
                    printf("%c %.1f %c %.1f D %.1f\n",ch1,d1,ch2,d2,GetD(d2,d1));
                else
                    printf("%c %.1f %c %.1f T %.1f\n",ch1,d1,ch2,d2,GetT(d2,d1));
            }
            getchar();
            scanf("%c",&ch1);
    }
    return 0;
}
double GetH(double T,double D)
{
    double H=0.0;
    double h=0.0,e=0.0;
    e = 6.11 * exp (5417.7530 * ((1/273.16) - (1/(D+273.16))));
    h = (0.5555) * (e - 10.0);
    H = T + h;
    return H;
}
double GetT(double H,double D)
{
    double T=0.0;
    double h=0.0,e=0.0;
    e = 6.11 * exp (5417.7530 * ((1/273.16) - (1/(D+273.16))));
    h = (0.5555) * (e - 10.0);
    T = H - h;
    return T;
}
double GetD(double T,double H)
{
    double D = 0.0;
    double h=0.0,e=0.0;
    h = H - T;
    e = h/0.5555 + 10.0;
    D = 1/(1/273.16-(log((e/6.11)))/5417.7530)-273.16;
    return D;
}
