#include "mex.h"
#include <stdio.h>
#include <math.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, 
  const mxArray *prhs[])
{
    
//     The Quadratic Equation "aX^2 + bX + C = 0" //
    
    float a, b, c, root1, root2;
    float realPart, imaginaryPart, disc;
 
    mexGetVariable	("%f %f %f", &a, &b, &c);
    /* If a = 0, it is not a quadratic equation */
   
    a=mxGetScalar(prhs[0]);
    b=mxGetScalar(prhs[1]);
    c=mxGetScalar(prhs[2]);
    mexPrintf("a = %f\n",a);
    mexPrintf("b = %f\n",b);
    mexPrintf("c = %f\n",c);
    if (a == 0 || b == 0 || c == 0)
    {
       mexPrintf("Error: Roots cannot be determined \n");
        exit(1);
    }
    else
    {
        disc = b * b - 4.0 * a * c;
        if (disc < 0)
        {
            mexPrintf("Imaginary Roots\n");
            realPart = -b / (2.0 * a) ;
            imaginaryPart = sqrt(abs(disc)) / (2.0 * a);
            mexPrintf("Root1 = %f  +i %f\n", realPart, imaginaryPart);
            mexPrintf("Root2 = %f  -i %f\n", realPart, imaginaryPart);
        }
        else if (disc == 0)
        {
            mexPrintf("Roots are real and equal\n");
            root1 = -b / (2.0 * a);
            root2 = root1;
            mexPrintf("Root1 = %f\n", root1);
            mexPrintf("Root2 = %f\n", root2);
        }
        else if (disc > 0 )
        {
            mexPrintf("Roots are real and distinct \n");
            root1 =(-b + sqrt(disc)) / (2.0 * a);
            root2 =(-b - sqrt(disc)) / (2.0 * a);
            mexPrintf("Root1 = %f  \n", root1);
            mexPrintf("Root2 = %f  \n", root2);
        }
    }
}
