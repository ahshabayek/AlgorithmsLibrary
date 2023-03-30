tests_src = [
  'gtest-all.cpp',
  'fibonacci_test.cpp',
  'max_pairwise_product_test.cpp'

]  
e = executable(
  'gtest-all',
  tests_src,
  dependencies : [
    gtest_dep,
    gmock_dep],
  link_with : libshield,
)    
test('gtest tests', e)