def char_to_num(char):
    if char == ' ':
        return 0
    return ord(char) - ord('a') + 1

def num_to_char(num):
    if num == 0:
        return ' '
    return chr(ord('a') + num - 1)

def solve():
    n = int(input())
    for _ in range(n):
        text = input()
        op, text = (text[0], text[2:])
        if op == 'e':
            nums = list(map(char_to_num, list(text)))
            for i in range(1, len(nums)):
                nums[i] = nums[i] +  nums[i - 1]
            out = list(map(lambda x: num_to_char(x % 27), nums))
            print(''.join(out))
        else:
            nums = list(map(char_to_num, list(text)))
            decoded = [0 for _ in range(len(nums))]
            decoded[0] = nums[0]
            for i in range(1, len(nums)):
                decoded[i] = nums[i] - nums[i - 1]
            out = list(map(lambda x: num_to_char(x % 27), decoded))
            print(''.join(out))

solve()
