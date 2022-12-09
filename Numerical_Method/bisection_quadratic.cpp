#include<iostream>
#include<math.h>
#include<cmath>
#include<iomanip>
using namespace std;

float fc_calculate(float coefficient[], float x)
{
    return coefficient[5]*pow(x,5) + coefficient[4]*pow(x,4) + coefficient[3]*pow(x,3) + coefficient[2]*pow(x,2) + coefficient[1]*x + coefficient[0] ;  
}

int main()
{
    int degree;
    float error, coefficients[6] = {0}, x, y, mid, temp, fc, fa;

    // Input highest degree of equation
    cout << "Enter the degree of equation : ";
    cin >> degree;

    // Input coefficients of the equation according to degree
    switch (degree)
    {
        case 1:
            cout << "Enter coefficients of eqn ax + b : ";
            for(int i=degree;i>=0;i--)
                cin >> coefficients[i];
            break;
        case 2:
            cout << "Enter coefficients of eqn ax2 + bx + c : ";
            for(int i=degree;i>=0;i--)
                cin >> coefficients[i];
            break;
        case 3:
            cout << "Enter coefficients of eqn ax3 + bx2 + cx + d : ";
            for(int i=degree;i>=0;i--)
                cin >> coefficients[i];
            break;
        case 4:
            cout << "Enter coefficients of eqn ax4 + bx3 + cx2 + dx + e : ";
            for(int i=degree;i>=0;i--)
                cin >> coefficients[i];
            break;
        case 5:
            cout << "Enter coefficients of eqn ax5 + bx4 + cx3 + dx2 + ex1 + f : ";
            for(int i=degree;i>=0;i--)
                cin >> coefficients[i];
            break;
        default:
            cout << "Invalid !";
    }
    // so that
    // for equation ax3 + bx2 + cx + d
    // coefficient[5]x5 + coefficient[4]x4 + coefficient[3]x3 + coefficient[2]x2 + coefficient[1]x + coefficient[0] 
    // coefficient[4] = 0
    // coefficient[3] = a
    // coefficient[2] = b
    // coefficient[1] = c
    // coefficient[0] = d

    // Input the interval
    cout << "Enter the interval (a,b) : ";
    cin >> x >> y;

    // Input Error Tolerance if specified other default 0.0005
    cout << "Error Tolerance? (Press zero'0' if not specified) : ";
    cin >> error;
    if(error==0)
    {
        error = 0.0005;
    }

    int i=0;
    // print bisection table headings
    cout << "i\t" << "a\t" << "b\t" << "c\t" << "f(c)" << endl;
    fa = fc_calculate(coefficients, x);
    do{
        // x = float((round(x*10000))/10000);
        // y = float((round(y*10000))/10000);
        mid = (x+y)/2.000;
        fc = fc_calculate(coefficients, mid);
        // mid = float((round(mid*10000))/10000);
        // fc = float((round(fc*100000))/100000);
        cout << i << "\t" << setprecision(4) << x << "\t" << setprecision(4) << y << "\t" << setprecision(4) << mid << "\t" << setprecision(4) << fc << endl;
        if(fa>=0)
        {
            if(fc>=0)
                x = mid;
            else
                y = mid;
        }
        else
        {
            if(fc>=0)
                y = mid;
            else
                x = mid;
        }
        i++;
    }while(abs(fc)>error);
    cout << "Root : " << mid;
}