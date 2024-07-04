# SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University
#
# SPDX-License-Identifier: MPL-2.0

import demonstrate_meson_no_openmp as demo

# define class for grouping (test sections)
class Test_no_openmp:
    def test_openmp_is_not_defined_for_compiler_in_header(self):
        assert demo.openmp_is_not_defined_for_compiler_in_header()

    def test_openmp_parallel_pragma_is_not_working_in_header(self):
        assert demo.openmp_parallel_pragma_is_not_working_in_header()

    def test_openmp_thread_count_is_not_same_as_std_thread_count_in_header(self):
        assert demo.openmp_thread_count_is_not_same_as_std_thread_count_in_header()
