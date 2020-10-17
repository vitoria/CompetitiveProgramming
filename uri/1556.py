while True:
    try:
        word = input()
        new_words = set([])

        for vowel in word:
            for new_word in new_words.copy():
                new_words.add(new_word + vowel)
            new_words.add(vowel)
        
        for new_word in sorted(new_words):
            print(new_word)
        print('')

    except EOFError:
        break