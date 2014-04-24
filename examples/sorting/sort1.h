#ifndef __SORT1_H__
#define __SORT1_H__

/**
 * sort1.h
 *   Specification of function for sorting strings that takes a 
 *   comparator as a parameter
 */


// +-------+-----------------------------------------------------------
// | Types |
// +-------+

typedef int (*StringComparator)(char *str1, char *str2);


// +--------------------+----------------------------------------------
// | Exported Functions |
// +--------------------+

int strings_sort (int n, char *strings[], StringComparator compare);

#endif // __SORT0_H__
