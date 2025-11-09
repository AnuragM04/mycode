# Write the program to save url, userid, password separated by | in text format

def create_file():
    with open("pwd_db", "xt"):
        pass
    print("Database Created!")
    
def save_credentials():
    print("File opened in Write-Mode!")
    
    url = input("Enter the URL: ")
    # url_bytes = url.encode("utf-8")
    uId = input("Enter the User-Name: ")
    # uId_bytes = uId.encode("utf-8")
    pwd = input("Enter the Password: ")
    # pwd_bytes = pwd.encode("utf-8")

    with open("pwd_db", "at") as file:
        file.write(f"{url} | {uId} | {pwd}\n")
    print("Credentials are secured.")
    
def get_credentials():
    keys = "URL | User Name | Password"
    with open("pwd_db", "rt") as file:
        print("File opened in Read-Mode!")
        while True:
            str_buff = file.readline()
            if not str_buff:
                break
            else:
                # list_buff = str_buff.strip().split(" | ")
                # for buffer in list_buff:
                #     print(buffer, end = " | ")
                d = dict(zip(keys.split(" | "), str_buff.split(" | ")))
                for k, v in d.items():
                    print(f"{k} : {v}")

def search_credentials():
    url = input("Enter URL to search: ")
    keys = "URL | User Name | Password"
    with open("pwd_db", "rt") as file:
        while True:
            str_buff = file.readline()
            if not str_buff:
                break
            else:
                if url in str_buff:
                    d = dict(zip(keys.split(" | "), str_buff.split(" | ")))
                    for k, v in d.items():
                        print(f"{k} : {v}")

while True:
    print("\n\n1: Save and Encrypt Data")
    print("2: Decrypt and Get Data")
    print("3: Search Data")
    print("4: Create database")
    print("5. Exit")
    choice = input("Your choice, should you choose to accept it: ")
    
    match choice:
        case "1":
            save_credentials()
            
        case "2":
            get_credentials()
        
        case "3":
            search_credentials()
        
        case "4":
            create_file()
            
        case "5":
            print("This code will self-destruct in five seconds...\nThank you.")
            break
        case _:
            print("Choice failed")
    
    if choice > "4":
        break