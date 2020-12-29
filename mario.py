def mario():
    while True:
       height = int(input("Height: "))
       width = height + 1
       if height >= 0 and height <= 23:
           break


    for i in range(1, height + 1):
        hashes = i + 1
        spaces = width - hashes

        print(" " * spaces, end="")
        print("#" * hashes)

if __name__ == "__main__":
    mario()

