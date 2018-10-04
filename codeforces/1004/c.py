def solve():
    n = int(input())
    nums = list(map(int, input().split()))
    seen = set()
    num_distinct = [0 for _ in range(n + 1)]
    for i in reversed(range(n)):
        if nums[i] not in seen:
            seen.add(nums[i])
            num_distinct[i] = num_distinct[i + 1] + 1
        else:
            num_distinct[i] = num_distinct[i + 1]
    
    seen = set()
    ans = 0
    for i in range(len(nums)):
        if nums[i] in seen:
            continue
        ans += num_distinct[i + 1]
        seen.add(nums[i])
    print(ans)

solve()
