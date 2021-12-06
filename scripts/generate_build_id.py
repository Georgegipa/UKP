import time
Import('env')
timestamp = int(time.time())
unique_build_id = hex(timestamp).lstrip("0x").upper()
a = "-DBUILD_ID='\"%s\"'" % unique_build_id
env.Append(BUILD_FLAGS=[f"{a}"])