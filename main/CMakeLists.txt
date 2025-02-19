idf_component_register(SRCS "my_ulp_app.c"
                    INCLUDE_DIRS "."
                    PRIV_REQUIRES ulp)

# ULP support additions to component CMakeLists.txt.
set(ulp_app_name "ulp_hello_world")

# Specify all C and Assembly source files.
set(ulp_sources "ulp_app/ulp_main.c")

# List all the component source files which include automatically generated ULP export file, ${ulp_app_name}.h:
set(ulp_exp_dep_srcs "my_ulp_app.c")

# Call function to build ULP binary and embed in project using the argument provided above
ulp_embed_binary(${ulp_app_name} "${ulp_sources}" "${ulp_exp_dep_srcs}")
