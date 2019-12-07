# json-where

> Where are you inside a JSON file?

![screenshot][13]

## TOC

- [Usage][4]
    - [From the command line][5]
    - [Inside `vim`][6]
- [Compile][1]
    - [Compiling with `make`][2]
    - [Compiling with `g++`][3]
- [Install][7]
- [Credits][8]
- [License][9]

## Usage

`json-where` can be used from the command line. You can also set it up to run
using a keybinding inside the editor of your choice.

### From the Command Line

```sh
# json-where file-name line column
$ json-where test.json 250  14
.[5].tags[3]
```

### Inside `vim`

You can also invoke `json-where` from `vim`. Once you build `json-where` and put
the executable in your `PATH`, you can use this function to invoke it based on
your cursor position.

```vim
function JsonWhere()
    if executable("json-where") == 0
        return 'ERROR: json-where not found in PATH'
    endif

    let cursor = getcurpos()
    let lnum = cursor[1]
    let colnum = cursor[2]

    let cmd_list = [ ]
    let cmd_list += [ 'json-where' ]
    let cmd_list += [ expand('%:p') ]
    let cmd_list += [ lnum ]
    let cmd_list += [ colnum ]

    let cmd = join(cmd_list, ' ')
    let json_where_output = systemlist(cmd)

    if len(json_where_output) > 0
        return json_where_output[len(json_where_output)-1]
    else
        return 'ERROR: json-where output is invalid'
    endif
endfunction
```

You can attach a keybinding to this function in normal mode:

```vim
nmap <leader>jw :echo JsonWhere()<cr>
```

**Note:** For best results, call JsonWhere with the cursor on the first
character in the JSON key or value.

## Compile

`json-where` is written in C++. All the dependencies are included in this
repository. You can compile this on any computer with g++ or clang.

**Note:** Compile process has been tested on the following setups:

1. Ubuntu 18.04 LTS with `make` and `g++`
    ```
    $ make --version
    GNU Make 4.1
    Built for x86_64-pc-linux-gnu

    $ g++ --version
    g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
    ```

### Compiling with `make`

```sh
make
```

You can find the compiled binary at `bin/json-where`.

### Compiling with `g++`

```sh
g++ -iquote include/ src/main.cpp -o json-where
```

## Install

After compiling the module, you can put the binary in one of the folders which
is in the `$PATH` variable of your shell.

```sh
cp bin/json-where /usr/local/bin
```

## Credits

- [`giacomodrago/minijson_reader`][10]

## License

`minijson_reader`'s LICENSE is included [here][11] and appended to the
[LICENSE][12] notice at the root of this repository.

Everything else in this repository is licensed under the MIT license.

Copyright (C) 2019 Siddharth Kannan <mail@siddharthkannan.in>

[1]: #compile
[2]: #compiling-with-make
[3]: #compiling-with-g++
[4]: #usage
[5]: #from-the-command-line
[6]: inside-vim
[7]: #install
[8]: #credits
[9]: #license
[10]: https://github.com/giacomodrago/minijson_reader
[11]: ./include/minijson/LICENSE.txt
[12]: ./LICENSE
[13]: ./img/screenshot.png
