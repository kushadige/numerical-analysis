#include <stdio.h>
#include <math.h>

// f(x) = -x² -x + 3
double test_func(double x) {
    return (-pow(x, 2) - x + 3);
}

double regula_falsi(double epsilon, double sub_limit, double top_limit) {
    
    double hasRealRoot = test_func(sub_limit) * test_func(top_limit);
    
    // function does not have a root in the specified range
    if(hasRealRoot > 0) {
        return 0;
    }
    
    double xl = sub_limit;
    double xh = top_limit;
    
    while(1) {
        
        double abs = xl - xh < 0 ? (xl - xh) * -1 : (xl - xh);
        //printf("abs: %.25f - xl: %.25f - xh: %.25f\n", abs, xl, xh);
        if(abs < epsilon) {
            break;
        }
        
        double calced_xh = test_func(xh);
        double calced_xl = test_func(xl);
        
        double xt = (xl*calced_xh - xh*calced_xl) / (calced_xh - calced_xl);
        
        //printf("control: %.25f\n\n", test_func(xt) * calced_xh);
        if(test_func(xt) * calced_xh < 0) {
            xl = xt;
        } else {
            xh = xt;
        }

    }

    return xl;
}

int main(int argc, char **argv)
{
    double epsilon = 0.01;
    double xl = 1;
    double xh = 2;
    
	printf("%.52f\n", regula_falsi(epsilon, xl, xh));
    
    // epsilon 0.7  -> root == 1.3013698630136987244299007215886376798152923583984375
    // epsilon 0.01 -> root == 1.3027756377319943403847446461440995335578918457031250

	return 0;
}