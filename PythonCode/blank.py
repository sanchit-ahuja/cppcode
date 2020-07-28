#Create a sequence from 100 to 999
three_dig_seq = range(999, 99)
# and an empty list for the palindromes
list_palindromes = []
 
# loop twice over the number sequence
for n1 in three_dig_seq:
    for n2 in three_dig_seq:
        # Get the product
        number = n1 * n2
        # Transform it in string
        number = str(number)
        length_number = int(len(number)/2)
        # Compare each 'letter' to check if
        # it's a palindrome
        for i in range(length_number):
            if number[i] != number[-i - 1]:
                number_is_palindrom = False
                break
        else:
            number_is_palindrom = True
        # Add the number if it's indeed
        # a palindrome
        if number_is_palindrom:
            list_palindromes.append(int(number))
 
print max(list_palindromes)
if __name__ == "__main__":
    pass
