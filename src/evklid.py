def gcd(a, b):
    if a == 0:
        return(b, 0 , 1)
    else:
        div, x, y = gcd(b%a, a)
    return(div, y - (b//a)*x, x)
num1 = int(input())
num2 = int(input())
print(gcd(num1, num2))