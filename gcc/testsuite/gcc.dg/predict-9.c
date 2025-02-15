/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-profile_estimate" } */

extern int global;
extern int global2;
extern int global3;

void foo (int base)
{
  int i;
  while (global < 10)
  {
    if(global || global2 || global3)
      return;

    for (i = base; i < 10; i++)
      if (i > 123)
	return;
  }
}

/* { dg-final { scan-tree-dump-times "first match heuristics: 2.0%" 3 "profile_estimate"} } */
/* { dg-final { scan-tree-dump-times "first match heuristics: 4.0%" 1 "profile_estimate"} } */
