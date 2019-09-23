# json-where

> Where are you inside a JSON file?

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

`json-where` can be used from the command line or from inside your editor.

### From the Command Line

```sh
$ ./json-where file_name.json 13
> .[0].nested_key.t1
```

### Inside `vim`

You can add the following function inside your `.vimrc` file.

**Note:** You _must_ have the `json-where` binary in your `PATH` for the
function to work properly. If you have the binary somewhere else, you can change
the function to call that absolute path instead.

```vim
function JsonWhere()
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

You can add a key-binding for this function:

```vim
nmap <leader>jw :echo JsonWhere()<cr>
```

## Compile

`json-where` is a C++ module. All the dependencies are included in this
repository. You can compile this on any computer with g++.

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

The compiled `json-where` binary is put inside the `bin/` folder.

### Compiling with `g++`

```sh
g++ -iquote include/ src/main.cpp -o json-where
```

## Install

After you have compiled the module, you must put the binary in one of the
folders which is in the `$PATH` variable of your shell to make it accessible
from everywhere.

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
