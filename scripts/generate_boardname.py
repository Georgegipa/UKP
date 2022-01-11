Import("env")
board = env["BOARD"]
a = "-DBOARD_NAME='\"%s\"'" % board
env.Append(BUILD_FLAGS=[f"{a}"])