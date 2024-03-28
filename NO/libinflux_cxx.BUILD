# in a BUILD.libinflux_cxx or similar file
load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

filegroup(
    name = "all_srcs",
    srcs = glob(include = ["**"], exclude = ["*.bazel"]), # This includes all files and directories recursively
    visibility = ["//visibility:public"],
)

cmake(
    name = "libinflux_cxx",
    # cache_entries = {
    #     "INFLUXCXX_TESTING": "OFF",
    #     "INFLUXCXX_SYSTEMTEST": "OFF"
    # }
    copts = ["-DINFLUXCXX_TESTING=OFF",
         "-DINFLUXCXX_SYSTEMTEST=OFF"]
    # lib_source = "@libinflux_cxx//:all", # Adjust according to the name you define in the WORKSPACE for the repository
    # lib_source = ":srcs",
    lib_source = ":all_srcs",
    out_static_libs = ["libinfluxdb-cxx.a"], # The name of the output library (adjust as needed)
    # Include any CMake options required to build the project
    # cmake_options = [
    #     "-DINFLUXCXX_TESTING=OFF"
    #     "-DINFLUXCXX_SYSTEMTEST=OFF"
    # ],

    visibility=["//visibility:public"]
)