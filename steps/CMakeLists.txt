set(LAB01_STEPS
    01_related_variables.cpp
    02_player_struct.cpp
    03_player_methods.cpp
    04_player_class_invariants.cpp
    05_default_constructor.cpp
    06_parameterized_constructor.cpp
    07_delegating_explicit.cpp
    08_robot_v1.cpp
    09_lifecycle_destructor.cpp
    10_const_mutable_cache.cpp
    11_out_of_class_overloads.cpp
    12_composition.cpp
    13_enum_static.cpp
    14_layout_alignment.cpp
    15_tagged_union.cpp
    16_robot_v2.cpp
)

foreach(step_source IN LISTS LAB01_STEPS)
    get_filename_component(step_name "${step_source}" NAME_WE)
    set(step_target "lab01_step_${step_name}")
    add_lab01_executable(${step_target} "${step_source}")
    set_target_properties(${step_target} PROPERTIES OUTPUT_NAME "${step_target}")

    if(BUILD_TESTING)
        add_test(NAME ${step_target} COMMAND ${step_target})
    endif()
endforeach()
