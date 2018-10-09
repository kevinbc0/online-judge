def divides(n, d):
    ans = 0
    while n % d == 0:
        ans += 1
        n = n //d
    return ans, n

def solve():
    small_facts = {
        '1': 1,
        '2': 2,
        '6': 3,
        '24': 4,
        '120': 5,
        '720': 6,
        '5040': 7,
        '40320': 8,
        '362880': 9,
        '3628800': 10,
        '39916800': 11,
        '479001600': 12
    }
    fact = str(input())
    if fact in small_facts:
        print(small_facts[fact])
        return
    new_fact = fact.rstrip('0')
    num_zeroes = len(fact) - len(new_fact)
    last_six = int(new_fact[-6:])
    
    num_twos = 0
    cur_zeroes = 0
    cur_last_six = 1
    for n in range(1, 500000):
        real_n = n
        pow_five, n = divides(n, 5)
        pow_two, n = divides(n, 2)
        if pow_five != 0:
            num_twos -= pow_five
            cur_zeroes += pow_five
        if pow_two != 0:
            num_twos += pow_two
            if num_twos > 10:
                cur_last_six = ((cur_last_six) * pow(2, num_twos - 10)) % 1000000
                num_twos = 10
        cur_last_six = (cur_last_six * n) % 1000000
        
        if cur_zeroes == num_zeroes:
            if cur_last_six * pow(2, num_twos) % 1000000 == last_six:
                print(real_n)
                return
        else:
            assert cur_zeroes < num_zeroes

solve()
