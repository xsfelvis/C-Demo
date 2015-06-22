
#include <stdio.h>
#include <stdlib.h>

#define LENGTH(s) (sizeof(s) / sizeof(int))

struct subarray{
    int start;
    int end;
    int sum;
};

void find_max_cross(int* array, int start, int mid, int end, struct subarray *p) {
    int left_sum = 0;
    int left = 0;
    int right_sum = 0;
    int right = 0;

    int tmp_sum = 0;

    int i = 0;
    for (i = mid; i >= start; i--) {
        tmp_sum = tmp_sum + array[i];
        if (tmp_sum > left_sum) {
            left_sum = tmp_sum;
            left = i;
        }
    }

    tmp_sum = 0;
    for (i = mid + 1; i<= end; i++) {
        tmp_sum = tmp_sum + array[i];
        if (tmp_sum > right_sum) {
            right_sum = tmp_sum;
            right = i;
        }
    }

    p->start = left;
    p->end = right;
    p->sum = left_sum + right_sum;
}

void find_max_subarray(int* array, int start, int end, struct subarray *p) {
    struct subarray sa_left;
    struct subarray sa_right;
    struct subarray sa_cross;

    if (start == end) {
        p->start = start;
        p->end = start;
        p->sum = array[start];
        return;
    }

    int mid = (start + end) / 2;

    find_max_subarray(array, start, mid, &sa_left);
    find_max_subarray(array, mid + 1, end, &sa_right);
    find_max_cross(array, start, mid, end, &sa_cross);

    if (sa_left.sum > sa_right.sum && sa_left.sum > sa_cross.sum) {
        p->start = sa_left.start;
        p->end = sa_left.end;
        p->sum = sa_left.sum;
    } else if (sa_right.sum > sa_left.sum && sa_right.sum > sa_cross.sum) {
        p->start = sa_right.start;
        p->end = sa_right.end;
        p->sum = sa_right.sum;
    } else {
        p->start = sa_cross.start;
        p->end = sa_cross.end;
        p->sum = sa_cross.sum;
    }
}

int main(void) {

    int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    struct subarray sa;

    find_max_subarray(array, 0, LENGTH(array) - 1, &sa);

    printf("max subarray : %d - %d, sum : %d", sa.start, sa.end, sa.sum);
    return EXIT_SUCCESS;
}
