# Numerical Analysis

## 1. Linear Interpolation

*   f(x) = -x²-x+3 
    
    Find a root of f(x) in the range of [0,1] with 0.01 Machine Epsilon (x ∈ [1,2])  

    f(1) = 1  
    f(2) = -3  
    f(1)*f(2) < 0 (has root)  
    xt = 1 + 2 / 2 (Bisection Method)  

*   REGULA FALSI (False Position Method)  

    (xh, f(xh)), (xl, f(xl))

    g(x) - y1 = m(x - x1)
    g(x) - f(xh) = (f(xh) - f(xl) / xh - xl) * (x - xh)
    g(xt) = 0 = (f(xh) - f(xl) / xh - xl) * (xt - xh) + f(xh)

    -f(xh) = ( xt(f(xh) - f(xl)) - xhf(xh) + xhf(xl) ) / ( xh - xl )  
    xt = ( -xhf(xh) + xlf(xh) + xhf(xh) - xhf(xl) ) / ( f(xh) - f(xl) )  
    xt = xlf(xh) - xhf(xl) / f(xh) - f(xl)
        
    | xl - xh | !< Epsilon   ->   continue iteration