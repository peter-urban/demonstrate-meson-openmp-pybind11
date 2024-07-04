# SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University
#
# SPDX-License-Identifier: MPL-2.0


# define class for grouping (test sections)
class Test_openmp_header_only:
    def test_openmp_is_defined_for_compiler_in_header(self):
        import demonstrate_meson_openmp_header_only as demo
        assert demo.openmp_is_defined_for_compiler_in_header()

    def test_openmp_parallel_pragma_is_working_in_header(self):
        import demonstrate_meson_openmp_header_only as demo
        assert demo.openmp_parallel_pragma_is_working_in_header()

    def test_openmp_thread_count_is_same_as_std_thread_count_in_header(self):
        import demonstrate_meson_openmp_header_only as demo
        assert demo.openmp_thread_count_is_same_as_std_thread_count_in_header()
