// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean
// Research Kiel SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent
// University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>

#include <demonstrate_meson_openmp/openmp_compare_thread_count.hpp>
#include <demonstrate_meson_openmp/openmp_openmp_defined.hpp>
#include <demonstrate_meson_openmp/openmp_try_parallel_pragma.hpp>

PYBIND11_MODULE(MODULE_NAME, m) {
  pybind11::add_ostream_redirect(m, "ostream_redirect");

  m.attr("__version__") = MODULE_VERSION;
  m.doc() = "Module to demonstrate Meson build system with pybind11 and OpenMP "
            "support.";

  m.def("openmp_parallel_pragma_is_not_working_in_header",
        [](){return !demonstrate_meson_openmp::openmp_parallel_pragma_is_working_in_header();},
        "Check if the OpenMP parallel pragma is working in the header file. (should not work)");

  m.def("openmp_is_not_defined_for_compiler_in_header",
        [](){return !demonstrate_meson_openmp::openmp_is_defined_for_compiler_in_header();},
        "Check if the _OPENMP macro is defined for the compiler in the header "
        "file. (should not work)");

  m.def("openmp_thread_count_is_not_same_as_std_thread_count_in_header",
        [](){return !demonstrate_meson_openmp::openmp_thread_count_is_same_as_std_thread_count_in_header();},
        "Check if the OpenMP thread count is the same as the std::thread count "
        "in the header file. (should not work)");

}
