if(EXISTS "C:/Users/Djibril BAH/Desktop/SaltInBank/tmp/build/test/BanqTest[1]_tests.cmake")
  include("C:/Users/Djibril BAH/Desktop/SaltInBank/tmp/build/test/BanqTest[1]_tests.cmake")
else()
  add_test(BanqTest_NOT_BUILT BanqTest_NOT_BUILT)
endif()
