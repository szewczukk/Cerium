name = ""
while True:
    action = input("{project} > ".format(project=name))

    if action == "init":
        name = input("  > name=")

    elif action == "add":
        if name != "":
            obj = input("  > object=")
            if obj == "resource" or obj == "res":
                print("res")
            elif obj == "scene" or obj == "scn":
                print("scn")

    elif action == "set":
        name = input("  > name=")

    elif action == "exit":
        break
