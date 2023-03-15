import numpy as np

# test_func == -x²-x+3
def test_func(x):
    return (-pow(x,2)-x+3)

def regula_falsi(f, xl, xh, epsilon, max_iter):
    # xl        : lower limit
    # xh        : upper limit
    # epsilon   : maximum absolute error
    # max_iter  : maximum iteration count

    if test_func(xl) * test_func(xh) >= 0:
        print("function does not have a root in the specified range..")
        return

    for x in range(max_iter):
        abs = (xl - xh) * -1 if xl - xh < 0 else (xl - xh);
        if(abs < epsilon):
            break;

        calc_fxh = test_func(xh)
        calc_fxl = test_func(xl)

        xt = (xl*calc_fxh - xh*calc_fxl) / (calc_fxh - calc_fxl)

        if(test_func(xt) * calc_fxh < 0):
            xl = xt
        else:
            xh = xt
        
        print(abs)

    return {
        "root": xl,
        "iteration_count": x,
        "absolute_error": (xl-xh)*(-1) if xl-xh < 0 else xl-xh
    }

print(regula_falsi(test_func, 1, 2, 0.2, 40))
