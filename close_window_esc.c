#include "so_long.h"

int  close_window_esc(int keycode, void *param)
{
  (void) param;

  if (keycode == 65307)
    exit(0);
  return (0);
}