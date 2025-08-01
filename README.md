# tbengine

Terminal-Based tExt eNgine

## Building

For Unix-like platforms, you can just run `make`. This generates a static library in the `lib` folder. To build the example, run `make test`. This compiles the `tbtest` example in the `bin` folder

On Windows, build support is currently not there, however Windows support is currently coded in. Since I am not experienced with building C code on Windows, feel free to make a PR to add Windows building support to the makefile.

## Getting Started 

You can check out the example in the `template` folder to see what to do.

### The Text Object

You can make a `Text` object like so:
```c
Text foo;
foo.color = BRIGHTCYAN;
foo.bg = BLACK;
foo.bold = false;
foo.string = "Hello, World!";
```
There are currently 16 color IDs coded in, ranging from 0 to 15. If you're using C++, you don't need to manually define the color, background, and bold values. However, you'll get a warning, which you can completely ignore. 

### How about outputting the text?

This is where the `tbout()` function comes in. It has 3 parameters. A `Text` object, a boolean, and an integer. The last two don't matter unless you want to make your text output character by character like an RPG. The `vn` boolean controls this. Set it to false if you don't want the RPG text output. The `ms` option controls how many milliseconds each character will take to output. Set it to 0 if you don't want to use it. However, in C++, all you need to do is put your `Text` object. Here's an example for `tbout()` written in C:

```c
// no RPG text output
tbout(foo, false, 0);

// RPG text output enabled
tbout(foo, true, 10);
```

Likewise, here is the C++ example:

```cpp
// no RPG text output
tbout(foo);

//RPG text output enabled

tbout(foo, true, 10);
```
