project('A-004', ['c', 'cpp'],
        version : '2.0',
        default_options : ['warning_level=3', 'c_std=c99']
)

RootDirectory = ''

ProjectSources = []

subdir('sources')

C_Compiler      = meson.get_compiler('c')
mingw32_lib     = C_Compiler.find_library('mingw32')
SDL2_lib        = C_Compiler.find_library('SDL2')
SDLmain_lib     = C_Compiler.find_library('SDL2main')
SDLimage_lib    = C_Compiler.find_library('SDL2_image')

executable('A-004', ProjectSources,
           include_directories : RootDirectory,
           dependencies : [mingw32_lib, SDL2_lib, SDLmain_lib, SDLimage_lib]
)