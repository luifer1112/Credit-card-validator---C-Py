from cs50 import get_string


def main():
    # We request the card number as a string to facilitate handling digits
    card = get_string("Number: ")

    # If the input is not just digits, we print INVALID
    if not card.isdigit():
        print("INVALID")
        return

    # Validate Luhn's algorithm
    if not check_luhn(card):
        print("INVALID")
        return

    # Check length and prefixes to determine the brand
    length = len(card)
    start_two = card[:2]
    start_one = card[0]

    if length == 15 and (start_two == "34" or start_two == "37"):
        print("AMEX")
    elif length == 16 and start_two in ["51", "52", "53", "54", "55"]:
        print("MASTERCARD")
    elif (length == 13 or length == 16) and start_one == "4":
        print("VISA")
    else:
        print("INVALID")


def check_luhn(card):
    """Apply Luhn's algorithm by traversing the digits from right to left."""
    total_sum = 0
    # We reverse the string to count backwards from the last digit
    reversed_card = card[::-1]

    for i, char in enumerate(reversed_card):
        digit = int(char)

        # Every second digit starting from the second to last (odd indices in the reversed string)
        if i % 2 == 1:
            doubled = digit * 2
            # Sumar los dígitos del resultado (ej. si doubled es 12 -> 1 + 2 = 3)
            total_sum += (doubled // 10) + (doubled % 10)
        else:
            total_sum += digit

    # It is valid if the remainder when dividing by 10 is 0
    return total_sum % 10 == 0


if __name__ == "__main__":
    main()
