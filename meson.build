project('A-004', 'c',
        version : '1.0',
        default_options : ['warning_level=3', 'c_std=c99']
)

#--------------------------
DependecyList = []
ProjectSourceList = []
LinkWithList = []
#--------------------------
RootDirectory = ''


subdir('sources')


executable('A-004', MainSource,
           dependencies : DependecyList,
           link_with : LinkWithList,
           include_directories : RootDirectory
)