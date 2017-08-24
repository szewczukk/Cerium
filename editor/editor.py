project_name = ""
while True:
    action = input("{project_name} > ".format(project_name=project_name))

    if action == "init" or action == "i":
        name = input("  > name=")
        path = input("  > path=")

    elif action == "add" or action == "a":
        if project_name != "":
            obj = input("  > object=")
            if obj == "resource" or obj == "res":
                print("res")
            elif obj == "scene" or obj == "scn":
                print("scn")
        else:
            print("  > There is no set project")
    elif action == "remove" or action == "r":
        if project_name != "":
            obj = input("  > object=")

    elif action == "set" or action == "s":
        project_name = input("  > name=")

    elif action == "exit" or action == "e":
        break
