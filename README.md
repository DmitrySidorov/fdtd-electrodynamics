# fdtd-electrodynamics

Simple FDTD client for electrodynamics purposes 

# Compilation process

Below is the process to install required dependancies and compilation process. Now is only for Linux, tested on Ubuntu 14.04 LTS. 

## Required libraries 

### Allegro

Allegro is a cross-platform library mainly aimed at video game and multimedia programming. It handles common, low-level tasks such as creating windows, accepting user input, loading data, drawing images, playing sounds, etc. and generally abstracting away the underlying platform.

To install the stable branch (5.2) run this command in your terminal:

```
sudo add-apt-repository ppa:allegro/5.2
```

Now, run these commands to install the development versions of Allegro:

```
sudo apt-get update
sudo apt-get install liballegro5-dev
```




