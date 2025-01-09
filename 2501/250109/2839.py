n = int(input())

answer = 1667
threefive = 0

for three in range(0, 1667, 3):
    for five in range(0, 1001, 5):
        if three+five == n:
            threefive = three//3 + five//5
            if threefive <= answer:
                answer = threefive

# 3과 5로 n키로를 만들 수 없는 경우
if answer == 1667:
    print("-1")
else:
    print(answer)