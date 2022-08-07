def main():
    cents = get_dollars() * 100

    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25

    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10

    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    coins = quarters + dimes + nickels + pennies

    print("Total number of coins: " + str(int(coins)))


def get_dollars():
    while True:
        try:
            n = float(input("How much? : "))
        except:
            print("Invalid input !")
        if n > 0:
            return n


def calculate_quarters(cents):
    return cents // 25


def calculate_dimes(cents):
    return cents // 10


def calculate_nickels(cents):
    return cents // 5


def calculate_pennies(cents):
    return cents


main()
