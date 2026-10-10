set(LAB02_STEPS
    01_manual_resource_management.cpp
    02_raii_owner.cpp
    03_stack_unwinding.cpp
    04_constructor_failure.cpp
    05_exception_safe_resize.cpp
    06_noexcept_contracts.cpp
    07_operator_overloading_basics.cpp
    08_array_operators.cpp
)

foreach(step_source IN LISTS LAB02_STEPS)
    get_filename_component(step_name "${step_source}" NAME_WE)
    add_lab02_executable("lab02_step_${step_name}" "${step_source}")
endforeach()
