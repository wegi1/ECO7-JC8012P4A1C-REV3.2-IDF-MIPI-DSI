file(GLOB SOURCES "*.cpp" "*.c")

idf_component_register(
    SRCS ${SOURCES}
    INCLUDE_DIRS "."
    REQUIRES 
        esp_driver_i2c 
        esp_lcd 
        esp_timer 
        esp_hw_support 
        esp_common 
        soc touch
)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-missing-field-initializers -Wno-type-limits -Wno-fpermissive)

