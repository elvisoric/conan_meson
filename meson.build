
project('base', 'cpp', default_options:['cpp_std=c++14'])

srcs = files(['srcs/main.cpp', 'srcs/foo.cpp'])

incdir = include_directories('include')
fmt_dep = dependency('fmt')
nanodbc_dep = dependency('nanodbc')

project_dep = declare_dependency(include_directories:incdir, sources:srcs, dependencies:[fmt_dep, nanodbc_dep])

executable('base', dependencies:[project_dep])

