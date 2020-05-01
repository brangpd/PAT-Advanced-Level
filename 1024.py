def reverse(n):
    res = 0
    while n != 0:
        res *= 10
        res += n % 10
        n //= 10
    return res


n, k = input().split()
n, k = int(n), int(k)

i = 0
while i < k:
    tmp = reverse(n)
    if tmp == n:
        break
    n += tmp
    i += 1

print(n)
print(i)
