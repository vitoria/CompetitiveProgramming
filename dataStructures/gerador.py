import os


while True:

    os.system("python randomm.py >input")

    os.system("./a.out <input >bibi")

    os.system("./teste <input >corr")

    bibi = open('bibi', 'r')

    corr = open('corr', 'r')

    if bibi.readlines() == corr.readlines():
        print 'ta certo, por enquanto'
    else:
        print "beeeeeeeeeeem"
        break
