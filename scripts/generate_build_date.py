Import("env")
from datetime import datetime
x=datetime.now().strftime("%d/%M/%Y %H:%M")
a = "-DBUILD_TIME='\"%s\"'" % x
env.Append(BUILD_FLAGS=[f"{a}"])