# load("@rules_foreign_cc//foreign_cc:defs.bzl")

# cmake(
#     name = "influxdb_cxx",
#     lib_source = "@influxdb_cxx//:all",
#     # Pass any necessary CMake arguments here
#     cmake_options = [
#         "-DCMAKE_BUILD_TYPE=Release",
#     ],
#     out_shared_libs = ["libinfluxdb.a"],  # Specify the output libraries here
# )


# in a BUILD.libinflux_cxx or similar file
load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

# cmake(
#     name = "libinflux_cxx",
#     lib_source = "@influxdb_cxx//:all", # This needs to be defined in the WORKSPACE file
#     out_static_libs = ["libinfluxdb-cxx.a"], # Adjust according to the actual output
#     # Add any necessary CMake options here using cmake_options = []
# )

filegroup(
    name = "all_srcs",
    srcs = glob(include = ["**"], exclude = ["*.bazel"]), # This includes all files and directories recursively
    visibility = ["//visibility:public"],
)

cmake(
    name = "libinflux_cxx",
    # lib_source = "@libinflux_cxx//:all", # Adjust according to the name you define in the WORKSPACE for the repository
    # lib_source = ":srcs",
    lib_source = ":all_srcs",
    out_static_libs = ["libinfluxdb-cxx.a"], # The name of the output library (adjust as needed)
    # Include any CMake options required to build the project
    # cmake_options = [],
    visibility=["//visibility:public"]
)
