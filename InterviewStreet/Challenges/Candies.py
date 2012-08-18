import sys

N = int(sys.stdin.readline())
rating = []
for case in range(0, N):
    rating.append(int(sys.stdin.readline()))
candies = [1]
for i in range(1, N):
    if rating[i] > rating[i-1]:
        candies.append(candies[i-1]+1)
    else:
        candies.append(1)

for i in range(1, N):
    j = N-i
    if rating[j] < rating[j-1] and candies[j] >= candies[j-1]:
        candies[j-1] = candies[j] + 1

ans = sum(candies)
print(ans)
        
