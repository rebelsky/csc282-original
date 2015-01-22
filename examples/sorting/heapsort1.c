/**
 * heapsort1.c
 *   A implementation of heapsort for strings.  Based closely on
 *   code Rebelsky wrote for CSC 207, available at
 *     https://github.com/Grinnell-CSC207/heaps/
 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>
#include <string.h>
#include "sort1.h"


// +---------+---------------------------------------------------------
// | Helpers |
// +---------+

/**
 * Find the index of the parent of the value in position i.
 */
int
parent (int i)
{
  return (i - 1) / 2;
} // parent

/**
 * Find the index of the left child of the value in position i.
 */
int
left (int i)
{
  return (i * 2) + 1;
} // left

/**
 * Find the index of the right child of the value in position i.
 */
int
right (int i)
{
  return (i * 2) + 2;
} // left

/**
 * Swap two strings in an array.
 */
int
strings_swap (int n, char *strings[], int i, int j)
{
  char *tmp = strings[i];
  strings[i] = strings[j];
  strings[j] = tmp;
  return 1;     // Success!
} // strings_swap

/**
 * Swap down in a heap of strings.
 */
void
strings_swapDown(int n, char *heap[], int pos, StringComparator compare)
{
  int l = left (pos);   // Index of the left child
  int r = right (pos);  // Index of the right child
  int c;                // Index of the larger child

  // If we don't have a left child, we're done
  if (l >= n)
    return;
  
  // There is at least one child
  else
    {
      // If there's only one child, the left child is larger
      if (r >= n)
        c = l;
      // If the left child is larger
      else if (compare (heap[l], heap[r]) >= 0)
        c = l;
      else // If the right child is larger
        c = r;
      // If the larger child is larger, swap down and coninue
      if (compare (heap[c], heap[pos]) >= 0)
        {
          strings_swap (n, heap, c, pos);
          strings_swapDown (n, heap, c, compare);
        } // if the child is larger
    } // at least one child
} // strings_swapDown

/**
 * Swap up in a heap of strings.
 */
void
strings_swapUp(int n, char *heap[], int pos, StringComparator compare)
{
  int p;        // Index of the parent

  // As long as the value at pos is larger than the parent
  while ((pos > 0) && (compare (heap[pos], heap[p = parent(pos)]) > 0))
    {
      // Swap with the parent
      strings_swap (n, heap, pos, p);
      // And continue upward
      pos = p;
    } // while
} // strings_swapUp

/**
 * Dump an array of strings.
 */
void
strings_dump (int n, char *strings[])
{
  int i;
  for (i = 0; i < n; i++)
    fprintf (stderr, "%s ", strings[i]);
  fprintf (stderr, "\n");
} // strings_dump


// +--------------------+----------------------------------------------
// | Exported Functions |
// +--------------------+

int
strings_sort (int n, char *strings[], StringComparator compare)
{
  int i;
  // Make a heap
  for (i = 0; i < n; i++)
    {
      strings_swapUp (n, strings, i, compare);
    } // for
  // Sort it
  for (i = 0; i < n; i++)
    {
      int size = n-i;
      strings_swap (size, strings, 0, size-1);
      strings_swapDown (size-1, strings, 0, compare);
    } // for
  return 1;     // Success
} // strings_sort
