import os
import easyocr
import string

def text_recognition(file_path):
    reader = easyocr.Reader(["en", "ru", "de"])

    result = reader.readtext(file_path, detail=0, paragraph=True)
    text = " ".join(result)
    return text

def analyze_text(text):
    num_characters = len(text)
    num_words = len(text.split())
    num_punctuation = sum(1 for char in text if char in string.punctuation)
    language = "English"
    return num_characters, num_words, num_punctuation, language

def main():
    folder_path = input("Enter the folder path containing your pictures: ")

    if os.path.exists(folder_path):
        files = os.listdir(folder_path)
        print("Files in the folder:")
        for i, file in enumerate(files, start=1):
            print(f"{i}. {file}")

        choice = int(input("Enter the number of the file you want to analyze: "))
        if 1 <= choice <= len(files):
            file_to_analyze = files[choice - 1]
            file_path = os.path.join(folder_path, file_to_analyze)
            print(f"Analyzing file: {file_to_analyze}")

            text = text_recognition(file_path)
            num_characters, num_words, num_punctuation, language = analyze_text(text)
            print(f"Number of characters: {num_characters}")
            print(f"Number of words: {num_words}")
            print(f"Number of punctuation: {num_punctuation}")
            print(f"Language: {language}")

        else:
            print("Invalid choice. Please enter a number within the range.")

    else:
        print('Folder does not exist')

if __name__ == "__main__":
    main()
