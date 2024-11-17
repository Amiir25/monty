def do_all(self, arg):
    """
    Prints all string representations of all instances and
    optionally filters by class name.
    """
    if not arg:
        print([str(obj) for obj in storage.all().values()])
        return

    cls = globals().get(arg)
    if cls and issubclass(cls, BaseModel):
        instances = [
            str(obj) for key, obj in storage.all().items()
            if key.startswith(arg + '.')
        ]
        print(instances)
    else:
        print("** class doesn't exist **")
Update default Method to Support New update Commands
Modify the default method to handle both the update commands:

<class name>.update(<id>, <attribute name>, <attribute value>)
<class name>.update(<id>, <dictionary representation>).
Here’s the updated default method:

def default(self, line):
    """Handles commands in the <ClassName>.<command>() format"""

    if '.' not in line:
        print("Command not found: {}".format(line))
        return

    cls_name, mtd_call = line.split('.', 1)
    mtd_name, _, args = mtd_call.partition('(')
    args = args.rstrip(')').strip()

    cls = globals().get(cls_name)
    if not cls or not issubclass(cls, BaseModel):
        print("** class doesn't exist **")
        return

    cmd_map = {
        "all": "do_all",
        "count": "do_count",
        "show": "do_show",
        "destroy": "do_destroy",
        "update": "do_update",
        "create": "do_create"
    }

    if mtd_name in cmd_map:
        if args:
            full_args = f"{cls_name} {args}"
        else:
            full_args = cls_name

        getattr(self, cmd_map[mtd_name])(full_args)

    elif mtd_name == "update":
        self.handle_update(cls_name, args)

    else:
        print("Invalid command: {}".format(mtd_name))

def handle_update(self, cls_name, args):
    """
    Handles the `update` command with different formats:
    - <class name>.update(<id>, <attribute name>, <attribute value>)
    - <class name>.update(<id>, <dictionary>)
    """
    import json

    args_list = args.split(', ', 1)

    if len(args_list) < 1:
        print("** instance id missing **")
        return

    obj_id = args_list[0].strip('"')

    if len(args_list) == 1:
        print("** attribute name missing **")
        return

    obj_key = f"{cls_name}.{obj_id}"
    obj = storage.all().get(obj_key)

    if not obj:
        print("** no instance found **")
        return

    if args_list[1].startswith('{') and args_list[1].endswith('}'):
        # Update with dictionary
        try:
            attr_dict = json.loads(args_list[1].replace("'", '"'))
            for key, value in attr_dict.items():
                setattr(obj, key, value)
            obj.save()
        except json.JSONDecodeError:
            print("** invalid dictionary format **")
    else:
        # Update with <attribute name>, <attribute value>
        attr_name, attr_value = args_list[1].split(', ', 1)
        attr_name = attr_name.strip('"')
        attr_value = attr_value.strip('"')

        # Type conversion if necessary
        if hasattr(obj, attr_name):
            attr_type = type(getattr(obj, attr_name))
            attr_value = attr_type(attr_value)

        setattr(obj, attr_name, attr_value)
        obj.save()
