# Arduino helper macros

macro(do_size size_target)
    add_custom_command(TARGET ${size_target}.elf POST_BUILD
            COMMAND ${SIZE} --format=berkeley "$<TARGET_FILE:${size_target}.elf>"
            COMMENT "Invoking: Cross ARM GNU Print Size")
endmacro(do_size)

macro(do_objcopy objcopy_target type)
    set(do_objcopy_cmd binary)
    set(do_objcopy_ext bin)

    if ("${type}" STREQUAL "srec")
        set(do_objcopy_cmd srec)
        set(do_objcopy_ext srec)
    endif ()

    if ("${type}" STREQUAL "hex")
        set(do_objcopy_cmd ihex)
        set(do_objcopy_ext hex)
    endif ()

    add_custom_target(${objcopy_target}.${do_objcopy_ext} ALL
            ${OBJCOPY} -O${do_objcopy_cmd} ${objcopy_target}.elf ${objcopy_target}.${do_objcopy_ext}
            DEPENDS ${objcopy_target}.elf
            COMMENT "Invoking: Cross ARM GNU OBJCOPY ${objcopy_target} to ${do_objcopy_cmd}")
endmacro(do_objcopy)
