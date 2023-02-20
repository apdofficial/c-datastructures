macro(add_test_file NAME)
	add_executable(${NAME} EXCLUDE_FROM_ALL ${CMAKE_CURRENT_SOURCE_DIR}/${NAME}.c)
    target_link_libraries(${NAME} PRIVATE data_structures_lib)
	add_test(NAME ${NAME} COMMAND $<TARGET_FILE:${NAME}>)
	set_target_properties(${NAME} PROPERTIES C_STANDARD 11)
	target_compile_options(${NAME} PUBLIC -Wall -Wextra)
endmacro(add_test_file)

add_test_file(test_linked_list)
set_tests_properties(test_linked_list PROPERTIES FIXTURES_REQUIRED test_fixture)

