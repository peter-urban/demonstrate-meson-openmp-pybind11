# SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

# --- Project ---
# Define project meta data
project(
  'demonstrate-meson-openmp',
  'cpp',
  license: 'MPL-2.0',

  version: '1.0.0',
  default_options: ['warning_level=2', 'buildtype=release', 'cpp_std=c++20'],
  meson_version: '>=1.4' #latest tested version
)

# --- dependencies ---
demolib_compile_args = []

if meson.get_compiler('cpp').get_id() != 'msvc'
  demolib_compile_args += ['-Werror=unknown-pragmas']  
endif

# openmp
openmp = dependency('openmp')

# pybind11
pymod = import('python').find_installation(get_option('python_path'), pure: false)
python3_dep = pymod.dependency()
pybind11_dep = dependency('pybind11')

# --- build targets ---

# add c++ src
subdir('src')
 

# -- tests (catch2) --
if get_option('build_tests').enabled()
    catch2 = subproject('catch2', default_options: ['tests=false', 'install=false'])
    catch2 = catch2.get_variable('catch2_with_main_dep')

    subdir('tests')
endif
