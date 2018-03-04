n = int(input())
nums = [int(input()) for _ in range(n)]
sol = ['{} is {}'.format(num, 'even' if num % 2 == 0 else 'odd') for num in nums]
print('\n'.join(sol))
