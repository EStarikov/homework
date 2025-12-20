def sum3(a, b, c):
    return a + b + c


def curry(func, n, *args1):
    if n != func.__code__.co_argcount:
        raise ValueError

    def curried(*args):
        if len(args + args1) > n:
            raise ValueError
        elif len(args + args1) == n:
            return func(*(args1 + args))
        else:
            return lambda *args2: curried(*(args + args2))
    return curried


def uncurry(func, n):
    def uncurried(*args):
        if len(args) != n:
            raise ValueError
        result = func
        for arg in args:
            result = result(arg)
        return result
    return uncurried


sum3_curry = curry(sum3, 3, 1)
sum3_uncurry = uncurry(sum3_curry, 2)
print(sum3_curry(2)(3))    # 6
print(sum3_uncurry(2, 3))  # 6
