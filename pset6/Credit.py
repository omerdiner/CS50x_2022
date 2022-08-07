def main():
    cardNumber = getInput()
    result = checkCard(cardNumber)
    print(result)


def getInput():
    while True:
        try:
            n = int(input("Card Number: "))
        except:
            print("Invalid input !")
        if n > 0:
            return str(n)


def isValidCard(cardNumber):
    twoTimesSum = 0
    normalSum = 0
    i = 0
    for c in cardNumber[::-1]:
        if i % 2 == 1:
            twoTimesSum += getSum(2 * int(c))
        else:
            normalSum += int(c)
        i += 1

    return (normalSum + twoTimesSum) % 10 == 0


def checkCard(cardNumber):
    if isValidCard(cardNumber):
        if len(cardNumber) == 15:
            if cardNumber.startswith("34") or cardNumber.startswith("37"):
                return "AMERICAN EXPRESS"
        elif len(cardNumber) == 13:
            if cardNumber.startswith("4"):
                return "VISA"
        elif len(cardNumber) == 16:
            if cardNumber.startswith("4"):
                return "VISA"
            elif cardNumber.startswith("51") or cardNumber.startswith("52") or cardNumber.startswith(
                    "53") or cardNumber.startswith("54") or cardNumber.startswith("55"):
                return "MASTERCARD"
        else:
            return "INVALID"
    else:
        return "INVALID"


def getSum(n):
    sum = 0
    for digit in str(n):
        sum += int(digit)
    return sum


if __name__ == '__main__':
    main()
