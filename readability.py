def main():
    count_letter = 0
    count_word = 1
    count_sentence = 0
    text = input(str("Text: "))
    n = len(text)
    for i in range(n):
        if text[i].isalnum() == True:
            count_letter =  count_letter + 1
    for i in range(n):
        if text[i].isspace() == True:
            count_word = count_word + 1
    for i in range(n):
        if text[i] == "?" or text[i] == "." or text[i] == "!":
            count_sentence = count_sentence + 1
    grade = round (0.0588 * ((100 * count_letter) / count_word) - 0.296 * ((100 * count_sentence) / count_word) - 15.8)
    if grade < 1 :
        print("Before Grade 1")
    elif grade < 16:
        print(f"Grade {grade}")
    else :
        print("Grade 16+");

if __name__ == "__main__":
    main()








