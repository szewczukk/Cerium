project_name = ""
scene_name = ""
print("Welcome to Cerium Game Editor v0.5")
print("Type help to get all commands")

while True:
    action = input("{project_name} / {scene_name} > ".format(project_name=project_name, scene_name=scene_name))

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

            elif obj == "person" or obj == "per":
                print("Person")

            elif obj == "prop" or obj == "prp":
                print("Prop")

            else:
                print("   < Incorrect object to add")
        else:
            print("   < There is no set project")

    elif action == "remove" or action == "r":
        if project_name != "":
            obj = input("  > object=")

    elif action == "set" or action == "s":
        what_to_set = input("  > what to set=")
        name_of = input("  > name=")

        if what_to_set == "project" or what_to_set == "p":
            project_name = name_of

        elif what_to_set == "scene" or what_to_set == "s":
            if project_name != "":
                scene_name = name_of
            else:
                print("   < You must set project before setting scene")
        else:
            print("   < Incorrect object to set")

    elif action == "exit" or action == "e":
        break

    elif action == "help" or action == "h":
        print("\"init\" to initialize new project")
        print("\"add\" to add new object to project")
        print("\"remove\" to remove object from project")
        print("\"set\" to set current project")
        print("\"exit\" to exit from editor")
    else:
        print("   < Incorrect command, type help to get list of all supported commands")
