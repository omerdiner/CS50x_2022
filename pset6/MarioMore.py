def main():
    height = getInput()
    for i in range(height):
        print(" " * (height - i - 1), end="")
        print("#" * (i + 1), end="")
        print(" ", end="")
        print("#" * (i + 1))


def getInput():
    while True:
        try:
            n = int(input("Height: "))
        except:
            print("Not an integer !")
        if n > 0:
            return n


main()
