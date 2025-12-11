import pytest
from hypothesis import given, strategies as st, settings
from hsort import h_sort

@given(st.lists(st.integers(), min_size=0, max_size=1000))
@settings(max_examples=500, deadline=40000)
def test_sorting_property(arr):
    result = h_sort(arr.copy())
    for i in range(len(result) - 1):
        assert result[i] <= result[i + 1]


@given(st.lists(st.integers()))
@settings(max_examples=300)
def test_preservation_property(arr):
    result = h_sort(arr.copy())
    assert sorted(arr) == sorted(result)
    assert len(result) == len(arr)


@pytest.mark.parametrize(
    ["n", "expected"], [([], []), ([2], [2]), ([1, 4, 8], [1, 4, 8]), ([
        8, 1, 5], [1, 5, 8]), ([9, 7, 5, 3], [3, 5, 7, 9]), ([1, 2], [1, 2]), ([2, 1], [1, 2])]
)
def test_sort(n, expected):
    assert h_sort(n) == expected
