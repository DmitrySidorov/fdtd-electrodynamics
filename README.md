# fdtd-electrodynamics

Simple FDTD client for electrodynamics purposes 

# Compilation process

Below is the process to install required dependancies and compilation process. Now is only for Linux, tested on Ubuntu 14.04 LTS and 16.04 LTS. 

## Required libraries 

### [Allegro](http://liballeg.org/)

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

### [GSL](https://www.gnu.org/software/gsl/)

The GNU Scientific Library (GSL) is a numerical library for C and C++ programmers. It is free software under the GNU General Public License.

The library provides a wide range of mathematical routines such as random number generators, special functions and least-squares fitting. There are over 1000 functions in total with an extensive test suite.

To install this library in ubuntu 14.04 run:

```
apt-get install gsl-bin
sudo apt-get install libgsl0ldbl
```

In 16.04 they have erased *libgsl0ldbl* so you will have to install the development version:

```
apt-get install gsl-bin
sudo apt-get install libgsl0-dev
```

The resources/docs can also be installed using: 

```
sudo apt-get install gsl-doc-info gsl-doc-pdf gsl-ref-html gsl-ref-psdoc
```





