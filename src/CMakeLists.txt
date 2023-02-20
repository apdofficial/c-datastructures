add_library(data_structures_lib STATIC)

target_sources(data_structures_lib
  PRIVATE
        linked_list.c
        common.c
)

target_include_directories(data_structures_lib PUBLIC include)
