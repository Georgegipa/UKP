Import("env")

def get_build_flag_value(flag_name):
    build_flags = env.ParseFlags(env['BUILD_FLAGS'])
    flags_with_value_list = [build_flag for build_flag in build_flags.get('CPPDEFINES') if type(build_flag) == list]
    defines = {k: v for (k, v) in flags_with_value_list}
    return defines.get(flag_name).strip('"')

str= "%s_%s_%s" % (get_build_flag_value("PROTOCOL"),env.GetProjectOption("board"),get_build_flag_value("PROTOCOL_VERSION")) 
env.Replace(PROGNAME=str)