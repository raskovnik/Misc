def goal_parser(command: str):
    return command.replace("()", "o").replace("(al)", "al")

print(goal_parser("G()(al)"))