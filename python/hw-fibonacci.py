def main():
    fibSize = int(input('Fibonacci iterations: '))  # Getting user input for the iterations and parsing it as an int
    a, b = 0, 1                                     # Declaring and assigning 2 variables a,b to the values 0, 1
    for i in range(fibSize):                        # Iterate for i in fibSize and stop when we reach the value of fibSize
        print(a)                                    # Print result
        a, b = b, a+b                               # re-assign values of a, b to the values of b, a+b

if __name__ == '__main__':
    main()
