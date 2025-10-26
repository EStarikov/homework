def sum3(a, b, c):
    return a + b + c


def curry(func, n):
    if n != func.__code__.co_argcount:
        raise Exception("неправильная арность")
        return

    def curried(*args):
        if len(args) >= n:
            return func(*args)
        else:
            return lambda *args2: curried(*(args + args2))
    return curried


def uncurry(func, n):
    def uncurried(*args):
        result = func
        for arg in args:
            result = result(arg)
        return result
    return uncurried


sum3_curry = curry(sum3, 3)
sum3_uncurry = uncurry(sum3_curry, 3)
print(sum3_curry(1)(2)(3))    # 6
print(sum3_uncurry(1, 2, 3))  # 6