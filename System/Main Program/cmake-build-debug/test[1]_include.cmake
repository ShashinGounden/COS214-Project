if(EXISTS "C:/Users/jonel/OneDrive/Documents/GitHub/COS214-Project/System/Main Program/cmake-build-debug/test[1]_tests.cmake")
  include("C:/Users/jonel/OneDrive/Documents/GitHub/COS214-Project/System/Main Program/cmake-build-debug/test[1]_tests.cmake")
else()
  add_test(test_NOT_BUILT test_NOT_BUILT)
endif()