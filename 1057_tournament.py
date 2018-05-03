N, jimin, hansu = map(int, input().split())
cnt = 0

while (jimin != hansu):
    cnt += 1

    jimin = (jimin + 1) //2
    hansu = (hansu + 1) //2

print(cnt)