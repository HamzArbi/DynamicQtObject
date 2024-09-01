# Environment

Here are the environment i used to make this project run :

-   Qt version : **6.7.2**
-   UI : **QtQuick (QML)**
-   Backend : **C++**
-   OS : **both Ubuntu & Windows**
-   The run is straight forward, just open the **Qt Creator**, _Ctrl+O_ to open an existing project, select the **CMakeLists.txt** and select the _Qt6.7.2 kit_, and click build and run and it's ready to go !
-   Copy past the samples folder I attached that contains **\*.json** files, somewhere on desktop (keep them inside the folder), I made the app to read directly from the desktop, you may have to change the number of samples from the file name on the code **(Controller.cpp:20)**.

# Some explanations in the code

The app starts from the _main.cpp_, it will declare a _Singleton_ cpp object that will also be used on the QML side, it will read the file config on startup, the config file is a **\*.json file**, that have this format :

```
{
    "cpp_data": [
      {
        "id": "data1",
        "sec": 2,
        "min": 100,
        "max": 800
      }
    ],
    "qml_data": [
      {
        "id": "box1",
        "x": 100,
        "y": 100,
        "color": "pink",
        "dataSource": "data1"
      }
    ]
} // But both part are read using C++
```

C++ will read all the data and add them in a **QVariantList**, which will make it easy to be read by QML through Q_PROPERTY, not forgetting that the C++ will instantly create a timer based on the **"sec"** number of seconds so the **"val"** property will be updated based on **min & max** variables and printing the message on console whenever a value is updated.

At the end the QML will read the Data through Q_PROPERTY and show it using the Repeater and use the remaining fields such as **x, y, color** to draw Rectangles based on how much data has been inserted on the **.json\* file, and showing the **val\*\* variable that you will notice changing whenever a signal of update is sent.

> Thank you for considering my assignment, looking forward to get updates from you !

```

```
