set(LAB011_STEPS
    01_default_and_value_initialization.cpp
    02_parentheses_braces_explicit.cpp
    03_aggregate_initialization.cpp
    04_designated_initializers.cpp
    05_configuration_and_invariants.cpp
)

foreach(step_source IN LISTS LAB011_STEPS)
    get_filename_component(step_name "${step_source}" NAME_WE)
    add_lab011_executable("lab011_step_${step_name}" "${step_source}")
endforeach()
