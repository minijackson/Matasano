boost_testing = dependency('boost', modules: 'test')

base64_testing = executable('base64_testing', 'base64_testing.cpp',
                            include_directories: base64_inc,
							link_with: libbase64,
							dependencies: boost_testing)

test('Base64 Testing', base64_testing, args: ['-l', 'test_suite'])

# vim: ft=cmake
