import os
import easyocr

# folder_path - way to folder with pictures
folder_path = input("Enter your address for the folder without spaces with your pictures: ")

if os.path.exists(folder_path):
    files = os.listdir(folder_path)
    print("Files in the folder:")

    file_list = []

    for file in files:
        print(file)

        # file_list - all files in folder
        file_list.append(file)

    images_list = [file for file in file_list if file.endswith('.png')]
    # images_list - files only with .png 
    print("PNG files in:", images_list)
    # names_files - only file names without .png
    names_files = [file[:-4] for file in images_list]

    print("names_files: ", names_files)

    ready_list = []

    for image in images_list:
        full_path = os.path.join(folder_path, image)

        # ready_list - list with full ways to images
        ready_list.append(full_path)

    print("Full paths of PNG files in ready_list:", ready_list)

    amount_files = len(ready_list)
    print("Number of files:", amount_files)

else:
    print('Folder does not exist')


def text_recognition(file_path):
    reader = easyocr.Reader(["en"])
    result = reader.readtext(file_path, detail=0, paragraph=True)
    return result


def main():
    folder_for_save = input("Enter your address for the folder to save your text pictures: ")

    if os.path.exists(folder_for_save):
        text_variables = []  # list with text from images

        for i in range(1, amount_files + 1):
            file_path_i = ready_list[i - 1]  # Corrected index and variable name
            globals()[f"file_path_{i}"] = file_path_i

            text = text_recognition(file_path=file_path_i)
            text_variables.append(text)

        
    
        
        for i, text in enumerate(text_variables, start=1):
            way_text = os.path.join(folder_for_save, names_files[i-1])  # Формирование пути к файлу
            with open(way_text, 'w') as main_txt_file:
                main_txt_file.write(str(text))

    else:
        print('Folder does not exist')


if __name__ == "__main__":
    main()
