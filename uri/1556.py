while True:
    try:
        word = input()

        new_words = []

        i = len(word) - 1

        while (i >= 0):
            size = len(new_words)
            for j in range(size):
                if word[i] + new_words[j] not in new_words:
                    new_words.append(word[i] + new_words[j])
            if word[i] not in new_words:
                new_words.append(word[i])
            i -= 1

        new_words.sort()

        for e in new_words:
            print(e)
        print('')
    except EOFError:
        break