project('Matasano crypto challenges', 'cpp', default_options : ['cpp_std=c++14'], license: 'MIT')

add_global_arguments(['-fdiagnostics-color=always'], language: 'cpp')

thread_dep = dependency('threads')

subdir('./src/1')

celero_dep = dependency('celero', fallback: ['celero', 'celero_dep'])

subdir('./tests')
subdir('./benchmarks')

# vim: ft=cmake
