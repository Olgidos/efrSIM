# efrSIM

Windows executable: https://drive.google.com/file/d/1u1It1q67IVsat86v-1ji2af1QlKqGXJ7/view?usp=sharing

## Building on Linux

### Requirements
Qt version >= 5.15 (5.13 couldn't build). When your distribution doesn't ship a recent enough version, you have to download a more recent version from the Qt website.

### Procedure

* Create a build directory

	```mkdir build```  
	```cd build```

* Call qmake on project file to automatically generate a Makefile

	```qmake ../awsomeSim.pro```

    or something like this when you had to download from the Qt website:

	```~/Qt/5.15.0/gcc_64/bin/qmake ../awsomeSim.pro```

* Call the Makefile

	```make```

* Mark as aexecutable

	```chmod +x efrSIM```

* Run executable

	```./efrSIM```
