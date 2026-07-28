from cs50 import get_string
import re

#Request the card number
card = get_string("Card Number:")

#Format validation using regular expression (must have between 13 and 16 numeric digits)
if re.fullmatch(r"\d{13,16}", card):
    card = int(card)
    #Range assessment for 13-digit VISA cards
    if card >= card >= 4000000000000 and card <5000000000000:

        #Explicit mathematical extraction of digits using remainder and integer division
        a = card % 10
        b = ((card % 100) - a) // 10
        c = ((card % 1000) - b) // 100
        d = ((card % 10000) - c) // 1000
        e = ((card % 100000) - d) // 10000
        f = ((card % 1000000) - e) // 100000
        g = ((card % 10000000) - f) // 1000000
        h = ((card % 100000000) - g) // 10000000
        i = ((card % 1000000000) - h) // 100000000
        j = ((card % 10000000000) - i) // 1000000000
        k = ((card % 100000000000) - j) // 10000000000
        l = ((card % 1000000000000) - k) // 100000000000
        m = ((card % 10000000000000) - l) // 1000000000000

        #Verification print. Prints all 13 digits
        print(f"card digits are: a={a}, b={b}, c={c}, d={d}, e={e}, f={f}, g={g}, h={h}, i={i}, j={j}, k={k}, l={l}, m={m}")

        #Extraction of the two digits resulting from multiplying each second number by 2 (Luhn's Algorithm)
        b1 = (b * 2) % 10
        b2 = (((b * 2) % 100) - b1) // 10
        d1 = (d * 2) % 10
        d2 = (((d * 2) % 100) - d1) // 10
        f1 = (f * 2) % 10
        f2 = (((f * 2) % 100) - f1) // 10
        h1 = (h * 2) % 10
        h2 = (((h * 2) % 100) - h1) // 10
        j1 = (j * 2) % 10
        j2 = (((j * 2) % 100) - j1) // 10
        l1 = (l * 2) % 10
        l2 = (((l * 2) % 100) - l1) // 10


        #Print separate digits for validation
        print(f"Doubled number's indiv digits: b1={b1}, b2={b2}, d1={d1}, d2={d2}, f1={f1}, f2={f2}, h1={h1}, h2={h2}, j1={j1}, j2={j2}, l1={l1}, l2={l2}")

        #Summation 1: Accumulation of duplicate digits
        sum1 = b1 + b2 + d1 + d2 + f1 + f2 + h1 + h2 + j1 + j2 + l1 + l2

        #Summation 2: Addition of the non-duplicated digits to the first sum
        sum2 = sum1 + a + c + e + g + i + k + m

        #Checking Luhn's algorithm (must be a multiple of 10)
        tot_rem = sum2 % 10

        print(f"sum2 = {sum2}")
        print(f"Total remain = {tot_rem}")

        if tot_rem == 0:
            print("VISA")
        else:
            print("INVALID")

    #Range evaluation for 15-digit AMEX cards (starting with 34 or 37)
    elif ((card >= 340000000000000 and card < 350000000000000) or (card >= 370000000000000 and card < 380000000000000)):

        #Single extraction for 15 digits
        a = card % 10
        b = ((card % 100) - a) // 10
        c = ((card % 1000) - b) // 100
        d = ((card % 10000) - c) // 1000
        e = ((card % 100000) - d) // 10000
        f = ((card % 1000000) - e) // 100000
        g = ((card % 10000000) - f) // 1000000
        h = ((card % 100000000) - g) // 10000000
        i = ((card % 1000000000) - h) // 100000000
        j = ((card % 10000000000) - i) // 1000000000
        k = ((card % 100000000000) - j) // 10000000000
        l = ((card % 1000000000000) - k) // 100000000000
        m = ((card % 10000000000000) - l) // 1000000000000
        n = ((card % 100000000000000) - m) // 10000000000000
        o = ((card % 1000000000000000) - n) // 100000000000000

        print(f"card digits are: a={a}, b={b}, c={c}, d={d}, e={e}, f={f}, g={g}, h={h}, i={i}, j={j}, k={k}, l={l}, m={m}, n={n}, o={o}")

        #Decomposition of duplicate products for 15 digits
        b1 = (b * 2) % 10
        b2 = (((b * 2) % 100) - b1) // 10
        d1 = (d * 2) % 10
        d2 = (((d * 2) % 100) - d1) // 10
        f1 = (f * 2) % 10
        f2 = (((f * 2) % 100) - f1) // 10
        h1 = (h * 2) % 10
        h2 = (((h * 2) % 100) - h1) // 10
        j1 = (j * 2) % 10
        j2 = (((j * 2) % 100) - j1) // 10
        l1 = (l * 2) % 10
        l2 = (((l * 2) % 100) - l1) // 10
        n1 = (n * 2) % 10
        n2 = (((n * 2) % 100) - n1) // 10

        print(f"Doubled number's indiv digits: b1={b1}, b2={b2}, d1={d1}, d2={d2}, f1={f1}, f2={f2}, h1={h1}, h2={h2}, j1={j1}, j2={j2}, l1={l1}, l2={l2}, n1={n1}, n2={n2}")

        sum1 = b1 + b2 + d1 + d2 + f1 + f2 + h1 + h2 + j1 + j2 + l1 + l2 + n1 + n2
        sum2 = sum1 + a + c + e + g + i + k + m +o

        #Comprobación de la tarjeta
        tot_rem = sum2 % 10
        #Verificación de sumatoria
        print(f"sum2 = {sum2}")
        print(f"total remain = {tot_rem}")

        if tot_rem == 0:
            print("AMEX")
        else:
            print("INVALID")


    #Range evaluation for 16-digit VISA and MASTERCARD cards
    elif ((card >= 4000000000000000 and card < 5000000000000000) or (card >= 5100000000000000 and card < 5600000000000000)):

        #Single extraction for 16 digits
        a = card % 10
        b = ((card % 100) - a) // 10
        c = ((card % 1000) - b) // 100
        d = ((card % 10000) - c) // 1000
        e = ((card % 100000) - d) // 10000
        f = ((card % 1000000) - e) // 100000
        g = ((card % 10000000) - f) // 1000000
        h = ((card % 100000000) - g) // 10000000
        i = ((card % 1000000000) - h) // 100000000
        j = ((card % 10000000000) - i) // 1000000000
        k = ((card % 100000000000) - j) // 10000000000
        l = ((card % 1000000000000) - k) // 100000000000
        m = ((card % 10000000000000) - l) // 1000000000000
        n = ((card % 100000000000000) - m) // 10000000000000
        o = ((card % 1000000000000000) - n) // 100000000000000
        p = ((card % 10000000000000000) - o) // 1000000000000000

        print(f"card digits are: a={a}, b={b}, c={c}, d={d}, e={e}, f={f}, g={g}, h={h}, i={i}, j={j}, k={k}, l={l}, m={m}, n={n}, o={o}, p={p}")

        b1 = (b * 2) % 10
        b2 = (((b * 2) % 100) - b1) // 10
        d1 = (d * 2) % 10
        d2 = (((d * 2) % 100) - d1) // 10
        f1 = (f * 2) % 10
        f2 = (((f * 2) % 100) - f1) // 10
        h1 = (h * 2) % 10
        h2 = (((h * 2) % 100) - h1) // 10
        j1 = (j * 2) % 10
        j2 = (((j * 2) % 100) - j1) // 10
        l1 = (l * 2) % 10
        l2 = (((l * 2) % 100) - l1) // 10
        n1 = (n * 2) % 10
        n2 = (((n * 2) % 100) - n1) // 10
        p1 = (p * 2) % 10
        p2 = (((p * 2) % 100) - p1) // 10

        print(f"Doubled number's indiv digits: b1={b1}, b2={b2}, d1={d1}, d2={d2}, f1={f1}, f2={f2}, h1={h1}, h2={h2}, j1={j1}, j2={j2}, l1={l1}, l2={l2}, n1={n1}, n2={n2}, p1={p1}, p2={p2}")

        sum1 = b1 + b2 + d1 + d2 + f1 + f2 + h1 + h2 + j1 + j2 + l1 + l2 + n1 + n2 + p1 + p2
        sum2 = sum1 + a + c + e + g + i + k + m +o

        tot_rem = sum2 % 10

        print(f"sum2 = {sum2}")
        print(f"total remain = {tot_rem}")

        #Determination of the financial network according to the first digit ('p')
        if tot_rem == 0 and p == 4:
            print("VISA")
        elif tot_rem == 0 and p == 5:
            print("MASTERCARD")
        else:
            print("INVALID")

else:
    print("INVALID")

