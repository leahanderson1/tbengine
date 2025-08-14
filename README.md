# tbengine

Terminal-Based tExt eNgine

## Building

For Unix-like platforms, you can just run `make`. This generates a static library in the `lib` folder. To build the example, run `make test`. This compiles the `tbtest` example in the `bin` folder

On Windows, build support is currently not there, however Windows support is currently coded in. Since I am not experienced with building C code on Windows, feel free to make a PR to add Windows building support to the makefile.

## To-do list

- [ ] Add full documentation
- [ ] Add SDL3 version so you don't need a terminal to use the library

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
On ending a piece of dialogue with RPG text, it's recommended to use `tbconfirm`. This prompts the player to push the enter/return key to continue dialogue. It has an argument, which is how fast in milliseconds do you want to blink the cursor. Of course, this is redundant if you're on Windows.
## Well, what if I want to ask the player for input?

That's rather simple, too!
enter the `tbin` function.
It has one single argument, which is the maximum length that the player's input string can be. It also returns a dynamically allocated string, which you'll need to `free()` after you're done using it.

Here's an example:
```c
mtbout("Say, what's your name?", BRIGHTCYAN, BLACK, false, true, 50);
char *name = tbin(20);
```

You can have multiple choices too!

### tbselect

The `tbselect()` function lets you have a numbered choice system. The argument `menu` is how many options you want to have. It will return whatever option the player picked. Note that 0 is the first option.
