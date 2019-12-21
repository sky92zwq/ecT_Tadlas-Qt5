# How to build? #
## client 
- first, install Qt5(recommend lateset version, Qt5.14 is latest until now)
- second, modify "CMAKE_PREFIX_PATH" according to your install path right now.  
  ```   
  set( CMAKE_PREFIX_PATH 'yourpath'/Qt5.14.0/5.14.0/mingw73_64/lib/cmake )
  ```
- third, go to the top level of the codes. 
  ``` 
  mkdir build
  cd build
  cmake ..
  make
  make install
- you can see a dir under the build path named "bin"
  ```
  cd bin
- finally, run the excutable file "ETClient"
## server
- to be continued...

# qt5.7usb
A software of ECT and TDLAS  
client and server are both based on Qt5  
client now is a empty shell,  
client is an entry to transmit command to server , get the information and dispaly.  
server is a calculation center whose data is from UDP port which is connected by a collection device.  
the communication protocol between client and server is TCP. 
