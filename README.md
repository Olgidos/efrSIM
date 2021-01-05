# efrSIM

Windows executable: https://drive.google.com/file/d/1u1It1q67IVsat86v-1ji2af1QlKqGXJ7/view?usp=sharing

A detailed explaination is provided in thesis_efrSIM.pdf

3D View movement: 
Page up:                         forward  
Page down:                       backward 
Arrow keys:                      left, right, up, down 
Left click + Mouse movement:     rotate view 

STOP, START, RESET Buttons are on the lower left side. 

As soon as simulation data is available, the red marker in the Big Chart can be used to scroll through the simulated time and specific moments can be displayed. After every simulation a .csv export containing every value is produced inside the progam folder "/efrSIM_output.csv".
A double click on one of the left-sided charts will display the course of its value in the Big Chart. 

Data View:
Every Value available in the Data class is displayed here. They are all sorted into folders depending on their information group. While simulating, the folders should be closed, since drawing charts uses performance. 

Parameter View:
Every Parameter available in the Data class is displayed here. They can be changed with clicking on their values (keeping the mouse inside the number area) and confirm with ENTER. There are also Parameter for chart zoom and replay speed available.

The standard setting correspond the setup of the racecar LillE at the Formula Student Spain 2019 event. 

The project can be downloaded on its GitHub page (https://github.com/Olgidos/efrSIM). There also an download link for a compiled version is provided.

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


