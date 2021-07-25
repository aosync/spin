project('spin', 'c')

spin_inc = include_directories('.')
spin_lib = static_library('spin', 'spin.c', include_directories : spin_inc)
spin_dep = declare_dependency(link_with : spin_lib, include_directories : spin_inc)

if not meson.is_subproject()
   executable('spinmain', 'main.c', dependencies : spin_dep)
endif