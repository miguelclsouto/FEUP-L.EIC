num = int(input())

for index in range (1, 11):

    if index == num + 1 and num != 0:

        break

    if num == index:

        res = num ** 2

        print(num, "^", 2, "=", res)

    else:

        res = num * index

        print(num, "x", index, "=", res)



   


